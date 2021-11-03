#ifndef PARCIAL2_PIII_FERNANDEZ_RUIBAL_BUBBLESORT_H
#define PARCIAL2_PIII_FERNANDEZ_RUIBAL_BUBBLESORT_H
#include <iostream>

void bubbleSort1(int *arr, int size)
{
  int aux;
  bool seguir = true;

  for (int i = 0; i < size - 1 && seguir; i++)
  {
    seguir = false;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        seguir = true;
        aux = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = aux;
      }
    }
  }
}

void bubbleSort(int *arr, int size, string persona)
{
  persona tempo;
    for (int i = 0;i < size; i++){
        for (int j = 0; j< size-1; j++){
            if (e[j].nomprov > e[j+1].nomprov){
                tempo = e[j]; 
                e[j] = e[j+1]; 
                e[j+1] = tempo;
            }
        }
    }
}
#endif //PARCIAL2_PIII_FERNANDEZ_RUIBAL_BUBBLESORT_H