#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#define MAX 10

struct lista{
    int prox;
    int numeros[MAX];
};

Lista* criarLista(){
    Lista *criada;

    criada=(Lista*)realloc(NULL,sizeof(struct lista));

    if(criada != NULL){
        criada->prox=0;
    }

    return criada;
}

int inserirFinal(Lista* lst,int num){
    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    lst->numeros[lst->prox]=num;
    lst->prox++;

    return 1;
}

int inserirInicio(Lista* lst,int num){
    int i;

    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    for(i=lst->prox-1;i>=0;i--){
        lst->numeros[i+1]=lst->numeros[i];
    }
    lst->numeros[0]=num;
    lst->prox++;

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

int removerInicio(Lista* lst){
    int i;

    if(lst == NULL){
        return 0;
    }
    for(i = 0;i<lst->prox;i++){
        lst->numeros[i]=lst->numeros[i+1];
    }
    lst->prox--;
    return 1;
}

int receberTam(Lista* lst){
    if(lst == NULL){
        return -1;
    }
    return lst->prox;
}

int verificarOrdem(Lista* lst){
    int i;
    int test = 0;

    for(i = 0;i < lst->prox; i++){
        if(lst->numeros[i] < lst->numeros[i+1]){
            test++;
        }
    }
    if(test == lst->prox){
        /*printf("\n\n<<LISTA ORDENADA >>\n");*/
        return 1;
    }
    else if(test == -lst->prox){
        /*printf("\n\n<<LISTA NAO ORDENADA >>");*/
        return 0;
    }
    else{
        /*printf("\n\n<< ERRO NA LISTA >>");*/
        return -1;
    }
}

void imprimirLista(Lista* lst){
    int i;
    if(lst->prox == 0){
        printf("\n\nLISTA VAZIA\n");
    }
    else{
        printf("\n\nIMPRIMINDO LISTA......\n");
        printf("\nLista: ");
        for(i = 0; i <lst->prox; i++){
            printf("%d , ",lst->numeros[i]);
        }
    }

    printf("\n\n");
}

void copiarLista(Lista* lst1, Lista* lst2){
    int i,j;
    int check;

    for(i = 0;i < lst1->prox;i++){
        check=0;
        for(j = 0;j < i; j++){
            if(lst1->numeros[j] == lst1->numeros[i]){
                check=1;
            }
        }
        if(check == 0){
            lst2->numeros[lst2->prox] = lst1->numeros[i];
            lst2->prox++;
        }
    }
}
