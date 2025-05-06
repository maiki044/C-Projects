#include <stdio.h>

void calcularDigitosCPF(int cpf[]) {
    int i, soma = 0, resto, primeiroDigito, segundoDigito;

    // Cálculo do primeiro dígito verificador
    for (i = 0; i < 9; i++) {
        soma += cpf[i] * (10 - i);
    }
    resto = soma % 11;
    primeiroDigito = (resto < 2) ? 0 : (11 - resto);

    // Cálculo do segundo dígito verificador
    soma = 0;
    for (i = 0; i < 9; i++) {
        soma += cpf[i] * (11 - i);
    }
    soma += primeiroDigito * 2;
    resto = soma % 11;
    segundoDigito = (resto < 2) ? 0 : (11 - resto);

    // Exibe o CPF completo com os dígitos verificadores
    printf("CPF completo: ");
    for (i = 0; i < 9; i++) {
        printf("%d", cpf[i]);
    }
    printf("-%d%d\n", primeiroDigito, segundoDigito);
}

int main() {
    int cpf[9] = {0, 5, 0, 2, 2, 5, 4, 3, 9};  // Exemplo de CPF sem os dígitos verificadores

    calcularDigitosCPF(cpf);

    return 0;
}
