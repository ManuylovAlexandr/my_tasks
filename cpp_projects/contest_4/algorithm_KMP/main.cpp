#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

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
//    for (int j = 0; j < z.size() - 1; ++j)
//    {
//        if (z[j + 1] - z[j] == 1)
//            z[j] = 0;
//    }
    return z;
}

//Основная задача - реализовать данный метод
//Можно изменить передачу параметров на ссылки (&)
//Можно добавлять любое количество любых вспомогательных методов, структур и классов
void getSubstrings(string &source, string &substring, vector<int> &res)
{
    vector<int> br = prefix(substring + "*" + source);
    for (int i = substring.length() + 1; i < br.size(); ++i)
    {
        if (br[i] == substring.length())
            res.push_back(i - 2 * substring.length());
    }
//    for (int i = 0; i < z.size(); ++i)
//    {
//        cout<<z[i]<< " ";
//    }
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main()
{
    string t;
    string p;
    vector<int> res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, t);
        getline(fin, p);
        fin.close();
    }

    getSubstrings(t, p, res);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res.size() << "\n";
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        fout << *i << "\n";
    fout.close();

    return 0;
}
