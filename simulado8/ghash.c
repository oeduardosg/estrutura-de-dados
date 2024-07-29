#include "ghash.h"

typedef struct cell cell;

struct cell {
    void * object;
    cell * next;
};

cell * create_cell(void * object) {

    cell * c = (cell *) calloc(1, sizeof(cell));
    c -> object = object;
    c -> next = NULL;

return c;
}

void * get_object(cell * c) {
return c -> object;
}

cell * get_next(cell * c) {
return c -> next;
}

void set_next(cell * c, cell * n) {
    c -> next = n;
}

void free_cell(cell * c) {
    if(!c) return;
    if(c -> next) free_cell(c -> next);
    free(c);
}

struct ghash {
    cell ** table;
    int size;
};

ghash * create_hash(int size) {

    ghash * ht = (ghash *) calloc(1, sizeof(ghash));
    ht -> table = (cell **) calloc(size, sizeof(cell *));
    ht -> size = size;

return ht;
}

void insert_hash(ghash * ht, void * object, int (*hash_it)(void *, int)) {

    int index = hash_it(object, ht -> size);
    
    if(!ht -> table[index]) ht -> table[index] = create_cell(object);
    else {
        cell * nc = create_cell(object);
        set_next(nc , ht -> table[index]);
        ht -> table[index] = nc;
    }

}

void * search_hash(ghash * ht, void * object, int (*hash_it)(void *, int), int (*compare)(void *, void *)) {

    int index = hash_it(object, ht -> size);

    if(!ht -> table[index]) printf("No object of index %d exists in the hash table.\n", index);
    else {
        cell * runner = ht -> table[index];
        while(runner) {
            if(compare(object, get_object(runner))) return get_object(runner);
            runner = get_next(runner);
        }
    }
    printf("The object was not found in the hash table.\n");

return NULL;
}

void free_hash(ghash * ht) {

    for(int i = 0; i < ht -> size; i++) {
        if(ht -> table[i]) {
            free_cell(ht -> table[i]);
        }
    }
    free(ht -> table);
    free(ht);
    
}


