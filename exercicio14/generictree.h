#ifndef generictree_c
#define generictree_c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeType treeType;

treeType * createEmptyTree();

treeType * createTree(treeType * left, treeType * right, void * data, void (* print)(void *), 
                    int (* compare)(void *, int), void (* free)(void *), int (* get)(void *));

void printTree(treeType * tree);

int compareTree(treeType * tree, void * data);

void freeTree(treeType * tree);

int emptyTree(treeType * tree);

int isLeaf(treeType * tree);

int leafs(treeType * tree);

int frequency(treeType * tree , char * name);

int height(treeType * tree);

void insertData(treeType * tree, void * data, void (* print)(void *), int (* compare)(void *, int), void (* free)(void *), int (* get)(void *));

treeType * mostRight(treeType * tree);

void removeData(treeType * tree, int searchKey);

void search(treeType * tree, int searchKey);

#endif