#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char ** argv) {

    if(argc <= 1) {
        printf("O diretório de arquivo não foi informado!\n");
        exit(1);
    }

    FILE * f = fopen(argv[1], "r");
    if(!f) {
        printf("Erro ao abrir o arquivo informado %s!\n", argv[1]);
        exit(1);
    }

    stats(f);

    fclose(f);

return 0;
}