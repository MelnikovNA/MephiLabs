//
// Created by Stif on 26.12.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include "lab6.h"

ll *cyclic_shift_word_right(ll **whead, int n) {
    // n++;

    ll *end;
    int wlen=word_len_ll(*whead, &end);
    if (wlen==EOF || wlen==0){
        return NULL;
    }

    int actual_shift=n%wlen;

    if (actual_shift==0){
        if (end->ch==EOF)
            return NULL;
        return end;
    }

    actual_shift++;

    ll *first=*whead;
    ll *tail,*tmp,*mid;
    ll *cur=first;

    for (int i=0;i<wlen;i++){
        if (i==wlen-actual_shift){
            mid=cur;
        }
        tmp=cur;
        cur=cur->next;
    }
    *whead=mid->next;
    tmp->next=first;
    mid->next=cur;

    if (cur->ch==EOF)
        return NULL;
    return cur;
}

// returns new head
ll *cyclic_shift_right_ll(ll *phead, int n){
    ll *next=cyclic_shift_word_right(&phead,n);
    while (next!=NULL){
        next=cyclic_shift_word_right(&next->next,n);
    }
    return phead;
}