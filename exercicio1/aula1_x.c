#include <stdio.h>
#include <stdlib.h>

int ** inverte2(int n, int * vet) {

    int ** vet2 = (int **) malloc(n * sizeof(int *));

    for(int i = 0; i < n; i++) {
        vet2[i] = &vet[i];
    }

    int * aux;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(*vet2[j] < *vet2[i]) {
                aux = vet2[i];
                vet2[i] = vet2[j];
                vet2[j] = aux;
            }
        }
    }

return vet2;
}

int main() {
    int n;

    printf("Quantos números deseja declarar? ");
    scanf("%d", &n);
    int * vet = (int *) malloc(n * sizeof(int));
    int ** vet2 = (int **) malloc(n * sizeof(int *));

    for(int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    vet2 = inverte2(n, vet);

    printf("O vetor ordenado é dado por [");
    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            printf("%d]", *vet2[i]);
            break;
        }
        printf("%d ", *vet2[i]);
    }

    free(vet);

return 0;
}