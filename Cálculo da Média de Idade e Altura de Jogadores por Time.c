#include <stdio.h>


int main(){

int idade [5][11];
float peso [5][11], altura[5][11],soma_das_alturas = 0,media_idade_de_cada_time[5],soma_idade_time[5] = {0},idade_menor_de18 = 0;;
int i,j;


for (i = 0;i < 5;i++){
    printf("Time %d\n",i + 1);
    for (j = 0;j<11;j++){
        printf("jogador %d - idade:",j + 1);
        scanf("%d",&idade[i][j]);

        printf("jogador %d -Peso:",j + 1);
        scanf("%f",&peso[i][j]);

        printf("jogador %d - altura:",j + 1);
        scanf("%f",&altura[i][j]);

        soma_idade_time[i]+= idade[i][j];//porque colocar um vetor de tamanho 5 para essa variavel

        soma_das_alturas += altura[i][j];//porque eu não preciso percorrer os 5 loops

        if (idade[i][j]< 18){
            idade_menor_de18++;
        }
    }

}

printf ("Quantidade de jogadores menores de 18:%d",idade_menor_de18);

for (i = 0; i<5;i++){
    media_idade_de_cada_time[i]= soma_idade_time[i] / 11;
    printf("a media de idade do time %d e: %.2f\n",i+ 1 ,media_idade_de_cada_time[i]);
}

printf ("a media de altura e:%.2f",soma_das_alturas / 55);

}
