//
// Created by Stif on 17.12.2022.
//
#include "detail.h"

void shakersort(void *arr, int count, size_t elem_size, comp_func cmp) //(double *mass, int count)
{
    int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
    int flag = 1;  // флаг наличия перемещений
    // Выполнение цикла пока левая граница не сомкнётся с правой
    // и пока в массиве имеются перемещения
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i<right; i++)  //двигаемся слева направо
        {
            if (cmp(elem(arr,elem_size,i),elem(arr,elem_size,i + 1))>0) // если следующий элемент меньше текущего,
            {             // меняем их местами
                swap(elem(arr,elem_size,i), elem(arr,elem_size,i+1),elem_size);
                flag = 1;      // перемещения в этом цикле были
            }
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i>left; i--)  //двигаемся справа налево
        {
            if (cmp(elem(arr,elem_size,i-1),elem(arr,elem_size,i))>0) // если предыдущий элемент больше текущего,
            {            // меняем их местами
                swap(elem(arr,elem_size,i), elem(arr,elem_size,i-1),elem_size);
                flag = 1;    // перемещения в этом цикле были
            }
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
}