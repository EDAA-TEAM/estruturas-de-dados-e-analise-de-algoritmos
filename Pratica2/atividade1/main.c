#include <stdio.h>
#include <stdlib.h>

int *alocarArray(int tamanho) {
    int *array = (int *)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return array;
}

void preencherArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        array[i] = i * 10;
    }
}

void imprimirArray(int *array, int tamanho) {
    printf("Array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *array, n;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    array = alocarArray(n);

    preencherArray(array, n);

    imprimirArray(array, n);

// Liberar a memória alocada com malloc
    free(array);

    return 0;
}