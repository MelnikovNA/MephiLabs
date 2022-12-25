#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include "lab6.h"

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
	