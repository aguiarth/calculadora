#include <stdio.h>

void decimal_para_binario(int numero);
// void decimal_para_octal(int numero);
// void decimal_para_hexadecimal(int numero);
// void decimal_para_bcd(int numero);

int main(){

    int numero;

    printf("Digite um número decimal inteiro positivo: \n");
    scanf("%d", &numero);
    
    decimal_para_binario(numero);

    return 0;
}

void decimal_para_binario(int numero) {
    // conversão base decimal para base binária
    // funciona apenas para valores inteiros positivos

    int resto, i = 0;
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

    // inverter a string
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binario[j]);
    }
    printf("\n");

}