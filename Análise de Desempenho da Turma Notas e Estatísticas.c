#include <stdio.h>


int main(){

float notas [15],mediaturma = 0;
int alunos = 0,soma = 0,acimadamedia,maiornota = 0,menornota = 100,reprovados = 0;


for (int i= 0; i< 10; i++){
    printf("me informe a nota do aluno %d:",i + 1);
    scanf("%f",&notas [i]);
    alunos++;
    soma += notas[i];
    mediaturma = soma / alunos;
    if (notas [i] > mediaturma){
        acimadamedia++;
    }
    if (notas [i] < 5){
        reprovados++;
    }
    if (notas[i] < menornota){
        menornota = notas[i];
    }
    if (notas[i] > maiornota){
        maiornota = notas[i];
    }
}

printf ("tem %d alunos acima da media\n",acimadamedia);
printf ("Alunos reprovados:%d\n",reprovados);
printf ("maior nota da sala:%d\n",maiornota);
printf ("menor nota da sala:%d\n",menornota);

}
