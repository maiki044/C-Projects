#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    char nome[30];
    float nota;
};

void CadastrarAluno (){
    struct Aluno a;
    FILE*arquivo = fopen("cadastraraluno.txt","ab");

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
        return 0;
    }
    for(int i = 0 ; i< 3 ; i++){
        printf("Me informe o nome do aluno:");
        fflush(stdin);
        fgets(a.nome,30,stdin);
        a.nome[strcspn(a.nome, "\n")] = '\0';

        printf("Me informe a nota do aluno:");
        scanf("%f",&a.nota);
        getchar();
        fwrite(&a,sizeof(struct Aluno),1,arquivo);
    }
    fclose(arquivo);

}

void VerAlunosCadastrados(){
    struct Aluno a;
    FILE*arquivo = fopen("cadastraraluno.txt","rb");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
        return 0;
    }
    printf("\n------ Alunos Cadastrados -----\n");
    while (fread(&a,sizeof(struct Aluno),1,arquivo)){
        printf("Nome: %s\n",a.nome);
        printf("Nota: %f\n",a.nota);
        printf("---------------\n");
    }
    fclose(arquivo);
}



int main(){
int opcao;
    do {

        printf("Menu de Opcao:\n");
        printf("1 - Cadastrar Aluno:\n");
        printf("2 - Ver alunos Cadastrados\n");
        printf("3 - Sair\n");
        printf("Escolha uma das opcoes:");
        scanf("%d",&opcao);

        switch (opcao){
        case 1 :
            CadastrarAluno ();
            break;
        case 2:
            VerAlunosCadastrados();
            break;
        case 3:
            printf("Encerrando programa...");
        break;
    }
}while (opcao != 3);

}
