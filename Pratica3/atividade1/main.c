#include <stdio.h>
#include <ctype.h>

int main() {
    char c;

    c = 'A';
    if (isalpha(c)) {
        printf("%c e uma letra.\n", c);
    } else {
        printf("%c nao e uma letra.\n", c);
    }

    c = '5';
    if (isdigit(c)) {
        printf("%c e um digito.\n", c);
    } else {
        printf("%c nao e um digito.\n", c);
    }

    c = 'B';
    if (isupper(c)) {
        printf("%c e uma letra maiuscula.\n", c);
    } else {
        printf("%c nao e uma letra maiuscula.\n", c);
    }

    c = 'x';
    if (islower(c)) {
        printf("%c e uma letra minuscula.\n", c);
    } else {
        printf("%c nao e uma letra minuscula.\n", c);
    }

    c = '1';
    if (isalnum(c)) {
        printf("%c e uma letra ou um digito.\n", c);
    } else {
        printf("%c nao e uma letra ou um digito.\n", c);
    }

    return 0;
}