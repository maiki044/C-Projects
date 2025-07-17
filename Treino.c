#include <stdio.h>

int main (){

float notas[10],soma = 0,media;
int i;

for (i=0;i<10;i++){
    printf("Nota do aluno %d:",i+1);
    scanf("%f",&notas[i]);
    soma += notas[i];
}
media = soma / 10;
printf("Media Geral da turma:%f",media);

for(i=0;i<10;i++){
    if(notas[i] > media){
        printf("Aluno %d: Aprovado!\n",i+1);
    }
}



}
