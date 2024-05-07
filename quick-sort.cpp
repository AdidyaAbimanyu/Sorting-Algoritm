#include <iostream>

using namespace std;

int partition(int *arr, int start, int end)
{
    int index = start, pivot_element = arr[end], pivot_index;
    int* temp = new int[end - start + 1];
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < pivot_element)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    temp[index] = pivot_element;
    index++;

    for (int i = start; i < end; i++)
    {
        if (arr[i] > pivot_element)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    index = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == pivot_element)
        {
            pivot_index = i;
        }
        arr[i] = temp[index];
        index++;
    }
    delete[] temp;
    return pivot_index;
}

void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int partition_index = partition(arr, start, end);
        quickSort(arr, start, partition_index - 1);
        quickSort(arr, partition_index + 1, end);
    }
}

int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    unsigned int i;

    srand(time(0));
    for (i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 1000000;
    }

    cout << "Sebelum sorting:\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0)
        {
            cout << "\n";
        }
    }

    quickSort(arr, 0, SIZE - 1);

    cout << "\n\nSetelah sorting:\n";
    for (i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0)
        {
            cout << "\n";
        }
    }

    return 0;
}