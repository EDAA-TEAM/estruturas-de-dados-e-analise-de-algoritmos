#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1
#define MAX_STRING 50

struct data {
    int dia, mes, ano;
};

struct funcionario {
    char cpf[MAX_STRING];
    char nome[MAX_STRING];
    char endereco[MAX_STRING];
    char telefone[MAX_STRING];
    char celular[MAX_STRING];
    struct data data_nascimento;
    struct data data_admissao;
    char departamento[MAX_STRING];
    char cargo[MAX_STRING];
    float salario;
};

struct tipo_pilha {
    struct funcionario vet[TAM];
    int topo;
};

typedef struct tipo_pilha pilha;

// Cria pilha.
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

// Insere um funcionário na pilha.
void Empilhar(pilha *p, struct funcionario f) {
    if (!PilhaCheia(p)) {
        (*p).topo++;
        (*p).vet[(*p).topo] = f;
    } else {
        printf("A pilha esta cheia. Não e possivel empilhar.\n");
    }
}

// Retira um funcionário da pilha.
struct funcionario Desempilhar(pilha *p) {
    struct funcionario temp;
    if (!PilhaVazia(p)) {
        temp = (*p).vet[(*p).topo];
        (*p).topo--;
    } else {
        printf("A pilha esta vazia. Não e possivel desempilhar.\n");
        strcpy(temp.cpf, ""); // Valor padrão para CPF
    }
    return temp;
}

// Procedimento para gravar funcionários da pilha em um arquivo binário.
void GravarPilhaEmArquivo(pilha *p, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    if (PilhaVazia(p)) {
        printf("A pilha esta vazia. Nada para gravar.\n");
    } else {
        fwrite(p->vet, sizeof(struct funcionario), p->topo + 1, arquivo);
    }

    fclose(arquivo);
}

// Procedimento para ler funcionários de um arquivo binário e empilhá-los.
void LerArquivoEEmpilhar(pilha *p, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    struct funcionario f;
    while (fread(&f, sizeof(struct funcionario), 1, arquivo) == 1 && !PilhaCheia(p)) {
        Empilhar(p, f);
    }

    fclose(arquivo);
}

// Função para imprimir o conteúdo da pilha.
void ImprimePilha(pilha *p) {
    if (PilhaVazia(p)) {
        printf("A pilha esta vazia.\n");
    } else {
        printf("Conteudo da pilha:\n");
        for (int i = 0; i <= p->topo; i++) {
            printf("Funcionário %d:\n", i + 1);
            printf("CPF: %s\n", p->vet[i].cpf);
            printf("Nome: %s\n", p->vet[i].nome);
            printf("Endereço: %s\n", p->vet[i].endereco);
            printf("Telefone: %s\n", p->vet[i].telefone);
            printf("Celular: %s\n", p->vet[i].celular);
            printf("Data de Nascimento: %02d/%02d/%04d\n", p->vet[i].data_nascimento.dia, p->vet[i].data_nascimento.mes, p->vet[i].data_nascimento.ano);
            printf("Data de Admissão: %02d/%02d/%04d\n", p->vet[i].data_admissao.dia, p->vet[i].data_admissao.mes, p->vet[i].data_admissao.ano);
            printf("Departamento: %s\n", p->vet[i].departamento);
            printf("Cargo: %s\n", p->vet[i].cargo);
            printf("Salário: %.2f\n", p->vet[i].salario);
            printf("\n");
        }
    }
}

// Função para pesquisar funcionários por CPF.
int PesquisarPorCPF(pilha *p, const char *cpf) {
    if (PilhaVazia(p)) {
        printf("A pilha esta vazia. Nenhum funcionario para pesquisar.\n");
        return 0;
    }

    for (int i = 0; i <= p->topo; i++) {
        if (strcmp(p->vet[i].cpf, cpf) == 0) {
            printf("Funcionario encontrado:\n");
            printf("CPF: %s\n", p->vet[i].cpf);
            printf("Nome: %s\n", p->vet[i].nome);
            printf("Endereco: %s\n", p->vet[i].endereco);
            printf("Telefone: %s\n", p->vet[i].telefone);
            printf("Celular: %s\n", p->vet[i].celular);
            printf("Data de Nascimento: %02d/%02d/%04d\n", p->vet[i].data_nascimento.dia, p->vet[i].data_nascimento.mes, p->vet[i].data_nascimento.ano);
            printf("Data de Admissão: %02d/%02d/%04d\n", p->vet[i].data_admissao.dia, p->vet[i].data_admissao.mes, p->vet[i].data_admissao.ano);
            printf("Departamento: %s\n", p->vet[i].departamento);
            printf("Cargo: %s\n", p->vet[i].cargo);
            printf("Salario: %.2f\n", p->vet[i].salario);
            return 1;
        }
    }

    printf("Funcionario com CPF %s nao encontrado.\n", cpf);
    return 0;
}

int main() {
    pilha minhaPilha;
    CriarPilha(&minhaPilha);

    // Ler informações de 10 funcionários do teclado e empilhá-los
    for (int i = 0; i < TAM; i++) {
        struct funcionario f;
        printf("Digite os dados do Funcionario %d:\n", i + 1);
        printf("CPF: ");
        scanf("%s", f.cpf);
        printf("Nome: ");
        scanf("%s", f.nome);
        printf("Endereco: ");
        scanf("%s", f.endereco);
        printf("Telefone: ");
        scanf("%s", f.telefone);
        printf("Celular: ");
        scanf("%s", f.celular);
        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &f.data_nascimento.dia, &f.data_nascimento.mes, &f.data_nascimento.ano);
        printf("Data de Admissao (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &f.data_admissao.dia, &f.data_admissao.mes, &f.data_admissao.ano);
        printf("Departamento: ");
        scanf("%s", f.departamento);
        printf("Cargo: ");
        scanf("%s", f.cargo);
        printf("Salario: ");
        scanf("%f", &f.salario);

        Empilhar(&minhaPilha, f);
    }

    // Gravar a pilha em um arquivo binário
    GravarPilhaEmArquivo(&minhaPilha, "funcionarios.dat");

    // Esvaziar a pilha
    while (!PilhaVazia(&minhaPilha)) {
        Desempilhar(&minhaPilha);
    }

    // Ler funcionários do arquivo e empilhá-los novamente
    LerArquivoEEmpilhar(&minhaPilha, "funcionarios.dat");

    // Imprimir a pilha novamente
    ImprimePilha(&minhaPilha);

    // Pesquisar um funcionário por CPF
    char cpf_pesquisa[MAX_STRING];
    printf("Digite o CPF para pesquisa: ");
    scanf("%s", cpf_pesquisa);
    PesquisarPorCPF(&minhaPilha, cpf_pesquisa);

    return 0;
}