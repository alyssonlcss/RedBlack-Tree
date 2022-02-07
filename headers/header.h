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

Node *createNode(int key);
void moveDad(Node *u, Node *v, Node **ptroot);
void leftRotate(Node **pt, int *h);
void rightRotate(Node **pt, int *h);
void insertRB(int inKey, Node **pt, int *h);
void removeRB(int x, Node **pt, int *h);
int height(Node *pt);
int checkRB(Node *pt);
void countNodes(Node *pt, int *sum);
void outputAVL(Node *pt);
void freeAVL(Node **pt);
void paInVec(int *vec, int seed);
void tests(Node **pt, int *vec, int *sum, int *h);

#endif