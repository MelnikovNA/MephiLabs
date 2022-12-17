//
// Created by Stif on 17.12.2022.
//
#include "detail.h"

void heapify(void *arr, int n, size_t size, int i, comp_func cmp) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && cmp(elem(arr,size,left), elem(arr,size,largest))>0)
        largest = left;

    if (right < n && cmp(elem(arr,size,right), elem(arr,size,largest))>0)
        largest = right;

    if (largest != i) {
        swap(elem(arr,size,i), elem(arr,size,largest),size);
        heapify(arr, n, size, largest,cmp);
    }
}
// heap sort
void heapsort(void *arr, int n, size_t elem_size, comp_func cmp) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, elem_size,i,cmp);

    for (int i = n - 1; i >= 0; i--) {
        swap(elem(arr,elem_size,0), elem(arr,elem_size,i),elem_size);
        heapify(arr, i, elem_size, 0,cmp);
    }
}

