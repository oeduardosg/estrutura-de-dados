#include <stdio.h>
#include "sortnsearch.h"

int main() {

    int array[5] = {5, 2, 4, 3, 1};

    quick_sort(array, 5);
    int found = binary_search(array, 0, 5, 5);

    printf("I found %d\n", found);

return 0;
}