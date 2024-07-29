#include "words.h"

int hash(void * key) {

    int index = 0;
    char * text = (char *)key;

    for(int i = 0; text[i] != '\0'; i++) index += (int)text[i];

return index % 100;
}

int compare(void * item1, void * item2) {
return !strcmp((char *)item1, (char *)item2);
}