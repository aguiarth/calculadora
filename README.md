# Calculadora Didática de Conversão entre Bases de Sistemas Numéricos

Este projeto é uma calculadora didática desenvolvida em C, projetada para converter números entre diferentes bases numéricas e representar números reais em formatos de ponto flutuante. O objetivo é auxiliar estudantes e entusiastas em computação na compreensão de conversões numéricas e a representação de números reais em computadores.

## Funcionalidades

A calculadora suporta as seguintes funcionalidades:

### 1. Conversões de Base 10 para Outras Bases

- **Base 2**: Conversão de números decimais para binário.
- **Base 8**: Conversão de números decimais para octal.
- **Base 16**: Conversão de números decimais para hexadecimal.
- **Código BCD**: Conversão de números decimais para o código decimal codificado em binário (Binary-Coded Decimal).

### 2. Conversão de Base 10 para Base com Sinal (16 bits)

- **Complemento a 2**: Conversão de números decimais para uma representação binária com sinal utilizando 16 bits (2 bytes).

### 3. Conversão de Reais em Decimal para `Float` e `Double`

- **Ponto Flutuante (Float e Double)**: Conversão de números reais em suas representações no formato [IEEE 754](https://en.wikipedia.org/wiki/IEEE_754), mostrando:
  - **Bits de Sinal**: Representação do sinal do número (positivo ou negativo).
  - **Expoente**: Exibição do valor do expoente.
  - **Expoente com Viés**: Exibição do expoente ajustado conforme o padrão IEEE 754.
  - **Fração (Mantissa)**: Representação da parte fracionária.

## Como Utilizar

1. **Clonagem do Repositório**: Clone o repositório para sua máquina local.

   ```bash
   git clone https://github.com/aguiarth/calculadora.git
   cd calculadora
   ```

2. **Compilação do Código**: Compile o código utilizando um compilador C.

   ```bash
   gcc -o calculadora calculadora.c
   ```

3. **Execução do Programa**: Execute o programa.

   ```bash
   ./calculadora
   ```

4. **Escolha a Conversão Desejada**: Siga as instruções no terminal para selecionar o tipo de conversão e insira o número a ser convertido.

## Estrutura do Projeto

- `calculadora.c`: Arquivo principal contendo a implementação das funcionalidades de conversão.
- `README.md`: Documentação do projeto.

## Futuras Melhorias

- Adicionar suporte para conversões de outras bases além da base 10.
- Implementar uma interface gráfica para facilitar o uso da calculadora.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests para melhorias e novas funcionalidades.

## Licença

Este projeto está licenciado sob a licença Creative Commons Attribution Share Alike 4.0 International ([CC-BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/)). Veja o arquivo [LICENSE](LICENSE.md) para mais detalhes.

---
