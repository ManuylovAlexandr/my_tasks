#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
vector<vector<int>> A;

void find_ans(int k, int s, vector<int> &ans, vector<int> &ans1, vector<int> &arr, vector<int> &mas)
{
    if (A[k][s] == 0)
        return;
    if (A[k - 1][s] == A[k][s])
        find_ans(k - 1, s, ans, ans1, arr, mas);
    else
    {
        find_ans(k - 1, s - arr[k - 1], ans, ans1, arr, mas);
        ans.push_back(mas[k - 1]);
        ans1.push_back(arr[k - 1]);
    }
}

void solve(int N, int W, vector<int> &arr, vector<int> &mas, vector<int> &res, vector<int> &res1)
{
    for (int j = 0; j < N + 1; ++j)
    {
        vector<int> a(W + 1);
        A.push_back(a);
    }

    for (int k = 1; k < N + 1; ++k)
    {
        for (int s = 1; s < W + 1; ++s)
        {
            if (s >= arr[k - 1])
                A[k][s] = max(A[k - 1][s], A[k - 1][s - arr[k - 1]] + mas[k - 1]);
            else
                A[k][s] = A[k - 1][s];
        }
    }
    find_ans(N, W, res, res1, arr, mas);
}

int main(int argc, const char *argv[])
{
    int N; //камни
    int M; //ограничения на вес

    vector<int> arr; //веса
    vector<int> mas; // стоимости

    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open())
    {
        vector<int> res;
        vector<int> res1;

        fin >> N;
        fin >> M;

        for (int i = 0; i < N; ++i)
        {
            int a;
            fin >> a;
            arr.push_back(a);
        }

        for (int i = 0; i < N; ++i)
        {
            int a;
            fin >> a;
            mas.push_back(a);
        }

        fin.close();

        solve(N, M, arr, mas, res, res1);

        int sum = 0;
        for (int re : res)
            sum += re;

        int sum1 = 0;
        for (int re : res1)
            sum1 += re;

        fstream fout;
        fout.open("output.txt", ios::out);
        fout << sum << '\n';
        fout << sum1 << '\n';
        fout << res.size() << '\n';

        for (int j : res1)
        {
            fout << j <<' ';
        }
        fout<<'\n';
        for (int re : res)
        {
            fout << re <<' ';
        }
        fout.close();
    }
    return 0;
}