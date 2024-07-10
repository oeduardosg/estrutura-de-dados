#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct hash {
    wordType ** tab;
    int size;
};


int hashIt(char * text) {

    int size = strlen(text), string_int_value = text[0];

    for(int i = 0; i < size; i++) {
        string_int_value += text[i];
    }

return string_int_value % 17;
}

hash * createHash(int size) {

    hash * hashTable = (hash *) calloc(1, sizeof(hash));
    hashTable -> tab = (wordType **) calloc(size, sizeof(wordType *));
    hashTable -> size = size;

return hashTable;
}

void insert(hash * hashTable, char * text) {

    int hash_code = hashIt(text);

    if(!hashTable -> tab[hash_code]) {
        hashTable -> tab[hash_code] = createWord(text);
    }
    else {
        wordType * toCompare = hashTable -> tab[hash_code];
        do {
            if(compareWord(toCompare, text)) {
                incWord(toCompare);
                break;
            }
            toCompare = nextWord(toCompare);
            if(!toCompare) {
                wordType * newWord = createWord(text);
                addressNextWord(newWord, hashTable -> tab[hash_code]);
                hashTable -> tab[hash_code] = newWord;
            }
        } while(1);
    }

}

void printHash(hash * hashTable) {

    for(int i = 0; i < hashTable -> size; i++) {
        if(hashTable -> tab[i]) printWord(hashTable -> tab[i]);
    }

}