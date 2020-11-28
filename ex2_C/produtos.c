#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"
#define MAX 10
#define TAM 30

struct data{
    int dia;
    int mes;
    int ano;
};

struct produtos{
    int cod;
    char nome[TAM];
    float preco;
    int estoque;
    struct data data;
};

struct lista{
    int prox;
    Produto produtos[MAX];
};

Lista* criarLista(){
    Lista *criada;

    criada=(Lista*)malloc(sizeof(struct lista));
    if(criada != NULL){
        criada->prox = 0;
    }
    return criada;
}

Produto cadastrarProduto(){
    Produto criado;

    fflush(stdin);
    printf("\n\n\t\t<<Insira os dados do produto >>\n\n");
    printf("NOME: ");
    fgets(criado.nome,TAM,stdin);

    printf("PRECO: ");
    scanf("%f",&criado.preco);

    printf("ESTOQUE: ");
    scanf("%d",&criado.estoque);

    printf("\n\t\t<< Data da ultima compra >>\n");
    printf("DIA: ");
    scanf("%d",&criado.data.dia);

    printf("MES:");
    scanf("%d",&criado.data.mes);

    printf("ANO:");
    scanf("%d",&criado.data.ano);


    return criado;
}

void imprimirProduto(Produto pr){

    printf("\n\t<< HISTORICO DO PRODUTO >>\n");
    printf("\nCODIGO: %d",pr.cod);
    printf("\nNOME: %s",pr.nome);
    printf("\nPRECO: %.2f",pr.preco);
    printf("\nQUANTIDADE NO ESTOQUE: %d",pr.estoque);
    printf("\nDATA da ultima compra: %d/%d/%d\n",pr.data.dia,pr.data.mes,pr.data.ano);

}

int inserirFinal(Lista* lst){

    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }
    lst->produtos[lst->prox]=cadastrarProduto();
    lst->produtos[lst->prox].cod=lst->prox+1;

    printf("\nCODIGO DO PRODUTO: %d\n",lst->produtos[lst->prox].cod);
    lst->prox++;

    system("PAUSE"); /*pausando prompt*/

    return 1;
}

int inserirInicio(Lista* lst){
    int i;

    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    for(i = lst->prox-1; i >= 0; i--){
        lst->produtos[i+1]=lst->produtos[i];
    }

    lst->produtos[0] = cadastrarProduto(lst);
    lst->produtos[lst->prox].cod=lst->prox+1;

    printf("\nCODIGO DO PRODUTO: %d\n",lst->produtos[lst->prox].cod);
    lst->prox++;

    system("PAUSE"); /*pausando prompt*/

    return 1;
}

int removerFinal(Lista* lst){

    if(lst == NULL){
        return 0;
    }

    lst->prox--; /*Decrementando o prox*/

    return 1;
}

int removerInicio(Lista* lst){
    int i;

    if(lst == NULL){
        return 0;
    }
    for(i = 0; i< lst->prox; i++){
        lst->produtos[i]=lst->produtos[i+1];
    }

    lst->prox--;

    return 1;
}

int buscarMenorPreco(Lista* lst){
    int i,aux=0;

    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    for(i = 0; i< lst->prox; i++){
        if(lst->produtos[i].preco < lst->produtos[aux].preco){
            aux = i;
        }
    }

    imprimirProduto(lst->produtos[aux]);

    system("PAUSE"); /*pausando prompt*/

    return 1;
}

int buscarEstoqueInferior(Lista* lst){
    int i,teste;

    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    printf("\nDigite o tamanho do estoque maximo para a busca: ");
    scanf("%d",&teste);

    for(i = 0; i < lst->prox; i++){
        if(lst->produtos[i].estoque<teste){
            imprimirProduto(lst->produtos[i]);
        }
    }
    system("PAUSE"); /*pausando prompt*/
    return 1;
}

int alterarProduto(Lista* lst){
    int codalt;

    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    printf("\nInsira CODIGO para alterar : ");
    scanf("%d",&codalt);

    lst->produtos[codalt-1] = cadastrarProduto();

    printf("\nCODIGO NAO ALTERADO.\n");

    system("PAUSE");/*pausando prompt*/

    return 1;
}

int relatorioCrescente(Lista* lst){
    int casas,casatemp;
    int aux1,i;
    int aux2 = 0,maior = 0;

    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    for(i = 0; i < lst->prox; i++){
        if(lst->produtos[i].estoque>maior){
            maior=lst->produtos[i].estoque;
        }
    }
    maior++;

    for(casas = 0; casas < lst->prox; casas++){
        if(casas == 0){
            aux1 = lst->produtos[0].estoque;
            casatemp = 0;
            for(i = 0;i < lst->prox; i++){
                if(lst->produtos[i].estoque<aux1){
                    aux1 = lst->produtos[i].estoque;
                    casatemp = i;
                }
            }

            imprimirProduto(lst->produtos[casatemp]);
            aux2 = aux1;
        }
        else{
            aux1 = maior;
            for(i = 0; i < lst->prox; i++){
                if(lst->produtos[i].estoque<aux1 && lst->produtos[i].estoque>aux2){
                    aux1 = lst->produtos[i].estoque;
                    casatemp = i;
                }
            }
            imprimirProduto(lst->produtos[casatemp]);
            aux2 = aux1;
        }
    }
    system("PAUSE");/*PAUSANDO O prompt*/

    return 1;
}

int relatorioDecrescente(Lista* lst){
    int casas,i,casatemp;
    int aux1,aux2=0,menor=0;

    if(lst == NULL){
        return 0;
    }
    if(lst->prox == MAX){
        return 0;
    }

    for(i = 0;i < lst->prox; i++){
        if(lst->produtos[i].estoque<menor){
            menor = lst->produtos[i].estoque;
        }
    }
    menor--;

    for(casas=0;casas<lst->prox;casas++){
        if(casas == 0){
            aux1 = lst->produtos[0].estoque;
            casatemp = 0;
            for(i = 0;i < lst->prox; i++){
                if(lst->produtos[i].estoque>aux1){
                    aux1 = lst->produtos[i].estoque;
                    casatemp = i;
                }
            }
            imprimirProduto(lst->produtos[casatemp]);
            aux2 = aux1;
        }
        else{
            aux1 = menor;
            for(i = 0;i < lst->prox; i++){
                if(lst->produtos[i].estoque>aux1 && lst->produtos[i].estoque<aux2){
                    aux1 = lst->produtos[i].estoque;
                    casatemp = i;
                }
            }
            imprimirProduto(lst->produtos[casatemp]);
            aux2 = aux1;
        }
    }
    system("PAUSE"); /*pausando o prompt*/
    return 1;
}

