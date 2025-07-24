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
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    fwrite(vetor, sizeof(int), TAM, arquivo);
    fclose(arquivo);
    printf("Números cadastrados com sucesso!\n");
}

void mostrarNumeros() {
    FILE *arquivo = fopen("numeros.dat", "rb");
    int vetor[TAM];

    if (arquivo == NULL) {
        printf("Arquivo não encontrado. Cadastre os números primeiro.\n");
        return;
    }

    fread(vetor, sizeof(int), TAM, arquivo);
    fclose(arquivo);

    printf("Números cadastrados: ");
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
        printf("Arquivo não encontrado. Cadastre os números primeiro.\n");
        return;
    }

    fread(vetor, sizeof(int), TAM, arquivo);
    fclose(arquivo);

    for (int i = 0; i < TAM; i++) {
        soma += vetor[i];
    }
    media = soma / (float)TAM;

    printf("Média dos números: %.2f\n", media);
    printf("Números maiores que a média: ");
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
        printf("1 - Cadastrar 10 números\n");
        printf("2 - Mostrar números\n");
        printf("3 - Mostrar média e maiores que a média\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
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
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
