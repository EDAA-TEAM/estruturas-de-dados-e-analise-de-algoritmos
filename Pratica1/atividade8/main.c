/*
Receba o peso de uma pessoa, calcule e apresente o novo peso:

a. Se a pessoa engordar 15%.
b. Se a pessoa emagrecer 20%.
*/

#include <stdio.h>

int main() {
    float peso, novoPesoEngordar, novoPesoEmagrecer;

    printf("Digite o peso da pessoa: ");
    scanf("%f", &peso);

    novoPesoEngordar = peso + (peso * 0.15); 

    novoPesoEmagrecer = peso - (peso * 0.20); 

    printf("Se a pessoa engordar 15%%, o novo peso sera: %.2f\n", novoPesoEngordar);
    printf("Se a pessoa emagrecer 20%%, o novo peso sera: %.2f\n", novoPesoEmagrecer);
    
    return 0;
}