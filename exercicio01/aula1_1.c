#include <stdio.h>

int main() {

    int n1 = 1, n2 = 2, n3 = 3, n4 = 4;
    int * p1, * p2, * p3, * p4;
    p1 = &n1;
    p2 = &n2;
    p3 = &n3;
    p4 = &n4;

    *p2 = 22;
    *p3 = 33;
    *p4 = 41;

    printf("n1 = %d\n", n1);
    printf("n2 = %d\n", *p2);
    printf("n1 = %d\n", *p3);
    printf("n2 = %d\n", *p4);

return 0;
}