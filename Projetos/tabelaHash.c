#include<stdio.h>
#include <stdlib.h>

/*
Ao inserir 10 elementos a calculo para determinaro tamanho do vetor é:
2 * 10 = (numero primo mais proximo)
*/
#define MAX 21

struct No
{
    int chave;
    struct No* prox;
};
struct Lista
{
    struct No* inicio;
    int tam;
};

typedef struct Lista lista;
typedef struct No no;

void inicializa_lista(lista* l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void adiciona_lista(lista* l, int valor)
{
    no* novoNo = (no *)malloc(sizeof(no));

    if (novoNo)
    {
        novoNo->chave = valor;
        novoNo->prox = l->inicio;
        l->inicio = novoNo;
        l->tam++;
    }else
    {
        printf("Erro ao alocar memoria!\n");
    }
}

int encontra_lista(lista* l, int valor)
{
    no* aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->chave == valor)
        {
            return aux->chave;
        }
        aux = aux->prox;
    }

    return 0;
}

void imprime_lista(lista* l)
{
    no* aux = l->inicio;
    printf("Tamanho = %d ", l->tam);
    while (aux != NULL)
    {
        printf("Chave: %d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n"); 
}

int funcao_hash(int valor)
{
    return valor%MAX;
}

int encontrar_tabela(lista tabela[], int valor)
{
    int id = funcao_hash(valor);
    printf("id : %d\n", id);
    return encontra_lista(&tabela[id], valor);

}

void inicializa_tabela(lista tabela[])
{
    for (int i = 0; i < MAX; i++)
    {
        inicializa_lista(&tabela[i]);
    }
}

void insere_tabela(lista tabela[], int valor)
{
    int id = funcao_hash(valor);
    adiciona_lista(&tabela[id], valor);
}

void imprime_tabela(lista tabela[])
{
    for (int i = 0; i < MAX; i++)
    {
      printf("%d = ", i); 
      imprime_lista(&tabela[i]);
    }

}

int main()
{
    int valor, chave;

    lista tabela[MAX];
    inicializa_tabela(tabela);

    imprime_tabela(tabela);

    printf("Digite os 10 numeros que deseja adicionar na tabela: \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &valor);
        insere_tabela(tabela, valor);
    }

    imprime_tabela(tabela);

    printf("Digite o vlor que deseja encontrar: ");
    scanf("%d", &chave);
    printf("\n");
    encontrar_tabela(tabela, chave);

    return 0;
}