/*
#include <stdio.h>
#include <stdlib.h>

// Função para inverter um array usando ponteiros
int* inverterArray(const int *array, int tamanho) {
    // Alocando memória para o novo array invertido
    int *arrayInvertido = (int*)malloc(tamanho * sizeof(int));

    // Verificando se a alocação de memória foi bem-sucedida
    if (arrayInvertido == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    // Ponteiro para o último elemento do array original
    const int *ptr_original = array + tamanho - 1;

    // Ponteiro para o primeiro elemento do novo array invertido
    int *ptr_invertido = arrayInvertido;

    // Copiando os elementos do array original para o novo array invertido na ordem inversa
    for (int i = 0; i < tamanho; i++) {
        *ptr_invertido = *ptr_original;
        ptr_invertido++;
        ptr_original--;
    }

    return arrayInvertido;
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    // Alocando memória para o array
    int *array = (int*)malloc(tamanho * sizeof(int));

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

    // Chamando a função para inverter o array
    int *arrayInvertido = inverterArray(array, tamanho);

    // Imprimindo o array invertido
    printf("Array invertido:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arrayInvertido[i]);
    }
    printf("\n");

    // Liberando a memória alocada
    free(array);
    free(arrayInvertido);

    return 0;
}
*/