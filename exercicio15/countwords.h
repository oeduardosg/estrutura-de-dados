#ifndef countwords_h
#define countwords_h

typedef struct wordType wordType;

wordType * createWord(char * word);

void incWord(wordType * word);

int compareWord(wordType * word, char * text);

void freeWord(wordType * word);

void theresNext(wordType * word);

wordType * nextWord(wordType * word);

void addressNextWord(wordType * word, wordType * toAddress);

void printWord(wordType * word);

#endif