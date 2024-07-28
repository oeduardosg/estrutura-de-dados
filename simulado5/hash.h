#ifndef _hash_h_
#define _hash_h_

#include <stdio.h>
#include <stdlib.h>

typedef struct hash hash;

hash * create_hash(int size);

int hash_it(char * name, int max);

void insert_hash(hash * table, char * name);

void find_hash(hash * table, char * name);

void create_file(hash * table, int classes);

void free_hash(hash * table);

#endif