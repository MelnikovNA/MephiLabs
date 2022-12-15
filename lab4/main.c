#include <stdio.h>
#include <malloc.h>
#include "lib4.h"

int main(void){
    char *input = my_readline("Enter String: "); 
    while (input != NULL){
    	input = max_trim(input);
        printf("\"%s\"\n", input);
        char *output = per_task(input);
        printf("\"%s\"\n", output);
        free(input);
        free(output);
        input = my_readline("Enter String: ");   
    }
    return 0;
}
