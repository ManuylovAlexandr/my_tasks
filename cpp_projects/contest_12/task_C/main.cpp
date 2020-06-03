#include "ReadWriter.h"
//string, fstream, iostream, vector, algorithm, Edge.h - included in ReadWriter.h

//Можно создавать любые классы и методы для решения задачи

using namespace std;

bool Comp(Edge a, Edge b)
{
    return a.W < b.W;
}

int findEdge(vector<Edge> &edges, int a, int b)
{
    for (int i = 0; i < edges.size(); ++i)
        if ((edges[i].A == a && edges[i].B == b) || (edges[i].B == a && edges[i].A == b))
            return i;
}

//Основной метод решения задачи, параметры:
//N - количество вершин, M - количество ребер в графе
//edges - вектор ребер, каждое ребро представлено 3-мя числами (А,В,W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра,
//передается по ссылке (&), чтобы не копировать, изменять вектор и его значения можно.
//Результат также в виде вектора ребер, передается по ссылке (&), чтобы не копировать его.
void solve(int N, int M, vector<Edge> &edges, vector<Edge> &result)
{
    sort(edges.begin(), edges.end(), Comp);
    vector<int> tree_id(N);
    for (int i = 0; i < N; ++i)
        tree_id[i] = i;
    for (int i = 0; i < M; ++i)
    {
        if (tree_id[edges[i].A] != tree_id[edges[i].B])
        {
            result.push_back(edges[i]);
            int old_id = tree_id[edges[i].B], new_id = tree_id[edges[i].A];
            for (int j = 0; j < N; ++j)
                if (tree_id[j] == old_id)
                    tree_id[j] = new_id;
        }
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

    //Основной структурой для ответа выбран вектор, так как в него проще добавлять новые элементы.
    //(а предложенные алгоритмы работают итеративно, увеличивая количество ребер входящих в решение на каждом шаге)
    vector<Edge> result;

    //Алгоритм решения задачи
    //В решение должны входить ребра из первоначального набора!
    solve(N, M, edges, result);

    //Выводим результаты
    rw.writeInt(result.size());
    rw.writeEdges(result);

    return 0;
}