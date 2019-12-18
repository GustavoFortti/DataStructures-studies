#ifndef LISTASEQUENCIAL_H
#define LISTASEQUENCIAL_H

#define size 100

typedef struct list List;

struct student
{
    int RA;
    char name[30];
    float n1, n2, n3;
};

List* create_list();
void free_list(List* li);
int size_list(List* li);
int max_size_list(List *li);
int min_size_list(List *li);
int insert_final(List *li, struct student st);

#endif
