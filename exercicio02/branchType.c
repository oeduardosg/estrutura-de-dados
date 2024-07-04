#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stockType.h"
#include "branchType.h"


struct branchType{
    char * name;
    stockType * stock;
};

branchType * createBranch(char * name, productType ** products, int productsQuantity) {

    branchType * branch = (branchType *) malloc(sizeof(branchType));

    branch -> name = strdup(name);
    branch -> stock = createStock(products, productsQuantity);

return branch;
}

void freeBranch(branchType * branch) {
    free(branch -> name);
    freeStock(branch -> stock);
    free(branch);
}

void printBranch(branchType * branch) {
    printf("\tFilial: %s\n", branch -> name);
    printStock(branch -> stock);
}

float getBranchStockValue(branchType * branch) {
return getStockValue(branch -> stock);
}