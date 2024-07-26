#ifndef _tree_h_
#define _tree_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree tree;

tree * createTree(char * word);

void searchWord(tree * t, char * word);

int wordsQuantity(tree * t);

void freeTree(tree * t);

void stats(tree * t);

#endif