#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#define MAX 16

struct pilha{
    int vet[MAX];
    int topo1;
    int topo2;
};

Pilha* criaPilha(){
    Pilha* criada = (Pilha*) malloc(sizeof(Pilha));

    if(criada == NULL){
        return NULL;
    }
    criada->topo1 = 0;
    criada->topo2 = MAX - 1;

    return criada;
}

int pushPilha1(Pilha* pilha,int num){
    if(pilha->topo1 > pilha->topo2){
        return 0;
    }

    pilha->vet[pilha->topo1] = num;
    pilha->topo1++;

    return 1;
}

int popPilha1(Pilha* pilha){
    if(pilha->topo1 == 0){
        return 0;
    }

    pilha->topo1--;

    return 1;
}

int pushPilha2(Pilha* pilha,int num){
    if(pilha->topo2 < pilha->topo1){
        return 0;
    }
    pilha->vet[pilha->topo2] = num;
    pilha->topo2--;

    return 1;
}

int popPilha2(Pilha* pilha){
    if(pilha->topo2 == MAX-1){
        return 0;
    }
    pilha->topo1++;

    return 1;
}

int imprimePilha1(Pilha* pilha){
    if(pilha->topo1 == 0){
        return 0;
    }

    int i;
    for(i = 0;i < pilha->topo1; i++){
        printf("Elemento[%d]: %d\n",(i+1),pilha->vet[i]);
    }
    return 1;
}

int imprimePilha2(Pilha* pilha){
    if(pilha->topo2 == MAX-1){
        return 0;
    }

    int i;
    int elemento = 1;

    for(i = MAX - 1; i > pilha->topo2; i--){
        printf("Elemento [%d]: %d\n",(elemento),pilha->vet[i]);
        elemento++;
    }

    return 1;
}


