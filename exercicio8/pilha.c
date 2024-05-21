#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct {
    int topo;
    int base;
} indicePilha;

struct pilhaDupla {
    int * itens[MAX_ITENS];
    indicePilha pilha1, pilha2;
};

pilhaDupla * inicPilha() {

    pilhaDupla * pilha = (pilhaDupla *) calloc(1, sizeof(pilhaDupla));

    pilha -> pilha1.topo = -1;
    pilha -> pilha1.base = 0;

    pilha -> pilha2.topo = MAX_ITENS;
    pilha -> pilha2.base = MAX_ITENS - 1;

return pilha;
}

void insereElemento(pilhaDupla * pilha, int indice, int * elemento) {

    if(pilha -> pilha1.topo == pilha -> pilha2.topo - 1) {
        printf("Overflow. Não é possível adicionar mais elementos à pilha.\n");
        return;
    }

    if(indice == 1) {
        pilha -> pilha1.topo += 1;
        pilha -> itens[pilha -> pilha1.topo] = elemento;
    }
    else {
        pilha -> pilha2.topo -= 1;
        pilha -> itens[pilha -> pilha2.topo] = elemento;
    }

}

int * removeElemento(pilhaDupla * pilha, int indice) {

    int * elemento = 0;

    if(indice == 1) {
        if(pilha -> pilha1.topo == pilha -> pilha1.base) {
            printf("Não há elementos para serem removidos na pilha %d.\n", indice);
            return NULL;
        }
        elemento = pilha -> itens[pilha -> pilha1.topo];
        pilha -> pilha1.topo -= 1;
    }
    else {
        if(pilha -> pilha2.topo == pilha -> pilha2.base) {
            printf("Não há elementos para serem removidos na pilha %d.\n", indice);
            return NULL;
        }
        elemento = pilha -> itens[pilha -> pilha2.topo];
        pilha -> pilha2.topo += 1;
    }

return elemento;
}

void imprimePilha(pilhaDupla * pilha) {

    printf("Pilha 1: ");
    for(int i = 0; i <= pilha -> pilha1.topo; i++) {
        printf("%d ", *pilha -> itens[i]);
    }
    printf("\n\n");

    printf("Pilha 2: ");
    for(int i = MAX_ITENS - 1; i >= pilha -> pilha2.topo; i--) {
        printf("%d ", *pilha -> itens[i]);
    }
    printf("\n\n");

}

void liberaPilha(pilhaDupla * pilha) {
    
    for(int i = 0; i <= pilha -> pilha1.topo; i++) {
        free(pilha -> itens[i]);
    }
    for(int i = MAX_ITENS - 1; i >= pilha -> pilha2.topo; i--) {
        free(pilha -> itens[i]);
    }

    free(pilha);
}
