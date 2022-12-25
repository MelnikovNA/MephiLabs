//
// Created by Stif on 26.12.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include "lab6.h"

void empty_ll (ll *head){
    if (head->ch==EOF){
        return;
    }
    // save head
   ll *cur2 = head->next;
   ll *cur;
    // free all other
   while(1){
        cur=cur2;
        cur2 = cur2->next;
        free(cur);
        if (cur2->ch == EOF)
            break;
   }

   free(cur2);

   head->ch=EOF;
   head->next=NULL;
 }

ll *max_trim(ll *head){
    ll *cur=NULL;
    int f = 0;
    while((head->ch == ' ' || head->ch == '\t') && head->ch!= EOF ){
        cur = head->next;
        free(head);
        head=cur;
    }

    ll *cur2 = NULL;
    ll *parent = NULL;
    cur2 = head;
    while(cur2->ch != EOF){
        if(cur2->ch == ' ' || cur2->ch == '\t'){
            f = 1;
            if(parent == NULL){
                fprintf(stderr, "Parent is NULL\n");
                return NULL;
            }
            parent->next = cur2->next;
            free(cur2);
            cur2 = parent->next;
            continue;

        }
        if (f==1){
            parent->next=new_ll(' ');
            parent=parent->next;
            parent->next=cur2;
        }

        f = 0;
        parent = cur2;
        cur2 = cur2->next;
    }
    return head;
}

void print_chain(ll *current){
    if (current==NULL){
        printf("NULL");
        return ;
    }
    while(current->ch!=EOF){
        putchar(current->ch);
        current=current->next;
    }
    fprintf(stdout,"\n");
    fflush(stdout);
}