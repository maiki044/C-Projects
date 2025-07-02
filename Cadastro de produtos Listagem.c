#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto{
    int codigo;
    char nome[20];
    float preco;
    int quantidade;
};

void cadastrarProduto(){
    struct Produto p;
    FILE*produtos = fopen("produtos.dat","ab");
    if(produtos == NULL){
        printf("Erro ao abrir arquivo");
        return 1;
    }

    printf("Me informe o codigo do produto:");
    scanf("%d",&p.codigo);
    getchar();
    printf("Me informe o nome do produto:");
    fgets(p.nome,20,stdin);

    printf("Preco do produto:");
    scanf("%f",&p.preco);

    printf("Me informe a Quantidade do produto:");
    scanf("%d",&p.quantidade);

    fwrite(&p,sizeof(struct Produto),1,produtos);
    printf("Produto Cadastrado com Sucesso!");
    fclose(produtos);
}

int main(){
    cadastrarProduto();
    return 0;
}
