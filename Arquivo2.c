#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void cadastrarNumeros() {
    FILE *arquivo = fopen("numeros.dat", "wb");
    int vetor[TAM];

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for (int i = 0; i < TAM; i++) {
        printf("Digite o %d� n�mero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    fwrite(vetor, sizeof(int), TAM, arquivo);
    fclose(arquivo);
    printf("N�meros cadastrados com sucesso!\n");
}

void mostrarNumeros() {
    FILE *arquivo = fopen("numeros.dat", "rb");
    int vetor[TAM];

    if (arquivo == NULL) {
        printf("Arquivo n�o encontrado. Cadastre os n�meros primeiro.\n");
        return;
    }

    fread(vetor, sizeof(int), TAM, arquivo);
    fclose(arquivo);

    printf("N�meros cadastrados: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void mostrarMediaEMaiores() {
    FILE *arquivo = fopen("numeros.dat", "rb");
    int vetor[TAM];
    int soma = 0;
    float media;

    if (arquivo == NULL) {
        printf("Arquivo n�o encontrado. Cadastre os n�meros primeiro.\n");
        return;
    }

    fread(vetor, sizeof(int), TAM, arquivo);
    fclose(arquivo);

    for (int i = 0; i < TAM; i++) {
        soma += vetor[i];
    }
    media = soma / (float)TAM;

    printf("M�dia dos n�meros: %.2f\n", media);
    printf("N�meros maiores que a m�dia: ");
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] > media) {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
}

int main() {
    int opcao;

    do {
        printf("\n------ MENU ------\n");
        printf("1 - Cadastrar 10 n�meros\n");
        printf("2 - Mostrar n�meros\n");
        printf("3 - Mostrar m�dia e maiores que a m�dia\n");
        printf("4 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarNumeros();
                break;
            case 2:
                mostrarNumeros();
                break;
            case 3:
                mostrarMediaEMaiores();
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
