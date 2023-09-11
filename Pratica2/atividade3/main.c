#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct Veiculo {
    char chassi[20];
    char marca[50];
    char modelo[50];
    float preco;
};

struct Veiculo *alocarVeiculos(int tamanho) {
    struct Veiculo *veiculos = (struct Veiculo *)malloc(tamanho * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return veiculos;
}

void preencherVeiculos(struct Veiculo *veiculos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o numero do chassi do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].chassi);
        limparBuffer();

        printf("Digite a marca do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].marca);
        limparBuffer();

        printf("Digite o modelo do veiculo %d: ", i + 1);
        scanf("%s", veiculos[i].modelo);
        limparBuffer();

        printf("Digite o preço do veiculo %d: ", i + 1);
        scanf("%f", &veiculos[i].preco);
        limparBuffer();
    }
}

void imprimirVeiculos(struct Veiculo *veiculos, int tamanho) {
    printf("Veículos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Chassi: %s, Marca: %s, Modelo: %s, Preço: %.2f\n",
               veiculos[i].chassi, veiculos[i].marca, veiculos[i].modelo, veiculos[i].preco);
    }
}

int main() {
    int n;
    printf("Digite o numero inicial de veiculos: ");
    scanf("%d", &n);
    limparBuffer();

    struct Veiculo *veiculos = alocarVeiculos(n);

    preencherVeiculos(veiculos, n);

    imprimirVeiculos(veiculos, n);

    free(veiculos);

    return 0;
}
