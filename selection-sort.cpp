#include <iostream>
#include <cstdlib> // Untuk menggunakan fungsi rand()
#include <ctime>   // Untuk menggunakan fungsi time()

using namespace std;

int main()
{
  const int SIZE = 1000000;
  int arr[SIZE], temp;
  int i, j, index;

  // Mengisi array dengan angka acak antara 0 dan 999999
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

  // Selection Sort
  for (i = 0; i < SIZE - 1; i++)
  {
    index = i;
    for (j = i + 1; j < SIZE; j++)
    {
      if (arr[j] < arr[index])
      {
        index = j;
      }
    }
    if (index != i)
    {
      temp = arr[i];
      arr[i] = arr[index];
      arr[index] = temp;
    }
  }

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