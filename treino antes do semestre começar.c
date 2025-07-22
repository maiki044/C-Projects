#include <stdio.h>

int main (){
    int num;
    unsigned long long fatorial = 1;

    printf("Digite um numero inteiro nao-negativo:");
    scanf("%d",&num);

    if (num < 0){
        printf("Fatorial nao definido para numeros negativos");
    }else {
        for(int i = 1;  i<= num;i++){
            fatorial *= i;
        }
        printf("Fatorial de %d = %llu\n",num,fatorial);
    }

    return 0;

}
