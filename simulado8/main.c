#include <stdio.h>
#include <stdlib.h>
#include "ghash.h"
#include "product.h"
#include "student.h"

int main() {

    ghash * ht1 = create_hash(10);

    product * p1 = create_product(100, "Car");
    product * p2 = create_product(101, "Motor");
    product * p3 = create_product(118, "Wheel");

    insert_hash(ht1, p1, hash_product);
    insert_hash(ht1, p2, hash_product);
    insert_hash(ht1, p3, hash_product);

    print_product(search_hash(ht1, p2, hash_product, compare_product));

    student * s1 = create_student("492", "Car");
    student * s2 = create_student("512", "Motor");
    student * s3 = create_student("845", "Wheel");

    insert_hash(ht1, s1, hash_student);
    insert_hash(ht1, s2, hash_student);
    insert_hash(ht1, s3, hash_student);

    print_student(search_hash(ht1, s3, hash_student, compare_student));

    free_hash(ht1);

return 0;
}