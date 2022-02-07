#include <stdlib.h>
#include <stdio.h>
#include "../headers/header.h"



int main(void) {
    int i, j;
    

    srand(time(NULL));
    for (i = 0; i < K; i++) {
        Node *root = NULL;
        int h, sum = 0, *vec = (int*)malloc(sizeof(int)*_10K);

        paInVec(vec, (rand() % 100)+1);
        for(j = 0; j < _10K; j++) {
            insertRN(createNode(vec[j]), &root)
        }
        /* printf("%d. AVL Tree\n", i+1);
        tests(&root, vec, &sum, &h); */
        freeAVL(&root);
        free(vec);
    }


    return 0;
}