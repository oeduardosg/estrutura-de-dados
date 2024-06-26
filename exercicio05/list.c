#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

struct cellType {
    productType * product;
    cellType * prior;
    cellType * next;
};

void freeCell(cellType * cell) {
    freeProduct(cell -> product);
    free(cell);
}

listType * createList() {
    return NULL;
}

listType * insertCell(listType * list, productType * product) {

    cellType * newCell = (cellType *) calloc(1, sizeof(cellType));
    newCell -> product = product;
    newCell -> next = NULL;
    newCell -> prior = NULL;

    if(list != NULL) {
        newCell -> next = list;
        list -> prior = newCell;
    }

    list = newCell;

return list;
}

listType * removeCell(listType * list, char * barcodeOrName) {

    if(!list) {
        printf("Não há produtos na lista.");
        return list;
    }

    cellType * checker = list;

    while(checker && strcmp(getProductName(checker -> product), barcodeOrName) && strcmp(getProductBarcode(checker -> product), barcodeOrName)) {
        checker = checker -> next;
    }

    if(!checker) {
        printf("O produto não foi encontrado.\n");
        return list;
    }

    if(checker == list) {
        if(!list -> next) {
            freeCell(list);
            return NULL;
        }
        list = list -> next;
        list -> prior = NULL;
        freeCell(checker);
        return list;
    }

    if(!checker -> next) {
        checker -> prior -> next = NULL;
        freeCell(checker);
        return list;
    }

    checker -> prior -> next = checker -> next;
    checker -> next -> prior = checker -> prior;

    freeCell(checker);

return list;
}

void printList(listType * list) {

    cellType * cellToPrint = list;

    if(!cellToPrint) {
        printf("Lista vazia.\n");
        return;
    }

    while(cellToPrint) {
        printProduct(cellToPrint -> product);
        cellToPrint = cellToPrint -> next;
    }
    printf("\n");

}

void freeList(listType * list) {

    cellType * cellToBeFreed = list, * nextCell;
    
    while(cellToBeFreed) {
        nextCell = cellToBeFreed -> next;
        freeCell(cellToBeFreed);
        cellToBeFreed = nextCell;
    }

}