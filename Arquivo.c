#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    int matricula;
    char nome[20];
    char curso[20];
    float nota_final;
};


void inserirAluno(){
    struct Aluno a;
    char continuar[30];

    FILE*arquivo = fopen("alunos.dat","ab");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
        return;
    }

    printf("----- Menu Cadastro Alunos ------\n");
    printf("Matricula:");
    scanf("%d",&a.matricula);
    getchar();

    printf("Nome:");
    fgets(a.nome,20,stdin);
    a.nome[strcspn(a.nome,"\n")] = '\0';

    printf("Curso:");
    fgets(a.curso,20,stdin);
    a.curso[strcspn(a.nome,"\n")] = '\0';

    printf("Nota Final:");
    fgets(continuar,20,stdin);
    a.nota_final = atof(continuar);

    fwrite(&a,sizeof(a),1,arquivo);
    fclose(arquivo);

}

int main(){

int opcao;
do{
    printf("---- Menu ----\n");
    printf("1 - Deseja Cdastrar um aluno\n");
    printf("2 - Sair\n");
    printf("Escolha uma das opcao:");
    scanf("%d",&opcao);
    if(opcao == 1){
        inserirAluno();
    }else if(opcao == 2){
        printf("Programa Encerrado...");
    }else{
        printf("Resposta Incorreta!\n");
    }
}while(opcao != 2);




}
