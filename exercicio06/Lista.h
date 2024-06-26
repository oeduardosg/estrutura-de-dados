#ifndef Lista_h
#define Lista_h

typedef struct lista Lista;

Lista * inicLista();

void insereAnimal(Lista * lista, void * animal, int species);

void removeAnimal(Lista * lista, void * animal);

void liberaLista(Lista * lista);

#endif