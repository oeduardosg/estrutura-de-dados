/**
 * This code was an attempt of using callback functions
 * It is working properly, but definitely not in a generic way
 * In a nutshell, everything is messed up
 */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "words.h"

int main(int argc, char ** argv) {

    /*if(argc <= 1) {
        printf("O diretório de arquivo não foi informado!\n");
        exit(1);
    }*/

    FILE * f = fopen("texto0.txt", "r");
    if(!f) {
        printf("Erro ao abrir o arquivo informado %s!\n", argv[1]);
        exit(1);
    }

    char word[32];
    Hash * ht = cria(100, sizeof(char *));
    while(fscanf(f, "%s", word) == 1) {
        hash_insere(ht, word, word, hash, compare);
    }

    stats(ht);

    libera(ht);
    fclose(f);

return 0;
}