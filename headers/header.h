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


Node *createNode(int key, Node *outside);
void moveDad(Node *u, Node *v, Node **root, Node *outside);
Node *external();
void leftRotate(Node *new, Node **root, Node *outside);
void rightRotate(Node *new, Node **root, Node *outside);
void rotaRN(Node *new, Node **root, Node *outside);
Node* searchNodede(Node* aux, int key, Node *outside);
Node* successor(Node *z, Node* outside);
void routeRemoveRB(Node *x, Node **root, Node *outside);
void removeRB(Node* trash, Node **root, Node *outside);
void insertRB(int new_key, Node **root, Node *outside);
void countNodes(Node *root, int *sum, Node *outside);
void tests(Node **root, int *vec, int *sum, Node *outside);
void freeRB(Node **root, Node *outside);
void paInVec(int *vec, int seed);


#endif