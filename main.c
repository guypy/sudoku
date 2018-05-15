#include <stdio.h>
#include <stdlib.h>

int main() {

    int i;
    int N = 3;
    int M = 3;
    printf("----------------------------------\n");
    for (i = 0; i < 81; ++i){
        int v = rand() % 9;

        if (i % (N*M*M) == 0 && i != 0)
            printf("|\n----------------------------------\n| ");
        else if (i % (N*M) == 0 && i != 0)
            printf("|\n| ");
        else if (i % N == 0) {
            printf("| ");
        }
        if (v) {
            printf("%d. ", v);
        } else {
            printf("   ");
        }
    }
    printf("|\n----------------------------------\n");


    return 0;
}