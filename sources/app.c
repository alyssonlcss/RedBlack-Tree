#include <stdlib.h>
#include <stdio.h>
#include "../headers/header.h"
#include <time.h>


int main(void) {
    int i;

    Node *outside = external();
    srand(time(NULL));
    for (i = 0; i < K; i++) {
        Node *root = outside;
        int *vec = (int*)malloc(sizeof(int)*_10K);
        paInVec(vec, (rand() % 100)+1);
        printf("%d - Red-Black Tree\n", i+1);
        tests(&root, vec, outside);
        freeRB(&root, outside);
        free(vec);
    }

    return 0;
}