#ifndef fila_h
#define fila_h

#include <stdio.h>
#include "amostra.h"

typedef struct fila Fila;

Fila * inicFila(char* nome);

void insereElemento(Fila * fila, Amostra * amostra);

Amostra * removeElemento(Fila * fila);

void liberaPosto(Fila * fila);

void imprimeFila(Fila * fila);

#endif