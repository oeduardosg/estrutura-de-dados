#ifndef _PRODUTO_H_
#define _PRODUTO_H_

typedef struct produtoType produtoType;

produtoType * createProduct(char * name, float price, char * barcode);

char * getProductName(produtoType * product);

char * getProductBarcode(produtoType * product);

void freeProduct(produtoType * product);

void printProduct(produtoType * product);

void printProductName(produtoType * product);

#endif