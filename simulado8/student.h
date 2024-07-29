#ifndef _student_h_
#define _student_h_

typedef struct student student;

student * create_student(int register_num, char * name);

int hash_student(void * s);

int compare_student(void * s1, void * s2);

void free_student(student * s);

#endif