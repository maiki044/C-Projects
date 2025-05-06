#include <stdio.h>

int main (){

char turno[100],categoria[100],continuar;
int i = 0,horas_trabalhadas[100];
float Salario[100],reajuste = 0,Salario_Bruto[100],Salario_Reajustado[100],imposto[100];

do {
    printf ("funcionario %d\n",i+1);

    printf("Qual seu turno de trabalho ?responda com [M - Manhã V - Vespertino N - Noturno]:");
    scanf (" %c",&turno[i]);

    printf("qual sua categoria? responda com [O - operario ou G - Gerente]:");
    scanf (" %c",&categoria[i]);

    printf ("Quantas horas trabalhadas:");
    scanf("%d",&horas_trabalhadas[i]);

    if (categoria[i]== 'O'||categoria[i] == 'o'){
        Salario[i] = 39.89;
    }
    if (categoria[i] == 'G'||categoria[i] == 'g'){
        Salario[i] = 61.17;
    }
    if (turno[i] == 'M'||turno[i] == 'm' ){
        reajuste = 0.10;
    }
    if (turno[i] == 'V'||turno[i] == 'v' ){
        reajuste = 0.15;
    }
    if (turno[i] == 'N'||turno[i] == 'n' ){
        reajuste = 0.12;
    }

    Salario_Bruto[i] = horas_trabalhadas[i] * Salario[i];

    Salario_Reajustado[i] = Salario_Bruto[i] + (Salario_Bruto[i] * reajuste);

    if ((categoria[i] == 'O'||categoria == 'o') &&  Salario_Bruto[i] <= 1600.00){
        imposto[i] = Salario_Bruto[i] * 0.02;
    }
    if ((categoria[i] == 'O'||categoria == 'o') &&  Salario_Bruto[i] > 1600.00){
        imposto[i] = Salario_Bruto[i] * 0.05;
    }
    if ((categoria[i] == 'G'||categoria == 'g') &&  Salario_Bruto[i] <= 4000.00){
        imposto[i] = Salario_Bruto[i] * 0.08;
    }
    if ((categoria[i] == 'G'||categoria == 'g') &&  Salario_Bruto[i] > 4000.00){
        imposto[i] = Salario_Bruto[i] * 0.12;
    }

    printf("Salario bruto do funcionario:%.2f\n",Salario_Bruto[i]);
    printf("Salario Reajustado:%.2f\n",Salario_Reajustado[i]);
    printf("Salario com imposto:%.2f",imposto[i]);

    printf ("Deseja continuar cadastrando mais funcionarios? digite [S/N]");
    scanf(" %c",&continuar);


}while (continuar == 'S'||continuar == 's');

}
