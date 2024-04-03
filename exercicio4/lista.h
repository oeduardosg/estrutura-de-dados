#ifndef _LISTA_H_
#define _LISTA_H_

#include "produto.h"

typedef struct listaType listaType;

listaType * createList();

void insertCell(listaType * lista, produtoType * produto);

void removeCell(listaType * lista, produtoType * produto);

void printlistaName(listaType * lista);

#endif