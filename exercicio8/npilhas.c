#include <stdio.h>
#include <stdlib.h>
#include "npilhas.h"

typedef struct {
    int topo;
    int base;
} indicePilha;

struct pilhas {
    int * itens[MAX_NITENS];
    indicePilha pilhas[N_PILHAS];
    int qtdPilhas;
};

pilhas * inicNPilhas(int qtdPilhas) {

    int topos = 0, resto = 0;
    pilhas * pilha = (pilhas *) calloc(1, sizeof(pilhas));

    topos = MAX_NITENS / qtdPilhas;
    resto = MAX_NITENS % qtdPilhas;

    for(int i = 1; i <= qtdPilhas; i++) {
        pilha -> pilhas[i - 1].base = topos * i - topos;
        pilha -> pilhas[i - 1].topo = pilha -> pilhas[i - 1].base - 1;
    }
    pilha -> qtdPilhas = qtdPilhas;

return pilha;
}

void insereNElemento(pilhas * pilha, int indice, int * elemento) {

    if(indice >= pilha -> qtdPilhas) {
        printf("Essa pilha não existe!\n");
        free(elemento);
        return;
    }
    if(pilha -> pilhas[indice].topo + 1 == pilha -> pilhas[indice + 1].base || pilha -> pilhas[indice].topo == MAX_NITENS - 1) {
        printf("Overflow. Não é possível adicionar mais elementos à essa pilha.\n");
        free(elemento);
        return;
    }

    pilha -> pilhas[indice].topo++;
    pilha -> itens[pilha -> pilhas[indice].topo] = elemento;

}

int * removeNElemento(pilhas * pilha, int indice) {

    int * elemento = 0;

    if(indice < 0 || indice >= pilha -> qtdPilhas) {
        printf("Essa pilha não existe!");
        return NULL;
    }

    if(pilha -> pilhas[indice].topo == pilha -> pilhas[indice].base - 1) {
        printf("Não há elementos na pilha para serem removidos.\n");
        return NULL;
    }

    elemento = pilha -> itens[pilha -> pilhas[indice].topo];
    pilha -> pilhas[indice].topo--;

return elemento;
}

void imprimeNPilha(pilhas * pilha) {

    for(int i = 0; i < pilha -> qtdPilhas; i++) {
        printf("Pilha %02d: ", i);
        for(int j = pilha -> pilhas[i].base; j <= pilha -> pilhas[i].topo; j++) {
            printf("%d ", *pilha -> itens[j]);
        }
        printf("\n");
    }

}

void liberaNPilha(pilhas * pilha) {
    
    for(int i = 0; i < pilha -> qtdPilhas; i++) {
        for(int j = pilha -> pilhas[i].base; j <= pilha -> pilhas[i].topo; j++) {
            free(pilha -> itens[j]);
        }
    }

    free(pilha);
}
