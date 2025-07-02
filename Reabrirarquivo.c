#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura fora do main
struct cliente {
    int codigo;
    char nome[20];
    char sobrenome[20];
    float limite;
    char telefone[14];
    int rg;
};

// Função para inserir cliente no arquivo
void insere() {
    struct cliente fatec;
    FILE *fptr = fopen("clientes.dat", "ab"); // "ab" = append binário

    if (fptr == NULL) {
        printf("\nProblema na abertura do arquivo.\n");
        exit(1);
    }

    printf("\nInforme o nome: ");
    fgets(fatec.nome, 20, stdin);
    fatec.nome[strcspn(fatec.nome, "\n")] = '\0'; // remove \n

    printf("Informe o sobrenome: ");
    fgets(fatec.sobrenome, 20, stdin);
    fatec.sobrenome[strcspn(fatec.sobrenome, "\n")] = '\0';

    printf("Informe o limite do cliente: ");
    scanf("%f", &fatec.limite);
    getchar(); // limpar buffer

    printf("Informe o telefone: ");
    fgets(fatec.telefone, 14, stdin);
    fatec.telefone[strcspn(fatec.telefone, "\n")] = '\0';

    printf("Informe o RG: ");
    scanf("%d", &fatec.rg);
    getchar();

    // grava no arquivo
    fwrite(&fatec, sizeof(struct cliente), 1, fptr);

    printf("\nCliente cadastrado com sucesso!\n");

    fclose(fptr);
}

int main() {
    insere(); // chama a função para inserir cliente
    return 0;
}
