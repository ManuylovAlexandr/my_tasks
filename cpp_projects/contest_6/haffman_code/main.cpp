#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

struct Node
{
public:
    int value = 0;
    string code = "-1";
    Node *left;
    Node *right;
    Node *parent = nullptr;

    Node(int val)
    {
        value = val;
    }

    void setCode(string c)
    {
        code = c;
    }

    void setValue(int v)
    {
        value = v;
    }
};


class Huffman
{
public:
    vector<Node*> q;
    vector<Node *> res;

    void push_el(Node *pNode)
    {
        vector<Node*>::iterator it = q.begin();
        while(it != q.end()){
            if ((*it)->value < pNode->value)
            {
                q.insert(it, pNode);
                return;
            }
            ++it;
        }
        q.push_back(pNode);
    }

    void build()
    {
        while (q.size() > 1)
        {
            Node *r = q.back();
            r->setCode("0");
            q.pop_back();
            Node *l = q.back();
            l->setCode("1");
            q.pop_back();
            Node *node = new Node(l->value + r->value);
            node->left = l;
            node->right = r;
            r->parent = node;
            l->parent = node;
            push_el(node);
        }
    }

    void addChance(int chance)
    {
        Node *node = new Node(chance);
        node->setValue(chance);
        q.push_back(node);
        res.push_back(node);
    }

    string get(int i)
    {
        string h_code;
        Node *tmp = res[i];
        while (tmp->parent != nullptr)
        {
            h_code += tmp->code;
            tmp = tmp->parent;
        }
        reverse(begin(h_code), end(h_code));
        return h_code;
    }
};


int main()
{
    int n;
    Huffman *huff = new Huffman();
    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open())
    {
        fin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            fin >> x;
            huff->addChance(x);
        }

        fin.close();

        huff->build();
        fstream fout;
        fout.open("output.txt", ios::out);
        for (int i = 0; i < n; i++)
        {
            fout << huff->get(i) << (i == n - 1 ? "" : " ");
        }
        fout.close();
        delete huff;
    }

    return 0;

}

