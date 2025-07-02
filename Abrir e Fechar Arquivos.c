#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
    char nome[50];//campos da struct
    int Idade;//campos da struct
};

int main(){

    FILE*arquivo;
    struct Pessoa p;//p é o nome da variavel
    int i;

    arquivo = fopen("pessoas.dat","wb");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
        return 1;
    }

    for(i=0;i<3;i++){
        printf("Digite o Nome da pesso %d:",i+1);
        fgets(p.nome,50,stdin);//p.nome é a parte da estrutura onde voce guarda um dos dados

        printf("Digite a Idade da Pessoa %d:",i+1);
        scanf("%d",&p.Idade);
        getchar();

        fwrite(&p,sizeof(struct Pessoa),1,arquivo);//Salva no arquivo
    }
    fclose(arquivo);//fechar o arquivo depois de salvar

    //abrir novamente o arquivo para leitura
    arquivo = fopen("pessoas.dat","wb");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
        return 1;
    }

    Printf("Pessoas Cadastradas____________\n");

    while(fread(&p,sizeof(struct Pessoa),1,arquivo)== 1){
        printf("Nome: %s",p.nome);
        printf("Idade: %d\n",p.Idade);
        printf("-------------------\n");
    }
    fclose(arquivo);

    return 0;

}
