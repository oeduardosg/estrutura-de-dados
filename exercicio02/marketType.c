#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "branchType.h"
#include "productType.h"
#include "marketType.h"

struct marketType{
    char * name;
    branchType ** branches;
    int branchesQuantity;
};

marketType * createMarket(char * name, int branchesQuantity, productType ** products, int productsQuantity) {

    marketType * market = (marketType *) malloc(sizeof(marketType));
    
    market -> name = strdup(name);
    market -> branchesQuantity = branchesQuantity;
    market -> branches = (branchType **) malloc(branchesQuantity * sizeof(branchType *));

    //Criando filiais
    char branchName[100];

    for(int i = 0; i < branchesQuantity; i++) {
        printf("Qual é o nome da filial? ");
        scanf("%99[^\n]s%*c", branchName);
        market -> branches[i] = createBranch(branchName, products, productsQuantity);
    }

return market;
}

void freeMarket(marketType * market) {

    free(market -> name);
    for(int i = 0; i < market -> branchesQuantity; i++) {
        freeBranch(market -> branches[i]);
    }
    free(market -> branches);
    free(market);

}

float getTotalStockValue(marketType * market) {
    float totalStockValue = 0;
    
    for(int i = 0; i < market -> branchesQuantity; i++) {
        totalStockValue += getBranchStockValue(market -> branches[i]);
    }

return totalStockValue;
}

void printMarket(marketType * market) {
    printf("Nome: %s, Estoque Total: %.2f\n", market -> name, getTotalStockValue(market));
    for(int i = 0; i < market -> branchesQuantity; i++) {
        printBranch(market -> branches[i]);
    }
}