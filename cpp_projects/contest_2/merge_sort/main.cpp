#include "ReadWriter.h"
#include "MergeSort.h"
//iostream, fstream включены в ReadWriter.h

//Не рекомендуется добавлять собственные вспомогательные классы и методы.
//Необходимо использовать уже имеющиеся классы и методы, добавив реализацию, соответствующую описанию.
using namespace std;

//Описание методов на английском языке имеется в классе MergeSort, в файле MergeSort.h
void MergeSort::sort(int *arr, int length)
{
    divide_and_merge(arr, 0, length - 1);
}

void MergeSort::merge(int *arr, int first, int second, int end)
{
    int i = first, k = first, j = second + 1;
    int mas[end + 1];

    while (i <= second + 1 && j <= end + 1)
    {
        if (arr[i] <= arr[j])
        {
            mas[k] = arr[i];
            i++;
        }
        else
        {
            mas[k] = arr[j];
            j++;
        }
        k++;
        if (i == second + 1)
        {
            while (j < end + 1)
            {
                mas[k] = arr[j];
                j++;
                k++;
            }
            break;
        }
        else if (j == end + 1)
        {
            while (i < second + 1)
            {
                mas[k] = arr[i];
                i++;
                k++;
            }
            break;
        }
    }

    for (int l = first; l < end + 1; ++l)
    {
        arr[l] = mas[l];
    }
}

void MergeSort::divide_and_merge(int *arr, int left, int right)
{
    if (left < right)
    {
        divide_and_merge(arr, left, (right + left) / 2);
        divide_and_merge(arr, (right + left) / 2 + 1, right);
        merge(arr, left, (right + left) / 2, right);
    }
}

int main()
{
    ReadWriter rw;

    int *brr = nullptr;
    int length;

    //Read data from file
    length = rw.readInt();

    brr = new int[length];
    rw.readArray(brr, length);

    //Start sorting
    MergeSort s;

    s.sort(brr, length);

    //Write answer to file
    rw.writeArray(brr, length);

    delete[] brr;

    return 0;
}
