#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef float elemento;

struct tipo_fila {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;

void CriarFila(fila *f) {
    (*f).inicio = -1;
    (*f).fim = -1;
}

int FilaVazia(fila *f) {
    return ((*f).inicio == (*f).fim);
}

int FilaCheia(fila *f) {
    return ((*f).fim == TAM);
}

void Enfileirar(fila *f, elemento e) {
    if (!FilaCheia(f)) {
        (*f).vet[(*f).fim++] = e;
    }
}

elemento Desenfileirar(fila *f) {
    if (!FilaVazia(f)) {
        return (*f).vet[(*f).inicio++];
    } else {
        return -1; // Indica fila vazia
    }
}

void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("Fila vazia\n");
    } else {
        printf("Conteúdo da fila:\n");
        int i;
        for (i = (*f).inicio; i < (*f).fim; i++) {
            printf("%.2f ", (*f).vet[i]);
        }
        printf("\n");
    }
}

void GravaFilaEmArquivo(fila *f, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo != NULL) {
        while (!FilaVazia(f)) {
            elemento e = Desenfileirar(f);
            fprintf(arquivo, "%.2f\n", e);
        }
        fclose(arquivo);
        printf("Fila gravada no arquivo com sucesso.\n");
    } else {
        printf("Erro ao abrir o arquivo para gravação.\n");
    }
}

void LeFilaDoArquivo(fila *f, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo != NULL) {
        elemento e;
        while (fscanf(arquivo, "%f", &e) == 1) {
            Enfileirar(f, e);
        }
        fclose(arquivo);
        printf("Fila lida do arquivo com sucesso.\n");
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}

int main() {
    fila minha_fila;
    CriarFila(&minha_fila);

    // Leitura da sequência de 10 números reais do teclado
    for (int i = 0; i < TAM; i++) {
        elemento num;
        printf("Digite o número %d: ", i + 1);
        scanf("%f", &num);
        Enfileirar(&minha_fila, num);
    }

    // Impressão da fila
    ImprimeFila(&minha_fila);

    // Gravação da fila em um arquivo de texto
    GravaFilaEmArquivo(&minha_fila, "fila.txt");

    // Limpa a fila
    CriarFila(&minha_fila);

    // Leitura da fila a partir do arquivo de texto
    LeFilaDoArquivo(&minha_fila, "fila.txt");

    // Impressão da fila após a leitura do arquivo
    ImprimeFila(&minha_fila);

    return 0;
}
