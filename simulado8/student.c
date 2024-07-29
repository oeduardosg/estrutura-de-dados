#include "student.h"

struct student {
    char * name;
    char * register_num;
};

student * create_student(char * register_num, char * name) {

    student * s = (student *) calloc(1, sizeof(student));
    s -> name = strdup(name);
    s -> register_num = strdup(register_num);

return s;
}

int hash_student(void * v, int size) {

    student * s = (student *)v;
    int total = 0;

    for(int i = 0; s -> register_num[i] != '\0'; i++) total += (int)s -> register_num[i];
    
return total % size;
}

int compare_student(void * v1, void * v2) {

    student * s1 = (student *)v1;
    student * s2 = (student *)v2;

return !strcmp(s1 -> register_num, s2 -> register_num);
}

void print_student(student * s) {
    printf("Student barcode: %s\n", s -> name);
    printf("Student color: %s\n\n", s -> register_num);
}

void free_student(student * s) {

    free(s -> name);
    free(s -> register_num);
    free(s);

}