#include "ReadWriter.h"
//string, fstream, iostream, vector, Edge.h - included in ReadWriter.h
#include <algorithm>
#include <climits>

using namespace std;
const int INF = 100000000;

// write all values
void ReadWriter::writeValues(std::vector<std::vector<int>> &result)
{
    if (!fout.is_open())
        throw std::ios_base::failure("file not open");

    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            if (i != j)
            {
                int a = result[i][j] == INF ? -1 : result[i][j];
                fout << i << " " << j << " " << a << '\n';
            }
        }
    }
}


void help(int N, vector<vector<int>> &w, vector<vector<int>> &result)
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                result[i][j] = min(result[i][j], result[i][k] + w[k][j]);
}

void solve(int N, int M, vector<Edge> &edges, vector<vector<int>> &result)
{
    vector<vector<int>> w(N);
    for (int j = 0; j < N; ++j)
    {
        w[j].assign(N, INF);
        w[j][j] = 0;
        result[j].assign(N, INF);
        result[j][j] = 0;
    }

    for (int i = 0; i < M; ++i)
    {
        w[edges[i].A][edges[i].B] = edges[i].W;
        result[edges[i].A][edges[i].B] = edges[i].W;
    }

    int m = 1;
    while (m < N - 1)
    {
        help(N, result, result);
        m *= 2;
    }
}


int main()
{
    ReadWriter rw;
    //Входные параметры
    //N - количество вершин, M - количество ребер в графе
    int N, M;
    rw.read2Ints(N, M);

    //Вектор ребер, каждое ребро представлено 3-мя числами (А, В, W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра
    //Основной структурой выбран вектор, так как из него проще добавлять и удалять элементы (а такие операции могут понадобиться).
    vector<Edge> edges;
    rw.readEgdes(M, edges);

    vector<vector<int>> result(N);

    //Алгоритм решения задачи
    solve(N, M, edges, result);

    rw.writeValues(result);

    return 0;
}