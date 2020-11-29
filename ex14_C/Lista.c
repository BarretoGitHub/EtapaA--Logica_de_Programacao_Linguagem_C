#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#define MAX 30

struct dados{
    float custo;
    char numero[MAX];
};

struct no{
    struct dados dados;
    struct tipoNo *prox;
};

typedef struct no noLista;

struct dados lerDados(){
    struct dados criado;

    printf("\n_______________________________\n");
    printf("\nInsira os DADOS A LIGACAO...");
    printf("\nNUMERO: ");
    fflush(stdin);
    gets(criado.numero);

    printf("CUSTO: ");
    scanf("%f",&criado.custo);

    return criado;
};

Lista* criarLista(){
    Lista* criada;

    criada = (Lista*) malloc(sizeof(Lista));

    if(criada == NULL){
        return NULL;
    }

    *criada = NULL;

    return criada;
}

int inserirLista(Lista* inicio){
    if(inicio == NULL){
        return NULL;
    }

    noLista* no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL){
        return 0;
    }
    no->dados = lerDados();

    if(*inicio == NULL){
        no->prox = no;
        *inicio = no;
    }
    else{
        int check = 0;
        noLista* aux = *inicio;
        noLista* aux2;

        while(aux->dados.custo > no->dados.custo && check == 0){
            aux2 = aux;
            aux = aux->prox;

            if(aux == *inicio){
                check = 1;
            }
        }
        if(aux == *inicio){
            aux2 = *inicio;

            while(aux2->prox != *inicio){
                aux2 = aux2->prox;
            }

            *inicio = no;
        }

        no->prox = aux;
        aux2->prox = no;
    }
    return 1;
}

int removerLista(Lista* inicio){
    char temp[MAX];

    fflush(stdin);
    printf("\n\nREMOVER QUAL NUMERO DA LISTA: ");
    gets(temp);

    noLista* aux = *inicio;
    noLista* aux2 = aux;

    int check = 0;
    while(aux2->prox != *inicio && check == 0){
        if(strcmp(aux->dados.numero,temp) == 0){
            check = 1;
        }
        else{
            aux2 = aux;
            aux = aux->prox;
        }
    }
    if(check == 0){
        printf("NUMERO INVALIDO.\n");

        return 0;
    }
    else{
        if(aux == *inicio){
            while(aux2->prox != *inicio){
                aux2 = aux2->prox;
            }
            *inicio = aux->prox;
        }

        aux2->prox = aux->prox;
        free(aux);

        printf("\nNUMERO EXCLUIDO!\n");

        return 1;
    }
}

int imprimirLista(Lista* inicio){
    if(inicio == NULL){
        return NULL;
    }

    noLista* aux = *inicio;

    int i = 1;
    while(aux->prox != *inicio){

        printf("(16)%s <consumiu> %.2f reais\n",aux->dados.numero,aux->dados.custo);
        i++;
        aux = aux->prox;
    }
    printf("(16)%s <consumiu> %.2f reais\n",aux->dados.numero,aux->dados.custo);

    return 1;
}


