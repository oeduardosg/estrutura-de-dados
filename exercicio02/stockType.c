#include <stdlib.h>
#include <stdio.h>
#include "itemType.h"
#include "stockType.h"

struct stockType{
    float quantity;
    itemType ** items;
    int itemsQuantity;
};

stockType * createStock(productType ** products, int itemsQuantity) {

    stockType * stock = (stockType *) malloc(sizeof(stockType));
    
    stock -> quantity = 0;
    stock -> itemsQuantity = itemsQuantity;
    stock -> items = (itemType **) malloc(itemsQuantity * sizeof(itemType *));

    int productQuantity = 0;

    for(int i = 0; i < itemsQuantity; i++) {
        printf("Qual a quantidade disponível do produto %s? ", getProductName(products[i]));
        scanf("%d%*c", &productQuantity);
        stock -> items[i] = createItem(products[i], productQuantity);
        stock -> quantity += getProductPrice(products[i]) * productQuantity;
    }

return stock;
}

void freeStock(stockType * stock) {

    for(int i = 0; i < stock -> itemsQuantity; i++) {
        freeItem(stock -> items[i]);
    }
    free(stock -> items);
    free(stock);

}

void printStock(stockType * stock) {

    printf("\tEstoque: %.2f\n", stock -> quantity);
    for(int i = 0; i < stock -> itemsQuantity; i++) {
        printItem(stock -> items[i]);
    }

}

float getStockValue(stockType * stock) {
return stock -> quantity;
}