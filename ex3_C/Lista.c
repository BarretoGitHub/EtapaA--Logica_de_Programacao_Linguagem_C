#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#define MAX 20
#define MAXM 40

struct lista{
    int numeros[MAX];
    int prox;
};

struct listaM{
    int numeros[MAXM];
    int prox;
};

Lista* criarLista(){
    Lista *criada;

    criada=(Lista*)malloc(sizeof (struct lista));

    if(criada != NULL){
        criada->prox = 0;
    }
    return criada;
}

int inserirInicio(Lista* lst, int num){
    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    if(lst->prox == 0){

        lst->numeros[0] = num;
        lst->prox++;

        return 1;
    }
    else{
        int i;

        for(i=lst->prox;i>0;i--){
            lst->numeros[i] = lst->numeros[i-1];
        }

        lst->numeros[0] = num;
        lst->prox++;

        return 1;
    }
}

int inserirFinal(Lista* lst, int num){
    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    lst->numeros[lst->prox] = num;
    lst->prox++;

    return 1;
}

int inserirOrdenado(Lista* lst, int num){
    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    ordenarLista(lst);

    int i,j;

    for(i = 0; i < lst->prox; i++){
        if(lst->numeros[i] > num){
            for(j = lst->prox; j > i; j--){
                lst->numeros[j] = lst->numeros[j-1];
            }

            lst->numeros[i] = num;
            lst->prox++;

            return 1;
        }
    }
}

int removerInicio(Lista* lst){
    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    int i;
    for(i = 0;i < lst->prox; i++){
        lst->numeros[i]=lst->numeros[i+1];
    }
    lst->prox--;
    return 1;
}

int removerFinal(Lista* lst){
    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    lst->prox--;
    return 1;
}

int ordenarLista(Lista* lst){
    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    int i,j,aux;
    for(i = 1;i < lst->prox; i++){
        for(j = 0;j<lst->prox - i; j++){
            if(lst->numeros[j] > lst->numeros[j+1]){
                aux = lst->numeros[j];
                lst->numeros[j] = lst->numeros[j+1];
                lst->numeros[j+1] = aux;
            }
        }
    }
    return 1;
}

int ordenarListaMerge(ListaM* lst){
    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAXM){
        return 0;
    }

    int i,j,aux;
    for(i = 1;i < lst->prox; i++){
        for(j = 0;j < lst->prox - i; j++){
            if(lst->numeros[j] > lst->numeros[j+1]){
                aux = lst->numeros[j];
                lst->numeros[j] = lst->numeros[j+1];
                lst->numeros[j+1] = aux;
            }
        }
    }
    return 1;
}

int imprimirLista(Lista* lst){
    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    int i;
    for(i = 0;i <lst->prox; i++){
        printf("NUMERO %d: %d\n",i+1,lst->numeros[i]);
    }
    return 1;
}

int imprimirListaMerge(ListaM* lst){
    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAXM){
        return 0;
    }

    int i;
    for(i = 0;i < lst->prox; i++){
        printf("NUMERO %d: %d\n",i+1,lst->numeros[i]);
    }
    return 1;
}

ListaM* mergeListas(Lista* lst1, Lista* lst2){
    if(lst1 == NULL || lst2 ==NULL){
        return 0;
    }
    if(lst1->prox == MAX || lst2->prox == MAX){
        return 0;
    }

    ListaM* merge;

    merge = (ListaM*)malloc(sizeof(ListaM));
    int i,j,check=0;

    for(i = 0;i < lst1->prox;i++){
        merge->numeros[i] = lst1->numeros[i];
    }
    for(j = 0;i < MAX && j < lst2->prox; i++, j++){
        merge->numeros[i] = lst2->numeros[j];
    }
    merge->prox = i;
    ordenarListaMerge(merge);

    return merge;

}


