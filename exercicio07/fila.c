#include "fila.h"
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula {
    Celula * nextCell;
    Amostra * amostra;
};

struct fila {
    char * nomeDaFila;
    Celula * lastIn;
    Celula * nextOut;
};

Fila * inicFila(char* nome) {

    Fila * fila = (Fila *) calloc(1, sizeof(Fila));

    fila -> nomeDaFila = strdup(nome);
    fila -> lastIn = NULL;
    fila -> nextOut = NULL;

return fila;
}

void insereElemento(Fila * fila, Amostra * amostra) {

    if(!fila) {
        printf("A fila não existe.\n");
        return;
    }

    Celula * novaCelula = (Celula *) calloc(1, sizeof(Celula));
    novaCelula -> amostra = amostra;
    novaCelula -> nextCell = NULL;

    if(!fila -> lastIn) {
        fila -> lastIn = novaCelula;
        fila -> nextOut = novaCelula;
    }
    else {
        if(retornaIdade(amostra) >= 60) {
            novaCelula -> nextCell = fila -> nextOut;
            fila -> nextOut = novaCelula;
        }
        else {
            fila -> lastIn -> nextCell = novaCelula;
            fila -> lastIn = novaCelula;
        }
    }

return;
}

Amostra * removeElemento(Fila * fila) {

    if(!fila) {
        printf("A fila não existe.\n");
        return NULL;
    }

    if(!fila -> nextOut) {
        printf("A fila não possui elementos para remover.\n");
        return NULL;
    }

    Celula * toFree = fila -> nextOut;
    Amostra * amostra = fila -> nextOut -> amostra;
    fila -> nextOut = fila -> nextOut -> nextCell;
    free(toFree);

return amostra;
}

void imprimeFila(Fila * fila) {
    
    Celula * runner = fila -> nextOut;

    while(runner) {
        imprimeAmostra(runner -> amostra);
        runner = runner -> nextCell;
    }
    printf("\n");

}

void liberaFila(Fila * fila) {
    
    Celula * liberador = fila -> nextOut;

    while(liberador) {
        fila -> nextOut = fila -> nextOut -> nextCell;
        liberaAmostra(liberador -> amostra);
        free(liberador);
        liberador = fila -> nextOut;
    }

    free(fila -> nomeDaFila);
    free(fila);

}
