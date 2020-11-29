#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define MAX 20
#include"Ex27.h"


void insertionSort(int *V, int N){
    int i, j, aux;
    int contComparacao = 0, contTroca = 0;

    for(i = 1; i < N; i++){
        aux = V[i];
        contComparacao++;

        for(j = i; (j > 0) && (aux < V[j - 1]); j--)
            V[j] = V[j - 1];
            V[j] = aux;
            contTroca++;

             //printf("\n<< PASSO A PASSO >>\n");
           //imprimeVetor(V,N);
    }

     tabelarDados(contComparacao,contTroca);
}


void selectionSort(int *V, int N){
    int i, j, menor, troca;
    int contComparacao = 0, contTroca = 0;

    for(i = 0; i < N-1; i++){
        menor = i;

        for(j = i+1; j < N; j++){
            contComparacao++;
            if(V[j] < V[menor])
                menor = j;
        }

        if(i != menor){
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
            contTroca++;

            //printf("\n<< PASSO A PASSO >>\n");
            //imprimeVetor(V,N);
        }
    }

     tabelarDados(contComparacao,contTroca);


}

void bubbleSort(int *V , int N){
    int i, continua, aux;
    int contComparacao = 0, contTroca = 0;

    do{
        continua = 0;
        for(i = 0; i < N-1; i++){
            contComparacao++;
            if (V[i] > V[i+1]){
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                continua = 1;
                contTroca++;
                //printf("\n<< PASSO A PASSO >>\n");
                //imprimeVetor(V,N);

            }
        }

    }while(continua);

    tabelarDados(contComparacao,contTroca);
}


void imprimeVetor(int *v, int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d ",v[i]);
    }

    printf("\n************************************* \n\n\n");
}


void merge(int *v,int ini, int meio,int fim){
    int i = ini, j = meio + 1, k = 0;
    int aux[MAX];
    int contComparacao = 0, contTroca = 0;

    while(i <= meio && j <= fim){
        if (v[i] <= v[j]){
            aux[k++] = v[i++];

        }

        else{
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

void tabelarDados(int cC,int cT){

    printf("\n\tQUANTIDADE DE COMPARACOES: %d",cC);

    printf("\n\tQUANTIDADE DE TROCAS: %d",cT);

}

void imprimirTabela(int *v,int n){

    printf(" \t---------------------------\n");
    printf(" \t<< Comparacao Tabelada >>\n");
    printf(" \t---------------------------\n");

   printf("--------------------------------------------\n");;

    printf("\t\t<< Bubble Sort >>\n");
    bubbleSort(v, n);

    printf("\n\n--------------------------------------------\n");;

    printf("\t\t<< Selection Sort >>\n");
    selectionSort(v,n);

    printf("\n\n--------------------------------------------\n");;

    printf("\t\t<< Insertion Sort >>\n");
    insertionSort(v,n);

    printf("\n\n--------------------------------------------\n");;


    //printf("\t\tMerge Sort");
   // mergeSort(v,0,n);

    //printf("\n\n--------------------------------------------\n");;

}





