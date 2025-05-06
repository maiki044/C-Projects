#include <stdio.h>

int main(){

char continuar;
int i= 0,j,quantidade[100],codigo[100] ,processamento[100],contador = 0;

do {
    printf("me informe o codigo do produto %d:",i+1);
    scanf("%d",&codigo[i]);

    printf("quantidade em estoque do produto %d:",i+1);
    scanf("%d",&quantidade[i]);

    if (quantidade[i] < 50){
        processamento[contador] = codigo[i];
        contador++;
    }
    printf("\nDeseja cadastrar outro funcionário? (S/N): ");
    scanf(" %c", &continuar);
    i++;
}while (continuar == 'S' || continuar == 's');


    printf("produtos com quantidade menor que 50 em estoque:");
    for (j= 0;j<contador ;j++){
        printf("codigo :%d\n",processamento[j]);
    }

}
