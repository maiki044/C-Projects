#include <stdio.h>

int main(){

int time [5][11],i= 0,j=0;
int idade [5][11],idade_menor_de_18;
float peso[5][11],altura[5][11],soma_idade_jogadores,soma_altura_jogadores,media_jogador_por_time;


for(i = 0; i< 5; i++){
    printf("time %d ------------------------\n",i+1);
    for (j = 0; j < 11;j++){
    printf("jogador %d --------\n",j+1);
    printf("idade:");
    scanf("%d",&idade[i][j]);
    printf("peso:");
    scanf("%f",&peso[i][j]);
    printf("altura:");
    scanf("%f",&altura[i][j]);
    }
    if (idade [i][j]<18){
        idade_menor_de_18++;
    }
    soma_idade_jogadores += idade [i][j];
    soma_altura_jogadores += altura[i][j];

}

printf("resultados:\n");
printf("quantidade de jogadores menores de 18 anos:%d\n",idade_menor_de_18);

for (i= 0;i < 5 ;i++){
    media_jogador_por_time = soma_idade_jogadores  /11;
    printf("a media de idade do time %d :%.2f\n",i+1,media_jogador_por_time);
}
printf("a media de altura de todos os jogadores:%.2f",soma_altura_jogadores/55);

}
