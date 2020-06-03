﻿#include "ReadWriter.h"
//string, fstream, iostream, vector, Edge.h - included in ReadWriter.h

//Можно создавать любые классы и методы для решения задачи

using namespace std;
const int INF = 2147483647;

//Так как здесь есть несколько способов вывода ответа, то я предлагаю вам самим реализовать метод вывода,
//определенный в классе ReadWriter.
//Можно прямо сюда закинуть матрицу, и потом вычислять какие значения записывать в файл,
//или сначала сформировать вывод в каком-то вспомогательном методе и затем здесь только отправлять в файл.
void ReadWriter::writeValues(std::vector<std::vector<int>> result)
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

    //Для записи в файл используйте конструкции:
    //fout << value1 << value2 << value3;

}


//Основной метод решения задачи, параметры:
//N - количество вершин, M - количество ребер в графе
//edges - вектор ориентированных ребер, каждое ребро представлено 3-мя числами (А, В, W),
// где A и B - номера вершин, которые оно соединяет (Путь строго из А в В), и W - вес ребра
//передается по ссылке (&), чтобы не копировать, изменять вектор и его значения можно.
void solve(int N, int M, vector<Edge> &edges, vector<vector<int>> &matrix)
{
    for (int i = 0; i < N; ++i)
    {
        matrix[i].assign(N, INF);
        matrix[i][i] = 0;
    }
    for (int j = 0; j < M; ++j)
        matrix[edges[j].A][edges[j].B] = edges[j].W;

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (matrix[i][k] < INF && matrix[k][j] < INF)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
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

    //Основной структурой для ответа выбран вектор, так как в него проще добавлять новые элементы.
    vector<vector<int>> result(N);

    //Алгоритм решения задачи
    solve(N, M, edges, result);
    //Здесь можно вызвать ещё какой-то метод, если вам требуется.

    rw.writeValues(result);

    return 0;
}