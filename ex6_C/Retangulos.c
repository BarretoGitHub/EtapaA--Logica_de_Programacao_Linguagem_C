#include <stdio.h>
#include <stdlib.h>
#include "Retangulos.h"

struct retangulo{
    float b;
    float h;
    float area;
};

typedef struct retangulo Retangulos;

struct No{
    struct retangulo dado;
    struct No* prox;
};

typedef struct No tipoNo;

Retangulos criarRetangulo(){
    Retangulos criar;

    printf("\n\t<<Insira dados do RETANGULO >>\n");

    printf("BASE: ");
    scanf("%f",&criar.b);

    printf("ALTURA: ");
    scanf("%f",&criar.h);

    criar.area = criar.b*criar.h;

    return criar;
}

Lista* criarLista(){
    Lista* criada = (Lista*) malloc(sizeof(Lista));

    if(criada == NULL){
        return NULL;
    }

    *criada = NULL;

    return criada;
}

int inserirInicio(Lista* inicio){
    if(inicio == NULL){
        return 0;
    }

    tipoNo* no;
    no = (tipoNo*) malloc(sizeof(tipoNo));

    if(no == NULL){
        return 0;
    }

    no->dado = criarRetangulo();
    no->prox = (*inicio);

    *inicio = no;

    return 1;
}

int inserirFinal(Lista* inicio){
    if(inicio == NULL){
        return 0;
    }

    tipoNo* no;
    no = (tipoNo*)malloc(sizeof(tipoNo));

    if(no == NULL){
        return 0;
    }

    tipoNo* aux;
    aux = *inicio;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = no;
    no->dado = criarRetangulo();
    no->prox = NULL;

    return 1;
}

int removerInicio(Lista* inicio){
    if(inicio == NULL){
        return 0;
    }

    tipoNo* aux = *inicio;
    *inicio = aux->prox;

    free(aux);

    return 1;
}

int removerFinal(Lista* inicio){
    if(inicio == NULL){
        return 0;
    }

    tipoNo* aux = *inicio;
    tipoNo* aux2;

    while(aux->prox != NULL){
        aux2 = aux;
        aux = aux->prox;
    }

    free(aux);
    aux2->prox = NULL;

    return 1;
}

int imprimirLista(Lista* inicio){
    tipoNo* aux;
    aux =*inicio;

    int i = 1;
    while(aux != NULL){
        printf("\n__________________________________________\n\n");

        printf("\t\t<<Retangulo %d >>\n",i);

        printf("\nBASE: %.2f\n",aux->dado.b);

        printf("\nALTURA: %.2f\n",i,aux->dado.h);

        printf("\nAREA: %.2f\n",aux->dado.area);

        aux = aux->prox;
        i++;
    }


    return 1;
}


