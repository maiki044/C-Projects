#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do aluno
struct Aluno {
    char nome[20];
    float nota1;
    float nota2;
};

// Função para cadastrar 5 alunos no arquivo binário
void CadastrarAlunos() {
    struct Aluno a;
    FILE* alunos = fopen("alunos.dat", "ab"); // Abre para acrescentar (append)

    if (alunos == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    for (int i = 0; i < 5; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Nome: ");
        getchar(); // Limpa o buffer antes do fgets
        fgets(a.nome, 20, stdin);
        a.nome[strcspn(a.nome, "\n")] = '\0'; // Remove o \n do final

        printf("Nota 1: ");
        scanf("%f", &a.nota1);

        printf("Nota 2: ");
        scanf("%f", &a.nota2);

        fwrite(&a, sizeof(struct Aluno), 1, alunos); // Escreve no arquivo
    }

    fclose(alunos); // Fecha o arquivo após o cadastro
}

// Função para calcular e mostrar a média de cada aluno
void CalcularMedia() {
    struct Aluno a;
    FILE* alunos = fopen("alunos.dat", "rb"); // Abre para leitura

    if (alunos == NULL) {
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n==== Resultados ====\n");

    // Lê cada aluno do arquivo e calcula a média
    while (fread(&a, sizeof(struct Aluno), 1, alunos) == 1) {
        float media = (a.nota1 + a.nota2) / 2;

        printf("\nAluno: %s\n", a.nome);
        printf("Nota 1: %.2f | Nota 2: %.2f | Média: %.2f --> ", a.nota1, a.nota2, media);

        if (media >= 6) {
            printf("Aprovado!\n");
        } else {
            printf("Reprovado!\n");
        }
    }

    fclose(alunos); // Fecha o arquivo após a leitura
}

// Função principal que exibe o menu
int main() {
    int opcao;

    do {
        printf("\n==== Menu Principal ====\n");
        printf("1 - Cadastrar alunos\n");
        printf("2 - Ver aprovações\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                CadastrarAlunos();
                break;
            case 2:
                CalcularMedia();
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}
