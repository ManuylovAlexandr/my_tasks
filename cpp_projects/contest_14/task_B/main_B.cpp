#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

BigInteger fact(int n)
{
    BigInteger res = 1;
    for (int i = 0; i < n; ++i)
        res *= (i + 1);
    return res;
}

BigInteger A(int n, int m)
{
    return fact(n) / fact(n - m);
}


//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
static string get(int n, int k, int m)
{
    vector<int> vect;
    for (int l = 1; l < n + 1; ++l)
        vect.push_back(l);
    BigInteger kreal = k - 1;
    string res;
    BigInteger a = A(n, m);
    int tmp = 0;
    for (int i = 0; i < m; ++i)
    {
        a /= (n - i);
        for (int j = 1; j < n + 1; ++j)
        {
            if (a * j > kreal)
            {
                tmp = j;
                break;
            }
        }
        kreal %= a;
        res += to_string(vect[tmp - 1]);
        vect.erase(vect.begin() + (tmp - 1));
        if (i != m - 1)
            res += " ";
    }
    return res;
}

int main(int argc, const char *argv[])
{
    int M, N, K;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open())
    {
        string str;
        getline(fin, str);
        N = atoi(str.c_str());
        getline(fin, str);
        K = atoi(str.c_str());
        getline(fin, str);
        M = atoi(str.c_str());
        fout << get(N, K, M) << endl;

        fout.close();
        fin.close();
    }
    return 0;
}