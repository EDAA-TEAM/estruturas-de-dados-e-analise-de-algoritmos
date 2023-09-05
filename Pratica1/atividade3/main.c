#include <stdio.h>

// Receba a cotação do dólar em reais
// e um valor que o usuário possui em dólares.
// Imprima este valor em reais.

int main() {
    float cotacaoDolar, valorDolar, valorReais;

    printf("Digite a cotação do dolar em reais: R$ ");
    scanf("%f", &cotacaoDolar);
    
    printf("Digite o valor em dolares: $ ");
    scanf("%f", &valorDolar);
  
    valorReais = cotacaoDolar * valorDolar;
    
    printf("O valor em reais e: R$ %.2f\n", valorReais);
    
    return 0;
}

