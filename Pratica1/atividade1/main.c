#include <stdio.h>
//Receba três notas, calcule e apresente a média 
//aritmética delas.
int main()
{
   int nota1, nota2, nota3;
    printf ("Digite a primeira nota ");
    scanf ("%i", &nota1);

    printf ("Digite a segunda nota ");
    scanf ("%i", &nota2);

    printf ("Digite a terceira nota ");
    scanf ("%i", &nota3);
    
    int media = (nota1 + nota2 + nota3) / 3;

    printf("A media entre as notas e = %i", media);

   return 0;
}
