#include <iostream>

using namespace std;

void merge(int *arr, int first, int second, int end)
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

void divide_and_merge(int *arr, int left, int right)
{
    if (left < right)
    {
        divide_and_merge(arr, left, (right + left) / 2);
        divide_and_merge(arr, (right + left) / 2 + 1, right);
        merge(arr, left, (right + left) / 2, right);
    }
}

int binary_search(int *arr, int value, int n)
{
    int l = -1, r = n, m = 0;

    while (l + 1 < r)
    {
        m = (l + r) / 2;
        if (value < arr[m])
        {
            r = m;
        }
        else{
            l = m;
        }

    }
    return r;
}

int main()
{
    int n, k;
    cin >> n;
    int left[n];
    int right[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> left[i] >> right[i];
    }

    divide_and_merge(left, 0, n - 1);
    divide_and_merge(right, 0, n - 1);

    cin >> k;

    for (int j = 0; j < k; ++j)
    {
        int hour;
        cin >> hour;

        cout << abs(binary_search(left, hour, n) - binary_search(right, hour-1, n)) << endl;
    }
}

