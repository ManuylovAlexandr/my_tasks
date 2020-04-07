#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>


using namespace std;

const int N = 31;

int countMinSum(int seconds, vector<int> &values1)
{
    vector<long> values;
    for (int i = 0; i < N; ++i)
        values.push_back((long)values1[i]);

    for (int i = 1; i < N; ++i)
    {
        if (values[i - 1] * 2 > values[i])
            values[i] = values[i - 1] * 2;
    }
    int p = 0;
    for (int i = 30; i > -1; --i)
    {
        if (seconds >= values[i])
        {
            seconds -= values[i];
            p += pow(2, i);
        }
    }
    if (seconds > 0)
        p++;
    return p;
}


int main()
{
    vector<int> values;
    int value = 0, seconds = 0;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        fin >> seconds;
        for (int i = 0; i < N; i++)
        {
            fin >> value;
            values.push_back(value);
        }
        fin.close();
    }

    int res = countMinSum(seconds, values);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}
