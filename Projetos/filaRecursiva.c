#include<stdio.h>
#include<stdlib.h>

struct No{
    int valor;
    struct No* prox;
};

struct Fila{

    struct No* frente;
    struct No* tras;
};

typedef struct Fila fila;
typedef struct Fila* filaPtr;
typedef struct No no;


no* criarNo(int num)
{
    no* p = (no *)malloc(sizeof(no));
    p->valor = num;
    p->prox = NULL;
    return p;
}

 filaPtr criarFila()
 {
     filaPtr f = (filaPtr)malloc(sizeof(fila));
     f->frente = NULL;
     f->tras = NULL;

     return f;
 }

 void imprimirFila(filaPtr f)
 {
     no* aux = f->frente;
     printf("Elementos da fila:\n");
     while(aux != NULL)
     {
        printf("'%d' -> ", aux->valor);
        aux = aux->prox;
     }
     printf("'NULL'\n");

 }

 void enfileirarRecursivoAux(filaPtr fila, no* novoNo)
 {
    if (fila->frente == NULL) {
        fila->frente = novoNo;
        fila->tras = novoNo;
    } else {
        fila->tras->prox = novoNo;
        fila->tras = novoNo;
    }
    imprimirFila(fila);
 }

 void enfileirarRecursivo(filaPtr fila, int num[], int tam)
 {     
    if (tam == 0) {
        return;
    }
    no* novoNo = criarNo(num[0]);
    enfileirarRecursivoAux(fila, novoNo);
    enfileirarRecursivo(fila, &num[1], tam - 1); // ao passar o endereço da posição seguinte, o índice 0 será
                                                 // atualizado para a o próximo númro do array
 }

int main()
{
    filaPtr f = criarFila();
    int opcao, *num, tam;

    printf("|------------------------|\n");
    printf("|     FILA RECURSIVA     |\n");
    printf("|------------------------|\n");
    do{
        printf("\n|--------------------------|");
        printf("\n|  1- Adicionar elemento   |");
        printf("\n|  2- Imprimir fila        |");
        printf("\n|  3- Sair                 |");
        printf("\n|--------------------------|\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
             case 1://insere na fila
                printf("\nDigite quantos elementos deseja adicionar: ");
                scanf("%d", &tam);

                num = (int* )malloc(tam * sizeof(int));
                for(int i = 0; i < tam; i++)
                {
                    printf("\nDigite os numeros que desja adicinar a lista: ");
                    scanf("%d", &num[i]);
                    
                }
                enfileirarRecursivo(f, num, tam);
                break;

            case 2://imprime
                imprimirFila(f);
                break;

            case 3://sair
                printf("Programa encerrado.");
                opcao = 3;
                break;
            default:
                printf("\n|-----------------------------|");
                printf("\n|       OPCAO INVALIDA!       |");
                printf("\n|-----------------------------|");
                break;

        }
    }while(opcao != 3);

    while (f->frente != NULL) {
        no* temp = f->frente;
        f->frente = f->frente->prox;
        free(temp);   
    }
    free(num);
    free(f);

    return 0;
}
