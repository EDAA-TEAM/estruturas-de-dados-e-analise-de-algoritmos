#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct tipo_pilhacircular {
    int vet[TAM];
    int topo;
};

typedef struct tipo_pilhacircular pilhacircular;

// Cria pilha.
void CriarPilha(pilhacircular *p) {
    (*p).topo = -1;
}

// Verifica se a pilha está vazia.
int PilhaVazia(pilhacircular *p) {
    return ((*p).topo == -1);
}

// Verifica se a pilha está cheia.
int PilhaCheia(pilhacircular *p) {
    return (((*p).topo == TAM - 1) && ((*p).vet[0] != -1)) || (((*p).topo == TAM - 2) && ((*p).vet[TAM - 1] != -1));
}

// Insere um elemento na pilha.
void Empilhar(pilhacircular *p, int e) {
    if (PilhaCheia(p)) {
        if ((*p).topo == TAM - 1) {
            (*p).topo = 0;
        } else {
            (*p).topo++;
        }
    } else {
        (*p).topo++;
    }
    (*p).vet[(*p).topo] = e;
}

// Retira um elemento na pilha.
int Desempilhar(pilhacircular *p) {
    int temp;
    if (PilhaVazia(p)) {
        printf("A pilha esta vazia. Nao e possivel desempilhar.\n");
        return -1; 
    } else {
        temp = (*p).vet[(*p).topo];
        (*p).vet[(*p).topo] = -1; 
        if ((*p).topo == 0) {
            (*p).topo = TAM - 1;
        } else {
            (*p).topo--;
        }
        return temp;
    }
}

