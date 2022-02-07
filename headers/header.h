#ifndef HEADER_H
#define HEADER_H

#define K 1000
#define _10K 10000
#define _100K 100000

struct node {
    int key;
    char color;
    struct node *dad;
    struct node *right;
    struct node *left;
};
typedef struct node Node;

void rotate1I(Node **pt, int *h);
void rotate2I(Node **pt, int *h);
void insertAVL(int inKey, Node **pt, int *h);
void rotate1R(Node **pt, int *h);
void rotate2R(Node **pt, int *h);
void swap(Node **a, Node **b);
void balance(Node **pt, char where, int *h);
void removeAVL(int x, Node **pt, int *h);
int height(Node *pt);
int checkAVL(Node *pt);
void countNodes(Node *pt, int *sum);
void outputAVL(Node *pt);
void freeAVL(Node **pt);
void paInVec(int *vec, int seed);
void tests(Node **pt, int *vec, int *sum, int *h);

#endif