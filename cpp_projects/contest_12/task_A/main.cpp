#include "ReadWriter.h"
#include <stack>
//string, fstream, iostream, vector, algorithm, Edge.h - included in ReadWriter.h

//Можно создавать любые классы и методы для решения задачи

using namespace std;

//Основной метод решения задачи, параметры:
//N - количество вершин, M - количество ребер в графе
//edges - вектор ребер, каждое ребро представлено 3-мя числами (А,В,W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра,
//передается по ссылке (&), чтобы не копировать, изменять вектор и его значения можно.
//Результат также в виде вектора ребер, передается по ссылке (&), чтобы не копировать его.

class Vertex
{
public:
    int number;
    int comp;
};

vector<Vertex> createVertexes(vector<Edge> &ed, int N)
{
    vector<Vertex> vert;
    for (int j = 0; j < N; ++j)
    {
        Vertex v;
        v.number = j;
        v.comp = j;
        vert.push_back(v);
    }
    return vert;
}

bool findEdge(vector<Edge> &result, Edge edge)
{
    for (int i = 0; i < result.size(); ++i)
        if (result[i].number == edge.number)
            return true;
    return false;
}

int findComponents(vector<Edge> &T, vector<Vertex> &vert)
{
    stack<Vertex> s;
    vector<bool> used;
    for (int i = 0; i < vert.size(); ++i)
        used.push_back(false);

    int comp = 0;
    int count = vert.size();
    s.push(vert[0]);
    used[0] = true;
    while (count > 0)
    {
        while (!s.empty())
        {
            Vertex v = s.top();
            s.pop();
            v.comp = comp;
            vert[v.number].comp = comp;
            count--;
            for (int i = 0; i < T.size(); ++i)
            {
                if (T[i].A == v.number && !used[T[i].B]){
                    s.push(vert[T[i].B]);
                    used[T[i].B] = true;
                }
                if (T[i].B == v.number && !used[T[i].A]){
                    s.push(vert[T[i].A]);
                    used[T[i].A] = true;
                }
            }
        }
        for (int j = 0; j < vert.size(); ++j)
        {
            if (!used[j]){
                s.push(vert[j]);
                used[j] = true;
                break;
            }
        }
        comp++;
    }
    return comp;
}

void solve(int N, int M, vector<Edge> &edges, vector<Edge> &result)
{
    vector<Vertex> vert = createVertexes(edges, N);
    vector<Edge> minEdges;
    for (int i = 0; i < N; ++i)
    {
        Edge tmp;
        tmp.W = 30000;
        minEdges.push_back(tmp);
    }

    while (result.size() < N - 1)
    {
        for (int j = 0; j < M; ++j)
        {
            if (vert[edges[j].A].comp != vert[edges[j].B].comp)
            {
                if (minEdges[vert[edges[j].A].comp].W > edges[j].W)
                    minEdges[vert[edges[j].A].comp] = edges[j];
                if (minEdges[vert[edges[j].B].comp].W > edges[j].W)
                    minEdges[vert[edges[j].B].comp] = edges[j];
            }
        }
        for (int k = 0; k < minEdges.size(); ++k)
        {
            if (!findEdge(result, minEdges[k]))
                result.push_back(minEdges[k]);
        }
        if (result.size() == N - 1)
            break;
        minEdges.clear();
        int comp_number = findComponents(result, vert);
        for (int i = 0; i < comp_number; ++i)
        {
            Edge tmp;
            tmp.W = 30000;
            minEdges.push_back(tmp);
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