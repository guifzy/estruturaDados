#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct dados {
    char nome[40];
    char sexo;
    int numHoras;
} dados;

void armazenar(dados alunos[], int max, FILE *arquivo) {
    for (int i = 0; i < max; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Digite o sexo do aluno %d (M/F): ", i + 1);
        scanf(" %c", &alunos[i].sexo);
        alunos[i].sexo = toupper((unsigned char) alunos[i].sexo);
        getchar();

        printf("Digite as horas diárias de estudo do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].numHoras);
        getchar();

        fwrite(&alunos[i], sizeof(dados), 1, arquivo);
    }
}

void maisHoras(int max, FILE *arqvLeitura) {
    dados alunoMaisHoras[3];
    dados temp;

    for (int i = 0; i < max; i++) {
        fread(&alunoMaisHoras[i], sizeof(dados), 1, arqvLeitura);
    }

    for (int i = 0; i < max - 1; i++) {
        for (int j = 0; j < max - i - 1; j++) {
            if (alunoMaisHoras[j].numHoras < alunoMaisHoras[j + 1].numHoras) {
                temp = alunoMaisHoras[j];
                alunoMaisHoras[j] = alunoMaisHoras[j + 1];
                alunoMaisHoras[j + 1] = temp;
            }
        }
    }

    printf("\nAlunos com mais horas de estudo:\n");
    for (int i = 0; i < max; i++) {
        printf("Nome: %s\n", alunoMaisHoras[i].nome);
    }
}

int main() {
    FILE *arqv;
    char nome[100];

    printf("Digite o nome do arquivo que deseja armazenar os dados: ");
    scanf("%s", nome);
    getchar();

    arqv = fopen(nome, "wb");
    if (arqv == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    dados alunos[3];
    const int MAXALUNOS = sizeof(alunos) / sizeof(alunos[0]);

    armazenar(alunos, MAXALUNOS, arqv);
    fclose(arqv);

    arqv = fopen(nome, "rb");
    if (arqv == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    maisHoras(MAXALUNOS, arqv);
    fclose(arqv);

    return 0;
}
