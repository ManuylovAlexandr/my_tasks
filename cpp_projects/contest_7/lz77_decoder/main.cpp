#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;


struct Node
{
    int offset;
    int length;
    char next;

public:
    Node(int o, int l, char n)
    {
        offset = o;
        length = l;
        next = n;
    }
};

string decodeLZ77(const vector<Node> &encoded)
{
    string res;
    for (int i = 0; i < encoded.size(); ++i)
    {
        if (encoded[i].length > 0)
        {
            int start = res.length() - encoded[i].offset;
            for (int j = 0; j < encoded[i].length; ++j)
                res += res[start + j];
        }
        res += encoded[i].next;
    }
    return res;
}

int main()
{
    int n;
    vector<Node> encoded;

    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open())
    {
        fin >> n;

        for (int i = 0; i < n; i++)
        {
            int offset;
            int len;
            char next;
            fin >> offset;
            fin >> len;
            fin >> next;
            encoded.emplace_back(offset, len, next);
        }

        fin.close();

        fstream fout;
        fout.open("output.txt", ios::out);
        fout<<decodeLZ77(encoded);
        fout.close();
    }
    return 0;
}