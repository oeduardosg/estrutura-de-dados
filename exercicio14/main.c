#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#include "generictree.h"
#include "items.h"

int main () {

    //Students Tree
    studentType * aline = createStudent("Aline", 20);
    studentType * eduardo = createStudent("Eduardo", 10);
    studentType * gabriel = createStudent("Gabriel", 30);
    studentType * raony = createStudent("Raony", 15);
    studentType * malu = createStudent("Malu", 25);
    studentType * marcela = createStudent("Marcela", 32);
    studentType * tales = createStudent("Tales", 24);

    treeType * tree = createTree(createEmptyTree(), createEmptyTree(), aline, printStudent, compareStudents, freeStudent, getStudentRgNum);
    insertData(tree, eduardo, printStudent, compareStudents, freeStudent, getStudentRgNum);
    insertData(tree, gabriel, printStudent, compareStudents, freeStudent, getStudentRgNum);
    insertData(tree, raony, printStudent, compareStudents, freeStudent, getStudentRgNum);
    insertData(tree, malu, printStudent, compareStudents, freeStudent, getStudentRgNum);
    insertData(tree, marcela, printStudent, compareStudents, freeStudent, getStudentRgNum);

    //Items tree
    itemType * computer = createItem("Computer", 2);
    itemType * smartphone = createItem("Smartphone", 1);
    itemType * headset = createItem("Headset", 3);

    treeType * itemsTree = createTree(createEmptyTree(), createEmptyTree(), computer, printItem, compareBarcode, freeItem, getBarcode);
    insertData(itemsTree, smartphone, printItem, compareBarcode, freeItem, getBarcode);
    insertData(itemsTree, headset, printItem, compareBarcode, freeItem, getBarcode);

    search(tree, 25);
    search(tree, 32);
    search(itemsTree, 2);
    search(itemsTree, 5);
    search(tree, 15);

    freeTree(tree);
    freeTree(itemsTree);
    freeStudent(tales);

return 0;
}