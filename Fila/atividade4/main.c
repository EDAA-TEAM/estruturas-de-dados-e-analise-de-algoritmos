#define TAM 5

typedef float elemento;

struct tipo_fila {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_fila fila;

void CriarFila(fila *f) {
    (*f).inicio = 0;
    (*f).fim = 0;
}

int FilaVazia(fila *f) {
    return ((*f).inicio == (*f).fim);       
}

int FilaCheia(fila *f) {
    return (((*f).fim + 1) % TAM == (*f).inicio);
}

void Enfileirar(fila *f, elemento e) {
    if (!FilaCheia(f)) {
        (*f).vet[(*f).fim] = e;
        (*f).fim = ((*f).fim + 1) % TAM; // Avança o índice de fim em um ciclo circular
    }
}

elemento Desenfileirar(fila *f) {
    elemento e;
    if (!FilaVazia(f)) {
        e = (*f).vet[(*f).inicio];
        (*f).inicio = ((*f).inicio + 1) % TAM; // Avança o índice de início em um ciclo circular
        return e;
    }
    // Se a fila estiver vazia, você pode retornar um valor especial para indicar erro, se necessário.
    // Neste exemplo, retornamos 0 para representar uma operação inválida.
    return 0;
}
