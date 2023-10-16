#include <stdio.h>

int calcularPotencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    } else {
        return base * calcularPotencia(base, expoente - 1);
    }
}

int main() {
    int base, expoente, resultado;

    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    if (expoente < 0) {
        printf("O expoente deve ser um número não negativo.\n");
        return 1;
    }

    resultado = calcularPotencia(base, expoente);
    printf("%d elevado a %d e igual a %d\n", base, expoente, resultado);

    return 0;
}