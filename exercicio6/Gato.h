#ifndef Gato_h
#define Gato_h

typedef struct Gato Gato;

Gato * inicGato(char * name, int behavior);

void liberaGato(Gato * cat);

void atribuiNivelAgressividadeGato(Gato * cat, int behavior);

#endif