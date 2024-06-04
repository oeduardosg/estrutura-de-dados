#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void calc_esfera(float r, float * area, float * volume) {

    *area = 4 * PI * pow(r, 2);
    *volume = (4 * PI * pow(r, 3))/3;

}

int raizes(float a, float b, float c, float * x1, float * x2) {

    float delta = pow(b, 2) - 4 * a * c;
    if(delta < 0) return 0;
    *x1 = (-b + sqrt(delta)) / 2 * a;
    *x2 = (-b - sqrt(delta)) / 2 * a;
    if(x1 == x2) return 1;

return 2;
}

int pares(int n, int * vet) {

    int qtdPares = 0;
    for(int i = 0; i < n; i++) {
        if(!(vet[i]%2)) qtdPares++;
    }

return qtdPares;
}

void inverte(int n, int * vet) {

    int * aux = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        aux[i] = vet[i];
    }

    int j = n - 1;
    for(int i = 0; i < n; i++) {
        vet[i] = aux[j];
        j--;
    }

    free(aux);
}

double avalia(double * poli, int grau, double x) {

    double resultado = 0;

    for(int i = 0; i < grau+1; i++) {
        resultado += poli[i] * pow(x, i);
    }

return resultado;
}

int main() {

    float r = 0, a = 0, b = 0, c = 0, area = 0, volume = 0, x1 = 0, x2 = 0;

    printf("Digite o valor do raio da esfera: ");
    scanf("%f", &r);
    calc_esfera(r, &area, &volume);
    printf("A área da esfera é igual a %.2f e o volume é de %.2f.\n", area, volume);

    int qtdRaizes = 0;
    printf("Digite os coeficientes de uma equação de segundo grau: ");
    scanf("%f %f %f", &a, &b, &c);
    qtdRaizes = raizes(a, b, c, &x1, &x2);
    if (qtdRaizes == 0) {
        printf("Não há raízes reais.\n");
    }
    else if (qtdRaizes == 1) {
        printf("Há uma raiz real em x = %.2f.\n", x1);
    }
    else {
        printf("As raízes reais são x' = %.2f e x'' = %.2f.\n", x1, x2);
    }

    int n;
    printf("Digite a quantidade de números que deseja declarar: ");
    scanf("%d", &n);
    printf("Declare todos os valores desejados: ");
    int * vet = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);

    }
    printf("Há %d par(es) no vetor\n", pares(n, vet));
    printf("O vetor invertido é dado por: ");
    inverte(n, vet);
    for(int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    free(vet);

    int grau;
    double x;
    printf("Digite o grau de um polinômio: ");
    scanf("%d", &grau);
    double * vet2 = (double *) malloc((grau + 1) * sizeof(double));
    printf("Digite os coeficientes do polinômio (%d): ", grau+1);
    for(int i = 0; i < grau+1; i++) {
        scanf("%lf", &vet2[i]);
    }
    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    printf("O resultado da equação é %.2lf", avalia(vet2, grau, x));

    free(vet2);

return 0;
}