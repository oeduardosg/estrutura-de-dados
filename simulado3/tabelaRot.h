#ifndef _tabelaRot_h_
#define _tabelaRot_h_

typedef struct nextHop nextHop;

typedef struct hashTab hashTab;

hashTab * createHash(int size);

nextHop * createNextHop(char * name, char * dest);

char * getDest(nextHop * nh);

nextHop * getNext(nextHop * nh);

void setNext(nextHop * nh, nextHop * next_nh);

void freeNextHop(nextHop * nh);

void insert(hashTab * ht, nextHop * nh);

void search(hashTab * ht, char * dest);

void freeHash(hashTab * hash);

#endif