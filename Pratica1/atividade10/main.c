/*
Receba o raio, calcule e apresente:

a. O comprimento de uma esfera: C = 2 * π * R.
b. A área de uma esfera: A = π * R2
c. O volume de uma esfera: V = 3⁄4 * π * R3

*/

#include <stdio.h>
#include <math.h> 

int main() {
    float raio, comprimento, area, volume;
    float pi = 3.14159265358979323846;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    comprimento = 2 * pi * raio;

    area = pi * pow(raio, 2);

    volume = (3.0 / 4.0) * pi * pow(raio, 3);

    printf("O comprimento da esfera e: %.2f\n", comprimento);
    printf("A area da esfera e: %.2f\n", area);
    printf("O volume da esfera e: %.2f\n", volume);

    return 0;
}






