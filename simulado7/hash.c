#include "hash.h"

typedef struct cell cell;

struct hash {
    cell ** dados;
    int tam;
    size_t tam_item;
};

struct cell {
    void * dado;
    int count;
    cell * prox;
};

cell * cria_celula(void * objeto) {

    cell * nova = (cell *) calloc(1, sizeof(cell));
    nova -> dado = strdup(objeto);
    nova -> prox = NULL;
    nova -> count = 1;

return nova;
}

int menor(const void * x, const void * y) {
    int x_value = ((cell *)x) -> count;
    int y_value = ((cell *)y) -> count;

return x_value - y_value;
}

Hash * cria(int tam, size_t tam_item) {

    Hash * ht = (Hash *) calloc(1, sizeof(Hash));
    ht -> dados = (cell **) calloc(tam, sizeof(cell *));
    ht -> tam = tam;
    ht -> tam_item = tam_item;

return ht;
}

void * busca(Hash* hash, void* key, int (*fhash)(void*), int (*comp)(void*,void*)) {

    int index = fhash(key);

    if(hash -> dados[index]) {
        cell * runner = hash -> dados[index];
        while(runner) {
            if(comp(runner -> dado, key)) return runner -> dado;
            runner = runner -> prox;
        }
    }

    printf("O objeto não foi encontrado.\n");

return NULL;
}

void hash_insere(Hash* thash, void * key, void * objeto, int (*hash)(void*), int(*comp)(void*,void*)) {

    int index = hash(key);
    
    if(!thash -> dados[index]) thash -> dados[index] = cria_celula(objeto);
    else {
        cell * runner = thash -> dados[index];
        while(runner) {
            if(comp(runner -> dado, objeto)) {
                runner -> count++;
                return;
            }
            runner = runner -> prox;
        }
        cell * nova = cria_celula(objeto);
        nova -> prox = thash -> dados[index];
        thash -> dados[index] = nova;
    }

}

void libera_celula(cell * c) {
    if(c -> prox) libera_celula(c -> prox);
    free(c -> dado);
    free(c);
}

void libera(Hash* table) {

    for(int i = 0; i < table -> tam; i++) {
        if(table -> dados[i]) libera_celula(table -> dados[i]);
    }
    free(table -> dados);
    free(table);
}

void stats(Hash * table) {

    int total = 0;
    for(int i = 0; i < table -> tam; i++) {
        if(table -> dados[i]) {
            cell * runner = table -> dados[i];
            while(runner) {
                total++;
                runner = runner -> prox;
            }
        }
    }


    cell palavras[total];
    int j = 0;
    for(int i = 0; i < table -> tam; i++) {
        if(table -> dados[i]) {
            cell * runner = table -> dados[i];
            while(runner) {
                palavras[j] = *runner;
                j++;
                runner = runner -> prox;
            }
        }
    }

    qsort(palavras, total, sizeof(cell), menor);

    FILE * exitf = fopen("saida.txt", "w");
    int soma = 0, i = 0;
    for(i = 0; i < total; i++) {
        fprintf(exitf, "%s %d\n", (char *)palavras[i].dado, palavras[i].count);
        soma += palavras[i].count;
    }

    fprintf(exitf, "\n------------------------\n");
    fprintf(exitf, "%d palavras distintas encontradas\n", total); 
    fprintf(exitf, "%d palavras no total\n", soma); 
    fprintf(exitf, "%s é a palavra de maior frequência (%d)\n", (char *)palavras[i-1].dado, palavras[i-1].count);

    fclose(exitf);

}