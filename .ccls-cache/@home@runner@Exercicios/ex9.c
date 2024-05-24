

#include <stdio.h>
#include <stdlib.h>

// Função de comparação para usar no qsort
int comparar(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

// Função para calcular a média
float calcularMedia(int *array, int tamanho) {
  float soma = 0;
  for (int i = 0; i < tamanho; i++) {
    soma += array[i];
  }
  return soma / tamanho;
}

// Função para calcular a mediana
float calcularMediana(int *array, int tamanho) {
  qsort(array, tamanho, sizeof(int), comparar);
  if (tamanho % 2 == 0) {
    return (array[tamanho / 2 - 1] + array[tamanho / 2]) / 2.0;
  } else {
    return array[tamanho / 2];
  }
}

// Função para calcular a moda
int calcularModa(int *array, int tamanho) {
  qsort(array, tamanho, sizeof(int), comparar);

  int moda = array[0];
  int contagem = 1;
  int maxContagem = 1;

  for (int i = 1; i < tamanho; i++) {
    if (array[i] == array[i - 1]) {
      contagem++;
    } else {
      if (contagem > maxContagem) {
        maxContagem = contagem;
        moda = array[i - 1];
      }
      contagem = 1;
    }
  }

  // Verifica se o último elemento é a moda
  if (contagem > maxContagem) {
    moda = array[tamanho - 1];
  }

  return moda;
}

int main() {
  int tamanho;

  printf("Digite o tamanho do array: ");
  scanf("%d", &tamanho);

  // Alocando memória para o array
  int *array = (int *)malloc(tamanho * sizeof(int));

  // Verificando se a alocação de memória foi bem-sucedida
  if (array == NULL) {
    printf("Erro ao alocar memória.\n");
    return 1;
  }

  // Preenchendo o array
  printf("Digite os elementos do array:\n");
  for (int i = 0; i < tamanho; i++) {
    scanf("%d", &array[i]);
  }

  // Calculando a média, mediana e moda
  float media = calcularMedia(array, tamanho);
  float mediana = calcularMediana(array, tamanho);
  int moda = calcularModa(array, tamanho);

  // Imprimindo os resultados
  printf("Média: %.2f\n", media);
  printf("Mediana: %.2f\n", mediana);
  printf("Moda: %d\n", moda);

  // Liberando a memória alocada
  free(array);

  return 0;
}

