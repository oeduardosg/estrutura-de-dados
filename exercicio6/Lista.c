#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Lista.h"

typedef struct cel Cel;

struct cel {
    Cel * prior;
    void * animal;
    int species;
    Cel * next;
};

struct lista {
    Cel * first;
    Cel * last;
};

Lista * inicLista() {

    Lista * lista = (Lista *) calloc(1, sizeof(Lista));

return lista;
}

void insereAnimal(Lista * lista, void * animal, int species) {

    Cel * newCel = (Cel *) calloc(1, sizeof(Cel));

    newCel -> animal = animal;
    newCel -> species = species;
    newCel -> next = NULL;

    if(!lista -> first) {
        lista -> first = newCel;
        lista -> last = newCel;
        newCel -> prior = NULL;
        return;
    }

    newCel -> prior = lista -> last;
    lista -> last -> next = newCel;
    lista -> last = newCel;

}

void removeAnimal(Lista * lista, void * animal) {

    Cel * checker = lista -> first;

    while(checker != animal && checker) {
        checker = checker -> next;
    }

    if(!checker) {
        printf("O animal não foi encontrado\n");
    }

    checker -> prior -> next = checker -> next;
    checker -> next -> prior = checker -> prior;

    //PAREI AQUI, FALTAM MAIS CASOS DE TROCA DE PONTEIROS;

}