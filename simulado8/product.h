#ifndef _product_h_
#define _product_h_

typedef struct product product;

product * create_product(int barcode, char * color);

int hash_product(void * p);

int compare_product(void * p1, void * p2);

void free_product(product * p);

#endif