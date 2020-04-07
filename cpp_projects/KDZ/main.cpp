// КДЗ по дисциплине Алгоритмы и структуры данных, 2019-2020 уч.год
// Мануйлов Александр Андреевич, группа БПИ-183, дата (07.04.2020)
// Среда разработки - CLion
// Состав проекта - main.cpp, ShannonFano.cpp
// Сделано сжатие и распаковка методом Шеннона - Фано, проведен вычислительный эксперимент, построены
// таблицы и графики, для измерения времени выполнения использовались наносекунды, оформлен отчет
// Не сделано сжатие и распаковка алгоритмом LZ77

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "ShannonFano.cpp"
#include <algorithm>
#include <windows.h>
#include "map"

using namespace std;

bool isFilesEqual(const string &lFilePath, const string &rFilePath)
{
    int BUFFER_SIZE = 2000000;
    ifstream lFile(lFilePath.c_str(), ifstream::in | ifstream::binary);
    ifstream rFile(rFilePath.c_str(), ifstream::in | ifstream::binary);


    if (!lFile.is_open() || !rFile.is_open())
    {
        cout << !lFile.is_open() << !rFile.is_open() << endl;
        return false;
    }
    char *lBuffer = new char[BUFFER_SIZE]();
    char *rBuffer = new char[BUFFER_SIZE]();

    do
    {
        lFile.read(lBuffer, BUFFER_SIZE);
        rFile.read(rBuffer, BUFFER_SIZE);

        if (memcmp(lBuffer, rBuffer, BUFFER_SIZE) != 0)
        {
            delete[] lBuffer;
            delete[] rBuffer;
            return false;
        }
    } while (lFile.good() || rFile.good());

    delete[] lBuffer;
    delete[] rBuffer;
    return true;
}

unsigned char bitsToChar(string s) //для перевода 8 символов(байта) в char
{
    unsigned char res = 0;
    for (int i = 0; i < 8; ++i)
    {
        char m[1] = {s[7 - i]};
        res += atoi(m) * pow(2, i);
    }
    return res;
}

string charToBits(unsigned char byte) //для перевода char в двоичный код (двоичную сс)
{
    string res;
    for (int i = 0; byte; i++)
    {
        res += to_string(byte % 2);
        byte /= 2;
    }
    reverse(res.begin(), res.end());
    if (res.length() < 8)
        res = string(8 - res.length(), '0') + res;

    return res;
}

string writeFile(const string &path, const string &bits) //записываем заштфрованный файл
{
    fstream fout;
    fout.open(path, ios::out);

    long i = 0;
    while (i + 8 < bits.length())
    {
        fout << bitsToChar(bits.substr(i, 8));
        i += 8;
    }
    fout.close();
    return bits.substr(i);
}

void readFile(const string &path, ShannonFano &shf) //чтение исходного файла
{
    fstream fin;
    fin.open(path, ios::in);
    if (fin.is_open())
    {
        while (true)
        {
            char a = fin.get();
            if (fin.eof())
                break;
            shf.addChar(a);
        }
        fin.close();
    }
}

void makeBitCode(string &bits, const string &path, ShannonFano &shf) //создаем битовую кодировку файла
{
    fstream fin;
    fin.open(path, ios::in);
    if (fin.is_open())
    {
        while (true)
        {
            char a = fin.get();
            if (fin.eof())
                break;
            bits += shf.getCode(a);
        }
        fin.close();
    }
}

void readCodedFile(string &bits, const string &path) //читаем закодированный файл и восстанавливаем кодировку
{
    fstream fin;
    fin.open(path, ios::in);
    if (fin.is_open())
    {
        while (true)
        {
            char a = fin.get();
            if (fin.eof())
                break;
            bits += charToBits(a);
        }
        fin.close();
    }
}

int main()
{
    LARGE_INTEGER frec, start, finish;
    ::QueryPerformanceFrequency(&frec);
    unordered_map<unsigned char, long> dict;
    map<int, string> helper_dict{
            make_pair(1, "txt"),
            make_pair(2, "pdf"),
            make_pair(3, "docx"),
            make_pair(4, "exe"),
            make_pair(5, "bin"),
            make_pair(6, "pptx"),
            make_pair(7, "bmp"),
            make_pair(8, "jpg"),
            make_pair(9, "bmp"),
            make_pair(10, "jpg"),
    };

    for (int j = 1; j < 11; ++j)
    {
        unordered_map<unsigned char, long> dict1;
        auto *shf = new ShannonFano();
        string bits;
        long num_bytes = 0;
        double H = 0;

        ::QueryPerformanceCounter(&start);

        readFile("DATA\\" + to_string(j) + "." + helper_dict[j], *shf);

        for (auto it = shf->counting_dict.begin(); it != shf->counting_dict.end(); it++)
        {
            num_bytes += it->second;
            dict[it->first] += it->second;
            dict1[it->first] += it->second;
        }

        fstream fout; // считаем частоты символов
        fout.open("DATA\\" + to_string(j) + "_.csv", ios::out);
        for (int i = 0; i < 256; ++i)
        {
            fout << dict1[i];
            fout << ";";
            if (dict1[i] != 0)
                H += ((double) dict1[i] / (double) num_bytes) * log2((double) dict1[i] / (double) num_bytes);
        }
        H *= -1;
        fout.close();

        shf->code_shannon_fano();

        makeBitCode(bits, "DATA\\" + to_string(j) + "." + helper_dict[j], *shf);

        string ending = writeFile("DATA\\" + to_string(j) + ".shan", bits);
        ::QueryPerformanceCounter(&finish);
        cout << "На запаковку " + to_string(j) + " файла потребовалось " +
                to_string((finish.QuadPart - start.QuadPart) * 1000000000 / frec.QuadPart) + " наносекунд" << endl;
        bits.clear();


        ::QueryPerformanceCounter(&start);

        readCodedFile(bits, "DATA\\" + to_string(j) + ".shan");
        bits += ending;

        shf->writeUnshan(bits, "DATA\\" + to_string(j) + ".unshan");

        ::QueryPerformanceCounter(&finish);
        cout << "На распаковку " + to_string(j) + " файла потребовалось " +
                to_string((finish.QuadPart - start.QuadPart) * 1000000000 / frec.QuadPart) + " наносекунд" << endl;

        cout << "Энтропия = " << H << endl;
        cout << isFilesEqual("DATA\\" + to_string(j) + "." + helper_dict[j], "DATA\\" + to_string(j) + ".unshan")
             << endl;

        delete shf;
    }
    fstream fout; // считаем частоты символов
    fout.open("DATA\\all_.csv", ios::out);
    for (int i = 0; i < 256; ++i)
    {
        fout << dict[i];
        fout << ";";
    }
    fout.close();
    return 0;
}