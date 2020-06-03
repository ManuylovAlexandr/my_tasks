#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<string> result;

void dec(int n, int k, int i, vector<int> &a)
{
    if (n < 0) return;
    if (n == 0)
    {
        string tmp;
        for (int j = 0; j < i; j++)
        {
            tmp += to_string(a[j]);
            if (j != i - 1)
                tmp += " ";
        }
        result.push_back(tmp);

    }
    else
    {
        if (n - k >= 0)
        {
            a[i] = k;
            dec(n - k, k, i + 1, a);
        }
        if (k - 1 > 0)
            dec(n, k - 1, i, a);
    }
}

//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
static string get(int n)
{
    vector<int> a(n);
    dec(n, n, 0, a);
    string res;
    for (int i = result.size() - 1; i > -1; --i)
    {
        res += result[i];
        if (i != 0)
            res += '\n';
    }
    return res;
}

int main(int argc, const char *argv[])
{
    int N;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open())
    {
        string str;
        getline(fin, str);
        N = atoi(str.c_str());
        fout << get(N) << endl;

        fout.close();
        fin.close();
    }
    return 0;
}