#include <stdio.h>

int main(){

int n [10];
int soma;

for (int i=0;i<10;i++){
    printf("me informe o numero %d:",i + 1);
    scanf("%d",& n [i]);
    soma += n [i];
}

printf ("a soma do resultado desses numeros: %d",soma);


}
