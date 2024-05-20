 #include <stdio.h>

int main(void) {
  int numeros;

  printf("Digite a Quantidade de números do Array :");
  scanf("%d", &numeros);
#include <stdio.h>
  
  int Array[numeros];

  printf("Digite os números do Array:", numeros);
  for (int i = 0; i < numeros; i++) {
    printf("Número %d:", i + 1);
    scanf("%d", &Array[i]);
  }

  // soma
  int soma = 0;
  for (int i = 0; i < numeros; i++) {
    soma += Array[i];
  }
  printf("A soma dos números do Array é : %d\n", soma);
}
