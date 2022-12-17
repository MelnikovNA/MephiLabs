//
// Created by Stif on 16.12.2022.
//

#ifndef UNTITLED1_DETAIL_H
#define UNTITLED1_DETAIL_H
#include <stdio.h>
enum ret_values{
    RET_OK,
    RET_EOF,
    RET_ERROR
};

enum sort_by {
    SORT_NONE,
    SORT_NAME,
    SORT_ID,
    SORT_COUNT
};

enum sort_algorythm {
    ALG_QUICKSORT,
    ALG_HEAPSORT,
    ALG_SHAKESORT
};

struct detail_struct {
    char *id;
    char *name;
    int count;
};
typedef struct detail_struct detail;


typedef int(*comp_func)(const void *, const void *);

comp_func get_comp_func(int comparison, int sort_desc);

void free_details(detail *d, int count);
detail* read_details_file(char *file_name, int *count);
void save_details_to_file(FILE* out_file, detail *details, int count);

void heapsort(void *arr, int n, size_t elem_size, comp_func cmp);
void shakersort(void *arr, int count, size_t elem_size, comp_func cmp);

void swap(void *a, void *b,size_t len);

void *elem(void *p, size_t size,int index);

#endif //UNTITLED1_DETAIL_H
