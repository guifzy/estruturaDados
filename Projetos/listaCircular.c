#include <stdio.h>
#include <stdlib.h>

struct Lista{

    struct No* inicio;
    struct No* fim;
    int tam;

};

struct No{
    int valor;
    struct No* prox;
    struct No* ant;

};
typedef struct Lista lista;
typedef struct No no;

lista* inicializa(){
    lista *l = (lista *)malloc(sizeof(lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

no* alocar(lista* l, int num){
    no* p = (no *)malloc(sizeof(no));
    p->valor = num;
    return p;
}

lista* inserir_comeco(lista* l, int num){
    no* novoNo = alocar(l, num);
    
    if (l->inicio == NULL)
    {
        l->inicio = novoNo;
        l->fim = novoNo;
        novoNo->prox = novoNo;
        novoNo->ant = novoNo;
    }else
    {
        novoNo->prox = l->inicio;
        novoNo->ant = l->fim;
        l->inicio->ant = novoNo;
        l->fim->prox = novoNo;
        l->inicio = novoNo;
    }

    l->tam ++;
    printf("Numero adicionado a lista!\n");
    return l;
}

lista* inserir_final(lista* l, int num){
    no* novoNo = alocar(l, num);

    if (l->inicio == NULL)
    {
        l->inicio = novoNo;
        l->fim = novoNo;
        novoNo->prox = novoNo;
        novoNo->ant = novoNo;
    }else
    {
        novoNo->ant = l->fim;
        novoNo->prox = l->inicio;
        l->fim->prox = novoNo;
        l->inicio->ant = novoNo;
        l->fim = novoNo;
    }

    l->tam ++;
    printf("Numero adicionado a lista!\n");
    return l;
}

lista* remover(){
    


}

void buscar(lista* l){
    no* aux = l->inicio;
    int busca;
    int contador = 1;
    int achou = 0;

    if(l->inicio == NULL)
    {
        printf("\nLista sem nenhum valor preenchido.");
        return;
    }
    printf("\nDigite o numero qu e deseja busacar na lista: ");
    scanf("%d", &busca);
    
    do
    {
        if (busca == aux->valor)
        {
            printf("Valor: %d | Posicao: %d", aux->valor, contador);
            achou = 1;
            break;          
        }
        aux = aux->prox;
        contador++;
        
    } while (aux != l->inicio);

    if (!achou) {
        printf("Número %d não encontrado na lista.\n", busca);
    }

}

void imprimir(lista* l){

    no* aux = l->inicio;

    if(l->inicio == NULL)
    {
        printf("Lista sem nenhum valor preenchido.");
        return;
    }

    printf("\n|-------------------------------|");
    printf("\n|      ELEMENTOS DA LISTA:      |");
    printf("\n|-------------------------------|\n");

    do{
        printf("Valor: %d -> ", aux->valor);
        aux = aux->prox;

    }while(aux != l->inicio);

    printf("-Final-\n");
    printf("Numero de elentos: %d", l->tam);

}

int main(){
    lista* l = inicializa();
    int num, opcoes;

    printf("\n|-------------------------------|");
    printf("\n|  BEM VINDO A LISTA CIRCULAR!  |");
    printf("\n|-------------------------------|\n");

    // fazer menu de op�oes
    do
    {
        printf("\n|------------------------------------|");
        printf("\n|  1- Adicionar no inicio da lista   |");
        printf("\n|  2- Adicionar no final da lista    |");
        printf("\n|  3- Remover item                   |");
        printf("\n|  4- Imprimir lista                 |");
        printf("\n|  5- Buscar item                    |");
        printf("\n|  6- Sair so programa               |");
        printf("\n|------------------------------------|\n");
        printf("\nInsira o numero correspondente a uma das opcoes acima: ");
        scanf("%d", &opcoes);

        switch (opcoes)
        {
            case 1://insere no inicio
                printf("\nDigite o numero que desja adicinar a lista: ");
                scanf("%d", &num);
                l = inserir_comeco(l, num);
                break;

            case 2://insere no final
                printf("\nDigite o numero que desja adicinar a lista: ");
                scanf("%d", &num);
                l = inserir_final(l, num);
                break;

            case 3://remove
                break;

            case 4://imprime
                imprimir(l);
                break;

            case 5://busca
                buscar(l);
                break;

            case 6://sair
                printf("\n   Programa encerrado.");
                opcoes = 6;
                break;

            default:
                printf("\n|-----------------------------|");
                printf("\n|       OPCAO INVALIDA!       |");
                printf("\n|-----------------------------|");
                break;
        }
    }while(opcoes != 6);

    return 0;
}
