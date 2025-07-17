#include <stdio.h>

struct Produto {
    char nome[30];
    int codigo;
    int quantidade;
    float preco;
};

int main() {
    struct Produto produtos[10];
    float totalEstoque = 0;

    for (int i = 0; i < 10; i++) {
        printf("Produto %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", produtos[i].nome);
        printf("Código: ");
        scanf("%d", &produtos[i].codigo);
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
        printf("Preço: ");
        scanf("%f", &produtos[i].preco);
        printf("\n");

        totalEstoque += produtos[i].quantidade * produtos[i].preco;
    }

    printf("Produtos com quantidade menor que 5:\n");
    for (int i = 0; i < 10; i++) {
        if (produtos[i].quantidade < 5) {
            printf("Nome: %s | Código: %d | Quantidade: %d\n", produtos[i].nome, produtos[i].codigo, produtos[i].quantidade);
        }
    }

    printf("Valor total do estoque: R$ %.2f\n", totalEstoque);

    return 0;
}
