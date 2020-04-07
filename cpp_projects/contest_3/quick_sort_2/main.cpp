#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

int partition(int *arr, int l, int r)
{
    int v = arr[r];
    int i = l, j = r;
    while (i <= j)
    {
        while (arr[i] < v)
        {
            i++;
        }
        while (arr[j] > v)
        {
            j--;
        }
        if (i >= j)
        {
            break;
        }
        swap(arr[i++], arr[j--]);
    }
    if(i == j)
        return --j;
    return j;
}

void quickSortHelper(int *numbers, int l, int r)
{
    if (l < r)
    {
        int q = partition(numbers, l, r);
        quickSortHelper(numbers, l, q);
        quickSortHelper(numbers, q + 1, r);
    }

}

void quickSort(int *numbers, int array_size)
{
    quickSortHelper(numbers, 0, array_size - 1);
}

int main()
{
    int *brr;
    int n;

    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open())
    {
        fin >> n;
        brr = new int[n];
        for (int i = 0; i < n; i++)
            fin >> brr[i];

        fin.close();
    }
    quickSort(brr, n);
    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < n; i++)
        fout << brr[i] << " ";

    fout.close();
    delete[] brr;
    return 0;
}