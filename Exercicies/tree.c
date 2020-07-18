#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;

typedef struct Tree {
    int id;
    struct Tree *left, *right;
}TR;

TR* createNewNodo(int id)
{
    TR* newNo = (TR*) malloc(sizeof(TR));
    newNo->left = NULL;
    newNo->right = NULL;
    newNo->id = id;
    return newNo;    
}

TR* insert(TR* raiz, TR* no)
{
    if (raiz == NULL) return (no);

    if (no->id < raiz->id) raiz->left = insert(raiz->left, no);
    else raiz->right = insert(raiz->right, no);

    return(raiz);
}

int main()
{
    TR* T = NULL; 

    TR* no = createNewNodo(20);
    T = insert(T, no);

}