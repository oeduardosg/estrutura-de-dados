#include <stdlib.h>
#include <string.h>
#include "Gato.h"

struct Gato {
    char * name;
    int behavior;
};

Gato * inicGato(char * name, int behavior) {

    Gato * cat = (Gato *) calloc(1, sizeof(Gato));

    cat -> name = strdup(name);
    cat -> behavior = behavior;

}

void liberaGato(Gato * cat) {

    free(cat -> name);
    free(cat);

}

void atribuiNivelAgressividadeGato(Gato * cat, int behavior) {
    cat -> behavior = behavior;
}