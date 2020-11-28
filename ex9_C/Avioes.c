#include <stdio.h>
#include <stdlib.h>
#include "Avioes.h"
#define MAX 40

struct aviao{
    char nome[MAX];
    int combustivel;
};


struct tipoNo{
    struct aviao dados;
    struct tipoNo* prox;
};

typedef struct tipoNo noFila;

struct noDescritor{
    int tam;
    struct tipoNo *inicio;
    struct tipoNo *fim;
};

avioes digitarDado(){
    avioes criada;
    fflush(stdin);

    printf("\n\t\t<< Insira os dados do Aviao >>\n");
    printf("TIPO: ");
    fgets(criada.nome,40,stdin);

    printf("QUANTIDADE COMBUSTIVEL: ");
    scanf("%d",&criada.combustivel);

    return criada;
}

Fila* criarFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));

    if(fila == NULL){
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;

    return fila;
}

int inserirFila(Fila* fila){
    if(fila == NULL){
        return 0;
    }

    avioes dado;
    noFila* no = (noFila*) malloc(sizeof(noFila));

    dado = digitarDado();
    no->dados=dado;
    no->prox = NULL;

    if(fila->inicio == NULL){
        fila->fim=no;
        fila->inicio=no;
    }
    else{
        noFila* aux;
        noFila* aux2;
        aux = fila->inicio;

        if(fila->inicio->dados.combustivel > no->dados.combustivel){
            no->prox = fila->inicio;
            fila->inicio = no;
        }

        else{
            while(aux != NULL && aux->dados.combustivel <= no->dados.combustivel){

                aux2 = aux;
                aux = aux->prox;
            }

            aux2->prox = no;
            no->prox = aux;

            if(aux2 == fila->fim){
                fila->fim = no;
            }

            else if(aux == fila->inicio){
                fila->inicio = no;
            }
        }
    }

    fila->tam++;

    return 1;
}

int removerFila(Fila* fila){
    if(fila == NULL){
        return 0;
    }

    noFila *aux;
    aux=fila->inicio;
    fila->inicio=fila->inicio->prox;

    free(aux);

    fila->tam--;

    return 1;
}

avioes consultarFila(Fila* fila){
    return fila->inicio->dados;
}

int imprimeFila(Fila* fila){
    if(fila == NULL){
        return 0;
    }

    noFila *aux;
    aux=fila->inicio;

    do{
        printf("\n\n\t<< DADOS DO AVIAO >>\n\n");
        printf("NOME: %s",aux->dados.nome);
        printf("QUANTIDADE COMBUSTIVEL: %d\n\n",aux->dados.combustivel);

        aux = aux->prox;

    }while(aux != NULL);

    return 1;
}

void liberaFila(Fila* fila){
    noFila* aux1;
    noFila* aux2;

    aux1 = fila->inicio;
    while(aux1 != fila->fim){
        aux2=aux1;
        aux1=aux1->prox;

        free(aux2);
    }
}

int tamanhoFila(Fila* fila){
    return fila->tam;
}

