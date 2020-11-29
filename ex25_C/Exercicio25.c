#include<stdio.h>
#include<stdlib.h>

#include"Exercicio25.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

int insere_lista(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }

    if(li->qtd == MAX){
        return 0;
    }


    li->dados[li->qtd] = al;
    li->qtd++;

    return 1;
}

void mergeSort(Lista *V, int inicio, int fim){
    int meio;

    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V,inicio,meio);
        mergeSort(V,meio+1,fim);
        merge(V,inicio,meio,fim);
    }
}

void merge(Lista *V, int inicio, int meio, int fim){
    int p1, p2;
    int tamanho, i, j, k;
    struct lista *temp;
    int fim1 = 0, fim2 = 0;

    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (struct lista*) malloc(tamanho*sizeof(struct lista));

    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(V->dados[p1].matricula < V->dados[p2].matricula)
                    temp->dados[i]= V->dados[p1++];
                else{
                     temp->dados[i]=V->dados[p2++];
                }

                if(p1 > meio){
                    fim1 = 1;
                }
                if(p2 > fim){
                   fim2 = 1;
                }
            }

            else{
                if(!fim1){
                    temp->dados[i]=V->dados[p1++];
                }

                else{
                    temp->dados[i]=V->dados[p2++];
                }
            }
        }

        for(j=0, k = inicio; j < tamanho; j++, k++){
            V->dados[k] = temp->dados[j];
        }

    }

    free(temp);
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;

    int i;
    for(i = 0; i < li->qtd; i++){
        printf("\nMATRICULA: %d\n",li->dados[i].matricula);

        printf("NOME: %s\n",li->dados[i].nome);

        printf("\n\t<< NOTAS>>\n");
        printf("\nNOTA 1: %.2f",li->dados[i].n1);
        printf("\nNOTA 2: %.2f",li->dados[i].n2);
        printf("\nNOTA 3: %.2f",li->dados[i].n3);

        printf("\n\n******************************\n");
    }
}

