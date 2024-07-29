#ifndef _product_h_
#define _product_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product product;

product * create_product(int barcode, char * color);

int hash_product(void * p, int size);

int compare_product(void * p1, void * p2);

void print_product(product * p);

void free_product(product * p);

#endif