#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <queue>
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

vector<Node> encodeLZ77(const string &s)
{
    queue<char> buffer;
    vector<Node> res;
    size_t pos = 0;
    while (pos < s.length())
    {
        Node node = findMatching(buffer, pos);
        for (int i = pos; i < pos + node.length + 1; ++i)
        {
            buffer.push(s[i]);
        }
        shiftBuffer(node.length + 1)
        pos += node.length;
        node.next = s[pos];
        res.push_back(node);
    }
    return res;
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}