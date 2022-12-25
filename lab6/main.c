#include <stdio.h>
#include <stdlib.h>

typedef struct ll_struct ll;
struct ll_struct{
    int ch;
    ll *next;
};

ll *new_ll(int ch){
    ll *ret=calloc(1,sizeof (ll));
    ret->ch=ch;
    return ret;
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

        f = 0;
        parent = cur2;
        cur2 = cur2->next;
    }
    return head;
}

int main() {
    int c;
    ll *head,*current;
    head= new_ll(EOF);
    current=head;
    while((c = getchar()) != EOF && c!=10){
//        printf("%d %d\n",c,errno);
        current->ch=c;
        current->next=new_ll(EOF);
        current=current->next;
    }
    head = max_trim(head);
    current=head;
    while(current->ch!=EOF){
        putchar(current->ch);
        current=current->next;
    }
    return 0;
}




