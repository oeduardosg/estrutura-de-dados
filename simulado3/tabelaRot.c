#include "tabelaRot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nextHop {
    char * name;
    char * dest;
    nextHop * next;
};

struct hashTab {
    nextHop ** tab;
    int size;
};

nextHop * createNextHop(char * name, char * dest) {

    nextHop * nh = (nextHop *) calloc(1, sizeof(nextHop));
    nh -> name = strdup(name);
    nh -> dest = strdup(dest);
    nh -> next = NULL;

return nh;
}

char * getDest(nextHop * nh) {
return nh -> dest;
}

nextHop * getNext(nextHop * nh) {
return nh -> next;
}

void setNext(nextHop * nh, nextHop * next_nh) {
    nh -> next = next_nh;
}

void freeNextHop(nextHop * nh) {
    free(nh -> name);
    free(nh -> dest);
    free(nh);
}

int hashString(char * dest) {

    char c = dest[0];
    int value = 0, i = 0;

    while(c != '\0') {
        value += (int)c;
        c = dest[i];
        i++;
    }

return value % 17;
}

hashTab * createHash(int size) {

    hashTab * hash_table = (hashTab *) calloc(1, sizeof(hashTab));
    hash_table -> tab = (nextHop **) calloc(size, sizeof(nextHop *));
    hash_table -> size = size;

return hash_table;
}

void insert(hashTab * ht, nextHop * nh) {

    int index = hashString(getDest(nh));
    if(ht -> tab[index]) {
        setNext(nh, ht -> tab[index]);
        ht -> tab[index] = nh;
    }
    else {
        ht -> tab[index] = nh;
    }

}

void search(hashTab * ht, char * dest) {

    int index = hashString(dest);
    
    if(!ht -> tab[index]) {
        printf("THE DESTINATION %s ISN'T AVAILABLE IN THE HASHTABLE.\n", dest);
        return;
    }

    if(!strcmp(dest, getDest(ht -> tab[index]))) {
        printf("FOUND A NEXTHOP FOR DESTINATION %s", dest);
        return;
    }
    else {

        nextHop * nh = ht -> tab[index];

        while(nh) {
            if(!strcmp(dest, getDest(ht -> tab[index]))) {
                printf("FOUND A NEXTHOP FOR DESTINATION %s", dest);
                return;
            }
            nh = getNext(nh);
        }

        printf("THE DESTINATION %s ISN'T AVAILABLE IN THE HASHTABLE.\n", dest);
        return;

    }

}

void freeHash(hashTab * hash) {

    for(int i = 0; i < hash -> size; i++) {
        free(hash -> tab[i]);
    }
    free(hash);

}