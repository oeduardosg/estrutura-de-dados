#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "product.h"

struct productType{

    char * name;
    float price;
    char * barcode;

};

productType * createProduct(char * name, float price, char * barcode) {

    productType * product = (productType *) malloc(sizeof(productType));

    product -> name = strdup(name);
    product -> price = price;
    product -> barcode = strdup(barcode);

return product;
}

char * getProductName(productType * product) {
return product -> name;
}

char * getProductBarcode(productType * product) {
return product -> barcode;
}

void freeProduct(productType * product) {

    free(product -> name);
    free(product -> barcode);
    free(product);

}

void printProduct(productType * product) {

    printf("Nome: %s, valor unitário: %.2f\n", product -> name, product -> price);

}

void printProductName(productType * product) {

    printf("%s", product -> name);

}
