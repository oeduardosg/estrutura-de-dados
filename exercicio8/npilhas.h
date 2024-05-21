#ifndef npilhas_h
#define npilhas_h

#include "npilhas.h"

#define MAX_NITENS 100
#define N_PILHAS 10

typedef struct pilhas pilhas;

pilhas * inicNPilhas(int qtdPilhas);

void insereNElemento(pilhas * pilha, int indice, int * elemento);

int * removeNElemento(pilhas * pilha, int indice) ;

void imprimeNPilha(pilhas * pilha);

void liberaNPilha(pilhas * pilha);

#endif