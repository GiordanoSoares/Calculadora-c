#include <stdio.h>
#include <stdlib.h>

int main () {
    double n1, n2, soma, sub, div, multi;
    char resposta;
    char entrada[100];
    int selecione;

    do {
        // MENU COM VALIDAÇÃO
        do {
            printf("\n=============================== Calculadora Simples ===============================\n");
            printf("Selecione uma Operação:\n");
            printf("1. Adição\n");
            printf("2. Subtração\n");
            printf("3. Multiplicação\n");
            printf("4. Divisão\n");
            printf("5. Sair\n");
            printf("Escolha: ");
            
            fgets(entrada, sizeof(entrada), stdin);
            
            if (sscanf(entrada, "%d", &selecione) != 1 || selecione < 1 || selecione > 5) {
                printf("Opção inválida! Tente novamente.\n");
                selecione = 0; // Força repetição
            }
        } while (selecione < 1 || selecione > 5);

        // TRATAR OPÇÃO DE SAÍDA
        if (selecione == 5) {
            printf("Obrigado por usar a calculadora! Até a próxima.\n");
            return 0;
        }

        // LEITURA DOS NÚMEROS
        printf("Digite o primeiro número: ");
        scanf("%lf", &n1);
        printf("Digite o segundo número: ");
        scanf("%lf", &n2);
        getchar(); // limpa o \n do buffer

        // OPERAÇÕES
        switch (selecione) {
            case 1:
                soma = n1 + n2;
                printf("Resultado: %.2lf + %.2lf = %.2lf\n", n1, n2, soma);
                break;
            case 2:
                sub = n1 - n2;
                printf("Resultado: %.2lf - %.2lf = %.2lf\n", n1, n2, sub);
                break;
            case 3:
                multi = n1 * n2;
                printf("Resultado: %.2lf * %.2lf = %.2lf\n", n1, n2, multi);
                break;
            case 4:
                if (n2 == 0) {
                    printf("Erro: Divisão por zero não é permitida.\n");
                } else {
                    div = n1 / n2;
                    printf("Resultado: %.2lf / %.2lf = %.2lf\n", n1, n2, div);
                }
                break;
        }

        // PERGUNTA PARA CONTINUAR
        do {
            printf("Deseja realizar outra operação? (s/n): ");
            scanf(" %c", &resposta);
            getchar(); // limpa o \n
            if (resposta != 's' && resposta != 'S' && resposta != 'n' && resposta != 'N') {
                printf("Resposta inválida. Digite 's' para sim ou 'n' para não.\n");
            }
        } while (resposta != 's' && resposta != 'S' && resposta != 'n' && resposta != 'N');

    } while (resposta == 's' || resposta == 'S');

    printf("Obrigado por usar a calculadora! Até a próxima.\n");
    return 0;
}
