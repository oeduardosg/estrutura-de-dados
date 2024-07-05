#include "generictree.h"

struct treeType{
    treeType * left;
    treeType * right;
    void * data;
    void (* print)(void *);
    int (* compare)(void *, int);
    void (* free)(void *);
    int (* get)(void *);
};

treeType * createEmptyTree() {
    return NULL;
}

treeType * createTree(treeType * left, treeType * right, void * data, void (* print)(void *), 
                    int (* compare)(void *, int), void (* free)(void *), int (* get)(void *)) {

    treeType * tree = (treeType *) calloc(1, sizeof(treeType));
    tree -> left = left;
    tree -> right = right;
    tree -> data = data;
    tree -> print = print;
    tree -> compare = compare;
    tree -> free = free;
    tree -> get = get;

return tree;
}

void printTree(treeType * tree) {
    if(emptyTree(tree)) return;

    printTree(tree -> left);

    tree -> print(tree -> data);

    printTree(tree -> right);
}

void freeTree(treeType * tree) {
    
    if(!emptyTree(tree -> right)) freeTree(tree -> right);
    if(!emptyTree(tree -> left)) freeTree(tree -> left);

    printf("Freeing: ");
    tree -> print(tree -> data);
    tree -> free(tree -> data);
    free(tree);

}

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

/*
int frequency(treeType * tree , char * name) { //retorna o número de vezes que o aluno aparece na árvore
    if(!tree) return 0;
    return frequency(tree -> left, name) + frequency(tree -> right, name) + !strcmp(getDataName(tree -> data), name);
}
*/

int height(treeType * tree) { //retorna a altura da árvore

    int heightLeft = 0;
    int heightRight = 0;
    if(!emptyTree(tree -> left)) heightLeft = 1 + height(tree -> left);
    if(!emptyTree(tree -> right)) heightRight = 1 + height(tree -> right);

return heightLeft >= heightRight ? heightLeft: heightRight;
}

void insertData(treeType * tree, void * data, void (* print)(void *), int (* compare)(void *, int), void (* free)(void *), int (* get)(void *)) {

    if(!tree) return;
    if(get(data) < get(tree -> data)) {
        if(!tree -> left) tree -> left = createTree(createEmptyTree(), createEmptyTree(), data,  print, compare, free, get);
        else insertData(tree -> left, data, print, compare, free, get);
    }
    else {
        if(!tree -> right) tree -> right = createTree(createEmptyTree(), createEmptyTree(), data, print, compare, free, get);
        else insertData(tree -> right, data, print, compare, free, get);
    }

}

treeType * mostRight(treeType * tree) {
    if(!emptyTree(tree -> right)) return mostRight(tree -> right);
return tree;
}

void removeData(treeType * tree, int searchKey) {

    if(!tree) return;
    if(tree -> get(tree -> data) != searchKey) {
        if(searchKey < tree -> get(tree -> data)) removeData(tree -> left, searchKey);
        else removeData(tree -> right, searchKey);
        return;
    }
    else {
        treeType * righter = mostRight(tree -> left);
        void * swapData = righter -> data;
        void * auxData = tree -> data;
        tree -> data = swapData;
        righter -> data = auxData;

        tree -> free(righter -> data);
        free(righter);
    }
    
}

void search(treeType * tree, int searchKey) {

    if(emptyTree(tree)) return;

    if(tree -> compare(tree -> data, searchKey)) {

        printf("This data was found inside the binary tree according to the search key of value %d:\n", searchKey);
        tree -> print(tree -> data);

    }
    else {
        if(searchKey > tree -> get(tree -> data)) search(tree -> right, searchKey);
        else search(tree -> left, searchKey);
    }

return;
}
