#include <stdio.h>

#define MAX 100

int main() {
    int n, i;
    int produtos[MAX], quantidade[MAX], processamento[MAX], cont = 0;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Produto %d - Código: ", i + 1);
        scanf("%d", &produtos[i]);
        printf("Produto %d - Quantidade em estoque: ", i + 1);
        scanf("%d", &quantidade[i]);

        if (quantidade[i] < 50) {
            processamento[cont] = produtos[i];
            cont++;
        }
    }

    printf("\n--- Produtos com estoque abaixo de 50 ---\n");
    for (i = 0; i < cont; i++) {
        printf("Produto código: %d\n", processamento[i]);
    }

    return 0;
}
