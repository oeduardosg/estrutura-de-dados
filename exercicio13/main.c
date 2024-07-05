#include <stdio.h>
#include "tree.h"
#include "student.h"

int main() {

    studentType * aline = createStudent("Aline", 20);
    studentType * eduardo = createStudent("Eduardo", 10);
    studentType * gabriel = createStudent("Gabriel", 30);
    studentType * raony = createStudent("Raony", 15);
    studentType * malu = createStudent("Malu", 16);
    studentType * marcela = createStudent("Marcela", 32);
    studentType * tales = createStudent("Tales", 24);

    treeType * tree = createTree(aline, createEmptyTree(), createEmptyTree());
    insertStudent(tree, eduardo);
    insertStudent(tree, gabriel);
    insertStudent(tree, raony);
    insertStudent(tree, malu);
    insertStudent(tree, marcela);
    insertStudent(tree, tales);

    removeStudentByRgNum(tree, 10);
    freeTree(tree);

return 0;
}
