#include "items.h"

struct itemType {
    char * name;
    int barcode;
};

itemType * createItem(char * name, int barcode) {

    itemType * item = (itemType *) calloc(1, sizeof(itemType));
    item -> name = strdup(name);
    item -> barcode = barcode;

return item;
}

void printItem(itemType * item) {

    printf("%10s - %05d\n", item -> name, item -> barcode);

}

void freeItem(void * data) {

    itemType * item = (itemType *)data;
    free(item -> name);
    free(item);

}

char * getItemName(itemType * item) {
    return item -> name;
}

int getBarcode(itemType * item) {
    return item -> barcode;
}

int compareBarcode(itemType  * item, int barcode) {
    return item -> barcode == barcode;
}