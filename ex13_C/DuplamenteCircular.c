#include <stdio.h>
#include <stdlib.h>
#include "DuplamenteCircular.h"
#define MAX 5

struct elemento{
    int numeros[MAX];
};

struct lista{
    struct elemento dado;
    struct lista *prox;

};

typedef struct lista tipoNo;

Lista* criarLista(){
    Lista* criada;
    criada = (Lista*) malloc(sizeof(Lista));
    if(criada != NULL){
        *criada=NULL;
    }
    return criada;
}

int insereInicio(Lista* inicio,struct elemento dado){
    if(inicio == NULL){
        return 0;
    }
    tipoNo* no;
    no = (tipoNo*) malloc(sizeof(tipoNo));
    if(no == NULL){
        return 0;
    }
    if(*inicio == NULL){
        *inicio = no;
        no->prox = *inicio;
        no->dado = dado;
        return 1;
    }
    else{
        tipoNo* aux = *inicio;
        while(aux->prox != *inicio){
            aux = aux->prox;
        }
        no->prox = *inicio;
        *inicio = no;
        no->dado = dado;
        aux->prox=*inicio;

    }

}

int inserirFinal(Lista* inicio,struct elemento dado){
    if(inicio == NULL){
        return 0;
    }
    tipoNo* no;
    no = (Lista*) malloc(sizeof(Lista));
    if(no == NULL){
        return 0;
    }

    tipoNo* aux = *inicio;
    while(aux->prox != *inicio){
        aux=aux->prox;
    }
    aux->prox = no;
    no->prox = *inicio;
    no->dado = dado;
    return 1;
}

void imprimeLista(Lista* inicio){
    if(inicio == NULL || (*inicio) == NULL){
         return;
    }

     Lista *no = *inicio;

    printf("LISTA: ");
    do{
        printf("%d\n",inicio->numeros[i]);
        no = no->prox;
    }while(no != (*inicio));

    printf("\n\n");

}

