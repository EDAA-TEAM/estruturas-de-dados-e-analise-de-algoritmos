#include <stdio.h>

/*
Receba uma temperatura em Celsius, 
calcule e mostre essa temperatura em Fahrenheit.
OBS: F = (C * 1,8) + 32.
*/

int main() {
    float temperaturaCelsius, temperaturaFahrenheit;
    
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &temperaturaCelsius);

    temperaturaFahrenheit = (temperaturaCelsius * 1.8) + 32;

    printf("A temperatura em graus Fahrenheit e: %.2f\n", temperaturaFahrenheit);
    
    return 0;
}