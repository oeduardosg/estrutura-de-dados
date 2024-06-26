#include "tree.h"

struct treeType {
    studentType * student;
    treeType * left;
    treeType * right;    
};

treeType * createEmptyTree() {
    return NULL;
}

treeType * createTree(studentType * student, treeType * left, treeType * right) {

    treeType * tree = (treeType *) calloc(1, sizeof(treeType));
    tree -> student = student;
    tree -> left = left;
    tree -> right = right;

return tree;
}

void printTree(treeType * tree) {

    printStudent(tree -> student);
    if(tree -> left) printTree(tree -> left);
    if(tree -> right) printTree(tree -> right);

}

void freeTree(treeType * tree) {

    if(tree -> right) freeTree(tree -> right);
    if(tree -> left) freeTree(tree -> left);
    freeStudent(tree -> student);
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

int frequency(treeType * tree , char * name) { //retorna o número de vezes que o aluno aparece na árvore
    if(!tree) return 0;
    return frequency(tree -> left, name) + frequency(tree -> right, name) + !strcmp(getStudentName(tree -> student), name);
}

int height(treeType * tree) { //retorna a altura da árvore

    int heightLeft = 0;
    int heightRight = 0;
    if(!emptyTree(tree -> left)) heightLeft = 1 + height(tree -> left);
    if(!emptyTree(tree -> right)) heightRight = 1 + height(tree -> right);

return heightLeft >= heightRight ? heightLeft: heightRight;
}

void insertStudent(treeType * tree, studentType * student) {

    if(!tree) return 0;
    if(getRgNum(student) < getRgNum(tree -> student)) {
        if(!tree -> left) createTree(student, createEmptyTree(), createEmptyTree());
        else insertStudent(tree -> left, student);
    }
    else {
        if(!tree -> right) createTree(student, createEmptyTree(), createEmptyTree());
        else insertStudent(tree -> right, student);
    }

}

treeType * mostRight(treeType * tree) {
    if(!emptyTree(tree -> right)) return mostRight(tree -> right);
return tree -> right;
}

studentType * removeStudentByRgNum(treeType * tree, int rgNum) {

    if(!tree) return 0;
    if(getRgNum(tree -> student) != rgNum) {
        if(rgNum < getRgNum(tree -> student)) return removeStudentByRgNum(tree -> left, rgNum);
        else return removeStudentByRgNum(tree -> right, rgNum);
    }

    //Repensar isso de swaptree pois está erradíssimo!!!!!
    treeType * swapTree = createStudent(getStudentName(tree -> student), getRgNum(tree -> student));

    if(!emptyTree(tree -> right)) {
        swapTree = mostRight(tree -> right);
    }
    else swapTree -> student = tree;
    
return tree -> student;
}
