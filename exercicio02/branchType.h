#ifndef _BRANCHTYPE_H_
#define _BRANCHTYPE_H_

#include "productType.h"

typedef struct branchType branchType;

branchType * createBranch(char * name, productType ** products, int productsQuantity);

void freeBranch(branchType * branch);

void printBranch(branchType * branch);

float getBranchStockValue(branchType * branch);

#endif