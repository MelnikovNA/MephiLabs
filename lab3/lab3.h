#ifndef __LAB3__
#define __LAV3__

int module(int num);
void min_max_func(int **A,int **B,int **newA, int **newB, int *len, int *new_lenght);
int init_arrays(int **numarg, int **denomarg);
int input();
void insert_element(int index, int *lenght, int **numarg, int **denomarg, int num_value, int denom_value);
void remove_element(int index, int *lenght, int **numarg, int **denomarg);
void my_exit(int *numarg, int *denom, int *new_num, int *new_denom);
void enter_element(int *num, int *denom);
void array_printf(const int *data, int len);
int menu();

#endif
