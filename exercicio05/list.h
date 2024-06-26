#ifndef _LIST_H_
#define _LIST_H_

#include "product.h"

typedef struct cellType cellType;
typedef cellType listType;

listType * createList();

listType * insertCell(listType * lista, productType * produto);

listType * removeCell(listType * lista, char * barcodeOrName);

void printList(listType * lista);

void freeList(listType * lista);

#endif