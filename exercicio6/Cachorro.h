#ifndef Cachorro_h
#define Cachorro_h

typedef struct Cachorro Cachorro;

Cachorro * inicCachorro(char * name, int behavior);

void liberaCachorro(Cachorro * dog);

#endif