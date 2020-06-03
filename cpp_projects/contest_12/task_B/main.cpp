#include "ReadWriter.h"
//string, fstream, iostream, vector, algorithm, Edge.h - included in ReadWriter.h

//Можно создавать любые классы и методы для решения задачи

using namespace std;

vector<vector<int>> graph;
int inf = 30000;

void fillGraph(int N, vector<Edge> &edges)
{
    for (int i = 0; i < N; ++i)
    {
        vector<int> tmp(N, inf);
        graph.push_back(tmp);
    }
    for (int j = 0; j < edges.size(); ++j)
    {
        graph[edges[j].A][edges[j].B] = edges[j].W;
        graph[edges[j].B][edges[j].A] = edges[j].W;
    }
}

int findEdge(vector<Edge> &edges, int a, int b){
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
    fillGraph(N, edges);
    vector<bool> used(N);
    vector<int> min_e(N, inf), sel_e(N, -1);
    min_e[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        int v = -1;
        for (int j = 0; j < N; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        used[v] = true;
        if (sel_e[v] != -1)
            result.push_back(edges[findEdge(edges, v, sel_e[v])]);

        for (int to = 0; to < N; ++to)
        {
            if (graph[v][to] < min_e[to])
            {
                min_e[to] = graph[v][to];
                sel_e[to] = v;
            }
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