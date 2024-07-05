#ifndef _student_h_
#define _student_h_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct studentType studentType;

studentType * createStudent();

void printStudent(studentType * student);

void freeStudent(void * data);

char * getStudentName(studentType * student);

int getStudentRgNum(studentType * student);

int compareStudents(studentType  * student, int rgNum);

#endif