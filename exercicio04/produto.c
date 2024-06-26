#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produto.h"

struct produtoType{

    char * name;
    float price;
    char * barcode;

};

produtoType * createProduct(char * name, float price, char * barcode) {

    produtoType * product = (produtoType *) malloc(sizeof(produtoType));

    product -> name = strdup(name);
    product -> price = price;
    product -> barcode = strdup(barcode);

return product;
}

char * getProductName(produtoType * product) {
return product -> name;
}

char * getProductBarcode(produtoType * product) {
return product -> barcode;
}

void freeProduct(produtoType * product) {

    free(product -> name);
    free(product -> barcode);
    free(product);

}

void printProduct(produtoType * product) {

    printf("Nome: %s, valor unitário: %.2f\n", product -> name, product -> price);

}

void printProductName(produtoType * product) {

    printf("%s", product -> name);

}
