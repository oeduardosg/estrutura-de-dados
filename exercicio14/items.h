#ifndef _items_h_
#define _items_h_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct itemType itemType;

itemType * createItem();

void printItem(itemType * item);

void freeItem(void * data);

int getBarcode(itemType * item);

int compareBarcode(itemType  * item, int rgNum);

#endif