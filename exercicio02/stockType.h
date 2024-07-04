#ifndef _STOCKTYPE_H_
#define _STOCKTYPE_H_

#include "productType.h"

typedef struct stockType stockType;

stockType * createStock(productType ** products, int itemsQuantity);

void freeStock(stockType * stock);

void printStock(stockType * stock);

float getStockValue(stockType * stock);

#endif