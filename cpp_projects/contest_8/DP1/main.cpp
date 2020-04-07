#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Основная задача - реализовать данный метод
int countMaxCross(string &riverMap)
{
    int res = 0;
    string s;
    for (char i : riverMap)
    {
        if (i != 'B')
            s += i;
        else
            ++res;
    }
    bool isLeft = true;
    for (int i = 0; i < s.length() - 1; ++i)
    {
        if (isLeft)
        {
            if (s[i] == 'L' && s[i + 1] == 'L')
            {
                isLeft = false;
                res++;
            }
        }

        else
        {
            if (s[i] == 'R' && s[i + 1] == 'R')
            {
                isLeft = true;
                res++;
            }
        }

        if (isLeft && s[i] == 'L')
            res++;

        else if (!isLeft && s[i] == 'R')
            res++;
    }

    if (isLeft && s[s.length() - 1] == 'L')
        res++;
    else if (isLeft)
        res++;
    else if (!isLeft && s[s.length() - 1] == 'R')
        res++;

    return res;
}


int main()
{
    string riverMap;
    int res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, riverMap);
        fin.close();
    }

    res = countMaxCross(riverMap);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}
