/*
#include <stdio.h>

void troca_letra(char *str) {
  char *ptr = str; // Ponteiro para percorrer a string

  while (*ptr != '\0') { // Loop até o final da string
    if (*ptr >= 'a' &&
        *ptr <= 'z') { // Verifica se o caractere é uma letra minúscula
      *ptr = *ptr - ('a' - 'A'); // Converte para maiúscula
    }
    ptr++; // Move para o próximo caractere
  }
}

int main() {
  char minuscula[100]; // Buffer para a string

  printf("Digite uma palavra: ");
  scanf("%99s", minuscula); // Lê a string do usuário

  troca_letra(minuscula);

  printf("A Palavra convertida é: %s\n", minuscula);

  return 0;
}


*/