
#include <stdio.h>
#include <stdlib.h>
#include "ListaHeterogenea.h"
#define RET 0
#define TRI 1
#define CIR 2

struct retangulo{
    float b;
    float h;
};

typedef struct retangulo Ret;

struct triangulo{
    float b;
    float h;
};

typedef struct triangulo Tri;

struct circulo{
    float r;
};

typedef struct circulo Cir;

struct lista{
    int tipo;
    struct lista *prox;
    struct lista *ant;
    void* dado;
};
typedef struct lista tipoNo;


Ret* criarRetangulo(){
    Ret* criar = (Ret*) malloc(sizeof(Ret));
    printf("\n\t<<Insira dados do RETANGULO >>\n\n");

    printf("BASE: ");
    scanf("%f",&criar->b);

    printf("ALTURA: ");
    scanf("%f",&criar->h);

    return criar;
}

Tri* criarTriangulo(){
    Tri* criar = (Tri*) malloc(sizeof(Tri));

    printf("\n\t<<Insira dados do TRIANGULO >>\n\n");

    printf("BASE: ");
    scanf("%f",&criar->b);

    printf("ALTURA: ");
    scanf("%f",&criar->h);

    return criar;
}

Cir* criarCirculo(){

    Cir* criar = (Cir*) malloc(sizeof(Cir));

    printf("\n\t<<Insira dados do CIRCULO >>\n\n");

    printf("RAIO: ");
    scanf("%f",&criar->r);

    return criar;
}

/*CALCULANDO AS AREAS DAS FIGURAS GEOMETRICAS*/

float areaRetangulo(Ret* dado){
    float area;
    area = dado->b * dado->h;
    return area;
}

float areaTriangulo(Tri* dado){
    float area;
    area = (dado->b * dado->h)/2;
    return area;
}

float areaCirculo(Cir* dado){
    float area;
    area = 3.14 * (dado->r * dado->r);
    return area;
}



int imprimirRetangulo(Ret* dado){
    float area;
    area = areaRetangulo(dado);

    printf("\n<< IMPRIMINDO DADOS DO RETANGULO >>\n");
    printf("\nBASE: %.2f",dado->b);
    printf("\n\nALTURA: %.2f",dado->h);
    printf("\nAREA: %.2f\n",area);

    return 1;
}

int imprimirTriangulo(Tri* dado){
    float area;
    area = areaTriangulo(dado);

    printf("\n<< IMPRIMINDO DADOS DO TRIANGULO >>\n");

    printf("\nBASE: %.2f",dado->b);

    printf("\nALTURA: %.2f",dado->h);

    printf("\nAREA: %.2f\n",area);

    return 1;
}

int imprimirCirculo(Cir* dado){
    float area;
    area = areaCirculo(dado);

    printf("\n<< IMPRIMINDO DADOS DO CIRCULO >>\n");

    printf("RAIO: %.2f\n",dado->r);

    printf("AREA: %.2f\n",area);

    return 1;
}



Lista* criarLista(){
    Lista* criada = (Lista*) malloc(sizeof(Lista));

    if(criada != NULL){
        *criada=NULL;
    }
    return criada;
}

int inserirInicio(Lista* inicio, int tipo){

    if(inicio==NULL){
        return 0;
    }

    tipoNo* no = (tipoNo*) malloc(sizeof(tipoNo));

    if(no == NULL){
        return 0;
    }

    if(*inicio!=NULL){
        tipoNo* aux = (tipoNo*) malloc(sizeof(tipoNo));

        aux = *inicio;
        aux->ant=no;
    }

    no->tipo=tipo;
    no->ant=NULL;
    no->prox=*inicio;

    *inicio=no;

    switch(tipo){
        case RET:
            no->dado=criarRetangulo();
            break;

        case TRI:
            no->dado=criarTriangulo();
            break;

        case CIR:
            no->dado=criarCirculo();
            break;
    }

    return 1;
}

int inserirFinal(Lista* inicio, int tipo){

    if(inicio==NULL){
        return 0;
    }

    if(*inicio == NULL){
        inserirInicio(inicio,tipo);
        return 1;
    }

    tipoNo* aux = *inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    tipoNo* no = (tipoNo*) malloc(sizeof(tipoNo));

    if(no == NULL){
        return 0;
    }

    no->tipo=tipo;
    aux->prox=no;
    no->ant=aux;
    no->prox=NULL;

    switch(tipo){
        case RET:
            no->dado=criarRetangulo();
            break;

        case TRI:
            no->dado=criarTriangulo();
            break;

        case CIR:
            no->dado=criarCirculo();
            break;

    }

    return 1;
}

int imprimirLista(Lista* inicio){

    if(inicio == NULL || *inicio == NULL){
        return 0;
    }

    tipoNo* aux = *inicio;

    while(aux!=NULL){
        switch(aux->tipo){
            case RET:
                imprimirRetangulo(aux->dado);
                break;

            case TRI:
                imprimirTriangulo(aux->dado);
                break;

            case CIR:
                imprimirCirculo(aux->dado);
                break;

        }

        aux=aux->prox;
    }
    return 1;
}

int removerInicio(Lista* inicio){
    if(inicio == NULL || *inicio == NULL){
        return 0;
    }

    tipoNo* aux = *inicio;
    tipoNo* aux2;

    *inicio = aux->prox;
    aux2=aux->prox;
    aux2->ant=NULL;

    free(aux);

    return 1;
}

int removerFinal(Lista* inicio){
    if(inicio == NULL || *inicio == NULL){
        return 0;
    }

    tipoNo* aux = *inicio;

    while(aux->prox != NULL){
        aux=aux->prox;
    }

    aux=aux->ant;
    free(aux->prox);
    aux->prox=NULL;

    return 1;
}


