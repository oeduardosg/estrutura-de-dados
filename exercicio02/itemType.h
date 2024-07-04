#ifndef _ITEMTYPE_H_
#define _ITEMTYPE_H_

#include "productType.h"

typedef struct itemType itemType;

itemType * createItem(productType * product, int quantity);

void freeItem(itemType * item);

void printItem(itemType * item);

productType * getProduct(itemType * item);

int getItemQuantity(itemType * item);

#endif