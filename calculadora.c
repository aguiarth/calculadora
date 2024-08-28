#include <stdio.h>
#include <string.h>

void decimal_para_binario(int numero);
void decimal_para_octal(int numero);
void decimal_para_hexadecimal(int numero);
void decimal_para_bcd(int numero);

int main(){

    int opcao;

    do {
        printf("Calculadora didática - conversão entre sistemas numéricos\n"
                "====================\n"
                "Selecione a opção desejada:\n"
                "1. Base 10 para bases 2, 8, 16 e código BCD (valores inteiros positivos)\n"
                "2. Base 10 para base 2 com sinal com 16 bits - complemento a 2 (valores inteiros)\n"
                "3. Base 10 para float e double (valores reais)\n"
                "4. Sair\n");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao > 4){
                printf("Opção inválida. Tente novamente.\n");
            }
    } while (opcao < 1 || opcao > 4);
    
    if (opcao == 1){
        int numero, opcao2;

        do {
            printf("Selecione a base do resultado:\n"
                    "1. Binário\n"
                    "2. Octal\n"
                    "3. Hexadecimal\n"
                    "4. Código BCD\n");
            scanf("%d", &opcao2);
            if (opcao2 < 1 || opcao2 > 4){
                printf("Opção inválida. Tente novamente.\n");
            }
        } while (opcao2 < 1 || opcao2 > 4);

        printf("Digite um número decimal inteiro positivo: \n");
        scanf("%d", &numero);

        if (opcao2 == 1){
            decimal_para_binario(numero);
        } else if (opcao2 == 2){
            decimal_para_octal(numero);
        } else if (opcao2 == 3){
            decimal_para_hexadecimal(numero);
        } else if (opcao2 == 4){
            decimal_para_bcd(numero);
        }
    } else if (opcao == 4){
        printf("Saindo...\n");
    }

    return 0;
}

void decimal_para_binario(int numero) {
    // função apenas para valores inteiros positivos

    int resto, i = 0, valorInicial = numero;
    char binario[33]; // limite para sistemas de 32 bits

    // para o decimal 0, o binário é 0
    if (numero == 0) {
        binario[i++] = '0';
    }
    
    // método da divisão - conversão decimal para binário
    while (numero > 0) {
        resto = numero % 2;
        printf("Dividindo %d por 2: quociente = %d, resto = %d\n", numero, numero / 2, resto);
        numero /= 2;
        binario[i++] = resto + '0'; // converter o valor numérico '0' ou '1' em ASCII para representação em string
    }

    // finalizar a string
    binario[i] = '\0';
    printf("O resultado é o último quociente seguido dos restos - leitura invertida.\n");
    printf("Decimal %d na base 2: ", valorInicial);

    // resultado - inverter a string
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binario[j]);
    }
    printf("\n");

}

void decimal_para_octal(int numero) {
    // apenas valores inteiros positivos

    int resto, i = 0, valorInicial = numero;
    char octal[12]; // maior tamanho para inteiros de 32 bits

    // para o decimal 0, o octal é 0
    if (numero == 0) {
        octal[i++] = '0';
    }
    
    // método da divisão - conversão decimal para octal
    while (numero > 0) {
        resto = numero % 8;
        printf("Dividindo %d por 8: quociente = %d, resto = %d\n", numero, numero / 8, resto);
        numero /= 8;
        octal[i++] = resto + '0';
    }

    // finalizar a string
    octal[i] = '\0';
    printf("O resultado é o último quociente seguido dos restos - leitura invertida.\n");
    printf("Decimal %d na base 8: ", valorInicial);

    // inverter a string
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", octal[j]);
    }
    printf("\n");

}

void decimal_para_hexadecimal(int numero) {
    // Função apenas para valores inteiros positivos
    int resto, i = 0, valorInicial = numero;
    char hexadecimal[9]; // Limite para inteiros de 32 bits (8 dígitos hexadecimais + 1 bit '/0')
    char caracteresHex[] = "0123456789ABCDEF"; // mapeamento de valores numéricos para caracteres hexadecimais

    // decimal 0 = hexadecimal "0"
    if (numero == 0) {
        hexadecimal[i++] = '0';
    }

    printf("Convertendo o decimal %d para hexadecimal:\n", valorInicial);

    // Método da divisão - conversão decimal para hexadecimal
    while (numero > 0) {
        resto = numero % 16;
        printf("Dividindo %d por 16: quociente = %d, resto = %d (%c)\n", numero, numero / 16, resto, caracteresHex[resto]);
        numero /= 16;
        hexadecimal[i++] = caracteresHex[resto];
    }

    // Finalizar a string
    hexadecimal[i] = '\0';

    // Exibir o resultado final
    printf("O resultado é o último quociente seguido dos restos - leitura invertida.\n");
    printf("Decimal %d na base hexadecimal: ", valorInicial);
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

void decimal_para_bcd(int numero) {
    // função apenas para valores inteiros positivos

    int valorInicial = numero;
    int digito, digitoOriginal, i;
    char bcd[41]; // limite BCD em sistemas 32 bits

    printf("Convertendo o decimal %d para BCD:\n", valorInicial);

    // 1 - converter cada dígito para BCD
    while (numero > 0){
        digito = numero % 10;
        digitoOriginal = digito;
        numero /= 10;

        // 1.1 - converter o dígito para binário de 4 bits
        char bcd_digito[5] = "";
        for (i = 3; i >= 0; i--){
            bcd_digito[i] = (digito % 2) + '0';
            digito /= 2;
        } 
        bcd_digito[4] = '\0';

        // 1.2 - exibir o BCD de cada dígito
        printf("Dígito %d convertido para BCD: %s\n", digitoOriginal, bcd_digito);

        // 1.3 - concatenar os dígitos ao BCD final
        char temp_bcd[41];
        snprintf(temp_bcd, sizeof(temp_bcd), "%s %s", bcd_digito, bcd);
        strcpy(bcd, temp_bcd);
    }

    // 2 - remover o espaço extra no início e no final da string BCD
    if (strlen(bcd) > 0) {
        if (bcd[strlen(bcd) - 1] == ' ') {
            bcd[strlen(bcd) - 1] = '\0';
        }
        if (bcd[0] == ' ') {
            memmove(bcd, bcd + 1, strlen(bcd));
        }
    }

    // 3 - exibir o resultado final
    printf("\nResultado final - %d em BCD: %s\n", valorInicial, bcd);

}