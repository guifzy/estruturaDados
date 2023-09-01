#include <stdio.h>

double potencia(double num, int pot) {
    if (pot == 0) 
    {
        return 1;
    } else
    {
        return num * potencia(num, pot - 1);
    }
}

int main() {
    double base;
    int expoente;

    printf("Digite a base: ");
    scanf("%lf", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    double resultado = potencia(base, expoente);
    printf("%.2lf elevado a %d = %.2lf\n", base, expoente, resultado);

    return 0;
}
