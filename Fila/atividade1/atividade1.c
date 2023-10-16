#include <stdio.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAM 10

typedef float elemento;

struct tipo_fila {
elemento vet[TAM];
int inicio, fim;
};
typedef struct tipo_fila fila;
//Cria fila.
void CriarFila(fila *f) {
(*f).inicio = -1;
(*f).fim = -1;
}
//Verifica se a fila está vazia.
int FilaVazia(fila *f) {
return((*f).inicio == (*f).fim);
}
//Verifica se a fila está cheia.
int FilaCheia(fila *f) {
return((*f).fim == TAM);
}
//Insere um elemento na fila.
void Enfileirar(fila *f, elemento e) {
(*f).vet[(*f).fim++] = e;
}
//Retira um elemento na fila.
elemento Desenfileirar(fila *f) {
return((*f).vet[(*f).inicio++]);
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