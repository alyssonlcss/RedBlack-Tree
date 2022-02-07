#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/header.h"



Node *createNode(int key){
    Node *new = (Node*) malloc(sizeof(Node));

    new->key = key;
    new->color = 'N';
    new->left = NULL;
    new->rigth = NULL;
    new->father = NULL;
    
    return new;
}


void insertRB(Node *new, Node **root) {
    Node *pt = root, *y = external;
    
    while(pt != external) {
        y = pt;
        if(new->key = pt->key) {
            printf("Existing key!\n");
            y = NULL;
            pt = external;
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
        if(y = external) {
            (*root) = z
        }
        else {
            if(new->key < y->key)
                y->left = z;
            else {
                y->right = z;
            }
        }
        new->left = new->right = external;
        new->color = "R"
        routeRN(new, root);
    }

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
                    rotateL(new, root);
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


void MoveDad(Node *u, Node *v, Node **ptroot) {
    if(u->dad == external)
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
    Node *external = (Node*) malloc(sizeof(Node));
    external->key = 0;
    external->color = 'N';
    external->left = NULL;
    external->rigth = NULL;
    external->dad = NULL;

    return external;
}


 void swap(Node **pt, Node **dadS) {
    Node *temp;

    temp = (*pt);
    (*pt) = (*dadS);
    (*dadS) = temp;

    temp->bal = (*pt)->bal;
    temp->key = (*pt)->key;
    temp->left = (*pt)->left;
    temp->right = (*pt)->right;

    //swap
    (*pt)->bal = (*dadS)->bal;
    (*pt)->key = (*dadS)->key;
    (*pt)->left = (*dadS)->left;
    (*pt)->right = (*dadS)->right;

    (*dadS)->bal = temp->bal;
    (*dadS)->key = temp->key;
    (*dadS)->left = temp->left;
    (*dadS)->right = temp->right;

}


void removeAVL(int x, Node **pt, int *h) {
    if((*pt) == NULL){
        puts("element does not exist!");
        *h = 0;
    }
    else {
        if(x < (*pt)->key) {
            removeAVL(x, &(*pt)->left, h);
            balance(pt, 'L', h);
        }
        else {
            if(x > (*pt)->key) {
                removeAVL(x, &(*pt)->right, h);
                balance(pt, 'R', h);
            }
            else {
                Node *aux = (*pt);
                
                if((*pt)->left == NULL) {
                    (*pt) = (*pt)->right;
                    *h = 1;
                }
                else {
                    if((*pt)->right == NULL) {
                        (*pt) = (*pt)->left;
                        *h = 1;
                    }
                    else {
                        Node *s = (*pt)->right;

                        if(s->left == NULL) {
                            s->left = (*pt)->left;
                            s->bal = (*pt)->bal;
                            (*pt) = s;
                            *h = 1;
                        }
                        else {
                            Node *dadS;
                            while(s->left != NULL) {
                                dadS = s;
                                s = s->left;
                            }
                            swap(pt, &dadS->left);
                            removeAVL(x, &(*pt)->right, h);
                        }
                        balance(pt, 'R', h);
                    }
                    free(aux);
                }
            }
        }
    }
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
