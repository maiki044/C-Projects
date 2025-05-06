#include <stdio.h>

int main() {
    char turno[100], categoria[100], continuar;
    float horas_trabalhadas[100], salario_hora, coeficiente;
    float salario_bruto[100], salario_reajustado[100], imposto[100];
    int i = 0;

    do {
        printf("\nFuncionário %d\n", i + 1);

        // Turno
        printf("Qual o turno? [M - Manhã | V - Vespertino | N - Noturno]: ");
        scanf(" %c", &turno[i]);

        // Categoria
        printf("Qual a categoria? [O - Operário | G - Gerente]: ");
        scanf(" %c", &categoria[i]);

        // Horas trabalhadas
        printf("Horas trabalhadas: ");
        scanf("%f", &horas_trabalhadas[i]);

        // Define o salário por hora
        if (categoria[i] == 'O' || categoria[i] == 'o') {
            salario_hora = 39.89;
        } else if (categoria[i] == 'G' || categoria[i] == 'g') {
            salario_hora = 61.17;
        } else {
            salario_hora = 0; // valor inválido
        }

        // Define coeficiente de reajuste pelo turno
        if (turno[i] == 'M' || turno[i] == 'm') {
            coeficiente = 0.10;
        } else if (turno[i] == 'V' || turno[i] == 'v') {
            coeficiente = 0.15;
        } else if (turno[i] == 'N' || turno[i] == 'n') {
            coeficiente = 0.12;
        } else {
            coeficiente = 0; // valor inválido
        }

        // Cálculo dos salários
        salario_bruto[i] = horas_trabalhadas[i] * salario_hora;
        salario_reajustado[i] = salario_bruto[i] + (salario_bruto[i] * coeficiente);

        // Cálculo do imposto
        if ((categoria[i] == 'O' || categoria[i] == 'o') && salario_bruto[i] <= 1600.00) {
            imposto[i] = salario_bruto[i] * 0.02;
        } else if ((categoria[i] == 'O' || categoria[i] == 'o') && salario_bruto[i] > 1600.00) {
            imposto[i] = salario_bruto[i] * 0.05;
        } else if ((categoria[i] == 'G' || categoria[i] == 'g') && salario_bruto[i] <= 4000.00) {
            imposto[i] = salario_bruto[i] * 0.08;
        } else if ((categoria[i] == 'G' || categoria[i] == 'g') && salario_bruto[i] > 4000.00) {
            imposto[i] = salario_bruto[i] * 0.12;
        } else {
            imposto[i] = 0; // valor inválido
        }

        // Exibir os resultados
        printf("\nResumo do Funcionário %d\n", i + 1);
        printf("Salário Bruto       : R$ %.2f\n", salario_bruto[i]);
        printf("Salário Reajustado  : R$ %.2f\n", salario_reajustado[i]);
        printf("Imposto             : R$ %.2f\n", imposto[i]);

        // Perguntar se deseja continuar
        printf("\nDeseja cadastrar outro funcionário? (S/N): ");
        scanf(" %c", &continuar);

        i++;
    } while ((continuar == 'S' || continuar == 's') && i < 100);

    return 0;
}
