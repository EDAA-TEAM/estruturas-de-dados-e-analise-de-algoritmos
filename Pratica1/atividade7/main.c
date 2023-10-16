/*
Receba o valor do salário mínimo e o valor do salário de um funcionário. 
O algoritmo
deve calcular e apresentar a quantidade de salários
 mínimos que esse funcionário
recebe.
*/

#include <stdio.h>

int main() {
    float salarioMinimo, salarioFuncionario, quantidadeSalarios;

    printf("Digite o valor do salario minimo: R$ ");
    scanf("%f", &salarioMinimo);

    printf("Digite o valor do salario do funcionario: R$ ");
    scanf("%f", &salarioFuncionario);

    quantidadeSalarios = salarioFuncionario / salarioMinimo;
 
    printf("O funcionario recebe %.2f salarios minimos.\n", quantidadeSalarios);

    return 0;
}