#include <stdio.h>

struct Produto {
  char nome_produto[20];
  float preco;
  int quantidade;
};

float calcular_total(struct Produto produtos[], int tamanho) {
  float total = 0;
  for (int i = 0; i < tamanho; i++) {
    total += produtos[i].preco * produtos[i].quantidade;
  }
  return total;
}

int main() {
  int num_produtos;
  printf("Quantos produtos você quer cadastrar? ");
  scanf("%d", &num_produtos);

  struct Produto produtos[num_produtos];

  for (int i = 0; i < num_produtos; i++) {
    printf("Nome do produto %d: ", i + 1);
    printf("\n");
    if (scanf("%s", produtos[i].nome_produto) != 1) {
      printf("Erro");
      return 1;
    }
    printf("Preço do produto %d: ", i + 1);
    printf("\n");
    if (scanf("%f", &produtos[i].preco) != 1) {
      printf("Erro");
      return 1;
    }
    getchar(); // Limpa o buffer
    printf("Quantidade do produto %d: ", i + 1);
    printf("\n");
    if (scanf("%d", &produtos[i].quantidade) != 1) {
      printf("Erro");
      return 1;
    }
    
  }

  for (int i = 0; i < num_produtos; i++) {
    printf("Produto: %s\nPreço: %.2f\nQuantidade: %d\n\n",
           produtos[i].nome_produto, produtos[i].preco, produtos[i].quantidade);
  }

  float total_estoque = calcular_total(produtos, num_produtos);
  printf("Valor total em estoque: R$%.2f\n", total_estoque);

  return 0;
}
