#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<bool> used;
vector<int> order, component;
vector<vector<int>> G, H;

void dfs1(int v)
{
    used[v] = true;
    for (int i = 0; i < G[v].size(); ++i)
        if (!used[G[v][i]])
            dfs1(G[v][i]);
    order.push_back(v);
}

void dfs2(int v)
{
    used[v] = true;
    component.push_back(v);
    for (int i = 0; i < H[v].size(); ++i)
        if (!used[H[v][i]])
            dfs2(H[v][i]);
}

vector<vector<string>> getList(const vector<string> &names, const vector<vector<bool>> &rel)
{
    vector<int> a;
    G.resize(names.size());
    H.resize(names.size());

    for (int i = 0; i < names.size(); ++i)
    {
        for (int j = 0; j < names.size(); ++j)
        {
            if (rel[i][j])
            {
                G[i].push_back(j);
                H[j].push_back(i);
            }
        }
    }

    vector<vector<string>> res;
    used.assign(names.size(), false);
    for (int i = 0; i < names.size(); ++i)
        if (!used[i])
            dfs1(i);

    used.assign(names.size(), false);
    for (int i = names.size() - 1; i > -1; --i)
    {
        int v = order[i];
        if (!used[v])
        {
            dfs2(v);
            vector<string> tmp;
            for (int j = 0; j < component.size(); ++j)
                tmp.push_back(names[component[j]]);

            sort(tmp.begin(), tmp.end());
            res.push_back(tmp);
            component.clear();
            tmp.clear();
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<string> names = vector<string>();
    vector<vector<bool>> relations;
    int startIndex;
    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        string str = "";
        getline(fin, str);
        while (str != "#")
        {
            names.emplace_back(str.substr(str.find(' ') + 1));
            getline(fin, str);
        }
        relations = vector<vector<bool >>(names.size());
        for (int i = 0; i < names.size(); i++)
        {
            relations[i] = vector<bool>(names.size());
            for (int j = 0; j < names.size(); j++)
                relations[i][j] = false;
        }
        getline(fin, str);
        while (fin)
        {
            int a = stoi(str.substr(0, str.find(' '))) - 1;
            int b = stoi(str.substr(str.find(' '))) - 1;
            relations[a][b] = true;
            getline(fin, str);
        }
        fin.close();
    }
    vector<vector<string>> res = getList(names, relations);
    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            fout << res[i][j] << "\n";
        fout << "\n";
    }
    fout.close();
    return 0;
}
