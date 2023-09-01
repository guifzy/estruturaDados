#include <stdio.h> 
#include <string.h>  

typedef struct aluno { 

    char nome[50]; 
    float nota1; 
    float nota2; 

} Aluno; 

Aluno cadastros[5]; 
const int MAXALUNOS = sizeof(cadastros) / sizeof(cadastros[0]); 

int main() { 

    FILE* arqv; 
    arqv = fopen("boletim.txt", "w"); 
  
    if (arqv == NULL) { 

        printf("Erro ao abrir arquivo."); 
        return 1; 
    } 

    for (int i = 0; i < MAXALUNOS; i++) { 

        printf("\nDigite o nome do aluno %d: ", i + 1); 
        fgets(cadastros[i].nome, sizeof(cadastros[i].nome), stdin); 
        cadastros[i].nome[strcspn(cadastros[i].nome, "\n")] = '\0';   

        printf("\nDigite a primeira nota: "); 
        scanf("%f", &cadastros[i].nota1); 
        getchar();  

        printf("\nDigite a segunda nota: "); 
        scanf("%f", &cadastros[i].nota2); 
        getchar(); 
  
        fprintf(arqv, "%s; %.2f; %.2f; \n", cadastros[i].nome, cadastros[i].nota1, cadastros[i].nota2); 
        printf("\nDados salvos no arquivo!"); 
    } 
  
    fclose(arqv); 
  
    FILE* arquivo = fopen("boletim.txt", "r"); 
     
    if (arquivo == NULL) { 

        printf("Erro ao abrir o arquivo.\n"); 
        return 1; 
    }  

    Aluno aluno; 
    char linha[100]; 

    while (fgets(linha, sizeof(linha), arquivo) != NULL) { 

        sscanf(linha, "%[^;]; %f; %f;", aluno.nome, &aluno.nota1, &aluno.nota2); 
        
        float media = (aluno.nota1 + aluno.nota2) / 2; 
        printf("%s %.1f %.1f\n Media: %.1f %s\n", aluno.nome, aluno.nota1, aluno.nota2, media, (media >= 5) ? "aprovado" : "reprovado"); 

    } 

    fclose(arquivo); 

    return 0; 

} 