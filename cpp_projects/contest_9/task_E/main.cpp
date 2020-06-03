#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int solve(int n, int a, int b, int c)
{
    vector<int> arr(n);
    arr[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        if (i >= a && arr[i - a] == 1)
            arr[i] = 1;
        if (i >= b && arr[i - b] == 1)
            arr[i] = 1;
        if (i >= c && arr[i - c] == 1)
            arr[i] = 1;
    }
    int res = 0;
    for (int i = 0; i <n ; ++i)
        res += arr[i];
    return res;
}

int main()
{
    int n, a, b, c;
    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open())
    {
        fin >> n;
        fin >> a;
        fin >> b;
        fin >> c;
        fin.close();

        fstream fout;
        fout.open("output.txt", ios::out);
        fout << solve(n, a, b, c);
        fout.close();
    }
    return 0;
}