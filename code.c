#include "remove.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    char mensagem[101];                 // variavel que armazena a mensagem em hexadecimal e o terminador nulo.
    char hexa[3];                       // vetor de caracteres usado para armazernar 2 caracteres da mensagem hexadecimal, alem do terminador nulo.
    int i, b, m, n, verificacao, x = 1; // Variáveis inteiras usadas como contadores, índices ou armazenamento temporário.
    char continua;                      // serve para armazenar a escolha do usuario se deseja continuar decodificando mais mensagens
    char fim[] = "00";                  // vetor de caracteres para indentificar o fim da mensagem.
    long int resultado;                 // uma variavel que armazena a conversão de hexadecimal para decimal.
    char mensagem_decodificada[m][101]; // Um vetor bidimensional de caracteres para armazenar as mensagens decodificadas
    // A primeira dimensão m é o número de mensagens, e a segunda dimensão 101 é o comprimento máximo de cada mensagem.

    // O programa entra em um laço do-while que continua a executar enquanto o usuário escolher continuar decodificando mensagens.
    //(ou seja, continua é igual a 's' ou 'S').
    do
    {
        // O programa solicita ao usuário que entre o número de mensagens que deseja decodificar e armazena a entrada em m.
        printf("Quantas mensagens deseja decodificar: ");
        scanf("%d", &m);
        // O programa itera m vezes para decodificar cada mensagem.
        for (n = 0; n < m; n++)
        {
            // O programa solicita ao usuário que entre um valor para b, que é usado no processo de decodificação.
            printf("\nDigite o valor de b: ");
            scanf("%d", &b);
            // O programa solicita ao usuário que entre uma mensagem hexadecimal, que é armazenada em mensagem.
            printf("Digite a mensagem em hexadecimal: ");
            scanf("%100s", mensagem);
            // Decodifica a mensagem hexadecimal.
            int indice = 0; // indice é inicializado como 0, que será usado como índice para armazenar os caracteres decodificados.
            // O laço itera sobre a mensagem hexadecimal em passos de 2 caracteres.
            //(já que cada valor hexadecimal é de 2 caracteres de comprimento).
            for (i = 0; i < strlen(mensagem); i += 2)
            {
                x = i / 2 + 1; // x é calculado como o índice dividido por 2 mais 1, que é usado na função func_val.
                // verificacao é definido como o resultado de chamar func_val com x e b como argumentos.
                // Se for diferente de zero, o processo de decodificação continua.
                verificacao = func_val(x, b);
                if (verificacao != 0)
                {
                    // O valor hexadecimal de 2 caracteres é extraído da mensagem e armazenado em hexa.
                    hexa[0] = mensagem[i];
                    hexa[1] = mensagem[i + 1];
                    hexa[2] = '\0';
                    // se o valor extraido for igual a 0 o laço quebra.
                    if (strcmp(hexa, fim) == 0)
                    {
                        break;
                    }
                    resultado = strtol(hexa, NULL, 16);                   // O valor hexadecimal e covertido em decimal usando strol e armazenado em resultado.
                    mensagem_decodificada[n][indice++] = (char)resultado; // O caractere decodificado e armazenado em mensagem_decodificada.
                }
            }
            mensagem_decodificada[n][indice] = '\0'; // O terminador nulo é adicionado ao fim da mensagem decodificada.
        }
        system("cls"); // limpa a tela antes de imprimir a mensagem.

        for (n = 0; n < m; n++)
        {
            printf("%s\n", mensagem_decodificada[n]); // O programa imprime cada mensagem decodificada armazenada em mensagem_decodificada.
        }
        // O programa pergunta ao usuário se deseja decodificar outra mensagem e armazena a escolha em continua.
        printf("\nDeseja decodificar outra mensagem (s/n): ");
        scanf(" %c", &continua);

    } while (continua == 's' || continua == 'S'); // verifica a escolha do usuário se for 's' ou 'S' ele continua para decodificar outra mensagem.

    return 0;
}