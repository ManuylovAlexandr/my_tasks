
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class ShannonFano
{
public:
    vector<int> mas;
    vector<string> res;

    ShannonFano()
    {
    }

    void helper(int l, int r)
    {
        if (l >= r)
            return;

        if (l == r - 1)
        {
            res[l] += "0";
            res[r] += "1";
            return;
        }

        int highPtr = l, highSum = mas[l];
        int lowPtr = r, lowSum = mas[r];
        while (highPtr != lowPtr - 1)
        {
            if (highSum >= lowSum)
            {
                lowPtr--;
                lowSum += mas[lowPtr];
            }
            else
            {
                highPtr++;
                highSum += mas[highPtr];
            }
        }

        for (int j = l; j <= r; ++j)
        {
            if (j <= highPtr)
                res[j] += "0";
            else
                res[j] += "1";
        }

        helper(l, highPtr);
        helper(lowPtr, r);
    }


    void build()
    {
        res.resize(mas.size());
        helper(0, mas.size() - 1);
    }

    void addChance(int chance)
    {
        mas.push_back(chance);
    }

    string get(int i)
    {
        return res[i];
    }

};


int main()
{
    int n;
    ShannonFano *shf = new ShannonFano();

    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open())
    {
        fin >> n;

        for (int i = 0; i < n; i++)
        {
            int x;
            fin >> x;
            shf->addChance(x);
        }

        fin.close();

        shf->build();
        fstream fout;
        fout.open("output.txt", ios::out);
        for (int i = 0; i < n; i++)
        {
            fout << shf->get(i) << (i == n - 1 ? "" : " ");
        }
        fout.close();
        delete shf;

    }
    return 0;
}