#include "ReadWriter.h"
#include <vector>
//string, iostream included in "ReadWriter.h"

using namespace std;

vector<vector<long long>> A;

long long func(int i, int j, int N, int M)
{
    if (i > -1 && j > -1 && i < N && j < M)
    {
        if (A[i][j] != -1)
            return A[i][j];
        else
        {
            A[i][j] = func(i - 2, j - 1, N, M) + func(i - 1, j - 2, N, M) + func(i - 2, j + 1, N, M) +
                      func(i + 1, j - 2, N, M);
            return A[i][j];
        }
    }
    else
        return 0;
}

void print(int N, int M)
{
    for (int i = 0; i < N; ++i)
    {
        string s;
        for (int j = 0; j < M; ++j)
        {
            s += to_string(A[i][j]) + " ";
        }
        cout << s << endl;
    }
}

//Можно добавлять любые вспомогательные методы и классы для решения задачи.

//Задача реализовать этот метод
//param N - количество строк (rows) доски
//param M - количество столбцов (columns) доски
//return - количество способов попасть в правый нижний угол доски (клетка N-1, M-1, если считать что первая клетка 0,0)
long long solve(int N, int M)
{
    for (int i = 0; i < N; ++i)
    {
        vector<long long> v(M, -1);
        A.push_back(v);
    }
    A[0][0] = 1;
    func(N - 1, M - 1, N, M);
    print(N, M);
    if (A[N - 1][M - 1] == -1)
        return 0;
    return A[N - 1][M - 1];
}

int main(int argc, const char *argv[])
{
    ReadWriter rw;

    int N = rw.readInt(); //количество строк (rows)
    int M = rw.readInt(); //количество столбцов (columns)
    //решение
    long long res = solve(N, M);
    //результат в файл
    rw.writeLongLong(res);

    return 0;
}