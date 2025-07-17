#include <stdio.h>

struct Funcionario {
    char nome[50];
    char cargo[30];
    float salario;
};

int main() {
    struct Funcionario funcionarios[5];
    int indiceMaior = 0;

    for (int i = 0; i < 5; i++) {
        printf("Funcion�rio %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", funcionarios[i].nome);
        printf("Cargo: ");
        scanf(" %[^\n]", funcionarios[i].cargo);
        printf("Sal�rio: ");
        scanf("%f", &funcionarios[i].salario);
        printf("\n");

        if (funcionarios[i].salario > funcionarios[indiceMaior].salario) {
            indiceMaior = i;
        }
    }

    printf("Funcion�rio com maior sal�rio:\n");
    printf("Nome: %s\nCargo: %s\nSal�rio: R$ %.2f\n",
           funcionarios[indiceMaior].nome,
           funcionarios[indiceMaior].cargo,
           funcionarios[indiceMaior].salario);

    return 0;
}
