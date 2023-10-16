#include <stdio.h>
#include <stdlib.h>

#define TAM 10
typedef float elemento; 

struct tipo_pilha {
    elemento vet[TAM];
    int topo;
};
typedef struct tipo_pilha pilha;

void CriarPilha(pilha *p) {
    (*p).topo = -1;
}

// Verifica se a pilha está vazia.
int PilhaVazia(pilha *p) {
    return ((*p).topo == -1);
}

// Verifica se a pilha está cheia.
int PilhaCheia(pilha *p) {
    return ((*p).topo == TAM - 1);
}

// Insere um elemento na pilha.
void Empilhar(pilha *p, elemento e) {
    if (!PilhaCheia(p)) {
        (*p).topo++;
        (*p).vet[(*p).topo] = e;
    } else {
        printf("A pilha esta cheia. Nao e possivel empilhar.\n");
    }
}

// Retira um elemento na pilha.
elemento Desempilhar(pilha *p) {
    if (!PilhaVazia(p)) {
        elemento temp = (*p).vet[(*p).topo];
        (*p).topo--;
        return temp;
    } else {
        printf("A pilha esta vazia. Nao e possivel desempilhar.\n");
        return 0; 
    }
}

// Procedimento para imprimir o conteúdo da pilha.
void ImprimePilha(pilha *p) {
    if (PilhaVazia(p)) {
        printf("A pilha está vazia.\n");
    } else {
        printf("Conteudo da pilha:\n");
        for (int i = 0; i <= p->topo; i++) {
            printf("%.2f\n", p->vet[i]); 
        }
    }
}

// Procedimento para gravar elementos da pilha em um arquivo de texto.
void GravarPilhaEmArquivo(pilha *p, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    if (PilhaVazia(p)) {
        fprintf(arquivo, "Pilha vazia.\n");
    } else {
        fprintf(arquivo, "Conteudo da pilha:\n");
        for (int i = 0; i <= p->topo; i++) {
            fprintf(arquivo, "%.2f\n", p->vet[i]); 
        }
    }

    fclose(arquivo);
}

// Procedimento para ler elementos de um arquivo de texto e empilhá-los.
void LerArquivoEEmpilhar(pilha *p, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    elemento num;
    while (fscanf(arquivo, "%f", &num) == 1 && !PilhaCheia(p)) {
        Empilhar(p, num);
    }

    fclose(arquivo);
}

int main() {
    pilha minhaPilha;
    CriarPilha(&minhaPilha);

    printf("Digite 10 numeros reais para empilhar na pilha:\n");
    for (int i = 0; i < TAM; i++) {
        float num;
        scanf("%f", &num);
        Empilhar(&minhaPilha, num);
    }

    ImprimePilha(&minhaPilha);

    GravarPilhaEmArquivo(&minhaPilha, "pilha.txt");
    
    while (!PilhaVazia(&minhaPilha)) {
        Desempilhar(&minhaPilha);
    }

    LerArquivoEEmpilhar(&minhaPilha, "pilha.txt");

    ImprimePilha(&minhaPilha);

    return 0;
}
