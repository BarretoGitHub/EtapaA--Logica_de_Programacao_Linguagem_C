#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct lista{
    int dado;
    struct lista *prox;
};

typedef struct lista tipoNo;

Lista* criarLista(){
    Lista* criada = (Lista*) malloc(sizeof(Lista));

    if(criada != NULL){
        *criada = NULL;
    }

    return criada;
}

int inserirInicio(Lista* inicio, int num){
    if(inicio == NULL){
        return 0;
    }
    tipoNo* no;
    no = (tipoNo*) malloc(sizeof(tipoNo));

    if(no == NULL){
        return 0;
    }

    no->dado = num;
    no->prox = (*inicio);
    *inicio = no;

    return 1;

}

int inserirFinal(Lista* inicio, int num){
    if(inicio==NULL){
        return 0;
    }
    tipoNo* no;
    no = (tipoNo*)malloc(sizeof(tipoNo));

    if(no==NULL){
        return 0;
    }

    tipoNo* aux;
    aux = *inicio;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox=no;
    no->dado=num;
    no->prox=NULL;

    return 1;
}

int removerInicio(Lista* inicio){
    if(inicio==NULL){
        return 0;
    }

    tipoNo* aux = *inicio;
    *inicio = aux->prox;

    free(aux);

    return 1;
}

int removerFinal(Lista* inicio){
    if(inicio==NULL){
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
    aux=*inicio;

    int i =0;
    while(aux->prox != NULL){
        printf("Lista[%d]: %d\n",i,aux->dado);
        aux=aux->prox;
        i++;
    }

    return 1;
}

Lista* unionListas(Lista* inicio1, Lista* inicio2){
    Lista *uniao;
    uniao=criarLista();

    tipoNo* aux;
    aux=*inicio1;
    *uniao=aux;

    while(aux->prox != NULL){
        aux=aux->prox;
    }

    aux->prox=*inicio2;

    free(inicio2);
    free(inicio1);

    return uniao;
}


