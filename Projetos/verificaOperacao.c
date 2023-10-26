#include<stdlib.h>
#include<stdio.h>

struct Pilha
{
    char dado;
    struct Pilha* prox;   
};

typedef struct Pilha pilha;
typedef struct Pilha* pilhaPtr;

void push(pilhaPtr* topo, char elemento) {
    pilhaPtr novoNo = (pilhaPtr)malloc(sizeof(pilha));
    novoNo->dado = elemento;
    novoNo->prox = *topo;
    *topo = novoNo;
}

char pop(pilhaPtr* topo) {
    pilhaPtr aux = *topo;
    char valor = (*topo)->dado;
    *topo = (*topo)->prox;
    free(aux);
    return valor;
}

void operacao(pilhaPtr* topo, char expressao[]) {
    
    char flag = '0';
    char top;
    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        if (c == '(' || c == '{' || c == '[') {
            push(topo, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if(*topo != NULL)
            {
                top = pop(topo);
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                {
                    push(topo, top);
                    flag = c;
                }                
            }else flag = c;                   
        }
    }
    
    if (*topo == NULL && flag == '0') 
    {
        printf("\n|-----------------------------|");
        printf("\n|       OPERACAO VALIDA!      |");
        printf("\n|-----------------------------|\n"); 
    }   
    else if(flag != '0')
    {
        printf("\n|------------------------------|");
        printf("\n|      OPERACAO INVALIDA!      |");
        printf("\n|------------------------------|\n"); 
        
    }else
    {
        printf("\n|------------------------------|");
        printf("\n|      OPERACAO INVALIDA!      |");
        printf("\n|------------------------------|\n"); 
    }    
}

void imprimir(pilhaPtr topo) {
    pilhaPtr temp = topo;
    if (temp == NULL)
    {
        printf("Lista vazia!\n");
        return;
    }
    printf("Conteudo remanescente da pilha:\n");
    while (temp != NULL) {
        printf("'%c' -> ", temp->dado);
        temp = temp->prox;
    }
    printf("'NULL'\n");
}

int main() {
    pilhaPtr p = NULL;
    int opcao;
    char expressao[50];

    do {
        printf("\n|------------------------------------|");
        printf("\n|  1- Inserir expressao              |");
        printf("\n|  2- Sair do programa               |");
        printf("\n|------------------------------------|\n");
        printf("\nInsira o numero correspondente a uma das opcoes acima: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a expressao: ");
                scanf("%s", expressao);
                if (expressao == NULL)
                {
                    printf("\n|------------------------------|");
                    printf("\n|      OPERACAO INVALIDA!      |");
                    printf("\n|------------------------------|\n"); 
                    break;
                }
                operacao(&p, expressao);
                imprimir(p);
                while(p != NULL) pop(&p);
                break;
            case 2:
                printf("\n   Programa encerrado.\n");
                break;
            default:
                printf("\n|-----------------------------|");
                printf("\n|       OPCAO INVALIDA!       |");
                printf("\n|-----------------------------|\n");
                break;
        }
    } while (opcao != 2);

    return 0;
}