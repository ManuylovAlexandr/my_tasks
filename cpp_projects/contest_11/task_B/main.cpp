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
vector<vector<int>> G;
vector<int> order;

vector<int> findSources(vector<vector<bool>> rel){

}

void dfs1(int v, vector<string> names)
{
    used[v] = true;
    vector<pair<string, int>> tmp;
    for (int j = 0; j < G[v].size(); ++j)
        tmp.emplace_back(names[G[v][j]], G[v][j]);

    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < tmp.size(); ++i)
        if (!used[tmp[i].second])
            dfs1(tmp[i].second, names);
    order.push_back(v);
}

vector<string> getList(vector<string> names, vector<vector<bool>> rel, vector<string> sources)
{
    vector<string> res;

    G.resize(names.size());
    for (int i = 0; i < names.size(); ++i)
        for (int j = 0; j < names.size(); ++j)
            if (rel[i][j])
                G[i].push_back(j);

    used.assign(names.size(), false);
    for (int i = 0; i < sources.size(); ++i)
    {
        int tmp = 0;
        for (int j = 0; j < names.size(); ++j)
            if (names[j] == sources[i])
                tmp = j;
        dfs1(tmp, names);
    }

    for (int k = order.size() - 1; k > -1; --k)
        res.push_back(names[order[k]]);

    return res;
}

void find(vector<int> &arr, int val){
    for (auto i = arr.begin(); i != arr.end(); ++i)
    {
        if (*i == val){
            arr.erase(i);
            return;
        }
    }
}

int main()
{
    vector<string> names = vector<string>();
    vector<vector<bool>> relations;
    vector<int> sources;
    vector<string> sources1;
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
        relations = vector<vector<bool>>(names.size());
        for (int i = 0; i < names.size(); i++)
        {
            relations[i] = vector<bool>(names.size());
            for (int j = 0; j < names.size(); j++)
                relations[i][j] = false;
        }

        for (int k = 0; k < names.size(); ++k)
            sources.push_back(k);

        getline(fin, str);
        while (fin)
        {
            int a = stoi(str.substr(0, str.find(' '))) - 1;
            int b = stoi(str.substr(str.find(' '))) - 1;
            find(sources, b);

            relations[a][b] = true;
            getline(fin, str);

        }
        fin.close();
    }
    for (int l = 0; l < sources.size(); ++l)
        sources1.push_back(names[sources[l]]);
    sort(sources1.begin(), sources1.end());
    vector<string> res = getList(names, relations, sources1);
    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < res.size(); i++)
        fout << res[i] << "\n";
    fout.close();
    return 0;
}