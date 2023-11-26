#include "Floresta.h"

int main() {
    // Exemplo de uso
    Floresta* minhaFloresta = criarFloresta(3);

    inserirProduto(minhaFloresta, 0, 50);
    inserirProduto(minhaFloresta, 1, 30);
    inserirProduto(minhaFloresta, 2, 70);

    // Percorrer e imprimir os produtos nas categorias
    percorrerPreOrdem(minhaFloresta, 0);
    percorrerEmOrdem(minhaFloresta, 1);
    percorrerPosOrdem(minhaFloresta, 2);

    No* produtoEncontrado = buscarProduto(minhaFloresta, 0, 50);
    if (produtoEncontrado != NULL) {
        printf("Produto encontrado na Categoria 0.\n");
    } else {
        printf("Produto não encontrado na Categoria 0.\n");
    }

    excluirProduto(minhaFloresta, 1, 30);

    // Percorrer e imprimir novamente após a exclusão
    percorrerEmOrdem(minhaFloresta, 1);

    // Liberar memória
    destruirFloresta(minhaFloresta);

    return 0;
}