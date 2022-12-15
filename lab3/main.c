#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

int main() {
    int *num = NULL, *denom = NULL, *new_num = NULL, *new_denom = NULL;
    int lenght = 0, new_lenght = 0, new_len, denom_value, num_value, index;
    while (1) {
        printf("current array len %d\n", lenght);
        int menu_choice = menu();
        switch (menu_choice) {
            case 0:
                // exit
                my_exit(num, denom, new_num, new_denom);
                break;

            case 1:
                //init array
                new_len = init_arrays(&num, &denom);
                if (new_len > 0) {
                    lenght = new_len;
                }
                break;

            case 2:
                printf("Input index: ");
                index = input();
                printf("Input numerator: ");
                num_value = input();
                printf("Input denominator: ");
                denom_value = input();
                insert_element(index, &lenght, &num, &denom, num_value, denom_value);
                break;

            case 3:
                //remove
                printf("Input index: ");
                index = input();
                remove_element(index, &lenght, &num, &denom);
                break;

            case 4:
                //personal task
                min_max_func(&num, &denom, &new_num, & new_denom, &lenght, &new_lenght);
                array_printf(new_num, new_lenght);
                for (int i = 0; i < new_lenght; ++i) {
                    printf("--\t");
                }
                printf("\n");
                array_printf(new_denom, new_lenght);
                break;

            case 5:
                //printf array
                array_printf(num, lenght);
                for (int i = 0; i < lenght; ++i) {
                    printf("--\t");
                }
                printf("\n");
                array_printf(denom, lenght);
                printf("\n");
                break;
            case 6:
                if(new_lenght!=0){
                    array_printf(new_num, new_lenght);
                    for (int i = 0; i < new_lenght; ++i) {
                        printf("--\t");
                    }
                    printf("\n");
                    array_printf(new_denom, new_lenght);
                    printf("\n");
                }
                else{
                    printf("Array empty");
                }
                break;
            case 99:
                lenght=10;
                num = (int *) malloc(lenght * sizeof(int));
                denom = (int *) calloc(lenght, sizeof(int));
                for(int i=0;i<lenght;i++){
                    num[i]=i+1;
                    denom[i]=i+10;
                }
                break;
            default:
                return 0;
        }
    }
}
