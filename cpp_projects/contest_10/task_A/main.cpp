#include "ReadWriter.cpp"
#include <queue>
#include <algorithm>

using namespace std;
//Можно добавлять любые методы для решения задачи.

bool Comp(const Node &a, const Node &b)
{
    return a.name < b.name;
}

//Задача - реализовать данный метод, решение должно быть в переменной result
void solve(std::vector<Node> &graph, int start, std::vector<std::string> &result)
{
    queue<Node> used;
    used.push(graph[start]);
    graph[start].visited = true;
    while (!used.empty())
    {
        vector<Node> arr;
        int size = used.size();
        for (int i = 0; i < size; ++i)
        {
            Node tmp = used.front();
            used.pop();
            arr.push_back(tmp);
            for (Node *neighbour : tmp.neighbours)
            {
                if (!neighbour->visited)
                {
                    used.push(*neighbour);
                    neighbour->visited = true;
                }
            }
        }
        sort(arr.begin(), arr.end(), Comp);
        for (const Node &j : arr)
            result.push_back(j.name);
    }
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
