#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
    char email[50];
};

int main() {
    struct Contato contatos[10];
    char busca[50];

    for (int i = 0; i < 10; i++) {
        printf("Contato %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", contatos[i].nome);
        printf("Telefone: ");
        scanf(" %[^\n]", contatos[i].telefone);
        printf("Email: ");
        scanf(" %[^\n]", contatos[i].email);
        printf("\n");
    }

    printf("Digite o nome para buscar: ");
    scanf(" %[^\n]", busca);

    int encontrado = 0;
    for (int i = 0; i < 10; i++) {
        if (strcmp(contatos[i].nome, busca) == 0) {
            printf("Nome: %s\nTelefone: %s\nEmail: %s\n", contatos[i].nome, contatos[i].telefone, contatos[i].email);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }

    return 0;
}
