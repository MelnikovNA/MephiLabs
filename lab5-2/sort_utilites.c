//
// Created by Stif on 17.12.2022.
//
#include <stdlib.h>

void swap(void *a, void *b,size_t len) {
    char *ca=a;
    char *cb=b;
    char c;
    while(len--){
        c=*ca;
        *ca++=*cb;
        *cb++=c;
    }
}

void *elem(void *p, size_t size,int index){
    return p+(size *index);
}

