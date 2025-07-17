#include <stdio.h>

struct Filme {
    char titulo[50];
    int ano;
    float nota;
};

int main() {
    struct Filme filmes[5];

    for (int i = 0; i < 5; i++) {
        printf("Filme %d\n", i + 1);
        printf("Título: ");
        scanf(" %[^\n]", filmes[i].titulo);
        printf("Ano: ");
        scanf("%d", &filmes[i].ano);
        printf("Nota (0 a 10): ");
        scanf("%f", &filmes[i].nota);
        printf("\n");
    }

    printf("Filmes com nota maior que 8:\n");
    for (int i = 0; i < 5; i++) {
        if (filmes[i].nota > 8) {
            printf("Título: %s | Ano: %d | Nota: %.1f\n", filmes[i].titulo, filmes[i].ano, filmes[i].nota);
        }
    }

    return 0;
}
