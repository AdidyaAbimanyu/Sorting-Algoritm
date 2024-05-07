#include <iostream>
#include <cstdlib> // Untuk menggunakan fungsi rand()
#include <ctime>   // Untuk menggunakan fungsi time()

using namespace std;

int main()
{
  const int SIZE = 100;
  int arr[SIZE], temp;

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

  // Insertion Sort
  for (int i = 1; i < SIZE; i++)
  {
    temp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = temp;
  }

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