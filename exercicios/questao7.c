#include <stdio.h>
#include <string.h> 

typedef struct aluno {
    char nome[50];
    float nota1;
    float nota2;

} aluno;

aluno cadastros[5];
const int MAXALUNOS = sizeof(cadastros) / sizeof(cadastros[0]);

int main() {

    FILE* arqv;
    arqv = fopen("boletim.txt", "w");

    if (arqv == NULL)
    {
        printf("Erro ao abrir arquivo.");
        return 1;
    }

    for (int i = 0; i < MAXALUNOS; i++)
    {
        printf("\nDigite o nome do aluno: ");
        fgets(cadastros[i].nome, sizeof(cadastros[i].nome), stdin);
        getchar();

        printf("\nDigite a primeira nota: ");
        scanf("%f", &cadastros[i].nota1);

        printf("\nDigite a segunda nota: ");
        scanf("%f", &cadastros[i].nota2);

        fprintf(arqv, "%s; %.2f; %.2f;", cadastros[i].nome, cadastros[i].nota1, cadastros[i].nota2);

    }
    fclose(arqv);

    return 0;
}
