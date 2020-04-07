#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <fstream>

using namespace std;

class ShannonFano
{
public:
    vector<int> mas; //частоты байтов в порядке невозрастания
    vector<string> res; //кодировки байтов соответсвии с вектором mas
    unordered_map<unsigned char, int> counting_dict; //словарь для подсчета частот байтов
    unordered_map<unsigned char, string> encoding_dict; //словарь для кодировки байтов
    unordered_map<string, unsigned char> coding_dict; //словарь для раскодирования

    ShannonFano() = default;

    void build(int l, int r) //метод шифрования методом Шеннона-Фано
    {
        if (l >= r)
            return;

        if (l == r - 1)
        {
            res[l] += "0";
            res[r] += "1";
            return;
        }

        int highPtr = l, highSum = mas[l];
        int lowPtr = r, lowSum = mas[r];
        while (highPtr != lowPtr - 1)
        {
            if (highSum >= lowSum)
            {
                lowPtr--;
                lowSum += mas[lowPtr];
            }
            else
            {
                highPtr++;
                highSum += mas[highPtr];
            }
        }

        for (int j = l; j <= r; ++j)
        {
            if (j <= highPtr)
                res[j] += "0";
            else
                res[j] += "1";
        }

        build(l, highPtr);
        build(lowPtr, r);
    }

    void code_shannon_fano()
    {
        unordered_map<unsigned char, int>::iterator it = counting_dict.begin();
        while (it != counting_dict.end()) //создаем массив частот байт
        {
            mas.push_back(it->second);
            it++;
        }
        res.resize(mas.size());
        sort(mas.begin(), mas.end(), std::greater<int>()); //для работы алгоритма
        build(0, mas.size() - 1); //получаем res с кодировками байтов
        for (int i = 0; i < mas.size(); ++i)
        {
            {
                it = counting_dict.begin();
                while (it->second != mas[i] && it != counting_dict.end())
                    it++; //ищем совпадение в словаре частот с кодировкой байта

                encoding_dict[it->first] = res[i];
                coding_dict[res[i]] = it->first;
                counting_dict.erase(it); //чтобы не было проблем с байтами одинаковой частоты
            }
        }
    }

    void addChar(unsigned char c) //учитываем количество встреч байтов
    {
        counting_dict[c] += 1;
    }

    string getCode(unsigned char byte)
    {
        return encoding_dict[byte];
    }

    void writeUnshan(const string &code, const string &path) //записываем раскодированный файл по строке бит
    {
        fstream fout;
        fout.open(path, ios::out);
        long i = 0;
        int offset = 1;
        while (i + offset <= code.length())
        {
            if (coding_dict.find(code.substr(i, offset)) != coding_dict.end())
            {
                fout << coding_dict[code.substr(i, offset)];
                i += offset;
                offset = 1;
            }
            else
                offset++;
        }
        fout.close();
    }
};