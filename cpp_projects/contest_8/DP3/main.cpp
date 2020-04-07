#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

string getLCS(string a, string b)
{
    int L[a.length() + 1][b.length() + 1];

    for (int k = 0; k <= a.length(); ++k)
        L[k][0] = 0;
    for (int k = 0; k <= b.length(); ++k)
        L[0][k] = 0;

    for (int i = 1; i < a.length() + 1; ++i)
    {
        for (int j = 1; j < b.length() + 1; ++j)
        {
            if (a[i - 1] == b[j - 1] && a[i - 1] != '\0')
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i][j - 1], L[i - 1][j]);
        }
    }

    string res;

    int i = a.length();
    int j = b.length();

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            res += a[i - 1];
            i--;
            j--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    string x;
    string y;
    string res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, x);
        getline(fin, y);
        fin.close();
    }

    res = getLCS(x, y);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}
