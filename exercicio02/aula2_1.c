#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productType.h"
#include "marketType.h"

int main() {

    int productsQuantity;
    printf("Quantos produtos serão declarados? ");
    scanf("%d", &productsQuantity);
    scanf("%*c");

    productType ** products = createProductsList(productsQuantity);

    char marketName[100];
    int branchesQuantity = 0;

    printf("Informe o nome do supermercado: ");
    scanf("%99[^\n]s%*c", marketName);
    printf("Informe quantas filiais existem : ");
    scanf("%d%*c", &branchesQuantity);
    marketType * market = createMarket(marketName, branchesQuantity, products, productsQuantity);

    printMarket(market);

    freeProductsList(products, productsQuantity);
    freeMarket(market);

return 0;
}