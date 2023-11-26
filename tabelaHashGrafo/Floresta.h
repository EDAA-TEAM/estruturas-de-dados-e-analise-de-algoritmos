#ifndef FLORESTA_H
#define FLORESTA_H

// Definição de um nó da árvore binária de pesquisa
typedef struct No {
    int chave; // Pode ser substituído pelo tipo de dado dos produtos
    struct No* esquerda;
    struct No* direita;
} No;

// Definição da árvore binária de pesquisa
typedef struct Arvore {
    No* raiz;
} Arvore;

// Definição da Floresta de árvores binárias de pesquisa
typedef struct Floresta {
    int num_categorias;
    Arvore** categorias;
} Floresta;

// Funções para manipulação da floresta
Floresta* criarFloresta(int num_categorias);
void destruirFloresta(Floresta* floresta);
void inserirProduto(Floresta* floresta, int categoria, int chave);
No* buscarProduto(Floresta* floresta, int categoria, int chave);
No* excluirProduto(Floresta* floresta, int categoria, int chave);
void percorrerPreOrdem(Floresta* floresta, int categoria);
void percorrerEmOrdem(Floresta* floresta, int categoria);
void percorrerPosOrdem(Floresta* floresta, int categoria);

#endif
