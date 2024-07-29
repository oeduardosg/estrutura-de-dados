#ifndef _ghash_h_
#define _ghash_h_

#include <stdio.h>
#include <stdlib.h>

typedef struct ghash ghash;

ghash * create_hash(int size);

void insert_hash(ghash * ht, void * object, int (*hash_it)(void *, int));

void * search_hash(ghash * ht, void * object, int (*hash_it)(void *, int), int (*compare)(void *, void *));

void free_hash(ghash * ht);

#endif


