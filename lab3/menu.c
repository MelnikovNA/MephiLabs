#include<stdio.h>
#include "lab3.h"

int menu() {
    int ret;
    do {
        printf("0 - exit\n1 - array initialization\n2 - input\n3 - remove\n4 - personal_task\n5 - printf array\n6 - task array printf\nInput - ");
        ret = input();
        if (ret >= 0 && ret <= 6) {
            return ret;
        }
        if (ret==99){
            return ret;
        }
        printf("illegal input\n");
    } while (1);
}
