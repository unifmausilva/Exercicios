
  #include <stdio.h>
// Exercicio 2
int contar_vogais(char *str);

int main() {
  char str[100];

  // Solicita ao usuário que insira uma string
  printf("Digite uma string: ");
  fgets(str, sizeof(str), stdin);

  // Remove o caractere de nova linha ('\n') do final da string, se presente
  str[strcspn(str, "\n")] = '\0';

  // Conta e exibe o número de vogais na string
  int numero_vogais = contar_vogais(str);
  printf("O número de vogais na string é: %d\n", numero_vogais);

  return 0;
}

// Função para contar o número de vogais em uma string
int contar_vogais(char *str) {
  int count = 0;
  char c;
  while ((c = *str++) != '\0') {
    // Converte o caractere para minúscula
    c = tolower(c);
    // Verifica se o caractere é uma vogal
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      count++;
    }
  }
  return count;
}
