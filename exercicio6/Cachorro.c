#include <stdlib.h>
#include <string.h>
#include "Cachorro.h"

struct Cachorro {
    char * name;
    int behavior;
};

Cachorro * inicCachorro(char * name, int behavior) {

    Cachorro * dog = (Cachorro *) calloc(1, sizeof(Cachorro));

    dog -> name = strdup(name);
    dog -> behavior = behavior;

}

void liberaCachorro(Cachorro * dog) {

    free(dog -> name);
    free(dog);

}