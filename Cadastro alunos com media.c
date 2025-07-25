#include <stdio.h>
#include <string.h>

// Definindo uma estrutura chamada "Aluno"
struct Aluno {
    char nome[50];
    float nota1;
    float nota2;
    float media;
};

// Fun��o que calcula a m�dia das notas
// Recebe um ponteiro para struct Aluno
void calcularMedia(struct Aluno *a) {
    a->media = (a->nota1 + a->nota2) / 2;
    // Acessamos os campos com seta (->) porque usamos ponteiro
}

// Fun��o que exibe os dados de um aluno
// Recebe a struct por valor (n�o precisa modificar)
void exibirAluno(struct Aluno a) {
    printf("Nome: %s\n", a.nome);
    printf("Nota 1: %.2f\n", a.nota1);
    printf("Nota 2: %.2f\n", a.nota2);
    printf("M�dia: %.2f\n", a.media);
    printf("----------------------\n");
}

int main() {
    // Criando um vetor com 3 alunos
    struct Aluno alunos[3];

    // Loop para entrada de dados dos alunos
    for(int i = 0; i < 3; i++) {
        printf("Digite o nome do aluno %d: ", i+1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        // Remove o \n do final, se existir
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Digite a nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Digite a nota 2: ");
        scanf("%f", &alunos[i].nota2);

        getchar(); // Limpa o buffer do teclado ap�s o scanf

        // Calcula a m�dia usando fun��o com ponteiro
        calcularMedia(&alunos[i]);
    }

    printf("\n===== Dados dos Alunos =====\n");

    // Mostra os dados dos alunos usando a fun��o void
    for(int i = 0; i < 3; i++) {
        exibirAluno(alunos[i]);
    }

    return 0;
}
