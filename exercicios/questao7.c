#include <stdio.h>
#include <string.h> 

typedef struct aluno {
    char nome[50];
    float nota1;
    float nota2;
    float nota3;

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
        printf("\nDigite o nome do aluno %d: ", i + 1);
        fgets(cadastros[i].nome, sizeof(cadastros[i].nome), stdin);

        printf("\nDigite a primeira nota: ");
        scanf("%f", &cadastros[i].nota1);
        getchar();

        printf("\nDigite a segunda nota: ");
        scanf("%f", &cadastros[i].nota2);
        getchar();

        printf("\nDigite a terceira nota: ");
        scanf("%f", &cadastros[i].nota3);
        getchar();

        fprintf(arqv, "%s; %.2f; %.2f;\n", cadastros[i].nome, cadastros[i].nota1, cadastros[i].nota2);
        printf("\nDados salvos no arquivo!");
        
    }
    fclose(arqv);

    return 0;
}
