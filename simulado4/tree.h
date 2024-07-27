#ifndef _tree_h_
#define _tree_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree tree;

tree * createTree(char * word);

int getCount(tree * t);

char * getWord(tree * t);

void searchWord(tree * t, char * word);

int wordsQuantity(tree * t);

int totalWords(tree * t);

tree * higherFrequency(tree * t);

void freeTree(tree * t);

void stats(FILE * f);

#endif