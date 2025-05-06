#include <stdio.h>

int main(){

char turno[100],categoria[100],continuar;
int i = 0;
float horas_trabalhadas[100],Salario,Coeficiente_reajuste,Salario_bruto [100],Salario_reajustado [100],imposto = 0;

do {
    printf("funcionario %d\n", i + 1);
    printf("qual seu turno de trabalho: M - manhã V - Vespertino N - Noturno:");
    scanf(" %c",&turno[i]);
    printf("qual categoria O - Operario ou G - Gerente:");
    scanf(" %c",&categoria[i]);
    printf("horas trabalhadas:");
    scanf("%f",&horas_trabalhadas[i]);
    if (categoria [i] == 'O' || categoria [i] == 'o'){
        Salario = 39.89;
    }
    if (categoria [i] == 'G' || categoria [i] == 'g'){
        Salario = 61.17;
    }
    if (turno [i] == 'M' || turno [i]== 'm'){
        Coeficiente_reajuste = 0.10;
    }
    if (turno [i] == 'V' || turno [i]== 'v'){
        Coeficiente_reajuste  = 0.15;
    }
    if (turno [i] == 'N' || turno [i]== 'n'){
        Coeficiente_reajuste  = 0.12;
    }
    Salario_bruto [i] = horas_trabalhadas[i] * Salario;
    Salario_reajustado [i] = Salario_bruto [i] + (Salario_bruto [i] * Coeficiente_reajuste);
    if ((categoria [i] == 'O' || categoria [i] == 'o')&& Salario_bruto [i]<= 1600.00){
        imposto = Salario_bruto [i] * 0.02;
    }
    if ((categoria [i] == 'O' || categoria [i] == 'o')&& Salario_bruto [i]> 1600.00){
        imposto = Salario_bruto [i] * 0.05;
    }
    if ((categoria [i] == 'G' || categoria [i] == 'g')&& Salario_bruto [i]<= 4000.00){
        imposto = Salario_bruto [i] * 0.08;
    }
    if ((categoria [i] == 'G' || categoria [i] == 'g')&& Salario_bruto [i]> 4000.00){
        imposto = Salario_bruto [i] * 0.12;
    }
    printf("salario bruto:%.2f\n",Salario_bruto[i]);
    printf("salario reajustado:%.2f\n",Salario_reajustado[i]);
    printf("imposto que vai ter que pagar:%.2f\n",imposto);
    printf("deseja continuar cadastrando? responda com S ou N:");
    scanf(" %c",&continuar);
}while(continuar == 'S'|| continuar == 's');

}


