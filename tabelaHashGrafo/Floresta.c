#include "Floresta.h"
#include <stdio.h>
#include <stdlib.h>

Floresta* criarFloresta(int num_categorias) {
    Floresta* floresta = (Floresta*)malloc(sizeof(Floresta));
    floresta->num_categorias = num_categorias;
    
    floresta->categorias = (Arvore**)malloc(num_categorias * sizeof(Arvore*));
    for (int i = 0; i < num_categorias; i++) {
        floresta->categorias[i] = (Arvore*)malloc(sizeof(Arvore));
        floresta->categorias[i]->raiz = NULL;
    }
    
    return floresta;
}

void destruirArvore(No* no) {
    if (no != NULL) {
        destruirArvore(no->esquerda);
        destruirArvore(no->direita);
        free(no);
    }
}

void destruirFloresta(Floresta* floresta) {
    for (int i = 0; i < floresta->num_categorias; i++) {
        destruirArvore(floresta->categorias[i]->raiz);
        free(floresta->categorias[i]);
    }
    free(floresta->categorias);
    free(floresta);
}

No* inserirNo(No* no, int chave) {
    if (no == NULL) {
        No* novoNo = (No*)malloc(sizeof(No));
        novoNo->chave = chave;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }

    if (chave < no->chave) {
        no->esquerda = inserirNo(no->esquerda, chave);
    } else if (chave > no->chave) {
        no->direita = inserirNo(no->direita, chave);
    }

    return no;
}

void inserirProduto(Floresta* floresta, int categoria, int chave) {
    if (categoria >= 0 && categoria < floresta->num_categorias) {
        floresta->categorias[categoria]->raiz = inserirNo(floresta->categorias[categoria]->raiz, chave);
    } else {
        printf("Categoria inválida.\n");
    }
}

No* buscarNo(No* no, int chave) {
    if (no == NULL || no->chave == chave) {
        return no;
    }

    if (chave < no->chave) {
        return buscarNo(no->esquerda, chave);
    } else {
        return buscarNo(no->direita, chave);
    }
}

No* buscarProduto(Floresta* floresta, int categoria, int chave) {
    if (categoria >= 0 && categoria < floresta->num_categorias) {
        return buscarNo(floresta->categorias[categoria]->raiz, chave);
    } else {
        printf("Categoria inválida.\n");
        return NULL;
    }
}

No* encontrarMinimo(No* no) {
    while (no->esquerda != NULL) {
        no = no->esquerda;
    }
    return no;
}

No* excluirNo(No* no, int chave) {
    if (no == NULL) {
        return no;
    }

    if (chave < no->chave) {
        no->esquerda = excluirNo(no->esquerda, chave);
    } else if (chave > no->chave) {
        no->direita = excluirNo(no->direita, chave);
    } else {
        if (no->esquerda == NULL) {
            No* temp = no->direita;
            free(no);
            return temp;
        } else if (no->direita == NULL) {
            No* temp = no->esquerda;
            free(no);
            return temp;
        }

        No* temp = encontrarMinimo(no->direita);
        no->chave = temp->chave;
        no->direita = excluirNo(no->direita, temp->chave);
    }

    return no;
}

No* excluirProduto(Floresta* floresta, int categoria, int chave) {
    if (categoria >= 0 && categoria < floresta->num_categorias) {
        floresta->categorias[categoria]->raiz = excluirNo(floresta->categorias[categoria]->raiz, chave);
    } else {
        printf("Categoria inválida.\n");
    }
}

void percorrerPreOrdemNo(No* no) {
    if (no != NULL) {
        printf("%d ", no->chave);
        percorrerPreOrdemNo(no->esquerda);
        percorrerPreOrdemNo(no->direita);
    }
}

void percorrerPreOrdem(Floresta* floresta, int categoria) {
    if (categoria >= 0 && categoria < floresta->num_categorias) {
        printf("Pre-ordem (Categoria %d): ", categoria);
        percorrerPreOrdemNo(floresta->categorias[categoria]->raiz);
        printf("\n");
    } else {
        printf("Categoria inválida.\n");
    }
}

void percorrerEmOrdemNo(No* no) {
    if (no != NULL) {
        percorrerEmOrdemNo(no->esquerda);
        printf("%d ", no->chave);
        percorrerEmOrdemNo(no->direita);
    }
}

void percorrerEmOrdem(Floresta* floresta, int categoria) {
    if (categoria >= 0 && categoria < floresta->num_categorias) {
        printf("Em-ordem (Categoria %d): ", categoria);
        percorrerEmOrdemNo(floresta->categorias[categoria]->raiz);
        printf("\n");
    } else {
        printf("Categoria inválida.\n");
    }
}

void percorrerPosOrdemNo(No* no) {
    if (no != NULL) {
        percorrerPosOrdemNo(no->esquerda);
        percorrerPosOrdemNo(no->direita);
        printf("%d ", no->chave);
    }
}

void percorrerPosOrdem(Floresta* floresta, int categoria) {
    if (categoria >= 0 && categoria < floresta->num_categorias) {
        printf("Pós-ordem (Categoria %d): ", categoria);
        percorrerPosOrdemNo(floresta->categorias[categoria]->raiz);
        printf("\n");
    } else {
        printf("Categoria inválida.\n");
    }
}
