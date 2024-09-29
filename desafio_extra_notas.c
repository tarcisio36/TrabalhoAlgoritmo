#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
    float N1, N2, PPD, exameU = 0, N3 = 0, menorNota = 0, notaFinal;
    int fez_exame, fezN3, i;
    
    printf("Digite a nota N1: ");
    scanf("%f", &N1);
    printf("Digite a nota N2: ");
    scanf("%f", &N2);
    printf("Digite a nota PPD: ");
    scanf("%f", &PPD);
    
    if((N1 < 0 || N1 > 4.5) || (N2 < 0 || N2 > 4.5) || (PPD < 0 || PPD > 1)){
    	printf("Digite uma nota válida. (Erro 3)");
    	return 3;
	}
	
	printf("Você realizou o Exame Unificado? ");
	scanf("%d", &fez_exame);
	
	if(fez_exame != 0){
		printf("Digite a nota do Exame Unificado: ");
		scanf("%f", &exameU);
		
		if(exameU < 0 || exameU > 1){
			printf("Digite uma nota válida. (Erro 3)");
    		return 3;	
		}
	}
	
	printf("Você precisou realizar a N3? ");
	scanf("%d", &fezN3);
	
	if(fezN3 != 0){
		printf("Digite a nota da N3: ");
		scanf("%f", &N3);
		if(N3 < 0 || N3 > 4.5){
			printf("Digite uma nota válida. (Erro 3)");
    		return 3;	
		}
	}
	
	if(fezN3 != 0){
		if(N1 < N2){
			N1 = N3;
		}
		else if (N2 < N1){
			N2 = N3;
		}
	}
	
	notaFinal = (N1 + N2 + PPD + exameU);
	
	if(notaFinal < 0){
		notaFinal = 0;
	}
	else if(notaFinal > 10){
		notaFinal = 10;
	}
	
	printf("Nota final: %.2f\n", notaFinal);
	if(notaFinal >= 6){
		printf("Aprovado!\n");
	}
	else{
		printf("Reprovado.\n");
	}
	
	return 0;
}
