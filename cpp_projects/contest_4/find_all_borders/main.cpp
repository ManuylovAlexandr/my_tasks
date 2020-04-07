#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> prefix(string s)
{
    int n = (int) s.length();
    vector<int> z(n);
    int k;
    for (int i = 1; i < n; ++i)
    {
        k = z[i - 1];
        while (k > 0 && s[k] != s[i])
            k = z[k - 1];
        if (s[k] == s[i])
            ++k;
        z[i] = k;
    }
    return z;
}

//Основная задача - реализовать данный метод
//Результат поместить в переменную res, она как раз доступна для изменения
//Можно добавлять любое количество любых вспомогательных методов, структур и классов
void getBorders(string &s, string &res)
{
    vector<int> z = prefix(s);
    for (int i = 0; i < z.size(); ++i)
    {
        cout << z[i] << " ";
        if (i + z[i] == z.size())
        {
            res += s.substr(i, z[i]) + "\n";
        }
    }
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main()
{
    string input;
    string res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, input);
        fin.close();
    }

    getBorders(input, res);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}
