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
        printf("Escolha uma opç
