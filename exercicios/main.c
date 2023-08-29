#include <stdio.h>
#include <string.h> 

typedef struct pessoa{
    char nome[50];
    int idade;
    float altura;
    char telefone[10];
} pessoa;

pessoa amigos[5];
const int MAX = 5;

int main() {
    int i = 0, achou = 0;
    char num[50];
    FILE* arqv;
    FILE* format;
    arqv = fopen("dados.txt", "w");

    if (arqv == NULL) {
        printf("Erro ao abrir arquivo");
        return 1;
    }

    for (i = 0; i < MAX; i++) {
        achou = 0;

        printf("\nDigite o telefone do amigo %d: ", i + 1);
        scanf("%9s", amigos[i].telefone);
        getchar();

        for (int j = 0; j < i; j++) {
            if (strcmp(amigos[i].telefone, amigos[j].telefone) == 0) {
                achou = 1;
                break;
            }
        }
        if (achou == 1) {
            printf("Esse telefone ja foi cadastrado");
            fclose(arqv);
            return 1;
        }
        else {
            printf("\nDigite o nome do amigo %d: ", i + 1);
            fgets(amigos[i].nome, sizeof(amigos[i].nome), stdin);

            printf("\nDigite a idade do amigo %d: ", i + 1);
            scanf("%d", &amigos[i].idade);

            printf("\nDigite a altura do amigo %d: ", i + 1);
            scanf("%f", &amigos[i].altura);
            getchar();

            fwrite(&amigos[i], sizeof(pessoa), 1, arqv);
        }
    }

    fclose(arqv);

    pessoa amigo[5];

    arqv = fopen("dados.txt", "r");
    format = fopen("amigosFormatados.txt", "w");

    if (arqv == NULL || format == NULL) {
        printf("Erro ao abrir arquivo");
        return 1;
    }

    for (i = 0; i < MAX; i++) {
        fread(&amigo[i], sizeof(pessoa), 1, arqv);
        fprintf(format, "[%s] tem [%d] anos e [%.2f] de altura.\nTel.: [%s].\n",
            amigo[i].nome, amigo[i].idade, amigo[i].altura, amigo[i].telefone);
    }

    fclose(arqv);
    fclose(format);

    return 0;
}
