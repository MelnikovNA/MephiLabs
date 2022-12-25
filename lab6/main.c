#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>

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

int word_len_ll( ll *head, ll **end){
    if (head==NULL){
        return EOF;
    }
    int len=0;
    while (head->ch!=EOF&&head->ch!=' '){
        len++;
        head=head->next;
    }
    *end=head;
    return len;
}

// return address of next space or EOF
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

int main(int argc, char **argv) {
    int c;
    ll *head,*current;
    head= new_ll(EOF);
    current=head;

    int shifts=6;
    char *end;

    while ((c = getopt(argc, argv, "s:")) != -1)
        switch (c) {
            case 's':
                shifts=strtol(optarg, &end, 10);
                if (errno!=0 || shifts <= 0){
                    fprintf(stderr, "wrong shifts count\n" );
                    return EXIT_FAILURE;
                }
                break;
            case 'h':
                printf("Arguments:\n"
                       "-s shifts count (%d by default)\n"
                        ,shifts
                );
                return EXIT_SUCCESS;
        }

    while((c = getchar()) != EOF ){
        if (c==10){
            fprintf(stdout,"orig:");
            print_chain(head);
            head = max_trim(head);
            fprintf(stdout,"trim:");
            print_chain(head);
            head=cyclic_shift_right_ll(head,shifts);
            fprintf(stdout,"rshf:");
            print_chain(head);
            empty_ll(head);
            current=head;
            continue;
        }
        current->ch=c;
        current->next=new_ll(EOF);
        current=current->next;
    }
    empty_ll(head);
    free(head);
    return 0;
}