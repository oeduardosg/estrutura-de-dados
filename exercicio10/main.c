#include <stdio.h>
#include "tree.h"
#include "student.h"

int main() {
    
    treeType * tree = createTree(createStudent("Eduardo", 1), 
                    createTree(createStudent("Raony", 2), createEmptyTree(), createTree(createStudent("Aline", 4), 
                    createEmptyTree(), createEmptyTree())), createTree(createStudent("Gabriel", 3), 
                    createTree(createStudent("Aline", 5), createEmptyTree(), createEmptyTree()), createEmptyTree()));

    printf("NAME FREQUENCY: %d\n", frequency(tree, "Aline"));
    printf("TREE HEIGHT: %d\n", height(tree));
    printf("LEAFS QUANTITY: %d\n", leafs(tree));

    freeTree(tree);

return 0;
}
