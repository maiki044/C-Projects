#include <stdio.h>

#define MAX_ALUNOS 3
#define MAX_NOTAS 3

int cadastrarNotas(float notas[MAX_ALUNOS][MAX_NOTAS]) {
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("\nAluno %d:\n", i + 1);
        for (int j = 0; j < MAX_NOTAS; j++) {
            printf("Digite a nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
    return 1;
}

float calcularMedia(float notas[MAX_ALUNOS][MAX_NOTAS], int aluno) {
    float soma = 0;
    for (int i = 0; i < MAX_NOTAS; i++) {
        soma += notas[aluno][i];
    }
    return soma / MAX_NOTAS;
}

int listarNotas(float notas[MAX_ALUNOS][MAX_NOTAS]) {
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("\nAluno %d:\n", i + 1);
        for (int j = 0; j < MAX_NOTAS; j++) {
            printf("Nota %d: %.2f\n", j + 1, notas[i][j]);
        }
        float media = calcularMedia(notas, i);
        printf("Média: %.2f\n", media);
    }
    return 1;
}

int main() {
    float notas[MAX_ALUNOS][MAX_NOTAS];
    int opcao;
    int notasCadastradas = 0;

    do {
        printf("\n---- MENU ----\n");
        printf("1 - Cadastrar Notas\n");
        printf("2 - Listar Notas e Médias\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                notasCadastradas = cadastrarNotas(notas);
                break;
            case 2:
                if (notasCadastradas) {
                    listarNotas(notas);
                } else {
                    printf("Nenhuma nota cadastrada ainda.\n");
                }
                break;
            case 3:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 3);

    return 0;
}
