#ifndef _student_h_
#define _student_h_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct studentType studentType;

studentType * createStudent();

void printStudent(studentType * student);

void freeStudent(studentType * student);

char * getStudentName(studentType * student);

int getRgNum(studentType * student);

#endif