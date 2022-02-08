#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/header.h"


Node *external(){
    Node *new = (Node*) malloc(sizeof(Node));
    new->key = 0;
    new->color = 'B';
    new->left = NULL;
    new->right = NULL;
    new->dad = NULL;

    return new;
}

Node *createNode(int key, Node* outside){
    Node *new = (Node*) malloc(sizeof(Node));
    new->key = key;
    new->color = 'B';
    new->left = outside;
    new->right = outside;
    new->dad = outside;

    return new;
}

void moveDad(Node *u, Node *v, Node **root, Node *outside){
    if(u->dad == outside){
        (*root) = v;
    }else{
        if(u == u->dad->left){
            u->dad->left = v;
        }else{
            u->dad->right = v;
        }
    }

    v->dad = u->dad;
}

Node* searchNode(Node* aux, int key, Node *outside) {
    if(aux == outside)
        return outside;

    if(key == aux->key)
        return aux;
    else if(key < aux->key) 
        searchNode(aux->left, key, outside);
    else if(key > aux->key)
        searchNode(aux->right, key, outside);
    else
        return outside;
}


Node* successor(Node *z, Node* outside) {
    Node* temp = z;
    while(temp->left != outside)
        temp = temp->left;

    return temp;
}

void leftRotate(Node *new, Node **root, Node *outside){
    Node *y = new->right;

    new->right = y->left;
    if (new->right != outside)
    {
        new->right->dad = new;
    }

    y->dad = new->dad;

    if (new->dad == outside)
        *root = y;
    else if (new == new->dad->left)
        new->dad->left = y;
    else
        new->dad->right = y;

    y->left = new;
    new->dad = y;
}

void rightRotate(Node *new, Node **root, Node *outside){
    Node *y = new->left;
    new->left = y->right;
    if (new->left != outside){
        new->left->dad = new;
    }

    y->dad = new->dad;

    if (new->dad == outside) 
        *root = y;
    else if (new == new->dad->left)
        new->dad->left = y;
    else
        new->dad->right = y;

    y->right = new;
    new->dad = y;
}

void routeRN(Node *new, Node **root, Node *outside){
    while (new->dad->color == 'R') {
        if (new->dad == new->dad->dad->left){
            Node *y = new->dad->dad->right;
            if (y->color == 'R'){
                new->dad->color = y->color = 'B';
                new->dad->dad->color = 'R';
                new = new->dad->dad;
            }
            else{
                if (new == new->dad->right){
                new = new->dad;
                leftRotate(new, root, outside);
                }
                new->dad->color = 'B';
                new->dad->dad->color = 'R';
                rightRotate(new->dad->dad, root, outside);
            }
        }
        else{
            Node *y = new->dad->dad->left;
            if (y->color == 'R'){
                new->dad->color = y->color = 'B';
                new->dad->dad->color = 'R';
                new = new->dad->dad;
            }
            else{
                if (new == new->dad->left){
                new = new->dad;
                rightRotate(new, root, outside);
                }
                new->dad->color = 'B';
                new->dad->dad->color = 'R';
                leftRotate(new->dad->dad, root, outside);
            }
        }
    }
    (*root)->color = 'B';
}

void insertRB(int new_key, Node **root, Node *outside){
    Node *new = NULL, *pt = (*root), *y = outside;
    
    while(pt != outside) {
		y = pt;
		if(new_key < pt->key)
			pt = pt->left;
		else
			pt = pt->right;
	}
    
    new = createNode(new_key, outside);

    if(y == outside)
		(*root) = new;
	else if(new_key < y->key)
		y->left = new;
	else
		y->right = new;
    
    routeRN(new, root, outside);
}

void routeRemoveRB(Node *x, Node **root, Node *outside) {
    Node *aux;
    while (x != *root && x->color != 'R') {
        if (x == x->dad->left) {
            aux = x->dad->right;
            if (aux->color == 'R') {
                x->dad->color = 'R'; aux->color = 'B';
                leftRotate(x->dad, root, outside);
                aux = x->dad->right;
            }
            if (aux->right->color == 'B' && aux->left->color == 'B') {
                aux->color = 'R';
                x = x->dad;
            }
            else {
                if (aux->left->color == 'R') {
                    aux->left->color = 'B'; aux->color = 'R';
                    rightRotate(aux, root, outside);
                    aux = x->dad->right;
                }
                aux->color = x->dad->color;
                aux->right->color = 'B';
                leftRotate(x->dad, root, outside);
                x = *root;
            }  
        }
        else {
            aux = x->dad->left;
            if (aux->color == 'R') {
                x->dad->color = 'R'; aux->color = 'B';
                rightRotate(x->dad, root, outside);
                aux = x->dad->left;
            }
            if (aux->left->color == 'B' && aux->right->color == 'B') {
                aux->color = 'R';
                x = x->dad;
            }
            else {
                if (aux->right->color == 'R') {
                    aux->right->color = 'B'; aux->color = 'R';
                    leftRotate(aux, root, outside);
                    aux = x->dad->left;
                }
                aux->color = x->dad->color;
                aux->left->color = 'B';
                rightRotate(x->dad, root, outside);
                x = *root;
            }
        }
    }
    x->color = 'B';
}

void removeRB(Node* trash, Node **root, Node *outside) {
    Node *y = trash;
    Node* aux;
    char old_color = y->color;

    if(y->left == outside) {
        aux = trash->right;
        moveDad(trash, trash->right, root, outside);
    }
    else {
        if(y->right == outside) {
            aux = trash -> left;
            moveDad(trash, trash->left, root, outside);
        }
        else {
            y = successor(trash, outside);
            old_color = y->color;
            aux = y -> right;
            if (y->dad == trash) {
                moveDad(y, aux, root, outside);
                y->right = trash->right;
                y->dad->right = y;
            }
            moveDad(trash, y, root, outside);
            y->left = trash->left;
            y->left->dad = y;
        }
    }
    if(old_color == 'B')
        routeRemoveRB(aux, root, outside);
}


void freeRB(Node **root, Node *outside){
    if((*root)->left != outside)
        freeRB(&(*root)->left, outside);
    if((*root)->right != outside)
        freeRB(&(*root)->right, outside);

    free(*root);
}

void dadnVec(int *vec, int seed) {
    int i, j;
    for(i = 0, j = 0; i < _10K; i++, j+=seed) {
        vec[i] = j;
    }
}

void countNodes(Node *root, int *sum, Node *outside){

    (*sum)++;

    if(root->left != outside){
        countNodes(root->left, sum, outside);
    }

    if(root->right != outside){
        countNodes(root->right, sum, outside);
    }
}

void paInVec(int *vec, int seed) {
    int i, j;
    for(i = 0, j = 0; i < _10K; i++, j+=seed) {
        vec[i] = j;
    }
}

void tests(Node **root, int *vec, int *sum, Node *outside) {
    int i;

    puts("\tEntering 10.000 Nodes.");
    for(i = 0; i < _10K; i++)
        insertRB(vec[i], root, outside);
    countNodes(*root, sum, outside);
    printf("\tNumber of Nodes: %d\n",*sum);

    puts("\t1000 nodes removed.");
    for(i = 0; i < K; i++)
        removeRB(searchNode(*root, vec[i],outside), root, outside);
    *sum = 0;
    countNodes(*root, sum, outside);
    printf("\tNumber of Nodes: %d\n",*sum);
}
