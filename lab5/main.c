#include <stdio.h>
#include "detail.h"
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>


int main(int argc, char **argv) {
    int count;
    char input_file_name[FILENAME_MAX];
    FILE *output_file = stdout;
    comp_func comparator;

    int c;
    int sort_on = SORT_NONE;
    int sort_direction = 0;
    int sort_alg = ALG_QUICKSORT;


    while ((c = getopt(argc, argv, "i:o:dINChSHQ")) != -1)
        switch (c) {
            case 'i':
                strcpy(input_file_name, optarg);
                break;
            case 'o':
                output_file = fopen(optarg, "w");
                if (output_file == NULL) {
                    fprintf(stderr, "could not open output file %s:(%i) %s\n",
                            optarg, errno, strerror(errno));
                    return EXIT_FAILURE;
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
                       "-i input file name\n"
                       "-o output file name\n"
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

    detail *d = read_details_file(input_file_name, &count);
    if (d == NULL) {
        return EXIT_FAILURE;
    }

    comparator = get_comp_func(sort_on, sort_direction);
    if (comparator == NULL) {
        return EXIT_FAILURE;
    }

    printf("count:%i\n", count);
    switch (sort_alg) {
        case ALG_QUICKSORT:
            qsort(d, count, sizeof(detail), comparator);
            break;
        case ALG_HEAPSORT:
            heapsort(d, count, sizeof(detail), comparator);
            break;
        case ALG_SHAKESORT:
            shakersort(d, count, sizeof(detail), comparator);
            break;
    }
    save_details_to_file(output_file, d, count);
    fclose(output_file);
    free_details(d, count);
    return EXIT_SUCCESS;
}
