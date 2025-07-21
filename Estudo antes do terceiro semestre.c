#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[50];
    int codigo;
    int quantidade;
    float preco;
};

int main(){

    struct Produto produtos[10];
    int produtosmenorquecinco = 0;
    int somaestoque = 0;

    for(int i = 0; i<10;i++){
        printf("Produto %d:\n",i+1);
        printf("Nome:");
        fgets(produtos[i].nome,50,stdin);
        getchar();

        printf("codigo:");
        scanf("%f",& produtos[i].codigo);

        printf("Quantidade:");
        scanf("%d",&produtos[i].quantidade);

        printf("Peco:");
        scanf("%f",&produtos[i].preco);

        if (produtos[i].quantidade < 5){
            produtosmenorquecinco++;
        }
        somaestoque += produtos[i].quantidade;

    }

    printf("Tem %d produtos com menos de 5 quantidades em estoque",produtosmenorquecinco);
    printf("Valor total do estoque: %d",somaestoque);
}
