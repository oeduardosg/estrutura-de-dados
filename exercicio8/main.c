#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "npilhas.h"

int * leNum() {

    int * num = malloc(sizeof(int));
    scanf("%d", num);

return num;
}

int main() {
    int op = 0;

    printf("Iniciar código em modo [1] Pilhas Duplas ou [2] N Pilhas: ");
    scanf("%d", &op);

    if(op == 1) {

        pilhaDupla * pilha = inicPilha();

        for(int i = 0; i < 5; i++) {
            insereElemento(pilha, 1, leNum());
            insereElemento(pilha, 2, leNum());
        }

        imprimePilha(pilha);

        int * t = removeElemento(pilha, 1);
        printf("%d\n\n", *t);

        insereElemento(pilha, 2, t);
        imprimePilha(pilha);
        liberaPilha(pilha);

    }
    else {

        int qtdPilhas = 0;
        printf("Quantas pilhas? ");
        scanf("%d", &qtdPilhas);
        pilhas * pilha = inicNPilhas(qtdPilhas);

        insereNElemento(pilha, 2, leNum());
        insereNElemento(pilha, 2, leNum());

        imprimeNPilha(pilha);
    }

return 0;
}