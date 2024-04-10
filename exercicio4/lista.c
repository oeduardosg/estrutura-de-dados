#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

struct celulaType {

    produtoType * produto;
    celulaType * prox;

};

struct listaType{

    celulaType * primeira;
    celulaType * ultima;

};

void freeCell(celulaType * cell) {
    freeProduct(cell -> produto);
    free(cell);
}

listaType * createList() {

    listaType * lista = (listaType *) calloc(1, sizeof(listaType));
    lista -> primeira = (celulaType *) calloc(1, sizeof(celulaType));
    lista -> ultima = (celulaType *) calloc(1, sizeof(celulaType));
    
    lista -> primeira = NULL;
    lista -> ultima = NULL;

}

void insertCell(listaType * lista, produtoType * product) {

    celulaType * celulaNova = (celulaType *) calloc(1, sizeof(celulaType));

    celulaNova -> produto = product;
    celulaNova -> prox = NULL;

    if(lista -> primeira == NULL) {
        lista -> primeira = celulaNova;
        lista -> ultima = celulaNova;
    }
    else {
        lista -> ultima -> prox = celulaNova;
        lista -> ultima = celulaNova;
    }

}

void removeCell(listaType * lista, char * barcodeOrName) {

    celulaType * celulaAux = (celulaType *) calloc(1, sizeof(celulaType));
    celulaAux = lista -> primeira;
    celulaType * ant;

    if(!lista -> primeira) {
        printf("Não há elementos na lista!\n");
        return;
    }

    while(celulaAux && strcmp(barcodeOrName, getProductName(celulaAux -> produto)) && strcmp(barcodeOrName, getProductBarcode(celulaAux -> produto))) {
        ant = celulaAux;
        celulaAux = celulaAux -> prox;
    }

    if(!celulaAux -> prox && strcmp(barcodeOrName, getProductName(celulaAux -> produto)) && strcmp(barcodeOrName, getProductBarcode(celulaAux -> produto))) {
        printf("Produto não encontrado.\n");
        ant -> prox = NULL;
        lista -> ultima = ant;
        return;
    }

    if(celulaAux == lista -> primeira) {
        void * aux = lista -> primeira -> prox;
        freeCell(lista -> primeira);
        freeCell(celulaAux);
        lista -> primeira = aux;
        return;
    }

    ant -> prox = celulaAux -> prox;
    freeCell(celulaAux);

}

void printList(listaType * lista) {

    celulaType * cellToPrint = lista -> primeira;

    while(cellToPrint) {
        printProduct(cellToPrint -> produto);
        cellToPrint = cellToPrint -> prox;
    }
    printf("\n");

}

void freeList(listaType * lista) {
    celulaType * cellToFree;
    celulaType * auxCell = lista -> primeira;

    while(auxCell) {
        cellToFree = auxCell;
        auxCell = cellToFree -> prox;
        freeCell(cellToFree);
    }

    free(lista);
}




