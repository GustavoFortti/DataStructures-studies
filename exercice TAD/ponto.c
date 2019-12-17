#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto
{
    float x;
    float y;
};

int main()
{
    float d;
    Ponto *p,*q;
    p = pto_cria(10, 15.7);
    q = pto_cria(2, -2.7);
    
    d = distancia(p, q);

    printf("%f\n", d);

    pto_libera(p);
    pto_libera(q);

    return 0;
}

Ponto* pto_cria( float x, float y)
{
    Ponto* p = ( Ponto*) malloc(sizeof(Ponto));
    if ( p != NULL)
    {
        p->x = x;
        p->y = y;
    }
    return p;
}

void pto_atribui( Ponto* p, float x, float y)
{
    p->x = x;
    p->y = y;
}

void pto_libera( Ponto* p)
{
    free(p);
}

void pto_acessa( Ponto *p, float *x, float *y)
{
    *x = p->x;
    *y = p->y;
}

float distancia( Ponto* p1, Ponto* p2)
{
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(abs(dx * dx - dy * dy));
}