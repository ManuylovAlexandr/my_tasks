#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
typedef unsigned long long ULL;

//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
static string get(ULL n, ULL k, ULL m)
{
    k--;
    vector<ULL> a(m, 1);
    int pos = m - 1;
    while (k)
    {
        a[pos--] = k % n + 1;
        k /= n;
    }
    std::stringstream ss;
    for (int i = 0; i < a.size(); ++i)
    {
        if (i != 0)
            ss << " ";
        ss << a[i];
    }
    return ss.str();
}

int main(int argc, const char *argv[])
{
    ULL M, N, K;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open())
    {
        string str;
        getline(fin, str);
        N = strtol(str.c_str(), NULL, 10);
        getline(fin, str);
        M = strtol(str.c_str(), NULL, 10);
        getline(fin, str);
        K = strtol(str.c_str(), NULL, 10);
        fout << get(N, K, M) << endl;

        fout.close();
        fin.close();
    }
    return 0;
}