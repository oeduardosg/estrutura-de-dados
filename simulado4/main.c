#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char * argv) {

    /*if(argc <= 1) {
        printf("O diretório de arquivo não foi informado!\n");
        exit(1);
    }

    FILE * f = fopen(argv, "w"); */
    FILE * f = fopen("texto0.txt", "r");
    if(!f) {
        printf("Erro ao abrir o arquivo %s!", argv);
        exit(1);
    }

    char word[64];
    fscanf(f, "%s", word);
    tree * twords = createTree(word);

    while(fscanf(f, "%s", word) == 1) {
        searchWord(twords, word);
    }
    int n = wordsQuantity(twords);

    fclose(f);
    freeTree(twords);

return 0;
}