#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;

struct Tree{
    int id;
    struct Tree *left, *right;
};

typedef struct Tree* tree;

tree createNewNode(int id)
{
    tree newNo = (tree) malloc(sizeof(struct Tree));
    newNo->left = NULL;
    newNo->right = NULL;
    newNo->id = id;

    return newNo;
}

tree insert(tree raiz, tree no)
{
    if (!raiz) return no;

    if (raiz->id < no->id) raiz->left = insert(raiz->left, no);
    else raiz->right = insert(raiz->right, no);

    return raiz;
}

tree search(int id, tree raiz) {
    if (!raiz) {return NULL;}
    if (raiz->id == id) {return raiz;}
    if (raiz->id > id) {search(id, raiz->left);}
    search(id, raiz->right);
}

int sizeTree(tree raiz)
{
    if (!raiz) return 0;
    return(sizeTree(raiz->left) + 1 + sizeTree(raiz->right));
}

void showTree(tree raiz)
{
    if (raiz)
    {
        printf("%i", raiz->id);
        printf("(");
        showTree(raiz->left);
        showTree(raiz->right);
        printf(")");
    }
}

int main()
{
    tree T = NULL;

    return 0;
}