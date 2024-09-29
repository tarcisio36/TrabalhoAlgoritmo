#include <stdio.h>

int main() {
    float N1, N2, PPD, exame = 0, N3 = 0, menorNota = 0, notaFinal;
    int fez_exame, fezN3;

    // Leitura da N1
    printf("Digite a nota N1 (0 a 4.5): ");
    scanf("%f", &N1);
    if (N1 < 0 || N1 > 4.5) {
        printf("Erro 3: Nota N1 invalida!\n");
        return 3;
    }

    // Leitura N2
    printf("Digite a nota N2 (0 a 4.5): ");
    scanf("%f", &N2);
    if (N2 < 0 || N2 > 4.5) {
        printf("Erro 3: Nota N2 invalida!\n");
        return 3;
    }

    // Leitura PPD
    printf("Digite a nota PPD (0 a 1): ");
    scanf("%f", &PPD);
    if (PPD < 0 || PPD > 1) {
        printf("Erro 3: Nota PPD invalida!\n");
        return 3;
    }

    // Leitura se o estudante realizou o Exame 
    printf("Fez o Exame Unificado? (0 para nao, 1 para sim): ");
    scanf("%d", &fez_exame);
    if (fez_exame == 1) {
        // Leitura do Exame
        printf("Digite a nota do Exame Unificado (0 a 1): ");
        scanf("%f", &exame);
        if (exame < 0 || exame > 1) {
            printf("Erro 3: Nota do Exame Unificado invalido.\n");
            return 3;
        }
    } else if (fez_exame != 0) {
        printf("Erro 3: Exame Unificado invalido.\n");
        return 3;
    }

    // Leitura se realizou a N3
    printf("Fez a N3? (0 para nao, 1 para sim): ");
    scanf("%d", &fezN3);
    if (fezN3 == 1) {
        // Leitura e validação N3
        printf("Digite a nota N3 (0 a 4.5): ");
        scanf("%f", &N3);
        if (N3 < 0 || N3 > 4.5) {
            printf("Erro 3: Nota N3 invalida.\n");
            return 3;
        }

        // Substituição da menor nota por N3
        menorNota = (N1 < N2) ? N1 : N2;
        if (N3 > menorNota) {
            if (menorNota == N1) {
                N1 = N3;
            } else {
                N2 = N3;
            }
        }
    } else if (fezN3 != 0) {
        printf("Erro 3: Flag da N3 invalida!\n");
        return 3;
    }

    // Calculo da nota final
    notaFinal = N1 + N2 + PPD + exame;

    // Validaçao nota final esta correta
    if (notaFinal < 0 || notaFinal > 10) {
        printf("Erro: Nota final fora do intervalo valido!\n");
        return 3;
    }

    // Resultado final
    printf("Nota final: %.2f\n", notaFinal);
    if (notaFinal >= 6.0) {
        printf("Estudante aprovado!\n");
    } else {
        printf("Estudante reprovado!\n");
    }

    return 0;
}

