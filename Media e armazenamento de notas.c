#include <stdio.h>
#include <string.h>

#define QTD_ALUNOS 5
#define QTD_NOTAS 3

struct Aluno {
    char nome[50];
    float notas[QTD_NOTAS];
    float media;
};

void calcularMedia(struct Aluno *a) {
    float soma = 0;
    for(int i = 0; i < QTD_NOTAS; i++) {
        soma += a->notas[i];
    }
    a->media = soma / QTD_NOTAS;
}

int main() {
    struct Aluno alunos[QTD_ALUNOS];
    int qtdCadastrados = 0;
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Exibir Alunos Aprovados\n");
        printf("3. Exibir Todos os Alunos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch(opcao) {
            case 1:
                if(qtdCadastrados < QTD_ALUNOS) {
                    struct Aluno novo;

                    printf("Nome do aluno: ");
                    fgets(novo.nome, sizeof(novo.nome), stdin);
                    novo.nome[strcspn(novo.nome, "\n")] = '\0';

                    for(int i = 0; i < QTD_NOTAS; i++) {
                        printf("Nota %d: ", i + 1);
                        scanf("%f", &novo.notas[i]);
                    }
                    getchar(); // limpar buffer

                    calcularMedia(&novo);
                    alunos[qtdCadastrados] = novo;
                    qtdCadastrados++;
                } else {
                    printf("Limite de alunos atingido.\n");
                }
                break;

            case 2:
                printf("\n=== Alunos Aprovados ===\n");
                for(int i = 0; i < qtdCadastrados; i++) {
                    if(alunos[i].media >= 7) {
                        printf("Nome: %s | Média: %.2f\n", alunos[i].nome, alunos[i].media);
                    }
                }
                break;

            case 3:
                printf("\n=== Todos os Alunos ===\n");
                for(int i = 0; i < qtdCadastrados; i++) {
                    printf("Nome: %s | Média: %.2f\n", alunos[i].nome, alunos[i].media);
                }
                break;

            case 4:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 4);

    return 0;
}
