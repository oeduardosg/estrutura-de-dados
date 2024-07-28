#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char ** argv) {

    FILE * f = fopen("entrada.txt", "r");

    int classes_qtt = 0;
    fscanf(f, "N %d", &classes_qtt);

    char name[32];
    hash * table = create_hash(100);

    while(fscanf(f, "%s", name) == 1) {
        insert_hash(table, name);
    }

    fclose(f);

    for(int i = 1; i <= classes_qtt; i++) {
        char file_name[32];
        sprintf(file_name, "entrada%d.txt", i);
        FILE * class_file = fopen(file_name, "r");
        if(!class_file) exit(1);
        char presence = 0;

        while(fscanf(class_file, "%s  %c", name, &presence) == 2) {
            if(presence == 'P') find_hash(table, name);
        }

        fclose(class_file);
    }

    create_file(table, classes_qtt);

    free_hash(table);

return 0;
}