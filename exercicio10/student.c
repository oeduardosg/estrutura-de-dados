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

    printf("%s - %05d\n", student -> name, student -> rgNum);

}

void freeStudent(studentType * student) {

    free(student -> name);
    free(student);

}

char * getStudentName(studentType * student) {
    return student -> name;
}