#include "arv_exp.h"
#include <stdlib.h>
#include <stdio.h>

struct arv {
    char op;
    float num;
    Arv * esq;
    Arv * dir;
};

Arv* CriaVazia(void) {
return NULL;
}

Arv* CriaOperador(char c, Arv* esq, Arv* dir) {

    Arv * ab = (Arv *) calloc(1, sizeof(Arv));
    ab -> op = c;
    ab -> num = 0;
    ab -> esq = esq;
    ab -> dir = dir;

return ab;
}

Arv* CriaOperando(int valor) {
    Arv * ab = (Arv *) calloc(1, sizeof(Arv));
    ab -> op = NULL;
    ab -> num = (float)valor;
    ab -> esq = CriaVazia();
    ab -> dir = CriaVazia();

return ab;
}

void Imprime(Arv* arv) {

    if(!arv) return;
    if(arv -> op) printf("(");
    if(arv -> esq) Imprime(arv -> esq);
    if(arv -> op) printf(" %c ", arv -> op);
    else printf("%.0f", arv -> num);
    if(arv -> dir) Imprime(arv -> dir);
    if(arv -> op) printf(")");
    
}


Arv* Libera (Arv* arv) {

    if(arv -> esq) Libera(arv -> esq);
    if(arv -> dir) Libera(arv -> dir);
    free(arv);

return NULL;
}

float Avalia(Arv* arv) {

    if(!arv -> op) return arv -> num;
    switch (arv -> op) {
    case '+':
        return Avalia(arv -> esq) + Avalia(arv -> dir);
        break;

    case '-':
        return Avalia(arv -> esq) - Avalia(arv -> dir);
        break;

    case '*':
        return Avalia(arv -> esq) * Avalia(arv -> dir);
        break;

    case '/':
        return Avalia(arv -> esq) / Avalia(arv -> dir);
        break;
    
    default:
        break;
    }

}


int Folhas(Arv* arv) {

    int quantidade = 0;
    if(!arv -> esq && !arv -> dir) return 1;
    if(arv -> esq) quantidade += Folhas(arv -> esq);
    if(arv -> dir) quantidade += Folhas(arv -> dir);

return quantidade;
}


int Altura(Arv* arv) {

    int tamanhoEsq = 0, tamanhoDir = 0;
    if(arv -> esq) tamanhoEsq = 1 + Altura(arv -> esq);
    if(arv -> dir) tamanhoDir = 1 + Altura(arv -> dir);

return tamanhoEsq >= tamanhoDir ? tamanhoEsq: tamanhoDir;
}