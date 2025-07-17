#include <stdio.h>

int main(){
float temperatura[3][7],soma,media,temperaturamaior = -100;
int i,j,cidademaior,diamaior;

for (i=0;i<3;i++){
    printf("\nCidade %d:\n",i+1);
    for(j=0;j<7;j++){
        printf("Temperatura %d:",j+1);
        scanf("%f",&temperatura[i][j]);
        if(temperatura[i][j] > temperaturamaior){
            temperaturamaior = temperatura[i][j];
            cidademaior = i;
            diamaior = j;
        }

    }
}
printf("Media de temperatura de cada cidade:\n");
for (i=0;i<3;i++){
    soma =0;
    for(j=0;j<7;j++){
        soma+= temperatura[i][j];
    }
    media = soma / 7;
    printf("A media de temperatura da cidade %d:%.2fC\n",i+1,media);
}
printf("A temperatura mais alta da semana:%.2fC\n",temperaturamaior);
printf("Cidade :%d",cidademaior);
printf("Dia : %d",diamaior);







}
