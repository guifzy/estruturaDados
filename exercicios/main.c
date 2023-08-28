#include <stdio.h>

int main()
{
	FILE* arqv;
	char nome_arquivo[50], conteudo[100];
		
	printf("Entre com o nome do arquivo, o ponto e a extensão: ");
	scanf("%s", nome_arquivo);

	arqv = fopen(nome_arquivo, "r");

	if (arqv == NULL)
	{
		printf("Erro ao abrir arquivo.");
		return 1;
	}

	while (fgets(conteudo, sizeof(conteudo), arqv) != NULL)
	{
		printf("%s", conteudo);
	}

<<<<<<< HEAD
	fclose(arqv);
	return 0;
=======
    FILE* fh_input;
    fh_input = fopen("io.txt", "r");

    int finput = 0;
    int lines = 0;
    int numbers[100];

    
    while (fscanf(fh_input, "%d", &finput) != EOF)
    {
        
        numbers[lines] = finput;
        printf("file line %d: %d\n", lines + 1, finput);
        lines++;
    }

    int total = 0;
    for (int i = 0; i < lines; i++)
        total = i;
    printf("Average: %d\n", total + 1);

    fclose(fh_input);
 /*
    fh_input = fopen("in.txt", "r");


    fgets(buffer, 256, fh_input);
    printf("Buffer: %s\n", buffer);

    fclose(fh_input);
    */

    return 0;
>>>>>>> 7ab03322a29844b015adff978639f53059af656d
}
