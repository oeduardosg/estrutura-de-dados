#include <stdlib.h>
#include <stdio.h>
#include "itemType.h"

struct itemType{
    int quantity;
    productType * product;
};

itemType * createItem(productType * product, int quantity) {

    itemType * item = (itemType *) malloc(sizeof(itemType));
    
    item -> quantity = quantity;
    item -> product = product;

return item;
}

void freeItem(itemType * item) {

    free(item);

}

void printItem(itemType * item) {

    printProduct(item -> product);
    printf(", quantidade: %d\n", item -> quantity);

}

productType * getProduct(itemType * item) {
return item -> product;
}

int getItemQuantity(itemType * item) {
return item -> quantity;
}