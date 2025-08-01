#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 50

struct Cliente {
    char nome[50];
    char cpf[15];
    char telefone[15];
};

void CadastrarCliente(struct Cliente clientes[], int *quantidade) {
    if (*quantidade >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    printf("Nome: ");
    getchar(); // limpar buffer
    fgets(clientes[*quantidade].nome, 50, stdin);
    clientes[*quantidade].nome[strcspn(clientes[*quantidade].nome, "\n")] = 0;

    printf("CPF: ");
    fgets(clientes[*quantidade].cpf, 15, stdin);
    clientes[*quantidade].cpf[strcspn(clientes[*quantidade].cpf, "\n")] = 0;

    printf("Telefone: ");
    fgets(clientes[*quantidade].telefone, 15, stdin);
    clientes[*quantidade].telefone[strcspn(clientes[*quantidade].telefone, "\n")] = 0;

    (*quantidade)++;
    printf("Cliente cadastrado com sucesso!\n");
}

void ListarClientes(struct Cliente clientes[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\nLista de Clientes:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("\nCliente %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Telefone: %s\n", clientes[i].telefone);
    }
}

void BuscarCliente(struct Cliente clientes[], int quantidade) {
    char busca[50];
    printf("Digite o nome a buscar: ");
    getchar();
    fgets(busca, 50, stdin);
    busca[strcspn(busca, "\n")] = 0;

    int encontrado = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(clientes[i].nome, busca) == 0) {
            printf("\nCliente encontrado:\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Telefone: %s\n", clientes[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Cliente não encontrado.\n");
    }
}

int main() {
    struct Cliente clientes[MAX_CLIENTES];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n----- Menu -----\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Buscar Cliente\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                CadastrarCliente(clientes, &quantidade);
                break;
            case 2:
                ListarClientes(clientes, quantidade);
                break;
            case 3:
                BuscarCliente(clientes, quantidade);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
