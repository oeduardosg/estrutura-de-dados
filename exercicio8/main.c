#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "npilhas.h"

int * leNum() {

    int * num = (int *) calloc(1, sizeof(int));
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

        int qtdPilhas = 0, pilha1 = 0, pilha2 = 0;
        printf("Quantas pilhas? [MÁXIMO 100]");
        scanf("%d", &qtdPilhas);
        pilhas * pilha = inicNPilhas(qtdPilhas);

        while(1) {
            printf("Informe a pilha e o elemento que deseja adicionar: ");
            scanf("%d", &pilha1);
            if(pilha1 == -1) break;
            insereNElemento(pilha, pilha1, leNum());
        }

        imprimeNPilha(pilha);

        while(1) {
            printf("Informe duas pilhas, uma para receber o último valor de outra: ");
            scanf("%d %d", &pilha1, &pilha2);
            if(pilha1 == -1) break;
            int * t = removeNElemento(pilha, pilha2);
            if(t) {
                insereNElemento(pilha, pilha1, t);
            }
        }

        imprimeNPilha(pilha);
        liberaNPilha(pilha);
    }

return 0;
}