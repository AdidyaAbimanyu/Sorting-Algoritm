#include <iostream>

using namespace std;

void merge(int array[], int left, int mid, int right)
{
    int sub_array_one = mid - left + 1;
    int sub_array_two = right - mid;

    int* left_array = new int[sub_array_one];
    int* right_array = new int[sub_array_two];

    for (int i = 0; i < sub_array_one; i++)
        left_array[i] = array[left + i];
    for (int j = 0; j < sub_array_two; j++)
        right_array[j] = array[mid + 1 + j];

    int index_of_sub_array_ne = 0;
    int index_of_sub_array_two = 0;
    int index_of_merged_array = left;

    while (index_of_sub_array_ne < sub_array_one && index_of_sub_array_two < sub_array_two) {
        if (left_array[index_of_sub_array_ne] <= right_array[index_of_sub_array_two]) {
            array[index_of_merged_array] = left_array[index_of_sub_array_ne];
            index_of_sub_array_ne++;
        }
        else {
            array[index_of_merged_array] = right_array[index_of_sub_array_two];
            index_of_sub_array_two++;
        }
        index_of_merged_array++;
    }

    while (index_of_sub_array_ne < sub_array_one) {
        array[index_of_merged_array] = left_array[index_of_sub_array_ne];
        index_of_sub_array_ne++;
        index_of_merged_array++;
    }

    while (index_of_sub_array_two < sub_array_two) {
        array[index_of_merged_array] = right_array[index_of_sub_array_two];
        index_of_sub_array_two++;
        index_of_merged_array++;
    }

    delete[] left_array;
    delete[] right_array;
}

void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main()
{
    const int SIZE = 100;
    int arr[SIZE];

    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 1000000;
    }

    cout << "Sebelum sorting:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0)
        {
            cout << "\n";
        }
    }

    mergeSort(arr, 0, SIZE - 1);

    cout << "\n\nSetelah sorting:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0)
        {
            cout << "\n";
        }
    }

    return 0;
}