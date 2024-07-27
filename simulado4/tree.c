#include "tree.h"

struct tree {
    char * word;
    int count;
    int key;
    tree * l;
    tree * r;
};

int getCount(tree * t) {
return t -> count;
}

char * getWord(tree * t) {
return t -> word;
}

int emptyTree(tree * t) {
return t == NULL;
}

tree * createTree(char * word) {
    
    int key = 0;
    for(int i = 0; word[i] != '\0'; i++) key += (int)word[i];

    tree * t = (tree *) calloc(1, sizeof(tree));
    t -> word = strdup(word);
    t -> count = 1;
    t -> key = key;
    t -> l = NULL;
    t -> r = NULL;

return t;
}

void searchWord(tree * t, char * word) {

    int key = 0;
    for(int i = 0; word[i] != '\0'; i++) key += (int)word[i];

    if(!strcmp(t -> word, word)) {
        t -> count++;
    }
    else if(key <= t -> key) {
        if(!emptyTree(t -> l)) searchWord(t -> l, word);
        else {
            t -> l = createTree(word);
        }
    }
    else {
        if(!emptyTree(t -> r)) searchWord(t -> r, word);
        else {
            t -> r = createTree(word);
        }
    }

}

int wordsQuantity(tree * t) {

    int quantity = 1;
    if(!emptyTree(t -> l)) quantity += wordsQuantity(t -> l);
    if(!emptyTree(t -> r)) quantity += wordsQuantity(t -> r);

return quantity;
}

int totalWords(tree * t) {
    
    int quantity = getCount(t);
    if(!emptyTree(t -> l)) quantity += totalWords(t -> l);
    if(!emptyTree(t -> r)) quantity += totalWords(t -> r);

return quantity;
}

tree * higherFrequency(tree * t) {

    tree * higherBranch = t;

    if(!emptyTree(t -> l)) {
        tree * hl = higherFrequency(t -> l);
        if(getCount(hl) > getCount(t)) higherBranch = hl;
    }
    if(!emptyTree(t -> r)) {
        tree * hr = higherFrequency(t -> r);
        if(getCount(hr) > getCount(t)) higherBranch = hr;
    }

return higherBranch;
}

void freeTree(tree * t) {

    if(!emptyTree(t -> l)) freeTree(t -> l);
    if(!emptyTree(t -> r)) freeTree(t -> r);
    free(t -> word);
    free(t);

}

int compare(const void * x, const void * y) {
    int x_value = ((tree *)x)->count;
    int y_value = ((tree *)y)->count;
    
    return x_value - y_value;
}

void fill(tree * words, int n, int * index, tree * t) {

    words[*index] = *t;
    if(!emptyTree(t -> l)) {
        (*index)++;
        fill(words, n, index, t -> l);
    }
    if(!emptyTree(t -> r)) {
        (*index)++;
        fill(words, n, index, t -> r);
    }

}

void stats(FILE * f) {

    char word[64];
    fscanf(f, "%s", word);
    tree * twords = createTree(word);

    while(fscanf(f, "%s", word) == 1) {
        searchWord(twords, word);
    }
    int n = wordsQuantity(twords);
    int total = totalWords(twords);
    tree * higherFrequencyBranch = higherFrequency(twords);
    int hcount = getCount(higherFrequencyBranch);
    char * hword = getWord(higherFrequencyBranch);

    printf("DADOS:\n");
    printf("Número de palavras distintas: %d\n", n);
    printf("Número total de palavras: %d\n", total);
    printf("Palavra mais repetida: '%s' (contagem: %d)\n", hword, hcount);

    tree words[n];
    int index = 0;
    fill(words, n, &index, twords);
    qsort(words, n, sizeof(tree), compare);

    FILE * exitf = fopen("saida.txt", "w");
    for(int i = 0; i < n; i++) {
        fprintf(exitf, "%s %d\n", getWord(&words[i]), getCount(&words[i]));
    }

    fprintf(exitf, "\n------------------------\n");
    fprintf(exitf, "%d palavras distintas encontradas\n", n); 
    fprintf(exitf, "%d palavras no total\n", total); 
    fprintf(exitf, "%s é a palavra de maior frequência (%d)\n", hword, hcount);

    fclose(exitf);

    freeTree(twords);

}