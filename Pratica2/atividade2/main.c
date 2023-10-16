#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
    char cpf[12];
    char nome[50];
    float salario;
};

struct Pessoa *alocarPessoas(int tamanho) {
    struct Pessoa *pessoas = (struct Pessoa *)calloc(tamanho, sizeof(struct Pessoa));
    if (pessoas == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return pessoas;
}

void preencherPessoas(struct Pessoa *pessoas, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o CPF da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].cpf);

        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);

        printf("Digite o salário da pessoa %d: ", i + 1);
        scanf("%f", &pessoas[i].salario);
    }
}

void imprimirPessoas(struct Pessoa *pessoas, int tamanho) {
    printf("Pessoas:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("CPF: %s, Nome: %s, Salário: %.2f\n", pessoas[i].cpf, pessoas[i].nome, pessoas[i].salario);
    }
}

int main() {
    int n;
    printf("Digite o numero de pessoas: ");
    scanf("%d", &n);

    struct Pessoa *pessoas = alocarPessoas(n);

    preencherPessoas(pessoas, n);

    imprimirPessoas(pessoas, n);

    // Liberar a memória alocada com calloc
    free(pessoas);

    return 0;
}