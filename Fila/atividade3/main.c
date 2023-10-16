#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct {
    char cpf[12];
    char nome[100];
    char endereco[100];
    char telefone[15];
    char celular[15];
    char data_nascimento[11];
    char data_admissao[11];
    char departamento[50];
    char cargo[50];
    float salario;
} Funcionario;

struct tipo_fila {
    Funcionario vet[TAM];
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

void Enfileirar(fila *f, Funcionario func) {
    if (!FilaCheia(f)) {
        (*f).vet[(*f).fim++] = func;
    }
}

Funcionario Desenfileirar(fila *f) {
    if (!FilaVazia(f)) {
        return (*f).vet[(*f).inicio++];
    }
    Funcionario vazio;
    memset(&vazio, 0, sizeof(Funcionario));
    return vazio; // Retorna um registro vazio indicando fila vazia
}

void ImprimeFila(fila *f) {
    if (FilaVazia(f)) {
        printf("Fila vazia\n");
    } else {
        printf("Conteúdo da fila:\n");
        for (int i = (*f).inicio; i < (*f).fim; i++) {
            printf("Nome: %s\n", (*f).vet[i].nome);
            printf("CPF: %s\n", (*f).vet[i].cpf);
            printf("Salário: %.2f\n", (*f).vet[i].salario);
            printf("----------------------------\n");
        }
    }
}

void GravaFilaEmArquivo(fila *f, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "wb");
    if (arquivo != NULL) {
        for (int i = (*f).inicio; i < (*f).fim; i++) {
            fwrite(&(*f).vet[i], sizeof(Funcionario), 1, arquivo);
        }
        fclose(arquivo);
        printf("Fila gravada no arquivo com sucesso.\n");
    } else {
        printf("Erro ao abrir o arquivo para gravação.\n");
    }
}

void LeFilaDoArquivo(fila *f, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo != NULL) {
        Funcionario func;
        while (fread(&func, sizeof(Funcionario), 1, arquivo) == 1) {
            Enfileirar(f, func);
        }
        fclose(arquivo);
        printf("Fila lida do arquivo com sucesso.\n");
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}

Funcionario PesquisarPorCPF(fila *f, char cpf[12]) {
    for (int i = (*f).inicio; i < (*f).fim; i++) {
        if (strcmp((*f).vet[i].cpf, cpf) == 0) {
            return (*f).vet[i];
        }
    }
    Funcionario vazio;
    memset(&vazio, 0, sizeof(Funcionario));
    return vazio; // Retorna um registro vazio se não encontrar o CPF
}

int main() {
    fila minha_fila;
    CriarFila(&minha_fila);

    // Leitura dos registros a partir do teclado e enfileiramento
    for (int i = 0; i < TAM; i++) {
        Funcionario func;
        printf("Digite os dados do funcionário %d:\n", i + 1);
        printf("CPF: ");
        scanf("%s", func.cpf);
        printf("Nome: ");
        scanf("%s", func.nome);
        printf("Endereço: ");
        scanf("%s", func.endereco);
        printf("Telefone: ");
        scanf("%s", func.telefone);
        printf("Celular: ");
        scanf("%s", func.celular);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf("%s", func.data_nascimento);
        printf("Data de Admissão (dd/mm/aaaa): ");
        scanf("%s", func.data_admissao);
        printf("Departamento: ");
        scanf("%s", func.departamento);
        printf("Cargo: ");
        scanf("%s", func.cargo);
        printf("Salário: ");
        scanf("%f", &func.salario);

        Enfileirar(&minha_fila, func);
    }

    // Impressão da fila
    ImprimeFila(&minha_fila);

    // Gravação da fila em um arquivo binário
    GravaFilaEmArquivo(&minha_fila, "funcionarios.bin");

    // Limpa a fila
    CriarFila(&minha_fila);

    // Leitura da fila a partir do arquivo binário
    LeFilaDoArquivo(&minha_fila, "funcionarios.bin");

    // Impressão da fila após a leitura do arquivo
    ImprimeFila(&minha_fila);

    // Pesquisa de funcionário por CPF
    char cpf_pesquisar[12];
    printf("Digite o CPF a ser pesquisado: ");
    scanf("%s", cpf_pesquisar);
    Funcionario resultado = PesquisarPorCPF(&minha_fila, cpf_pesquisar);
    if (strcmp(resultado.cpf, cpf_pesquisar) == 0) {
        printf("Funcionário encontrado:\n");
        printf("Nome: %s\n", resultado.nome);
        printf("CPF: %s\n", resultado.cpf);
        printf("Salário: %.2f\n", resultado.salario);
        // Imprima os outros campos aqui
    } else {
        printf("Funcionário com CPF %s não encontrado.\n", cpf_pesquisar);
    }

    return 0;
}
