#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    int codigo;
    char nome[20];
    float preco;
    int quantidade;
};

// Função para cadastrar um produto
void cadastrarProduto() {
    struct Produto p;
    FILE *produtos = fopen("produtos.dat", "ab");

    if (produtos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("\nCódigo do produto: ");
    scanf("%d", &p.codigo);
    getchar();

    printf("Nome do produto: ");
    fgets(p.nome, 20, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    printf("Preço: ");
    scanf("%f", &p.preco);

    printf("Quantidade: ");
    scanf("%d", &p.quantidade);

    fwrite(&p, sizeof(struct Produto), 1, produtos);
    fclose(produtos);

    printf("Produto cadastrado com sucesso!\n");
}

// Função para listar todos os produtos cadastrados
void listarProdutos() {
    struct Produto p;
    FILE *produtos = fopen("produtos.dat", "rb");

    if (produtos == NULL) {
        printf("Nenhum produto cadastrado ainda.\n");
        return;
    }

    printf("\n=== Lista de Produtos Cadastrados ===\n");

    while (fread(&p, sizeof(struct Produto), 1, produtos) == 1) {
        printf("Código: %d\n", p.codigo);
        printf("Nome: %s\n", p.nome);
        printf("Preço: R$ %.2f\n", p.preco);
        printf("Quantidade: %d\n", p.quantidade);
        printf("----------------------------\n");
    }

    fclose(produtos);
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
