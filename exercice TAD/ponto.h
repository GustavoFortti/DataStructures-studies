#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;
//create point 
Ponto* pto_cria( float x, float y);
// insert values in struct
void pto_atribui( Ponto* p, float x, float y);
// free struct
void pto_libera( Ponto* p);
// access values
void pto_acessa( Ponto *p, float *x, float *y);
// distance between x and y
float distancia( Ponto* p1, Ponto* p2);

#endif 