/*
Receba os valores dos dois catetos de um triângulo, 
calcule e apresente o valor da
hipotenusa. OBS - Teorema de Pitágoras: a
2 = b2 + c2
.
*/

#include <stdio.h>
#include <math.h> 

int main() {
    float catetoA, catetoB, hipotenusa;

    printf("Digite o valor do primeiro cateto: ");
    scanf("%f", &catetoA);

    printf("Digite o valor do segundo cateto: ");
    scanf("%f", &catetoB);

    hipotenusa = sqrt(catetoA * catetoA + catetoB * catetoB);

    printf("A hipotenusa do triângulo é: %.2f\n", hipotenusa);

    return 0;
}