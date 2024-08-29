#include <stdio.h>
#include <string.h>

void decimal_para_binario(int numero);
void decimal_para_octal(int numero);
void decimal_para_hexadecimal(int numero);
void decimal_para_bcd(int numero);
void decimal_para_binario_16(int numero);
// void decimal_para_float(float numero);
// void decimal_para_double(double numero);

int main(){

    int opcao;

    do {
        printf("Calculadora didática - conversão entre sistemas numéricos\n"
                "--------------------\n"
                "Selecione a opção desejada:\n"
                "1. Base 10 para bases 2, 8, 16 e código BCD (valores inteiros positivos)\n"
                "2. Base 10 para base 2 com sinal com 16 bits - complemento a 2 (valores inteiros)\n"
                "3. Base 10 para float e double (valores reais)\n"
                "4. Sair\n");
        
        // verificar entrada válida
        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n'); // Limpar buffer
            opcao = 0;
            continue;
        }
        getchar();

        if (opcao == 1){
            int numero, opcao2;

            do {
                printf("Selecione a conversão:\n"
                        "1. Binário\n"
                        "2. Octal\n"
                        "3. Hexadecimal\n"
                        "4. Código BCD\n"
                        "5. Voltar\n");
                
                if (scanf("%d", &opcao2) != 1) {
                    printf("Entrada inválida! Por favor, insira um número.\n");
                    while (getchar() != '\n');
                    opcao2 = 0;
                    continue;
                }
                getchar();

                if (opcao2 >= 1 && opcao2 <= 4) {
                    printf("Digite um número decimal inteiro positivo: ");
                    if (scanf("%d", &numero) != 1) {
                        printf("Entrada inválida! Por favor, insira um número inteiro.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                }

                if (opcao2 == 1){
                    decimal_para_binario(numero);
                } else if (opcao2 == 2){
                    decimal_para_octal(numero);
                } else if (opcao2 == 3){
                    decimal_para_hexadecimal(numero);
                } else if (opcao2 == 4){
                    decimal_para_bcd(numero);
                } else if (opcao2 == 5){
                    printf("Voltando ao menu principal...\n");
                    break;
                }
            } while (opcao2 != 5);

        } else if (opcao == 2){
            int numero;
            printf("Decimal inteiro: ");
            scanf("%d", &numero);
            decimal_para_binario_16(numero);
        } else if (opcao == 3){
            int opcao3;
            double numero;
            do {
                printf("Selecione a conversão:\n"
                        "1. Float\n"
                        "2. Double\n");
                scanf("%d", &opcao3);
                if (opcao3 < 1 || opcao3 > 2){
                    printf("Opção inválida. Tente novamente.\n");
                }
            } while (opcao3 < 1 || opcao3 > 2);

            printf("Digite um número decimal real: \n");
            scanf("%lf", &numero);

            if (opcao3 == 1){
                printf("\nImplementar - decimal para float");
            } else if (opcao3 == 2){
                printf("\nImplementar - decimal para double");
            }
        } else if (opcao == 4){
            printf("Saindo...\n");
        }

    } while (opcao != 4);

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
    printf("Divisões sucessivas por 2:\n");
    while (numero > 0) {
        resto = numero % 2;
        printf("%d dividido por 2 = %d, resto = %d\n", numero, numero / 2, resto);
        numero /= 2;
        binario[i++] = resto + '0'; // converter o valor numérico '0' ou '1' em ASCII para representação em string
    }

    // finalizar a string
    binario[i] = '\0';
    printf("O resultado é a leitura invertida dos restos.\n");
    printf("Decimal %d na base 2: ", valorInicial);

    // resultado - inverter a string
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binario[j]);
        if ((i - j) % 4 == 0 && j != 0) {
            printf(" ");
        }
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
    printf("Divisões sucessivas por 8:\n");
    while (numero > 0) {
        resto = numero % 8;
        printf("%d dividido por 8 = %d, resto = %d\n", numero, numero / 8, resto);
        numero /= 8;
        octal[i++] = resto + '0';
    }

    // finalizar a string
    octal[i] = '\0';
    printf("O resultado é a leitura invertida dos restos.\n");
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

    printf("A base hexadecimal possui 16 possibilidades de valores: 0123456789ABCDEF.\n");

    // decimal 0 = hexadecimal "0"
    if (numero == 0) {
        hexadecimal[i++] = '0';
    }

    printf("Convertendo o decimal %d para hexadecimal:\n", valorInicial);

    // Método da divisão - conversão decimal para hexadecimal
    printf("Divisões sucessivas por 2:\n");
    while (numero > 0) {
        resto = numero % 16;
        printf("%d dividido por 16 = %d, resto = %d (%c)\n", numero, numero / 16, resto, caracteresHex[resto]);
        numero /= 16;
        hexadecimal[i++] = caracteresHex[resto];
    }

    // Finalizar a string
    hexadecimal[i] = '\0';

    // Exibir o resultado final
    printf("O resultado é a leitura invertida dos restos.\n");
    printf("Decimal %d na base hexadecimal: ", valorInicial);
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
        if ((i - j) % 4 == 0 && j != 0) {
            printf(" ");
        }
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
        char bcdDigito[5] = "";
        for (i = 3; i >= 0; i--){
            bcdDigito[i] = (digito % 2) + '0';
            digito /= 2;
        } 
        bcdDigito[4] = '\0';

        // 1.2 - exibir o BCD de cada dígito
        printf("Dígito %d convertido para BCD: %s\n", digitoOriginal, bcdDigito);

        // 1.3 - concatenar os dígitos ao BCD final
        char tempBcd[41];
        snprintf(tempBcd, sizeof(tempBcd), "%s %s", bcdDigito, bcd);
        strcpy(bcd, tempBcd);
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

void decimal_para_binario_16(int numero){
    // Função para converter um decimal para binário com 16 bits
    unsigned int valor;
    int i;
    char binario[17]; // 16 bits + 1 bit para terminador nulo

    printf("\nValor inicial: %d\n", numero);

    // 1 - valor absoluto
    if (numero < 0){
        printf("O valor é um decimal inteiro negativo. Vamos calcular o complemento a 2 usando 16 bits:\n");
        valor = (unsigned int)(-numero);

        // 1.1 - binário do valor absoluto
        printf("\n1. Converter o valor absoluto para binário: ");
        for (i = 15; i >= 0; i--){
            binario[i] = (valor % 2) + '0';
            valor /= 2;
        }

        for (i = 0; i < 16; i++) {
            printf("%c", binario[i]);
            if ((i + 1) % 4 == 0 && i < 15){
                printf(" ");
            }
        }

        // 1.2 - inverter todos os bits - complemento a 1
        printf("\n2. Inverter todos os bits (complemento a 1): ");
        for (i = 0; i < 16; i++){
            binario[i] = (binario[i] == '0') ? '1' : '0';
        }

        for (i = 0; i < 16; i++) {
            printf("%c", binario[i]);
            if ((i + 1) % 4 == 0 && i < 15){
                printf(" ");
            }
        }

        // 1.3 - adicionar 1 - complemento a 2
        printf("\n3. Adicionar 1 (complemento a 2): ");
        for (i = 15; i >= 0; i--){
            if (binario[i] == '0'){
                binario[i] = '1';
                break;
            } else {
                binario[i] = '0';
            }
        }

        for (i = 0; i < 16; i++) {
            printf("%c", binario[i]);
            if ((i + 1) % 4 == 0 && i < 15){
                printf(" ");
            }
        }
        printf("\n");

    } else {
        printf("O valor é um decimal inteiro positivo. Basta converter para a base 2 usando 16 bits:\n");
        valor = (unsigned int)numero;
        // 3 - binário do número positivo
        for (i = 15; i >= 0; i--){
            binario[i] = (valor % 2) + '0';
            valor /= 2;
        }

        printf("   Binário: ");
        for (i = 0; i < 16; i++) {
            printf("%c", binario[i]);
            if ((i + 1) % 4 == 0 && i < 15){
                printf(" ");
            }
        }
        printf("\n");

    }
    // finalizar a string
    binario[16] = '\0'; // terminador nulo

    // 4 - exibir o resultado final
    printf("Decimal %d em binário com 16 bits: ", numero);
    for (i = 0; i < 16; i++){
        printf("%c", binario[i]);
        // espaço a cada 4 bits
        if ((i + 1) % 4 == 0 && i < 15){
            printf(" ");
        }
    }
    printf("\n");
}

// void decimal_para_float(float numero);
// void decimal_para_double(double numero);