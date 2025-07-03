#include <stdio.h>



struct Livro {
    int codigo;
    char titulo[20];
    char autor[20];
    float preco;
};

void CadastrarLivro(){
    struct Livro l;
    FILE*livros = fopen ("arquivo.dat","ab");//apenas abrir arquivos binarios
    if(livros == NULL){
        printf("Erro ao abrir arquivo");
        return ;
    }
    printf("Codigo:");
    scanf("%d",&l.codigo);
    getchar();

    printf("Titulo:");
    fgets(l.titulo,20,stdin);

    printf("Autor:");
    fgets(l.autor,20,stdin);

    printf("preco:");
    scanf("%f",&l.preco);

    fwrite(&l,sizeof(struct Livro),1,livros);
    fclose(livros);
}

void ListarTodosOsProdutos(){
   struct Livro l;
    FILE*livros = fopen ("arquivo.dat","rb");//ler arquivos
    if(livros == NULL){
        printf("Erro ao abrir arquivo");
        return ;
    }
    printf("====== listagem de Produtos cadastrados ======\n");
    while (fread(&l,sizeof(struct Livro),1,livros)== 1){
        printf("Codigo: %d\n",l.codigo);
        printf("Titulo: %s\n",l.titulo);
        printf("autor: %s\n",l.autor);
        printf("preco: %f\n",l.preco);
        printf("--------------------\n");
    }
    fclose(livros);
}

int main(){
    int opcao;
    do{
        printf("====Menu de opcoes====\n");
        printf("1 - Cadastrar produtos\n");
        printf("2 - Listar produtos\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao:");
        scanf("%d",&opcao);
        switch(opcao){
    case 1:
        CadastrarLivro();
        break;
    case 2:
        ListarTodosOsProdutos();
        break;
    case 3 :
        printf("Programa Finalizado...");
        break;
        }


    }while (opcao != 3);

return 0;


}






