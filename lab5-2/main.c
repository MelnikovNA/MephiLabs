#include <stdio.h>
#include "detail.h"
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <time.h>
#include <errno.h>


int main(int argc, char **argv) {

    int c;
    int sort_on = SORT_NONE;
    int sort_direction = 0;
    int sort_alg = ALG_QUICKSORT;

    int set_size=0;
    int sets_count=0;

    char *end;

    while ((c = getopt(argc, argv, "c:s:dINChSHQ")) != -1)
        switch (c) {
            case 's':
                sets_count=strtol(optarg, &end, 10);
                if (errno!=0 || sets_count <= 0){
                    fprintf(stderr, "wrong sets_count set_size\n" );
                }
                break;
            case 'c':
                set_size=strtol(optarg, &end, 10);
                if (errno!=0 || set_size <= 0){
                    fprintf(stderr, "wrong sets_count set_size\n" );
                }
                break;
            case 'd':
                sort_direction = 1;
                break;
            case 'I':
                sort_on = SORT_ID;
                break;
            case 'N':
                sort_on = SORT_NAME;
                break;
            case 'C':
                sort_on = SORT_COUNT;
                break;
            case 'S':
                sort_alg = ALG_SHAKESORT;
                break;
            case 'H':
                sort_alg = ALG_HEAPSORT;
                break;
            case 'Q':
                sort_alg = ALG_QUICKSORT;
                break;

            case 'h':
                printf("Arguments:\n"
                       "-s sets_count\n"
                       "-c set_size\n"
                       "-d sort descent (ascent by default)\n"
                       "-I sort by ID\n"
                       "-N sort by NAME\n"
                       "-C sort by COUNT\n"
                       "-H HEAP sort alg\n"
                       "-S SHAKER sort alg\n"
                       "-Q QUICK sort alg (default sort)\n"
                );
                return EXIT_SUCCESS;
            default:
                fprintf(stderr, "wrong arg %c\n", c);
                return EXIT_FAILURE;
        }

    if (sort_on == SORT_NONE) {
        fprintf(stderr, "sort on must be selected\n");
        return EXIT_FAILURE;
    }

    if (sets_count <1) {
        fprintf(stderr, "sets count must be >=1\n");
        return EXIT_FAILURE;
    }

    if (set_size <1) {
        fprintf(stderr, "set size must be >=1\n");
        return EXIT_FAILURE;
    }


    comp_func comparator = get_comp_func(sort_on, sort_direction);
    if (comparator == NULL) {
        return EXIT_FAILURE;
    }

    printf("set_size:%i\n", set_size);

    detail **details_set=malloc(sizeof(detail *)*sets_count);

    for(int i=0;i<sets_count;i++){
        details_set[i] = make_details_set(set_size);
    }
    clock_t start=clock();
    for(int i=0;i<sets_count;i++) {
        detail *d = details_set[i];
        switch (sort_alg) {
            case ALG_QUICKSORT:
                qsort(d, set_size, sizeof(detail), comparator);
                break;
            case ALG_HEAPSORT:
                heapsort(d, set_size, sizeof(detail), comparator);
                break;
            case ALG_SHAKESORT:
                shakersort(d, set_size, sizeof(detail), comparator);
                break;
        }
    }
    printf("time for %d sets is %f sec\n",sets_count,(double)(clock()-start)/CLOCKS_PER_SEC);

    for(int i=0;i<sets_count;i++) {
        free_details(details_set[i], set_size);
    }
    free(details_set);
    return EXIT_SUCCESS;
}
