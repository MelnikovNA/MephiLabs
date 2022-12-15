#include<stdio.h>
#include<stdlib.h>
#include"lab3.h"

int input() {
    int num;
    while (scanf("%d", &num) != 1) {
        printf("Incorrect input, input correct: ");
        scanf("%*[^\n]");
    }
    return num;
}

void my_exit(int *numarg, int *denom, int *new_num, int *new_denom) {
    if (numarg != NULL) {
        free(numarg);
    }
    if (denom != NULL) {
        free(denom);
    }
    if (new_num != NULL) {
        free(new_num);
    }
    if (new_denom != NULL) {
        free(new_denom);
    }
    exit(0);
}

void min_max_func(int **A,int **B,int **newA, int **newB, int *len, int *new_len)
{
    if (*len == 0) {
        printf("empty array\n");
        return;
    }
    int minA=(*A)[0], minB = (*B)[0];
    int maxA=(*A)[0], maxB = (*B)[0];
    int tmpA1, tmpA2, indexMin = 0, indexMax = 0, start, end;
    if (newA!=NULL){
        free(*newA);
        (*newA) = NULL;
    }
    if(newB != NULL){
        free(*newB);
        (*newB) = NULL;
    }
    for(int i = 0; i<=*len-2;++i)
    {
        tmpA1=module((*A)[i+1])* module(maxB);
        tmpA2=module(maxA)* module((*B)[i+1]);
        if(tmpA1>tmpA2)
        {
            maxA = module((*A)[i+1]);
            maxB = module((*B)[i+1]);
            indexMax = i+1;
        }
        tmpA1=module((*A)[i+1])* module(minB);
        tmpA2=module(minA) * module((*B)[i+1]);
        if(tmpA1<tmpA2)
        {
            minA = module((*A)[i+1]);
            minB = module((*B)[i+1]);
            indexMin = i+1;
        }
    }

    printf("max - %d / %d %d\n", maxA, maxB,indexMax);
    printf("min - %d / %d %d\n", minA, minB, indexMin);

    if(indexMax>indexMin)
    {
        start = indexMin;
        end = indexMax;
    }
    else
    {
        start = indexMax;
        end = indexMin;
    }
    *new_len = end-start-1;
    *newA = (int *) malloc((*new_len)* sizeof(int));
    *newB = (int *) malloc((*new_len)* sizeof(int));
    int num = 0, tmp_Start = start+1, tmp_End = end;
    while (tmp_Start<tmp_End)
    {
        (*newA)[num]=(*A)[tmp_Start];
        (*newB)[num]=(*B)[tmp_Start];
        tmp_Start+=1;
        num+=1;
    }
    for(int i =start+1; i<end;++i)
    {
        remove_element(start+1,len, A, B);
    }
}

int module(int num)
{
    if(num<0){
        return num*(-1);
    }
    else{
        return num;
    }
}
