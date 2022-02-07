#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/header.h"

Node *outside = external();

Node *createNode(int key){
    Node *new = (Node*) malloc(sizeof(Node));

    new->key = key;
    new->color = 'N';
    new->left = NULL;
    new->rigth = NULL;
    new->father = NULL;
    
    return new;
}

void moveDad(Node *u, Node *v, Node **ptroot) {
    if(u->dad == outside)
        (*ptroot) = v
    else {
        if(u == u->dad->left) {
            u->dad->left = v
        }
        else {
            u->dad->right = v
        }
    }
    v->dad = u->dad
}


Node *external(){
    Node *outside = (Node*) malloc(sizeof(Node));
    outside->key = 0;
    outside->color = 'N';
    outside->left = NULL;
    outside->rigth = NULL;
    outside->dad = NULL;

    return outside;
}


void leftRotate(Node *new, Node **root) {
    Node *y = new->right;
    new->right = y->left;

    if (new->right != outside)
        new->right->dad = y;
    y->dad = new->dad;

    if (new->dad == outside)
        (*root) = y;
    else if (new == new->dad->left)
        new->dad->left = y;
    else
        new->dad->right = y;
        
    y->left = new;
    new->dad = y;
}

void rightRotate(Node *new, Node **root) {
    Node *y = new->left;
    new->left = y->right;

    if (new->left != outside)
        new->left->dad = new;

    y->dad = new->dad;

    if (new->dad == outside)
        (*root) = y;
    else if (new == new->dad->left)
        new->dad->left = y;
    else
        new->dad->right = y;

    y->right = new;
    new->dad = y;
}


void rotaRN(Node *new, Node **root) {
    Node *y = NULL;
    while(new->dad->color = "R") {
        if(new->dad = new->dad->dad->left) {
            y = new->dad->dad->right;
            if(y->color = "R") {
                new->dad->color = y->color = "N";
                new->dad->dad->color = "R";
                new = new->dad->dad;
            }
            else {
                if(new == new->dad->right) {
                    new = new->dad;
                    leftRotate(new, root);
                }
                new->dad->color = "N";
                new->dad->dad->color = "R";
                rotateR(new->dad->dad, root)
            }
        } 
        else {
             y = new->dad->dad->right;
            if(y->color = "R") {
                new->dad->color = y->color = "N";
                new->dad->dad->color = "R";
                new = new->dad->dad;
            }
            else {
                if(new == new->dad->right) {
                    new = new->dad;
                    rotateL(new, root);
                }
                new->dad->color = "N";
                new->dad->dad->color = "R";
                rotateR(new->dad->dad, root)
            }
        }      
    }
    (*root)->color = "N";
}

void insertRB(Node *new, Node **root) {
    Node *pt = root, *y = outside;
    
    while(pt != outside) {
        y = pt;
        if(new->key = pt->key) {
            printf("Existing key!\n");
            y = NULL;
            pt = outside;
        }
        else {
            if(new->key < pt->key) 
                pt = pt->left;
            else
                pt = pt->right;
        }
    }
    if(y != NULL) {
        new->dad = y;
        if(y = outside) {
            (*root) = z
        }
        else {
            if(new->key < y->key)
                y->left = z;
            else {
                y->right = z;
            }
        }
        new->left = new->right = outside;
        new->color = "R"
        routeRN(new, root);
    }

}




void removeRB(int x, Node **pt, int *h) {
    
}


int height(Node *pt) {
    int hl, hr, diff;
    if(pt == NULL) {
        return 0;
    }
    else {
        hl = height(pt->left);
        hr = height(pt->right);
        if (hl > hr) return hl+1;
        else return hr+1;
    }
}


void countNodes(Node *pt, int *sum) {
    if(pt->left != NULL)
        countNodes(pt->left, sum);
    if(pt->right != NULL)   
        countNodes(pt->right, sum);
    *sum += 1;
}

void outputAVL(Node *pt) {
    printf("%d (%d);\n", pt->key, pt->bal);
    if(pt->left != NULL)
        outputAVL(pt->left);
    //printf("%d (%d);\n", pt->key, pt->bal);
    if(pt->right != NULL)   
        outputAVL(pt->right);
    /* printf("%d (%d);\n", pt->key, pt->bal); */
}

void freeAVL(Node **pt) {
    if((*pt)->left != NULL)
        freeAVL(&(*pt)->left);
    if((*pt)->right != NULL)
        freeAVL(&(*pt)->right);

    free(*pt);
}

void paInVec(int *vec, int seed) {
    int i, j;
    for(i = 0, j = 0; i < _10K; i++, j+=seed) {
        vec[i] = j;
    }
}

void tests(Node **pt, int *vec, int *sum, int *h) {
    int i;

    countNodes(*pt, sum);
    printf("\tNumber of Nodes: %d\n",*sum);
    if(checkAVL(*pt)) puts("\tIt's AVL!");
    else puts("\tIt's not AVL!");

    puts("\t1000 nodes removed.");
    for(i = 0; i < K; i++) {
        removeAVL(vec[i], &(*pt), h);
    }
    *sum = 0;
    countNodes(*pt, sum);
    printf("\tNumber of Nodes: %d\n",*sum);
    if(checkAVL(*pt)) printf("\tIt's AVL!\n");
    else printf("\tIt's not AVL!");
}
