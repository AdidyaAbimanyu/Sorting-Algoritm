#include <iostream>
#include <cstdlib> // Untuk menggunakan fungsi rand()
#include <ctime>   // Untuk menggunakan fungsi time()

using namespace std;

int main()
{
  const int SIZE = 100000;
  int arr[SIZE];

  // Mengisi array dengan angka acak antara 0 dan 999999
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

  // Sorting array menggunakan algoritma Bubble Sort
  for (int i = 0; i < SIZE - 1; i++)
  {
    for (int j = 0; j < SIZE - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  cout << "\n\nSetelah diurutkan:\n";
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