#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define MAX 40

Pilha* criarPilha();

struct pilha{
    char letra;
    struct pilha *prox;
};

typedef struct pilha noPilha;

Pilha* criarPilha(){
    Pilha* criada = (Pilha*) malloc(sizeof(Pilha));

    if(criada == NULL){
        return;
    }

    return criada;
}

void inicializarComandos(Pilha* pilha){
    char vet[MAX];

    printf("INSIRA PALVRA:");
    fgets(vet,MAX,stdin);

    printf("\n\nPALAVRA INSERIDA: ");
    fputs(vet,stdout);

    inverterString(pilha,vet);

    printf("\n\nPALAVRA INVERTIDA: ");
    fputs(vet,stdout);
}

void inverterString(Pilha* pilha,char vet[MAX]){
    int i = 0,t1,t2;

    while(vet[i] != '\n'){
        if(i == 0){
            t1 = 0;
        }
        if(vet[i] == ' ' || vet[i] == '.'){
            t2 = i-1;
            invertePalavra(pilha,vet,t1,t2);
            t1 = i+1;
        }
        i++;
    }
}

void invertePalavra(Pilha* pilha,char vet[MAX],int t1,int t2){
    int i;
    char aux;

    for(i = t1; i< t2 + 1; i++){
        aux = vet[i];
        pilhaPush(pilha,aux);
    }
    for(i = t1;i < t2 + 1; i++){
        vet[i] = pilhaPop(pilha);
    }
}


int pilhaPush(Pilha* topo, char letra){
    noPilha* no = (noPilha*) malloc(sizeof(noPilha));

    no->letra = letra;
    no->prox = *topo;
    *topo = no;

    return 1;
}

char pilhaPop(Pilha* topo){
    char temp;

    noPilha* aux = *topo;
    temp = aux->letra;
    *topo = aux->prox;

    free(aux);

    return temp;
}


