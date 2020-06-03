#include "ReadWriter.cpp"
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

bool Comp(const Node *a, const Node *b)
{
    return a->name < b->name;
}


void DFS(Node &n, std::vector<Node> &graph, std::vector<std::string> &result){
    if (n.visited)
        return;

    result.push_back(n.name);
    n.visited = true;
    vector<Node*> arr;

    for (Node *neighbour : n.neighbours)
        arr.push_back(neighbour);

    sort(arr.begin(), arr.end(), Comp);

    for (Node *neighbour : arr)
        DFS(*neighbour, graph, result);

}
//Можно добавлять любые методы для решения задачи.

//Задача - реализовать данный метод, решение должно быть в переменной result
void solve(std::vector<Node> &graph, int start, std::vector<std::string> &result)
{
    DFS(graph[start], graph, result);
}

int main()
{
    std::vector<Node> graph;
    std::vector<std::string> result;
    int start;

    ReadWriter rw;
    rw.readGraph(graph, start);
    solve(graph, start, result);
    rw.writeAnswer(result);
    return 0;
}
