#ifndef _PRODUCT_H_
#define _PRODUCT_H_

typedef struct productType productType;

productType * createProduct(char * name, float price, char * barcode);

char * getProductName(productType * product);

char * getProductBarcode(productType * product);

void freeProduct(productType * product);

void printProduct(productType * product);

void printProductName(productType * product);

#endif