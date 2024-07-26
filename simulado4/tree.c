#include "tree.h"

struct tree {
    char * word;
    int count;
    int key;
    tree * l;
    tree * r;
};

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

void freeTree(tree * t) {

    if(!emptyTree(t -> l)) freeTree(t -> l);
    if(!emptyTree(t -> r)) freeTree(t -> r);
    free(t -> word);
    free(t);

}

void stats(tree * t);