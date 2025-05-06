#include <stdio.h>

int main (){

int matriz [4][4],i,j,soma=0;

printf("digite os elementos da matriz 4x4:\n");

for(i=0;i<4;i++){
        for(j=0;j<4;j++){
        printf("elemento [%d][%d]:",i,j);
        scanf("%d",&matriz[i][j]);
    }
}
for (i=0;i<4;i++){
    for(j=0;j<4;j++){
        printf("soma da matriz %d:%d",j,soma);
        soma += matriz [i][j];
    }
    printf("\n");
}
}
