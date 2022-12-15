#include<stdio.h>
#include<stdlib.h>
#include"lab3.h"

int init_arrays(int **numarg, int **denomarg) {
    printf("enter len:");
    int lenght;
    lenght = input();
    if (lenght < 0) {
        printf("error\n");
        return -1;
    }

    if (*numarg != NULL) {
        free(*numarg);
        *numarg = NULL;
    }

    if (*denomarg != NULL) {
        free(*denomarg);
        *numarg = NULL;
    }

    if (lenght == 0) {
        return lenght;
    }

    // распределить память
    *numarg = (int *) malloc(lenght * sizeof(int));
    *denomarg = (int *) calloc(lenght, sizeof(int));
    // ввести элементы

    for (int i = 0; i < lenght; i++) {
        printf("enter %i element: \n", i);
        enter_element(&((*numarg)[i]), &((*denomarg)[i]));
    }

    return lenght;
}

void enter_element(int *num, int *denom)
{
    printf("Input numerator: ");
    while (scanf("%d", num) != 1)
    {
        printf("Incorrect input, input correct");
        scanf("%*[^\n]");
    }
    printf("Input denominator: ");
    while (scanf("%d", denom) != 1)
    {
        printf("Incorrect input, input correct");
        scanf("%*[^\n]");
    }
}

void insert_element(int index, int *lenght, int **numarg, int **denomarg, int num_value, int denom_value) {
    if (*lenght == 0) {
        printf("empty array\n");
        return;
    }
    // .....*...... <- итог
    if (index > *lenght) {
        index = *lenght;
    }
    (*lenght)++;

    *numarg = realloc(*numarg, (*lenght) * sizeof(int));
    *denomarg = realloc(*denomarg, (*lenght)  * sizeof(int));
    // ...........X

    for (int i = (*lenght)-1; i > index; i--) {
        printf("%d", i);
        (*numarg)[i] = (*numarg)[i - 1];
        (*denomarg)[i] = (*denomarg)[i - 1];
    }

    printf("enter %d element: \n", index);

    (*numarg)[index] = num_value;
    (*denomarg)[index] = denom_value;

    return;
}

void remove_element(int index, int *lenght, int **numarg, int **denomarg) {
    if (index > *lenght || index < 0) {
        printf("out of bounds\n");
        return;
    }

    if (*lenght == 0) {
        printf("empty array\n");
        return;
    }

    if (*lenght == 1) {
        if (*numarg != NULL) {
            free(*numarg);
            *numarg = NULL;
        }

        if (*denomarg != NULL) {
            free(*denomarg);
            *denomarg = NULL;
        }
        (*lenght) = 0;
        return;
    }

    (*lenght)--;

    for (int i = index; i < *lenght; i++) {
        (*numarg)[i] = (*numarg)[i + 1];
        (*denomarg)[i] = (*denomarg)[i + 1];
    }

    *numarg = realloc(*numarg, (*lenght)  * sizeof(int));
    *denomarg = realloc(*denomarg, (*lenght) * sizeof(int));

    return;
}

void array_printf(const int *data, int lenght)
{
    printf("\n");
    for (int i = 0; i < lenght; ++i) {
        printf("%d\t", data[i]);
    }
    printf ("\n");
}
