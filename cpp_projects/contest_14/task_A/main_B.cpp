#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
static string get(int N,int k, int m)
{
    
    return "";
}

int main(int argc, const char * argv[]) 
{
    int M,N,K;
    fstream fin;
    fstream fout;
    fin.open("input.txt",ios::in);
    fout.open("output.txt",ios::out);
    if(fin.is_open()) {
        string str;
        getline(fin,str);
        N = atoi( str.c_str());
        getline(fin,str);
        K = atoi( str.c_str());
        getline(fin,str);
        M = atoi( str.c_str());
        fout << get(N, K, M)<< endl;
         
        fout.close();
        fin.close();
    }
    return 0;
}