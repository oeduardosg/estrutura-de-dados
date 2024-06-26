#ifndef pilha_h
#define pilha_h

#include "pilha.h"

#define MAX_ITENS 10

typedef struct pilhaDupla pilhaDupla;

pilhaDupla * inicPilha();

void insereElemento(pilhaDupla * pilha, int indice, int * elemento);

int * removeElemento(pilhaDupla * pilha, int indice) ;

void imprimePilha(pilhaDupla * pilha);

void liberaPilha(pilhaDupla * pilha);

#endif