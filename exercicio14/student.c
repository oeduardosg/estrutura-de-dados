#include "student.h"

struct studentType {
    char * name;
    int rgNum;
};

studentType * createStudent(char * name, int rgNum) {

    studentType * student = (studentType *) calloc(1, sizeof(studentType));
    student -> name = strdup(name);
    student -> rgNum = rgNum;

return student;
}

void printStudent(studentType * student) {

    printf("%10s - %05d\n", student -> name, student -> rgNum);

}

void freeStudent(void * data) {

    studentType * student = (studentType *)data;
    free(student -> name);
    free(student);

}

char * getStudentName(studentType * student) {
    return student -> name;
}

int getStudentRgNum(studentType * student) {
    return student -> rgNum;
}

int compareStudents(studentType  * student, int rgNum) {
    return student -> rgNum == rgNum;
}