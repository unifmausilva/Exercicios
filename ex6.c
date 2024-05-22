/*
#include <stdio.h>

#define MAX_NAME 50
typedef struct {
  char nome[MAX_NAME];
  int idade;
  float salario;
} Funcionario;

void cadastro_funcionario (FILE *file){
  Funcionario funcionarios;

  printf("Digite o nome do funcionário:");
  scanf("%s", funcionarios.nome);
  printf("Digite a idade do funcionario");
  scanf(" %d", &funcionarios.idade);
  printf("Digite o salario do funcionario");
  scanf(" %f", funcionarios.salario);

  fseek(file, 0, SEEK_END);
  fwrite(&funcionarios, sizeof(Funcionario), 1, file);
  printf("Registro adicionado com sucesso!\n");
  

  
}
void listar_funcionarios(FILE *file){
  Funcionario funcionarios;

  fseek(file, 0, SEEK_SET);
  while(fread(&funcionarios, sizeof(Funcionario), 1, file)){
    printf("Nome: %s\n Idade: %d \n Salario: %f \n",funcionarios.nome, funcionarios.idade, funcionarios.salario);
  }
}
void buscar_funcionario(FILE *file, const char *nome) {
    Funcionario funcionario;
    int encontrado = 0;

    fseek(file, 0, SEEK_SET);
    while (fread(&funcionario, sizeof(Funcionario), 1, file)) {
        if (strcmp(funcionario.nome, nome) == 0) {
            printf("Nome: %s, Idade: %d, Salário: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
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
    char nome[MAX_NAME_LENGTH];

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
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_funcionario(file);
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
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    fclose(file);
    return 0;
}

*/