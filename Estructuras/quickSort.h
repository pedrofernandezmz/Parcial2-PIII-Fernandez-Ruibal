#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_QUICKSORT_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_QUICKSORT_H
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
//void quickSort(int *arr, int inicio, int fin)
void quickSort(vector<string> arr[], int inicio, int fin)
{
  int i, j, medio;
  //int pivot, aux;
  vector<string> pivot, aux;

  medio = (inicio + fin) / 2;
  pivot = arr[medio];
  i = inicio;
  j = fin;

  do
  {
    while (stoi(arr[i][1]) > stoi(pivot[1]))
      i++;
    while (stoi(arr[j][1]) < stoi(pivot[1]))
      j--;

    if (i <= j)
    {
      aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
      i++;
      j--;
    }
  } while (i <= j);

  if (j > inicio)
    quickSort(arr, inicio, j);
  if (i < fin)
    quickSort(arr, i, fin);
}

#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_QUICKSORT_H