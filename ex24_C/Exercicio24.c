#include<stdio.h>
#include<stdlib.h>

#include "Exercicio24.h"

//Busca Linear
int buscaLinear(int *V, int N, int elem){
    int i=0;
    for(i = 0; i < N; i++){
        if(elem == V[i])
            return i; //retorna a posição
    }
    return -1;
}

//Busca Ordenada
int buscaOrdenada(int *V, int N, int elem){
    int i;
    for(i = 0; i < N; i++){
        if(elem == V[i]){
            return i;//retorna a posição
        }
        else
            if(elem < V[i]){
                return -1;
            }
    }
    return -1;
}

//Busca Binária
int buscaBinaria(int *V, int N, int elem){
    int inicio, meio,fim;

    inicio = 0;
    fim = N-1;

    while(inicio <= fim){
        meio = (inicio + fim)/2;

        if(elem < V[meio]){
            fim = meio - 1;
        }

        else if(elem > V[meio]){
                inicio = meio + 1;
        }

        else if(!(elem > V[meio])){
                return meio;
        }

    }
    return -1;
}

