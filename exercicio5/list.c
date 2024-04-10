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

    while(checker && strcmp(getProductName(checker -> product), barcodeOrName) && strcmp(getProductName(checker -> product), barcodeOrName)) {
        checker = checker -> next;
    }

    if(!checker) {
        printf("O produto não foi encontrado.");
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

    celulaType * cellToPrint = lista;
    if();

    while(cellToPrint) {
        printProduct(cellToPrint -> produto);
        cellToPrint = cellToPrint -> prox;
    }
    printf("\n");

}