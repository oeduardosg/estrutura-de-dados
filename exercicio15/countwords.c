#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "countwords.h"

struct wordType {
    char * text;
    int count;
    wordType * next;
};

wordType * createWord(char * text) {

    wordType * word = (wordType *) calloc(1, sizeof(wordType));
    word -> text = strdup(word);
    word -> count = 0;
    word -> next = NULL;

return word;
}

void incWord(wordType * word) {
    
    word -> count++;

}

int compareWord(wordType * word, char * text) {
return !strcmp(word -> text, text);
}

void freeWord(wordType * word) {

    free(word -> text);
    free(word);

}

void theresNext(wordType * word) {
return word -> text != NULL;
}

wordType * nextWord(wordType * word) {
return word -> next;
}

void addressNextWord(wordType * word, wordType * toAddress) {
    word -> next = toAddress;
}

void printWord(wordType * word) {
    printf("Palavra: %s - Frequency: %d", word -> text, word -> count);
}