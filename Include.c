#include <stdio.h>

int main(){
    float numeros[10],numerospositivos=0,numerosnegativos = 0;;
    int i;

    for(i =0; i< 10; i++){
        printf("Me informe o numero %d:",i+1);
        scanf("%f",&numeros[i]);
        if(numeros[i] > 0){
            numerospositivos++;
        }else{
            numerosnegativos;
        }
    }

    printf("Numeros Positivos: %f",numerospositivos);
    printf("Soma numeros negativos: %f",numerosnegativos);


}

