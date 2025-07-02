#include <stdio.h>
int main(){

int idade[5],i;
char nome[5][20],maisvelho = 0,indicedomaisvelho;

for(i=0;i<5;i++){
    printf("Pessoa %d",i+1);
    printf("Qual seu nome:");
    scanf("%s",&nome[i]);
    printf("Qual sua idade:");
    scanf("%d",&idade[i]);
    if(idade[i] > maisvelho){
        maisvelho = idade[i];
        indicedomaisvelho = i;
    }

}
printf("Nome da pessoa mais velha:%s",nome [indicedomaisvelho]);

}
