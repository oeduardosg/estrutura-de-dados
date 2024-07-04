#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "productType.h"

struct productType{
    char * name;
    float price;
};

productType * createProduct(char * name, float price) {

    productType * product = (productType *) malloc(sizeof(productType));

    product -> name = strdup(name);
    product -> price = price;

return product;
}

productType ** createProductsList(int productsQuantity) {

    productType ** products = (productType **) malloc(productsQuantity * sizeof(productType *));

    char productName[100];
    float price = 0;

    printf("- CADASTRO DE PRODUTOS -\n");
    for(int i = 0; i < productsQuantity; i++) {
        printf("Nome do produto [%d]: ", i);
        scanf("%99[^\n]s%*c", productName);
        printf("Preço do produto [%d]: ", i);
        scanf("%f%*c", &price);
        products[i] = createProduct(productName, price);
    }

return products;
}

void freeProduct(productType * product) {

    free(product -> name);
    free(product);

}

void freeProductsList(productType ** products, int productsQuantity) {

    for(int i = 0; i < productsQuantity; i++) {
        freeProduct(products[i]);
    }
    free(products);
}

void printProduct(productType * product) {

    printf("\t\tItem: %s, valor unitário: %.2f", product -> name, product -> price);

}

char * getProductName(productType * product) {
return product -> name;
}

float getProductPrice(productType * product) {
return product -> price;
}