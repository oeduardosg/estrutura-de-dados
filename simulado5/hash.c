#include "hash.h"
#include <string.h>

typedef struct person person;

struct person {
    char * name;
    int presence;
    person * next;
};

struct hash {
    person ** list;
    int size;
};

//Person functions

person * create_person(char * name) {
    
    person * student = (person *) calloc(1, sizeof(person));
    student -> name = strdup(name);
    student -> presence = 0;
    student -> next = NULL;

return student;
}

void add_presence(person * student) {
    student -> presence++;
}

int get_presences(person * student) {
return student -> presence;
}

char * get_name(person * student) {
return student -> name;
}

void free_person(person * student) {
    
    if(student -> next) free_person(student -> next);
    free(student -> name);
    free(student);

}

hash * create_hash(int size) {

    hash * table = (hash *) calloc(1, sizeof(hash));
    table -> list = (person **) calloc(size, sizeof(person *));
    table -> size = size;

return table;
}

int hash_it(char * name, int max) {

    int index = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        index += (int)name[i];
    }

return index % max;
}

void insert_hash(hash * table, char * name) {
    
    int index = hash_it(name, table -> size);

    if(!table -> list[index]) {
        person * student = create_person(name);
        table -> list[index] = student;
    }
    else {
        person * student = create_person(name);
        student -> next = table -> list[index];
        table -> list[index] = student;
    }

}

void find_hash(hash * table, char * name) {

    int index = hash_it(name, table -> size);

    if(!table -> list[index]) {
        printf("The student %s is IMPOSSIBLE to exist or to be registered in the hash table.\n", name);
        return;
    }

    person * runner;
    for(runner = table -> list[index]; strcmp(get_name(runner), name) && runner; runner = runner -> next);
    if(runner) add_presence(runner);
    else printf("Student %s was not found.\n", name);

}

void create_file(hash * table, int classes) {

    FILE * exit = fopen("saida.txt", "w");
    for(int i = 0; i < table -> size; i++) {
        if(table -> list[i]) {
            person * runner = table -> list[i];
            while(runner) {
                fprintf(exit, "%s %dP %dF\n", get_name(runner), get_presences(runner), classes - get_presences(runner));
                runner = runner -> next;
            }
        }
    }

    fclose(exit);

}

void free_hash(hash * table) {

    for(int i = 0; i < table -> size; i++) {
        if(table -> list[i]) free_person(table -> list[i]);
    }
    free(table -> list);
    free(table);

}