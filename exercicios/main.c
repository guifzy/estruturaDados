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

	fclose(arqv);
	return 0;
}
