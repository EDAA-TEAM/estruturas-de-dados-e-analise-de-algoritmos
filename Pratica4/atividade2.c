#include <stdio.h>

int somaNaturais(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + somaNaturais(n - 1); 
    }
}

int main() {
    int n, resultado;

    printf("Digite um valor para n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O valor de n deve ser um numero positivo.\n");
        return 1;
    }

    resultado = somaNaturais(n);
    printf("A soma dos primeiros %d numeros naturais e igual a %d\n", n, resultado);

    return 0;
}
