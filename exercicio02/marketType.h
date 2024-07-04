#ifndef _MARKETTYPE_H_
#define _MARKETTYPE_H_

typedef struct marketType marketType;

marketType * createMarket(char * name, int branchesQuantity, productType ** products, int productsQuantity);

void freeMarket(marketType * market);

void printMarket(marketType * market);

#endif