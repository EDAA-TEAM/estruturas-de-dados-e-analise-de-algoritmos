#include <stdio.h>
#include <stdlib.h>
#define TAM 5
typedef int elemento;
#include "pilha.h"

int main() {
    int num, resto;
    pilha p;
    CriarPilha(&p);

    printf("\nInforme um numero inteiro: ");
    scanf("%d", &num);

    int bits_processados = 0; // Variável para contar os bits processados
    int num_original = num;   // Salvar o número original

    while (num != 0 && bits_processados < TAM) {
        resto = num % 2;
        Empilhar(&p, resto);
        num /= 2;
        bits_processados++;
    }

    if (bits_processados < TAM) {
        printf("\nCorrespondente em binario: ");
        while (PilhaVazia(&p) == FALSO) {
            resto = Desempilhar(&p);
            printf("%d", resto);
        }
        printf("\n");
    } else {
        printf("\nA representação binária tem mais de 5 bits.\n");
        printf("Bits mais significativos não processados.\n");
        printf("Representação binária parcial: ");
        while (PilhaVazia(&p) == FALSO) {
            resto = Desempilhar(&p);
            printf("%d", resto);
        }
        printf("\n");
    }

    if (bits_processados < TAM) {
        printf("Valor equivalente em decimal: %d\n", num_original);
    } else {
        printf("Valor equivalente em decimal dos bits processados: %d\n", num_original >> (bits_processados - 1));
    }

    system("pause");
    return 0;
}
