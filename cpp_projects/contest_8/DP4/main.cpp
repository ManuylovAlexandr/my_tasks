#include "ReadWriter.h"
#include <algorithm>
//vector, string, iostream included in "ReadWriter.h"

using namespace std;
vector<vector<int>> A;

void find_ans(int k, int s, vector<int> &ans, int *stones)
{
    if (A[k][s] == 0)
        return;
    if (A[k - 1][s] == A[k][s])
        find_ans(k - 1, s, ans, stones);
    else
    {
        find_ans(k - 1, s - stones[k - 1], ans, stones);
        ans.push_back(stones[k - 1]);
    }
}

//Можно добавлять любые вспомогательные методы и классы для решения задачи.

//Задача реализовать этот метод
//param N - количество камней
//param M - ограничения на вес
//param stones - массив размера N, с весами камней
//param res - вектор результатов (вес камней, которые надо взять)


void solve(int N, int W, int *stones, vector<int> &res)
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
            if (s >= stones[k - 1])
                A[k][s] = max(A[k - 1][s], A[k - 1][s - stones[k - 1]] + stones[k - 1]);
            else
                A[k][s] = A[k - 1][s];
        }
    }

    find_ans(N, W, res, stones);
    sort(res.begin(), res.end());
}

int main(int argc, const char *argv[])
{
    ReadWriter rw;
    int N = rw.readInt(); //камни
    int W = rw.readInt(); //ограничения на вес
    int *arr = new int[N]; //имеющиеся камни
    rw.readArr(arr, N);

    //основной структурой выбран вектор, так как заранее неизвестно какое количество камней будет взято
    vector<int> res;
    //решаем задачу
    solve(N, W, arr, res);
    int sum = 0;
    for (int i = 0; i < res.size(); i++)
        sum += res.at(i);

    //записываем ответ в файл
    rw.writeInt(sum); //итоговый вес
    rw.writeInt(res.size()); //количество взятых камней
    rw.writeVector(res); //сами камни

    delete[] arr;
    return 0;
}