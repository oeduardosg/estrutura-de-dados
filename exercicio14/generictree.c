#include <stdio.h>
#include <stdlib.h>

typedef struct treeType treeType;

struct treeType{
    treeType * left;
    treeType * right;
    void * data;
    void (* print)(void *);
    int (* compare)(void *, void *);
};

treeType * createEmptyTree() {
    return NULL;
}

treeType * createTree(treeType * left, treeType * right, void * data, void (* print)(void *), int (* compare)(void *, void *)) {

    treeType * tree = (treeType *) calloc(1, sizeof(treeType));
    tree -> left = left;
    tree -> right = right;
    tree -> data = data;
    tree -> print = print;
    tree -> compare = compare;

return tree;
}

void printTree(treeType * tree) {
    if(emptyTree(tree)) return;

    printTree(tree -> left);

    tree -> print(tree -> data);

    printTree(tree -> right);
}

int compareTree(treeType * tree, void * data) {
    return tree -> compare(tree -> data, data);
}

/*
void freeTree(treeType * tree) {

    if(tree -> right) freeTree(tree -> right);
    if(tree -> left) freeTree(tree -> left);
    freedata(tree -> data);
    free(tree);

}
*/

int emptyTree(treeType * tree) {
    return tree == NULL;
}

int isLeaf(treeType * tree) {
    if(!tree) return 0;
    return emptyTree(tree -> left) && emptyTree(tree -> right);
}

int leafs(treeType * tree) { //retorna o número de folhas da árvore

    if(emptyTree(tree)) return 0;
    if(isLeaf(tree)) {
        return 1;
    }
    else {
        return leafs(tree -> left) + leafs(tree -> right);
    }

}

int frequency(treeType * tree , char * name) { //retorna o número de vezes que o aluno aparece na árvore
    if(!tree) return 0;
    return frequency(tree -> left, name) + frequency(tree -> right, name) + !strcmp(getdataName(tree -> data), name);
}

int height(treeType * tree) { //retorna a altura da árvore

    int heightLeft = 0;
    int heightRight = 0;
    if(!emptyTree(tree -> left)) heightLeft = 1 + height(tree -> left);
    if(!emptyTree(tree -> right)) heightRight = 1 + height(tree -> right);

return heightLeft >= heightRight ? heightLeft: heightRight;
}

void insertData(treeType * tree, void * data, void (* print)(void *), int (* compare)(void *, void *)) {

    if(!tree) return 0;
    if(getRgNum(data) < getRgNum(tree -> data)) {
        if(!tree -> left) createTree(data, createEmptyTree(), createEmptyTree(), print, compare);
        else insertData(tree -> left, data, print, compare);
    }
    else {
        if(!tree -> right) createTree(data, createEmptyTree(), createEmptyTree(), print, compare);
        else insertData(tree -> right, data, print, compare);
    }

}

treeType * mostRight(treeType * tree) {
    if(!emptyTree(tree -> right)) return mostRight(tree -> right);
return tree;
}

void * removeData(treeType * tree, void * data) {

    //Os datas comparados não fazem sentido! Adicionar a função de compare.

    if(!tree) return;
    if(getRgNum(tree -> data) != data) {
        if(data < getRgNum(tree -> data)) removeData(tree -> left, data);
        else removeData(tree -> right, data);
        return;
    }

    treeType * righter = mostRight(tree -> left);
    void * swapData = righter -> data;
    void * auxData = tree -> data;
    tree -> data = swapData;
    righter -> data = auxData;

    
return tree -> data;
}


