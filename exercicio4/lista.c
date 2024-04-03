#include <stdlib.h>
#include "lista.h"

typedef struct {

    produtoType * produto;
    celulaType * prox;

} celulaType;

struct listaType{

    celulaType * primeira;
    celulaType * ultima;

};

listaType * createList() {

    listaType * lista = (listaType *) calloc(1, sizeof(listaType));
    
    lista -> primeira = NULL;
    lista -> ultima = NULL;

}

void * insertCell(listaType * lista, produtoType * product) {

    celulaType * celulaNova = (celulaType *) calloc(1, sizeof(celulaType));

    celulaNova -> produto = product;
    celulaNova -> prox = NULL;

    if(lista -> primeira == NULL) lista -> primeira = celulaNova;
    lista -> ultima -> prox = celulaNova;
    lista -> ultima = celulaNova;

}

void * removeCell(listaType * lista, char * barcodeOrName) {

    celulaType * celulaAux = (celulaType *) calloc(1, sizeof(celulaType));
    celulaAux = lista -> primeira;
    celulaType * ant;

    if(!lista -> primeira) {
        printf("Não há elementos na lista!\n");
        return;
    }

    while(celulaAux && strcmp(barcodeOrName, getProductName(celulaAux -> produto)) && strcmp(barcodeOrName, getProductName(celulaAux -> produto))) {
        ant = celulaAux;
        celulaAux = celulaAux -> prox;
    }

    if(!celulaAux -> prox && strcmp(barcodeOrName, getProductName(celulaAux -> produto)) && strcmp(barcodeOrName, getProductName(celulaAux -> produto))) {
        printf("Produto não encontrado.\n");
        ant -> prox = NULL;
        lista -> ultima = ant;
        return;
    }

    if(celulaAux == lista -> primeira) {
        void * aux = lista -> primeira -> prox;
        freeCell(lista -> primeira);
        lista -> primeira = aux;
        return;
    }

    ant -> prox = celulaAux -> prox;
    freeCell(celulaAux);

}

void freeList(listaType * lista) {
    celulaType * cellToFree;
    celulaType * auxCell;

    while(!cellToFree) {
        cellToFree = auxCell;
        auxCell = cellToFree -> prox;
        freeCell(cellToFree);
    }

    free(lista);
}




