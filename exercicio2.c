#include <stdio.h>

int main(){

int numeros[15];
int i,j;

for (i = 0; i<15;i++){
    printf("Me informe o numero %d:",i+1);
    scanf("%d",&numeros[i]);
}

printf("\nQuantos numeros sao pares e quando sao impares:\n");
for(i=0;i<15;i++){
    if(numeros [i] % 2 == 0){
        printf("Numero %d : Par\n",i+1);
    }else {
        printf("Numero %d : Impar\n",i+1);
    }
}

}
