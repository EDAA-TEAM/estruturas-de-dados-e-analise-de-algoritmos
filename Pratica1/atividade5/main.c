#include <stdio.h>

/*
Calcule e apresente a área de um losango. 
As diagonais maior e menor do losango
devem ser informadas pelo usuário. 
OBS: AREA = (DIAGONAL MAIOR * DIAGONAL
MENOR) / 2.
*/

int main() {
    float diagonalMaior, diagonalMenor, area;
    
    printf("Digite o valor da diagonal maior do losango: ");
    scanf("%f", &diagonalMaior);
    
    printf("Digite o valor da diagonal menor do losango: ");
    scanf("%f", &diagonalMenor);
    
    area = (diagonalMaior * diagonalMenor) / 2.0;
    
    printf("A area do losango e: %.2f\n", area);
    
    return 0;
}