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
        return ;
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

void listarProdutos(){

    struct Produto p;
    FILE*produtos = fopen("produtos.dat","rb");

    if(produtos == NULL){
        printf("Erro ao abrir arquivo");
        return ;
    }

    printf("\n========Lista de Produtos Cadastrados========\n");

    while (fread(&p,sizeof(struct Produto),1,produtos)== 1){
        printf("Codigo: %d\n",p.codigo);
        printf("nome: %s\n",p.nome);
        printf("preco: %.2f\n",p.preco);
        printf("quantidade: %d\n",p.quantidade);

    }

    fclose(produtos);

}

int main(){

    int opcao;

    do{
        printf("\nMenu de opcoes:");
        printf("1 - Cadastrar produtos\n");
        printf("2 - listar produtos\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao:");
        scanf("%d",&opcao);
        getchar();
    switch(opcao){
    case 1 :
        cadastrarProduto();
        break;
    case 2:
        listarProdutos();
        break;
    case 3 :
        printf("Saindo...");
        break;
    default:
        printf("opcao invalida");
    }
    }while(opcao != 3);

    return 0;
}
