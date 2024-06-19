#include "sortnsearch.h"

void bubble_sort(int * array, int size) {

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(array[i] > array[j]) {

               int aux = array[j];
               array[j] = array[i];
               array[i] = aux;

            }
        }
    }

}

//I just copied that function from the material
void quick_sort(int * array, int size) {

    if (size <= 1) return;
    else {
        int x = array[0];
        int a = 1;
        int b = size-1;
        do {
        while (a < size && array[a] <= x) a++;
        while (array[b] > x) b--;
        if (a < b) { /* faz troca */
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
        a++; b--;
        }
        } while (a <= b);

        /* troca piarrayô */
        array[0] = array[b];
        array[b] = x;
        /* ordena sub-arrayetores restantes */
        quick_sort(b,array);
        quick_sort(size-a,&array[a]);
        }

}

int linear_search(int * array, int size, int wanted) {

    for(int i = 0; i < size; i++) {
        if(array[i] == wanted) return i;
    }

return -1;
}

int binary_search(int * array, int beginning, int size, int wanted) {

    int middle = (size + beginning)/2;

    if(size == beginning) return -1;
    if(wanted != array[middle]) {

        if(wanted < array[middle]) return binary_search(array, 0, middle, wanted);
        else return binary_search(array, middle, size, wanted);

    }
    else return middle;

}

void print_array(int * array, int size) {

    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}