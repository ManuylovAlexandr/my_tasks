#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

// Функция сортировки подсчетом
void countingSort(int *numbers, int array_size)
{
    int max = 0;
    for (int i = 0; i < array_size; ++i)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    int count_array[max + 1];
    for (int i = 0; i <= max; ++i)
    {
        count_array[i] = 0;
    }
    for (int i = 0; i < array_size; ++i)
    {
        count_array[numbers[i]]++;
    }

    int index = array_size - 1;
    for (int i = sizeof(count_array) / sizeof(count_array[0]) - 1; i > -1; --i)
    {
        for (int j = 0; j < count_array[i]; ++j)
        {
            numbers[index] = i;
            index--;
        }
    }
}

//Не удалять и не изменять метод main без крайней необходимости.
//Необходимо добавить комментарии, если все же пришлось изменить метод main.
int main()
{
    //Объект для работы с файлами
    ReadWriter rw;

    int *brr = nullptr;
    int n;

    //Ввод из файла
    n = rw.readInt();

    brr = new int[n];
    rw.readArray(brr, n);

    //Запуск сортировки, ответ в том же массиве (brr)
    countingSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}
