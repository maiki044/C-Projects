#include <stdio.h>

int main() {
    int notas[10];
    int i,contador = 0,soma= 0,maxima10= 0,minima= 0;
    float media= 0;
for (i = 0; i < 10; i++) {
        int nota_valida = 0;
        do {
            printf("De uma nota de 1 a 10 para o atendimento do cliente %d: ", i + 1);
            scanf("%d", &notas[i]);


            if (notas[i] < 1 || notas[i] > 10) {
                printf("Opcao invalida. Digite um número de 1 a 10.\n");
            } else {
                nota_valida = 1; // marca como válida
            }


        } while (!nota_valida);

            contador++;
            soma += notas[i] ;

            if (notas [i] == 10){
                maxima10++;
            }
            if (notas [i] < 5){
                minima++;
            }
    }



    printf("Media geral de notas dos clientes:%d",soma/contador);
    printf("Clientes que deram nota maxima:%d",maxima10);
    printf("Clientes que deram nota minima:%d",minima);
    return 0;
}
