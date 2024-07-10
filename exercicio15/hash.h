#ifndef hash_h
#define hash_h

#include "countwords.h"

#define HASH_SIZE 100

typedef struct hash hash;

void insert(hash hashTable, char * text);

void printHash(hash hashTable);

#endif