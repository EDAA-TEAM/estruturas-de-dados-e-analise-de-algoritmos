#include <stdio.h>

//Faça um programa que receba o salário de um funcionário, 
//calcule e mostre o novo
//salário, sabendo-se que ele teve um aumento de 25%.

int main() {
    float salario, novoSalario;
    
    printf("Digite o salario do funcionario: R$ ");
    scanf("%f", &salario);
    
    novoSalario = salario + (salario * 0.25);
    
    printf("O novo salario do funcionario com 25%% de aumento e: R$ %.2f\n", novoSalario);
    
    return 0;
}
