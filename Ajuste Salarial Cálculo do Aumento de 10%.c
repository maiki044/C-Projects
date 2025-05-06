#include <stdio.h>

#define TAMANHO_TURMA 10

int main() {
    float salario [3],salariomultiplicado;
    int i ;

    for (i=0;i<3;i++){
        printf("me iforme o salario %d:\n",i+1);
        scanf("%f",&salario[i]);
        salario[i] *= 1.10;
    }



    for (i=0; i<3;i++){
        printf("salario %d com  de aumento : %f\n",i+1,salario[i]);
    }
    return 0;
}
