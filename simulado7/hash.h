#ifndef _hash_h_
#define _hash_h_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash Hash;

Hash * cria(int tam, size_t tam_item);

void * busca(Hash* hash, void* key, int (*fhash)(void*), int (*comp)(void*,void*));

void hash_insere(Hash* thash, void * key, void * objeto, int (*hash)(void*), int(*comp)(void*,void*));

void libera(Hash* table);

void stats(Hash * table);

#endif