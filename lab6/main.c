#include <stdio.h>
#include <stdlib.h>

int main() {
    int c;
    while((c = getchar()) != EOF){
        printf("%d %d\n",c,errno);
        printf("%c\n",c, c);
    }
    return 0;
}
