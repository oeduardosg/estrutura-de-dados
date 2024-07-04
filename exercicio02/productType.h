#ifndef _PRODUCTTYPE_H_
#define _PRODUCTTYPE_H_

typedef struct productType productType;

productType * createProduct(char * name, float price);

productType ** createProductsList(int productsQuantity);

void freeProduct(productType * product);

void freeProductsList(productType ** products, int productsQuantity);

void printProduct(productType * product);

char * getProductName(productType * product);

float getProductPrice(productType * product);

#endif