#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define MAX 16
#include"Exercicio26.h"


void insertionSort(int *V, int N){
    int i, j, aux;
    for(i = 1; i < N; i++){
        aux = V[i];
        for(j = i; (j > 0) && (aux < V[j - 1]); j--)
            V[j] = V[j - 1];
        V[j] = aux;
    }
}


void selectionSort(int *V, int N){
    int i, j, menor, troca;
    for(i = 0; i < N-1; i++){
        menor = i;
        for(j = i+1; j < N; j++){
            if(V[j] < V[menor])
                menor = j;
        }
        if(i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

void bubbleSort(int *V  , int N){
    int i, continua, aux;
    do{
        continua = 0;
        for(i = 0; i < N-1; i++){
            if (V[i] > V[i+1]){
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                continua = 1;
            }
        }
    }while(continua);
}


void imprimeVetor(int *v, int n){
    int i;

    printf("\n\n\t\t<<ELEMENTOS INSERIDOS>>\n");

    for(i = 0; i < n; i++){
        printf("%d ",v[i]);
    }

    printf("\n***********************************************************\n");
}
void imprimeDecrescente(int *v, int n){
    int i;

   printf("\n\t\t<<< ORDEM DECRESCENTE >>>\n");

    for(i = n-1; i >=0; i--){
        printf("%d ",v[i]);
    }

    printf("\n***********************************************************\n");
}

void imprimeCrescente(int *v, int n){
    int i;

    printf("\n\t\t<<< ORDEM CRESCENTE >>>\n");

    for(i = 0; i < n; i++){
        printf("%d ",v[i]);
    }

    printf("\n***********************************************************\n");
}

void merge(int *v,int ini, int meio,int fim){
    int i = ini, j = meio + 1, k = 0;
    int aux[MAX];

    while(i <= meio && j <= fim){
        if (v[i] <= v[j]){
            aux[k++] = v[i++];
        }else{
            aux[k++] = v[j++];
        }
    }
    while(i <= meio){
        aux[k++] = v[i++];
    }
    while(j <= fim){
        aux[k++] = v[j++];
    }

    for(i = ini, k = 0; i <= fim; i++,k++){
        v[i] = aux[k];
    }
}
void mergeSort (int *v, int esq, int dir){
    int meio;

    if(esq < dir){
        meio = (esq+dir)/2;

        mergeSort(v,esq,meio);

        mergeSort(v,meio+1,dir);

        merge(v,esq,meio,dir);
    }
}


