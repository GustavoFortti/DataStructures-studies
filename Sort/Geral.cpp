#include "Funcionalidades.h"
#include <stdlib.h>

int * createVector(int size)
{
    int *vector = (int*) malloc(sizeof(int) * size);

    for (size_t i = 0; i < size; i++)
    {
        *(vector + i) = rand() % (size * 10);
    }
    
    return vector;
}