#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

typedef struct {
  char nome[MAX_NAME];
  int idade;
  float salario;
} Funcionario;

// Função de comparação para ordenar pelo campo idade
int compararIdade(const void *a, const void *b) {
  Funcionario *funcionarioA = (Funcionario *)a;
  Funcionario *funcionarioB = (Funcionario *)b;
  return (funcionarioA->idade - funcionarioB->idade);
}

void cadastro_funcionario(FILE *file) {
  Funcionario funcionarios;

  printf("Digite o nome do funcionário: ");
  scanf("%s", funcionarios.nome);
  printf("Digite a idade do funcionario: ");
  scanf("%d", &funcionarios.idade);
  printf("Digite o salario do funcionario: ");
  scanf("%f", &funcionarios.salario);

  fseek(file, 0, SEEK_END);
  fwrite(&funcionarios, sizeof(Funcionario), 1, file);
  printf("Registro adicionado com sucesso!\n");
}

void listar_funcionarios(FILE *file) {
  Funcionario funcionarios;

  fseek(file, 0, SEEK_SET);
  while (fread(&funcionarios, sizeof(Funcionario), 1, file)) {
    printf("Nome: %s\nIdade: %d\nSalario: %.2f\n", funcionarios.nome,
           funcionarios.idade, funcionarios.salario);
  }
}

void buscar_funcionario(FILE *file, const char *nome) {
  Funcionario funcionario;
  int encontrado = 0;

  fseek(file, 0, SEEK_SET);
  while (fread(&funcionario, sizeof(Funcionario), 1, file)) {
    if (strcmp(funcionario.nome, nome) == 0) {
      printf("Nome: %s, Idade: %d, Salário: %.2f\n", funcionario.nome,
             funcionario.idade, funcionario.salario);
      encontrado = 1;
      break;
    }
  }

  if (!encontrado) {
    printf("Funcionário com nome %s não encontrado.\n", nome);
  }
}

int main() {
  FILE *file;
  int opcao;
  char nome[MAX_NAME];

  file = fopen("funcionarios.bin", "a+b");
  if (file == NULL) {
    perror("Não foi possível abrir o arquivo");
    return 1;
  }

  do {
    printf("\nMenu:\n");
    printf("1. Adicionar novo funcionário\n");
    printf("2. Listar todos os funcionários\n");
    printf("3. Buscar funcionário por nome\n");
    printf("4. Ordenar funcionários por idade\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      cadastro_funcionario(file);
      break;
    case 2:
      listar_funcionarios(file);
      break;
    case 3:
      printf("Digite o nome do funcionário para buscar: ");
      scanf("%s", nome);
      buscar_funcionario(file, nome);
      break;
    case 4:
      // Ordenar funcionários por idade
      fseek(file, 0, SEEK_SET);
      Funcionario funcionarios[100]; // Supondo um máximo de 100 funcionários
      int num_funcionarios = 0;
      while (fread(&funcionarios[num_funcionarios], sizeof(Funcionario), 1,
                   file)) {
        num_funcionarios++;
      }
      qsort(funcionarios, num_funcionarios, sizeof(Funcionario), compararIdade);

      // Imprimir a lista atualizada
      printf("Lista de funcionários ordenada por idade:\n");
      for (int i = 0; i < num_funcionarios; i++) {
        printf("Nome: %s, Idade: %d, Salário: %.2f\n", funcionarios[i].nome,
               funcionarios[i].idade, funcionarios[i].salario);
      }

      // Reescrever o arquivo com os funcionários ordenados
      fseek(file, 0, SEEK_SET);
      fwrite(funcionarios, sizeof(Funcionario), num_funcionarios, file);
      printf("Funcionários ordenados por idade e arquivo atualizado.\n");
      break;
    case 5:
      printf("Saindo...\n");
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
    }
  } while (opcao != 5);

  fclose(file);
  return 0;
}
