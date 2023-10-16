#include <stdio.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAM 10
typedef float elemento;

struct tipo_pilha {
    elemento vet[TAM];
    int topo;
};
typedef struct tipo_pilha pilha;
    //Cria pilha.
    void CriarPilha(pilha *p) {
    (*p).topo = -1;
}

    int PilhaVazia(pilha *p) {
    return((*p).topo == 0);
}

//Verifica se a pilha está cheia.
int PilhaCheia(pilha *p) {
return((*p).topo == TAM);
}
//Insere um elemento na pilha.
void Empilhar(pilha *p, elemento e) {
(*p).vet[(*p).topo] = e;
(*p).topo++;
}
//Retira um elemento na pilha.
elemento Desempilhar(pilha *p) {
    (*p).topo--;
        return (*p).vet[(*p).topo];
}

void ImprimePilha(pilha *p) {
    if (PilhaVazia(p)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Conteúdo da pilha:\n");
        for (int i = 0; i < p->topo; i++) {
            printf("%d ", p->vet[i]); // Supondo que elemento seja do tipo int.
        }
        printf("\n");
    }
}