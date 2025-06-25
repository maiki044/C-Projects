#include <stdio.h>

int main(){

char turno,categoria,continuar;
float horastrabalhadas,SalarioHora = 0,Reajuste = 0,SalarioBruto = 0,SalarioReajustado = 0,imposto =0;

do{
int i;
    printf("Turno do funcionario (M- manha, V - Vespertino, N- Noturno):");
    scanf(" %c",&turno);

    printf("Categoria (O- Operario, G- Gerente):");
    scanf(" %c",&categoria);

    printf("Quantas horas trabalhadas:");
    scanf("%f",&horastrabalhadas);
    getchar();

    if (categoria == 'o'|| categoria == 'O'){
        SalarioHora = 39.89;
    }else if (categoria == 'g'|| categoria == 'G'){
        SalarioHora = 61.17;
    }

    if(turno == 'm'|| turno == 'M'){
        Reajuste = 0.10;
    }else if(turno == 'v'|| turno == 'V'){
        Reajuste = 0.15;
    }else if(turno == 'n'|| turno == 'N'){
        Reajuste = 0.12;
    }

    SalarioBruto = horastrabalhadas * SalarioHora;
    SalarioReajustado = SalarioBruto + (SalarioBruto * Reajuste);

    if(categoria == 'o' || categoria == 'O' && SalarioBruto <= 1600 ){
        imposto = 0.02;
    }else if(categoria == 'o' || categoria == 'O' && SalarioBruto > 1600 ){
        imposto = 0.05;
    }else if(categoria == 'g' || categoria == 'G' && SalarioBruto <= 4000 ){
        imposto = 0.08;
    }else if(categoria == 'g' || categoria == 'G' && SalarioBruto > 4000 ){
        imposto = 0.12;
    }
    float SalarioFinal = SalarioReajustado - (SalarioReajustado * imposto);

    printf("Salario Bruto: %.2f\n",SalarioBruto);
    printf("Salario Reajustado: %.2f\n",SalarioReajustado);
    printf("Salario com Imposto: %.2f\n",SalarioFinal);
    getchar();

    printf("Deseja continuar cadastrando? (S sim ou N nao):");
    scanf("%c",&continuar);

}while(continuar == 's'|| continuar == 'S');
}
