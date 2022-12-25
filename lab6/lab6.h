#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>

#ifndef LAB6_LAB6_H
#define LAB6_LAB6_H

typedef struct ll_struct ll;
struct ll_struct{
    int ch;
    ll *next;
};

void empty_ll (ll *head);
void print_chain(ll *current);

int word_len_ll( ll *head, ll **end);

ll *cyclic_shift_word_right(ll **whead, int n);
ll *cyclic_shift_right_ll(ll *phead, int n);
ll *max_trim(ll *head);
ll *new_ll(int ch);

#endif //LAB6_LAB6_H