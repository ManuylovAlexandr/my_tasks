#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> manacher(string &s)
{
    int l = 0, r = -1, n = s.length();
    vector<int> d(n);
    for (int i = 0; i < n; ++i)
    {
        int k = i > r ? 1 : min(d[l + r - i], r - i + 1);
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k])
            ++k;
        d[i] = k;
        if (i + k - 1 > r)
        {
            l = i - k + 1;
            r = i + k - 1;
        }
    }
    return d;
}

void calculate(string &s, vector<int> &res)
{
    res = manacher(s);
    for (int i = 0; i < res.size(); ++i)
        res[i] = (res[i] - 1) * 2 + 1;
}

int main()
{
    string input;
    vector<int> res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, input);
        fin.close();
    }

    calculate(input, res);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        fout << *i << " ";
    fout.close();
    return 0;
}