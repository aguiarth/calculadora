#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void metodo_da_divisao(long long int numero, int base, char *resultado);
void decimal_para_bcd(long long int numero);
void decimal_para_binario_16(long long int numero);
void decimal_para_float_double(double numero, int is_double);

int main(){

    int opcao;

    do {
        printf("Calculadora didática - conversão entre sistemas numéricos\n"
                "--------------------\n"
                "Selecione a opção desejada:\n"
                "1. Base 10 para bases 2, 8, 16 e código BCD (valores naturais)\n"
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
            int opcao1;
            long long int numero;

            do {
                printf("Selecione a conversão:\n"
                        "1. Binário\n"
                        "2. Octal\n"
                        "3. Hexadecimal\n"
                        "4. Código BCD\n"
                        "5. Voltar\n");
                
                if (scanf("%d", &opcao1) != 1) {
                    printf("Entrada inválida! Por favor, insira um número.\n");
                    while (getchar() != '\n');
                    opcao1 = 0;
                    continue;
                }
                getchar();

                if (opcao1 >= 1 && opcao1 <= 4) {
                    printf("Digite um número decimal inteiro positivo: ");
                    if (scanf("%lld", &numero) != 1) {
                        printf("Entrada inválida! Por favor, insira um número inteiro.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                }

                if (opcao1 == 1){
                    char binario[65]; // limite em sistemas de 64 bits (64 dígitos bin + terminador nulo)
                    metodo_da_divisao(numero, 2, binario);
                } else if (opcao1 == 2){
                    char octal[23]; // 64 bits (22 dígitos oct + '/0')
                    metodo_da_divisao(numero, 8, octal);
                } else if (opcao1 == 3){
                    char hexadecimal[17]; // 64 bits (16 dígitos hex + '/0')
                    printf("A base hexadecimal possui 16 possibilidades de valores: 0123456789ABCDEF.\n");
                    metodo_da_divisao(numero, 16, hexadecimal);
                } else if (opcao1 == 4){
                    decimal_para_bcd(numero);
                } else if (opcao1 == 5){
                    printf("Voltando ao menu principal...\n");
                    break;
                }
            } while (opcao1 != 5);

        } else if (opcao == 2){
            long long int numero;
            printf("Decimal inteiro: ");
            scanf("%lld", &numero);
            decimal_para_binario_16(numero);
        } else if (opcao == 3){
            int opcao3;
            double numero;
            do {
                printf("Selecione a conversão:\n"
                        "1. Float\n"
                        "2. Double\n"
                        "3. Voltar\n");

                if (scanf("%d", &opcao3) != 1) {
                    printf("Entrada inválida! Por favor, insira um número.\n");
                    while (getchar() != '\n');
                    opcao3 = 0;
                    continue;
                }
                getchar();

                if (opcao3 >= 1 && opcao3 <= 2) {
                    printf("Usaremos o padrão numérico IEEE 754 para a conversão.\n"
                            "Digite um valor decimal real: ");
                    if (scanf("%lf", &numero) != 1) {
                        printf("Entrada inválida!\n");
                        while (getchar() != '\n');
                        continue;
                    }
                }

                if (opcao3 == 1){
                    printf("\nRepresentação IEEE 754 como float:\n");
                    decimal_para_float_double(numero, 0);
                } else if (opcao3 == 2){
                    printf("\nRepresentação IEEE 754 como double:\n");
                    decimal_para_float_double(numero, 1);
                } else if (opcao3 == 3){
                    printf("Voltando ao menu principal...\n");
                    break;
                }
            } while (opcao3 != 3);            
        } else if (opcao == 4){
            printf("Saindo...\n");
        }

    } while (opcao != 4);

    return 0;
}

void metodo_da_divisao(long long int numero, int base, char *resultado) {
    // função apenas para números naturais

    int resto, i = 0;
    long long int valorInicial = numero;
    char caracteres[] = "0123456789ABCDEF"; // mapeamento base 16

    // para o decimal 0, o resultado é 0
    if (numero == 0) {
        resultado[i++] = '0';
    }
    
    // método da divisão - conversão base 10 para outras bases
    printf("\nDivisões sucessivas por %d:\n", base);
    while (numero > 0) {
        resto = numero % base;
        printf("%lld dividido por %d = %lld, resto = %d\n", numero, base, numero / base, resto);
        numero /= base;
        resultado[i++] = caracteres[resto]; // converter o valor numérico '0' ou '1' em ASCII para representação em string
    }

    // finalizar e inverter a string
    resultado[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = resultado[j];
        resultado[j] = resultado[i - j - 1];
        resultado[i - j - 1] = temp;
    }

    // resultado
    printf("O resultado é a leitura invertida dos restos.\n");
    printf("%lld na base %d: ", valorInicial, base);

    for (int j = 0; j < i; j++) {
        printf("%c", resultado[j]);
        if ((j + 1) % 4 == 0 && j != i - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void decimal_para_bcd(long long int numero) {
    // função apenas para valores inteiros positivos

    long long int valorInicial = numero;
    int digito, digitoOriginal, i;
    char bcd[81]; // limite BCD em sistemas 64 bits (20 dígitos * 4 bits + 1 terminador nulo)

    printf("Na Codificação Binária Decimal, cada dígito decimal é representado por 4 bits (nibble).\n");
    printf("%lld em BCD:\n", valorInicial);

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
        char tempBcd[81];
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
    printf("\nResultado final - %lld em BCD: %s\n", valorInicial, bcd);
}

void decimal_para_binario_16(long long int numero){
    // Função para converter um decimal para binário com 16 bits
    unsigned int valor;
    int i;
    char binario[17]; // 16 bits + 1 bit para terminador nulo

    printf("\nValor inicial: %lld\n", numero);

    // 1 - valor absoluto
    if (numero < 0){
        printf("O valor é um decimal inteiro negativo. Vamos calcular o complemento a 2 usando 16 bits:\n");
        valor = (unsigned long long int)(-numero);

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
            if ((15 - i) % 4 == 0 && i < 15){
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
            if ((15 - i) % 4 == 0 && i < 15){
                printf(" ");
            }
        }
        printf("\n");

    } else {
        printf("O valor é um decimal inteiro positivo. Basta converter para a base 2 usando 16 bits:\n");
        valor = (unsigned long long int)numero;
        // 3 - binário do número positivo
        for (i = 15; i >= 0; i--){
            binario[i] = (valor % 2) + '0';
            valor /= 2;
        }

        printf("   Binário: ");
        for (i = 0; i < 16; i++) {
            printf("%c", binario[i]);
            if ((15 - i) % 4 == 0 && i < 15){
                printf(" ");
            }
        }
        printf("\n");

    }
    // finalizar a string
    binario[16] = '\0'; // terminador nulo

    // 4 - exibir o resultado final
    printf("Decimal %lld em binário com 16 bits: ", numero);
    for (i = 0; i < 16; i++){
        printf("%c", binario[i]);
        // espaço a cada 4 bits
        if ((15 - i) % 4 == 0 && i < 15){
            printf(" ");
        }
    }
    printf("\n");
}

void decimal_para_float_double(double numero, int is_double){
    // 1 - determinar o bit de sinal
    printf("\n1. Determinar o bit de sinal:\n");
    int sinal;
    if (numero < 0){
        sinal = 1;
        numero = -numero;
        printf("Valor negativo - bit de sinal = 1\n");
    } else {
        sinal = 0;
        printf("Valor não negativo - bit de sinal = 0\n");
    }

    // 2 - Converter a parte inteira e a parte fracionária para binário
    printf("2. Converter a parte inteira e a parte fracionária para binário:\n");
    int parteInteira = (int)numero;
    double parteFracionaria = numero - parteInteira;

    // 2.1 - parte inteira
    char binInt[64];
    int intIndex = 0;
    if (parteInteira == 0) {
        binInt[intIndex++] = '0';
    } else {
        while (parteInteira > 0) {
            binInt[intIndex++] = (parteInteira % 2) + '0';
            parteInteira /= 2;
        }
        for (int i = 0; i < intIndex / 2; i++) {
            char temp = binInt[i];
            binInt[i] = binInt[intIndex - i - 1];
            binInt[intIndex - i - 1] = temp;
        }
    }
    binInt[intIndex] = '\0';
    printf("2.1 Parte inteira em binário: %s\n", binInt);

    // 2.2 parte fracionária
    char binFrac[64];
    int fracIndex = 0;
    while (parteFracionaria > 0 && fracIndex < 52) {
        parteFracionaria *= 2;
        int bit = (int)parteFracionaria;
        binFrac[fracIndex++] = bit + '0';
        parteFracionaria -= bit;
    }
    binFrac[fracIndex] = '\0';
    printf("2.2 Parte fracionária em binário: %s\n", binFrac);

    // 3 - normalizar representação binária
    printf("3. Normalizar a representação binária - número na notação científica (1.mantissa * 2^expoente)\n");
    char binNormalizado[128];
    int exp = 0;
    if (binInt[0] != '0') {
        exp = intIndex - 1; // expoente = índice do último bit da parte inteira menos 1
        snprintf(binNormalizado, sizeof(binNormalizado), "%s%s", binInt, binFrac);
    } else {
        int shift = 0;
        while (binFrac[shift] == '0') {
            shift++;
        }
        exp = -shift - 1;
        snprintf(binNormalizado, sizeof(binNormalizado), "%s", binFrac + shift + 1);
    }
    printf("Representação binária normalizada: 1.%s * 2^%d\n", binNormalizado, exp);
    printf("Expoente: %d\n", exp);

    // 4 - determinar expoente com viés - 127 para float, 1023 para double
    printf("4. Determinar expoente com viés - 127 para float, 1023 para double\n");
    int vies = is_double ? 1023 : 127;
    int expoente = exp + vies;
    printf("Expoente com viés = %d + %d = %d\n", exp, vies, expoente);
    printf("Esse resultado deve ser convertido para binário.\n");

    // 5 - mantissa - 23 bits para float, 52 bits para double
    printf("5. Montar a mantissa - 23 bits para float, 52 bits para double\n");
    printf("A mantissa é a parte fracionária da representação normalizada:\n");
    int mantissaBits = is_double ? 52 : 23;
    char mantissa[53] = {0};
    
    if (binNormalizado[0] == '1') {
        strncpy(mantissa, binNormalizado + 1, mantissaBits);
    } else {
        strncpy(mantissa, binNormalizado, mantissaBits);
    }

    int mantissaLength = strlen(mantissa);
    for (int i = mantissaLength; i < mantissaBits; i++) {
        mantissa[i] = '0';
    }
    mantissa[mantissaBits] = '\0';
    printf("Mantissa: %s\n", mantissa);

    // 6 - resultado final = sinal + expoente + mantissa
    printf("6. Resultado final = sinal + expoente + mantissa\n");
    printf("Sinal: %d\n", sinal);
    printf("Expoente: ");
    for (int i = (is_double ? 10 : 7); i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
        if (i % 4 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf("\nMantissa: ");
    for (int i = 0; i < mantissaBits; i++) {
        printf("%c", mantissa[i]);
        if ((i + 1) % 4 == 0 && i != mantissaBits - 1) {
            printf(" ");
        }
    }
    printf("\n");
}