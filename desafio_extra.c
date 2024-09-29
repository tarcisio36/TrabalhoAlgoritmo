#include <stdio.h>
#include <limits.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");
  // LIMITE DOS DADOS:
  printf("          Tipo         |  Minimo | Maximo\n");
  printf("-----------------------|---------|--------\n");
  printf("char                   | %d      | %d\n", CHAR_MIN, CHAR_MAX);
  printf("int                    | %d      | %d\n", INT_MIN, INT_MAX);
  printf("short int              | %d      | %d\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned int           | %u      | %u\n", 0, UINT_MAX);
  printf("long int               | %ld     | %ld\n", LONG_MIN, LONG_MAX);
  printf("unsigned long int      | %lu     | %lu\n", 0, ULONG_MAX);
  printf("long long int          | %lld    | %lld\n", LLONG_MIN, LLONG_MAX);
  printf("unsigned long long int | %llu    | %llu\n", 0, ULLONG_MAX);

  // VALOR ACIMA DO LIMITE:
  int maiorValor = INT_MAX;
  int maiorValorMaisUm = INT_MAX + 1;
  printf("\nMaior valor + 1: %d", maiorValorMaisUm); // VALOR MAIOR DOQUE O ESPERADO
  printf("\nMaior valor: %d\n", maiorValor); //VALOR MAXIMO
  
  return 0;
}

