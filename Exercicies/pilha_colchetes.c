#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **No, int data)
{
    struct node *pos = (struct node*) malloc(sizeof(struct node));
    
    pos->data = data;
    pos->next = *No;
    *No = pos;
}

void show(struct node *No, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%i\n", No->data);
        No = No->next;
    }
}

void swap(struct node **No)
{
    if (*No == NULL || (*No)->next == NULL) return;

    struct node *end = *No, *first = NULL;
    while (end != NULL && end->next != NULL ) //  end->next != NULL && end != NULL -> parece que se for nessa ordem a tela mostra "segmente found" por que?
    {
        struct node *aux = end->next;
        end->next = aux->next;
        aux->next = end;

        if (first == NULL) *No = aux;
        else first->next = aux;
        
        first = end;
        end = end->next;
    }
}

int main(int argc, char const *argv[])
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8};
    struct node *list = NULL;
    unsigned size = sizeof(v) / sizeof(v[0]);

    int i;
    for (i = size - 1; i >= 0; i--)
    {
        insert(&list, v[i]);
    }
    swap(&list);
    show(list, size);
    return 0;
}
