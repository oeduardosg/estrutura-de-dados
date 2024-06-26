#ifndef _tree_h_
#define _tree_h_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "student.h"

typedef struct treeType treeType;

treeType * createEmptyTree();

treeType * createTree();

void printTree(treeType * tree);

void freeTree(treeType * tree);

int leafs(treeType * tree); //retorna o número de folhas da árvore

int frequency(treeType* tree , char* name); //retorna o número de vezes que o aluno aparece na árvore

int height(treeType * tree); //retorna a altura da árvore

void insertStudent(treeType * tree, studentType * student);

studentType * removeStudentByRgNum(treeType * tree, int rgNum);

#endif