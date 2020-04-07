#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

//Необходимо реализовать метод
//о алгоритме можно прочитать в источниках указанных в программе курса, или на странице курса в ЛМС или в презентациях к семинару.
int Wagner_Fischer_for_Damerau_Levenshtein(string& s, string& t)
{
    int len_s = s.length() + 1;
    int len_t = t.length() + 1;
    int D[len_s][len_t];

    for (int i = 0; i < len_s; ++i)
        D[i][0] = i;

    for (int j = 0; j < len_t; j++)
        D[0][j] = j;

    for (int i = 1; i < len_s; ++i)
    {
        for (int j = 1; j < len_t; ++j)
        {
            int cost = s[i - 1] == t[j - 1] ? 0 : 1;
            D[i][j] = min(min(D[i - 1][j] + 1, D[i][j - 1] + 1), D[i - 1][j - 1] + cost);

            if (i > 1 && j > 1 && s[i - 1] == t[j - 2] && s[i - 2] == t[j - 1])
                D[i][j] = min(D[i][j], D[i - 2][j - 2] + cost);
        }
    }
    return D[len_s - 1][len_t - 1];
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main(int argc, const char * argv[])
{
    int n;
    fstream fin;
    fstream fout;
    fin.open("input.txt",ios::in);
    fout.open("output.txt",ios::out);
    if(fin.is_open()) {
        string N;
        getline(fin,N);
        n = atoi( N.c_str());
        for (int i = 0; i < n; i++) {
            string s;
            string t;
            getline(fin,s);
            getline(fin,t);
            fout << Wagner_Fischer_for_Damerau_Levenshtein(s, t) << (i == n-1 ? "" : " ");
        }
        fout.close();
        fin.close();
    }
    return 0;
}