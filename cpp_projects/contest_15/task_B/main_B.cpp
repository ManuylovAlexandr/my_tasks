#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void convert(long long val, long long base, vector<long long> &res)
{
    long long k;
    while (val >= base)
    {
        k = val % base;
        res.push_back(k + 1);
        val /= base;
        base--;
    }
    res.push_back(val + 1);
}

//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
static string get(long long n, long long k)
{
    vector<long long> a;
    convert(k - 1, n, a);
    int capacity = a.size();
    for (int i = 0; i < n - capacity; ++i)
        a.push_back(1);
    reverse(a.begin(), a.end());
    stringstream ss;
    for(size_t i = 0; i < a.size(); ++i)
    {
        if(i != 0)
            ss << " ";
        ss << a[i];
    }
    return ss.str();
}

int main(int argc, const char *argv[])
{
    long long N, K;
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
        K = strtol(str.c_str(), NULL, 10);
        fout << get(N, K) << endl;

        fout.close();
        fin.close();
    }
    return 0;
}