#include <stdio.h>

int main(){
    FILE *arq;
    char nome[50];
    int idade,i;
for(i=0;i<5;i++){
    arq = fopen("pessoas.txt","w");

    if(arq == NULL){
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    printf("Digite seu nome:");
    scanf("%s",&nome);

    printf("Digite sua idade:");
    scanf("%d",&idade);

    printf(arq,"nome: %s\nidade:%d",nome,idade);

    fclose(arq);
    printf("Dados salvos com sucesso\n");

    return 0;
}

}
