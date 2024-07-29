#include "product.h"

struct product {
    int barcode;
    char * color;
};

product * create_product(int barcode, char * color) {

    product * p = (product *) calloc(1, sizeof(product));
    p -> barcode = barcode;
    p -> color = strdup(color);

return p;
}

int hash_product(void * v, int size) {

    product * p = (product *)v;

return p -> barcode % size;
}

int compare_product(void * v1, void * v2) {

    product * p1 = (product *)v1;
    product * p2 = (product *)v2;

return (p1 -> barcode == p2 -> barcode) && (!strcmp(p1 -> color, p2 -> color));
}

void print_product(product * p) {
    printf("Product barcode: %d\n", p -> barcode);
    printf("Product color: %s\n\n", p -> color);
}

void free_product(product * p) {
    free(p -> color);
    free(p);
}