//
// Created by Stif on 16.12.2022.
//

#include <malloc.h>
#include <stdio.h>
#include "detail.h"
#include <string.h>
#include <errno.h>

// return EOF on error
int scanf_detail(FILE *file, detail *d) {
    int count;
    char id[15];
    char name[100];

    int ret = fscanf(file, "%14s%99s%d", id, name, &count);

    if (ret == EOF) {
        if (feof(file)) {
            return RET_EOF;
        }
        fprintf(stderr, "could not read file:(%i) %s\n", errno, strerror(errno));
        return RET_ERROR;
    }

    if (ret != 3) {
        fprintf(stderr, "syntax error in input file\n");
        return RET_ERROR;
    }

    if (strlen(id) != 8) {
        fprintf(stderr, "syntax error in input file: invalid id length\n");
        return RET_ERROR;
    }

    if (count < 1) {
        fprintf(stderr, "syntax error in input file: invalid count type\n");
        return RET_ERROR;
    }

    d->count = count;
    d->name = strdup(name);
    d->id = strdup(id);

    return RET_OK;
}

detail *read_details_file(char *file_name, int *count) {
    int details_allocated = 0;
    int alloc_step = 10;
    int details_readed = 0;
    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        fprintf(stderr, "could not read file %s:(%i) %s\n",
                file_name, errno, strerror(errno));
        return NULL;
    }
    detail *details = NULL;
    while (!feof(f)) {
        if (details_allocated < details_readed + 1) {
            details_allocated += alloc_step;
            details = realloc(details, sizeof(detail) * details_allocated);
        }
        int ret = scanf_detail(f, &details[details_readed]);
        switch (ret) {
            case RET_ERROR:
                free_details(details, details_readed);
                return NULL;
            case RET_EOF:
                continue;
            case RET_OK:
                details_readed++;
                break;
        }
    }
    *count = details_readed;
    fclose(f);
    return details;
}

void free_details(detail *d, int count) {
    for (int i = 0; i < count; i++) {
        free(d[i].id);
        free(d[i].name);
    }
    free(d);
}

void save_details_to_file(FILE* out_file, detail *details, int count){
    while(count--){
        fprintf(out_file,"%s\t%s\t%d\n",details->id,details->name,details->count);
        details++;
    }
}

