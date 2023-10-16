#include <stdio.h>
//2) Receba o ano de nascimento de uma pessoa, 
// o ano atual e imprima:
// a. A idade da pessoa no ano atual.
// b. A idade que a pessoa terá em 2050.

int main()
{
    int anoAtual;
    int anoNascimento;

    printf("Digite o seu ano de nascimento ");
    scanf("%i", & anoNascimento);

    printf("Digite o ano Atual ");
    scanf("%i", & anoAtual);

    int idadeAtual = anoAtual - anoNascimento;
    int idade2050 = 2050 - anoNascimento;

    printf("Sua idade atual e = %i\n", idadeAtual);
    printf("Sua idade em 2050 e = %i", idade2050);

    return 0;
}
