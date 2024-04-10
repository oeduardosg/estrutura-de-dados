#ifndef _LISTA_H_
#define _LISTA_H_

#include "product.h"

typedef struct cellType cellType;
typedef cellType listType;

listType * createList();

void insertCell(listType * lista, productType * produto);

void removeCell(listType * lista, char * barcodeOrName);

void printList(listType * lista);

void freeList(listType * lista);

#endif