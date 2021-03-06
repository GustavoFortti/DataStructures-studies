#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

struct list
{
    int qtd;
    struct student data[size];
};

int main()
{

    struct student data_student[4] = {{2,"Andre",9.5,7.8,8.5},
                                      {4,"Ricardo",7.5,8.7,6.8},
                                      {1,"Bianca",9.7,6.7,8.4},
                                      {3,"Ana",5.7,6.1,7.4}};
    
    List *li;

    li = create_list;
    
    //int size_li;
    //size_li = size_list(li);
    //size_li = max_size_list(li);
    //size_li = min_size_list(li);
    int i;
    int r;
    for ( i = 0; i < 4; i++)
    {
        // x = insert_final(li, data_student[i]);
        // x = insert_first(li, data_student[i]);
        r = sort_list(li, data_student[i]);
    }

    r = remove_final(li);
    r = remove_list_first(li);
    int ra;
    r = remove_list(li, ra);

    

    free_list(li);
}

List* create_list()
{
    List *li = (List*) malloc( sizeof(List));
    if ( li != NULL)
    {
        li-> qtd = 0;
    }
    return li;
}

void free_list(List* li)
{
    free(li);
}

int size_list(List* li)
{
    if ( li = NULL)
    {
        return -1;
    }
    else
    {
        return li->qtd;
    }
}

int max_size_list(List *li)
{
    if (li == NULL)
    {
        return -1;
    }
    else
    {
        return ( li->qtd == size);        
    }
    
}

int min_size_list(List *li)
{
    if ( li == NULL)
    {
        return -1;
    }
    else
    {
        return (li->qtd == 0);
    }
}

int insert_final(List *li, struct student st)
{
    if ( li == NULL)
    {
        return 0;
    }
    if (max_size_list(li))
    {
        return 0;
    }
    li->data[li->qtd] = st;
    li->qtd++;
    return 1;
}

int insert_first(List *li, struct student st)
{
    if ( li == NULL)
    {
        return 0;
    }
    if ( max_size_list(li))
    {
        return 0;
    }
    int i;
    for ( i = li->qtd; i > 0; i--)
    {
        li->data[i+1] = li->data[i];
    }
    li->data[0] = st;
    li->qtd++;
    return 1;
}

int sort_list(List *li, struct student st)
{
    if ( li == NULL)
    {
        return 0;
    }
    if ( max_size_list(li))
    {
        return 0;
    }
    int i;
    for ( i = 0; li->data[i].RA < st.RA && i < li->qtd ; i++);
    int aux = i;
    for (i = li->qtd; i >= aux; i--)
    {
        li->data[i+1] = li->data[i];
    }
    li->data[aux] = st;
    li->qtd;
    return 1;
}

int remove_final(List* li)
{
    if (li == NULL)
    {
        return 0;
    }
    if (li->qtd == 0)
    {
        return 0;
    }
    li->qtd--;
    return 1;
}

int remove_list_first(List* li)
{
    if ( li == NULL)
    {
        return 0;
    }
    if ( li->qtd == 0)
    {
        return 0;
    }
    int i = 0;
    for ( i = 0; i < li->qtd; i++)
    {
        li->data[i] = li->data[i+1];
    }
    li->qtd--;
    return 1;
}

int remove_list(List* li, int mat)
{
    if (li == NULL)
    {
        return 0;
    }
    if (li->qtd == 0)
    {
        return 0;
    }
    int aux, i;
    for ( i = 0; i < li->qtd && li->data[i].RA != mat; i++);
    if ( i == li->qtd)
    {
        return 0;
    }
    aux = i;
    for ( i = aux; i < li->qtd-1; i++)
    {
        li->data[i] = li->data[i+1];
    }
    li->qtd--;    
    return 1;
}
