#ifndef _LISTA_H_
#define _LISTA_H_

#include "produto.h"

typedef struct celulaType celulaType;
typedef struct listaType listaType;

listaType * createList();

void insertCell(listaType * lista, produtoType * produto);

void removeCell(listaType * lista, char * barcodeOrName);

void printList(listaType * lista);

void freeList(listaType * lista);

#endif