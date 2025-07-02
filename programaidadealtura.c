#include <stdio.h>

int main(){

int idade[5];
int i,j;
float altura[5],peso[5],idade_mais_de_cinquenta = 0,idade_entre_dez_e_vinte = 0,soma_altura = 0, peso_40kg = 0;

for(i=0;i<5;i++){
    printf("Pessoa %d\n",i+1);
    printf("Idade:");
    scanf("%d",&idade[i]);
    printf("Altura:");
    scanf("%f",&altura[i]);
    printf("Peso:");
    scanf("%f",&peso[i]);
    if(idade[i] > 50){
        idade_mais_de_cinquenta++;
    }
    if(idade[i] > 10 && idade[i] < 20){
        idade_entre_dez_e_vinte++;
        soma_altura += altura[i];
    }
    if(peso[i]< 40){
        peso_40kg++;
    }
}
float porcentagem = (peso_40kg * 100.0)/5;
float mediadasaltura = soma_altura / idade_entre_dez_e_vinte;
printf("Quantidade de pessoas com idade superior a 50:%d\n",idade_mais_de_cinquenta);
printf("A media das alturas das pessoas com idade entre 10 a 20:%.2f\n",mediadasaltura);
printf("porcentagem :%.2f%%",porcentagem);


}
