
#include <stdio.h>
#include <stdlib.h>

// Função para alocar memória para uma matriz
double **alocar_matriz(int linhas, int colunas) {
  double **matriz = (double **)malloc(linhas * sizeof(double *));
  for (int i = 0; i < linhas; i++) {
    matriz[i] = (double *)malloc(colunas * sizeof(double));
  }
  return matriz;
}

// Função para liberar memória alocada para uma matriz
void liberar_matriz(double **matriz, int linhas) {
  for (int i = 0; i < linhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
}

// Função para multiplicar duas matrizes
double **multiplicar_matrizes(double **matriz1, int linhas1, int colunas1,
                              double **matriz2, int linhas2, int colunas2) {
  if (colunas1 != linhas2) {
    printf("Não é possível multiplicar as matrizes. Número de colunas da "
           "matriz 1 não é igual ao número de linhas da matriz 2.\n");
    return NULL;
  }

  double **resultado = alocar_matriz(linhas1, colunas2);

  for (int i = 0; i < linhas1; i++) {
    for (int j = 0; j < colunas2; j++) {
      resultado[i][j] = 0;
      for (int k = 0; k < colunas1; k++) {
        resultado[i][j] += matriz1[i][k] * matriz2[k][j];
      }
    }
  }

  return resultado;
}

// Função para transpor uma matriz
double **transpor_matriz(double **matriz, int linhas, int colunas) {
  double **transposta = alocar_matriz(colunas, linhas);

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      transposta[j][i] = matriz[i][j];
    }
  }

  return transposta;
}

// Função para imprimir uma matriz
void imprimir_matriz(double **matriz, int linhas, int colunas) {
  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      printf("%.2f\t", matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  // Exemplo de uso das funções

  int linhas1 = 3, colunas1 = 2;
  int linhas2 = 2, colunas2 = 4;

  // Alocando e preenchendo a primeira matriz
  double **matriz1 = alocar_matriz(linhas1, colunas1);
  matriz1[0][0] = 1;
  matriz1[0][1] = 2;
  matriz1[1][0] = 3;
  matriz1[1][1] = 4;
  matriz1[2][0] = 5;
  matriz1[2][1] = 6;

  // Alocando e preenchendo a segunda matriz
  double **matriz2 = alocar_matriz(linhas2, colunas2);
  matriz2[0][0] = 1;
  matriz2[0][1] = 2;
  matriz2[0][2] = 3;
  matriz2[0][3] = 4;
  matriz2[1][0] = 5;
  matriz2[1][1] = 6;
  matriz2[1][2] = 7;
  matriz2[1][3] = 8;

  // Multiplicação das matrizes
  double **resultado_multiplicacao = multiplicar_matrizes(
      matriz1, linhas1, colunas1, matriz2, linhas2, colunas2);
  printf("Resultado da multiplicação:\n");
  imprimir_matriz(resultado_multiplicacao, linhas1, colunas2);

  // Transposição da primeira matriz
  double **transposta = transpor_matriz(matriz1, linhas1, colunas1);
  printf("Transposta da primeira matriz:\n");
  imprimir_matriz(transposta, colunas1, linhas1);

  // Liberando memória alocada
  liberar_matriz(matriz1, linhas1);
  liberar_matriz(matriz2, linhas2);
  liberar_matriz(resultado_multiplicacao, linhas1);
  liberar_matriz(transposta, colunas1);

  return 0;
}
