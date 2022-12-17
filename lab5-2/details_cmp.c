//
// Created by Stif on 16.12.2022.
//
#include "detail.h"
#include <string.h>
#include <stdio.h>

int cmp_func_name_asc(const void *a, const void *b) {
    detail *d1 = (detail *) a;
    detail *d2 = (detail *) b;

    return strcmp(d1->name, d2->name);
}

int cmp_func_name_desc(const void *a, const void *b) {
    detail *d1 = (detail *) a;
    detail *d2 = (detail *) b;

    return -strcmp(d1->name, d2->name);
}

int cmp_func_id_asc(const void *a, const void *b) {
    detail *d1 = (detail *) a;
    detail *d2 = (detail *) b;

    return strcmp(d1->id, d2->id);
}

int cmp_func_id_desc(const void *a, const void *b) {
    detail *d1 = (detail *) a;
    detail *d2 = (detail *) b;

    return -strcmp(d1->id, d2->id);
}

int cmp_func_count_asc(const void *a, const void *b) {
    detail *d1 = (detail *) a;
    detail *d2 = (detail *) b;

    return d1->count - d2->count;
}

int cmp_func_count_desc(const void *a, const void *b) {
    detail *d1 = (detail *) a;
    detail *d2 = (detail *) b;

    return (d2->count - d1->count);
}

comp_func get_comp_func(int comparison, int sort_desc) {
    switch (comparison) {
        case SORT_NAME:
            if (!sort_desc)
                return cmp_func_name_asc;
            return cmp_func_name_desc;
        case SORT_ID:
            if (!sort_desc)
            return cmp_func_id_asc;
            return cmp_func_id_desc;
        case SORT_COUNT:
            if (!sort_desc)
            return cmp_func_count_asc;
            return cmp_func_count_desc;
    }
    fprintf(stderr,"illegal comparison number %d\n",comparison);
    return NULL;
}

