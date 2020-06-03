#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void next_combination(vector<int> &a)
{
    for (int i = a.size() - 1; i > 0; --i)
    {
        if (a[i - 1] != 0)
        {
            a[i - 1]--;
            a[i]++;
            for (int j = i + 1; j < a.size(); ++j)
            {
                a[i] += a[j];
                a[j] = 0;
            }
            break;
        }
    }
}

//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
static string get(int n, int k, int m)
{
    vector<int> values;
    values.push_back(n);
    for (int j = 1; j < m; ++j)
        values.push_back(0);

    for (int l = 0; l < k - 1; ++l)
        next_combination(values);

    stringstream ss;
    for (size_t i = 0; i < m; ++i)
    {
        if (i != 0)
            ss << " ";
        ss << values[i];
    }
    string res = ss.str();
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
        M = atoi(str.c_str());
        getline(fin, str);
        K = atoi(str.c_str());
        fout << get(N, K, M) << endl;

        fout.close();
        fin.close();
    }
    return 0;
}