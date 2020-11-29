#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

struct pilha{
    int op;
    struct pilha *prox;
};

typedef struct pilha noPilha;

Pilha* criarPilha(){
    Pilha* criada = (Pilha*) malloc(sizeof(Pilha));
    if(criada == NULL){
        return NULL;
    }
    *criada = NULL;
    return criada;
}

int pushPilha(Pilha* topo,int op){ //Empilhar Pilha
    if(topo == NULL){
        return 0;
    }

    noPilha* no = (noPilha*) malloc(sizeof(noPilha));
    if(no == NULL){
        return 0;
    }
    no->op = op;
    no->prox = *topo;
    *topo = no;

    return 1;
}

int popPilha(Pilha* topo){ //Desempilhar Pilha
    if(topo == NULL){
        return NULL;
    }

    noPilha* aux = *topo;

    int temp;
    temp = aux->op;
    *topo = aux->prox;

    free(aux); //liberando aux

    return temp;
}

int comandoRetornar(Pilha* topo){
    noPilha* aux1;
    noPilha* aux2 = NULL;

    printf("\n\t<<<Historico - Percurso do Robo >>\n\n");
    printf("\n\n...MOVIMENTOS DE IDA...\n\n");

    while(aux2 != *topo){
        aux1 = *topo;
        while(aux1->prox != aux2){
            aux1 = aux1->prox;
        }

        switch(aux1->op){
        case 1:
            printf("Frente\n");
            break;
        case 2:
            printf("Direita\n");
            break;
        case 3:
            printf("Esquerda\n");
            break;
        }
        aux2 = aux1;
    }

    printf("\n\t<<<Historico - Percurso do Robo >>\n");
    printf("\n\n...MOVIMENTOS DE VOLTA...\n\n");

    while(*topo != NULL){
        int flag = popPilha(topo);

        if(flag == 2){
            flag = 3;
        }

        else if(flag == 3){
            flag = 2;
        }

        switch(flag){
        case 1:
            printf("Frente\n");
            break;
        case 2:
            printf("Direita\n");
            break;
        case 3:
            printf("Esquerda\n");
            break;
        }
    }

    printf("\n\n.............Historico concluido com SUCESSO !!!...........\n\n\n");

    return 1;
}


