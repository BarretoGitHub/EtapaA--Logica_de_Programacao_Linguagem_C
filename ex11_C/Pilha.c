#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define MAX 20

struct pilha{
    float num;
    struct pilha *prox;
};

typedef struct pilha pilhaNo;


Pilha* criarPilha(){
    Pilha* criada = (Pilha*) malloc(sizeof(Pilha));

    if(criada == NULL){
        return NULL;
    }

    *criada = NULL;

    return criada;
}

void inicializarComandos(Pilha* pilha){
    int check = 0;
    char vet[MAX];

    printf("\n\t<<<< BEM-VINDO A CALCULADORA >>>>\n\n");

    printf("\n\t\t<<< Menu >>> \n");
    printf("\nI - Imprimir operacao");
    printf("\nS - Sair");


    while(check != 1){
        printf("\n\nINSIRA o proximo numero ou operador: ");
        fflush(stdin);
        fgets(vet,MAX,stdin);

            switch(vet[0]){

            case '+':
                fazerContas(pilha,1);
                break;

            case '-':
                fazerContas(pilha,2);
                break;

            case '*':
                fazerContas(pilha,3);
                break;

            case '/':
                fazerContas(pilha,4);
                break;

            case 's' :
                check = 1;
                break;
            case 'i':
                imprimirPilha(pilha);
                break;

            default:
                adicionarNumero(pilha,vet);
                break;
            }

    }

}

int adicionarNumero(Pilha* topo, char vet[MAX]){
    if(topo == NULL){
        return 0;
    }

    float numero;
    numero = strtof(vet,NULL);

    pilhaNo* no = (pilhaNo*) malloc(sizeof(pilhaNo));

    no->num = numero;
    no->prox = *topo;
    *topo = no;

    return 1;
}

int fazerContas(Pilha* topo, int tipo){
        if(topo == NULL){
        return 0;
    }

    float el1,el2,res;

    pilhaNo* aux;
    pilhaNo* aux2;

    aux2 = *topo;
    aux = aux2->prox;
    el1 = aux2->num;
    el2 = aux->num;

    switch(tipo){
    case 1:
        res = el2 + el1;
        break;

    case 2:
        res = el2 - el1;
        break;

    case 3:
        res = el2 * el1;
        break;

    case 4:
        res = el2/el1;
        break;
    }

    aux->num = res;
    free(aux2);
    *topo = aux;

    return 1;
}


int imprimirPilha(Pilha* topo){
    if(topo == NULL){
        return 0;
    }
    pilhaNo* aux;
    aux = *topo;
    while(aux != NULL){
        printf("%0.2f\n",aux->num);
        aux = aux->prox;
    }

    return 1;
}

