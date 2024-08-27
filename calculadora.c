#include <stdio.h>

void decimal_para_binario(int numero);
void decimal_para_octal(int numero);
// void decimal_para_hexadecimal(int numero);
// void decimal_para_bcd(int numero);

int main(){

    int numero;

    printf("Digite um número decimal inteiro positivo: \n");
    scanf("%d", &numero);
    
    decimal_para_binario(numero);
    decimal_para_octal(numero);

    return 0;
}

void decimal_para_binario(int numero) {
    // função apenas para valores inteiros positivos

    int resto, i = 0, valorInicial = numero;
    char binario[33]; // limite para sistemas de 32 bits

    if (numero == 0) {
        binario[i++] = '0';
    }
    
    // método da divisão
    while (numero > 0) {
        resto = numero % 2;
        numero /= 2;
        binario[i++] = resto + '0'; // converter o valor numérico '0' ou '1' em ASCII para representação em string
    }

    // finalizar a string
    binario[i] = '\0';

    printf("Decimal %d na base 2: ", valorInicial);

    // inverter a string
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binario[j]);
    }
    printf("\n");

}

void decimal_para_octal(int numero) {
    // apenas valores inteiros positivos

    int resto, i = 0, valorInicial = numero;
    char octal[12]; // maior tamanho para inteiros de 32 bits

    if (numero == 0) {
        octal[i++] = '0';
    }
    
    // método da divisão
    while (numero > 0) {
        resto = numero % 8;
        numero /= 8;
        octal[i++] = resto + '0';
    }

    // finalizar a string
    octal[i] = '\0';

    printf("Decimal %d na base 8: ", valorInicial);

    // inverter a string
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", octal[j]);
    }
    printf("\n");

}