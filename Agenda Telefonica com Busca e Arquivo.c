#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
    char email[50];
};

void cadastrarContato(struct Contato contatos[], int *quantidade) {
    if (*quantidade >= 10) {
        printf("Agenda cheia!\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", contatos[*quantidade].nome);
    printf("Telefone: ");
    scanf(" %[^\n]", contatos[*quantidade].telefone);
    printf("Email: ");
    scanf(" %[^\n]", contatos[*quantidade].email);
    (*quantidade)++;

    printf("Contato cadastrado com sucesso!\n");
}

void buscarContato(struct Contato contatos[], int quantidade) {
    char nomeBusca[50];
    printf("Digite o nome para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrou = 0;
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
            printf("Nome: %s\nTelefone: %s\nEmail: %s\n",
                   contatos[i].nome, contatos[i].telefone, contatos[i].email);
            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        printf("Contato não encontrado.\n");
    }
}

void salvarContatos(struct Contato contatos[], int quantidade) {
    FILE *f = fopen("agenda.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(f, "%s,%s,%s\n", contatos[i].nome, contatos[i].telefone, contatos[i].email);
    }

    fclose(f);
    printf("Contatos salvos em agenda.txt\n");
}

int main() {
    struct Contato contatos[10];
    int quantidade = 0, opcao;

    do {
        printf("\n--- MENU AGENDA ---\n");
        printf("1. Cadastrar Contato\n");
        printf("2. Buscar Contato\n");
        printf("3. Salvar Agenda em Arquivo\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarContato(contatos, &quantidade);
                break;
            case 2:
                buscarContato(contatos, quantidade);
                break;
            case 3:
                salvarContatos(contatos, quantidade);
                break;
            case 0:
                printf("Encerrando a agenda...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
