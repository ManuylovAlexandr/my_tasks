#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

BigInteger P(int n)
{
    BigInteger res = 1;
    for (int i = 1; i < n + 1; ++i)
        res *= i;
    return res;
}

//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
static string get_day(int n, int k)
{
    vector<int> vect;
    for (int l = 1; l < n + 1; ++l)
        vect.push_back(l);
    BigInteger kreal = k - 1;
    string res;
    BigInteger a = P(n);
    int tmp = 0;
    for (int i = 0; i < n - 1; ++i)
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
        res += " ";
    }
    res += to_string(vect[0]);
    return res;
}

int main(int argc, const char *argv[])
{
    int N, K;
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
        fout << get_day(N, K) << endl;

        fout.close();
        fin.close();
    }

    return 0;
}
