/*
Calcule e mostre a tabuada de multiplicação de um número 
informado pelo usuário no
teclado.
Exemplo:
Informe um número: 7
*/

#include <stdio.h>

int main() {
    int numero;

    printf("Informe um numero: ");
    scanf("%d", &numero);

    printf("Tabuada de %d:\n", numero);
    for (int i = 0; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}