#ifndef _student_h_
#define _student_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student student;

student * create_student(char * register_num, char * name);

int hash_student(void * v, int size);

int compare_student(void * v1, void * v2);

void print_student(student * s);

void free_student(student * s);

#endif