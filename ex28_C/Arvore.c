#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include <math.h>
#define MAX 3

struct arvore{
    int tam;
    int* num;
};

Arvore* criarArvore(int altura){
    Arvore* criada = (Arvore*) malloc(sizeof(Arvore));

    criada->tam = (pow(2,altura)) - 1;

    criada->num = (int*) malloc(criada->tam*sizeof(int));

    int i;
    for(i = 0; i < criada->tam; i++){
        criada->num[i] = 0;
    }

    return criada;
}

int inserirElemento1(Arvore* arvore){
	int opcao = 1;
	int indice;

	system("CLS"); /*Limpando TELA*/
	while(opcao != 0){

		printf("\n\nInsira um numero: ");
		scanf("%d",&indice);

		if(indice < 0 || indice >= pow(MAX,2)-1){
			printf("Erro.Numero INVALIDO\n");
		}
		else{
			opcao = 0;
			inserirElemento(arvore,indice);
		}
	}
}


int inserirElemento(Arvore* arvore, int indice){
    int flag = 0;

    if(indice != 0){
        int paiArvore = indice;

        if(indice % 2 != 0){
            paiArvore++;
        }

        while(paiArvore != 0){
            if(paiArvore % 2 != 0){
                paiArvore++;
            }

            paiArvore = (paiArvore/2) - 1;

            if(arvore->num[paiArvore] == 0){
                flag = 1;
                break;
            }
        }
    }


	if(flag == 1){
		printf("ERRO.NUMERO INVALIDO!!\n\n");
        system("PAUSE");
		return 0;
	}
	else{
		int elemento = 0;
		while(elemento == 0){
			printf("Insira um numero ");
			scanf("%d",&elemento);

			if(elemento == 0){
				printf("Insira um numero diferente de ZERO!\n");

			}
		}
		arvore->num[indice] = elemento;
	}


    system("PAUSE");
	return 1;
}

int imprimeArvore(Arvore* arvore,int indice){

    if(arvore->tam - 1 < indice){
        return 0;
    }
    printf("<%d",arvore->num[indice]);
    imprimeArvore(arvore,2 * indice + 1);
    imprimeArvore(arvore,2 * indice + 2);
    printf(">");


}

int imprimeArvoreInserir(Arvore* arvore,int indice){
    if(arvore->tam - 1 < indice){
        return 0;
    }
    printf("<%d",indice);
    imprimeArvoreInserir(arvore,2 * indice + 1);
    imprimeArvoreInserir(arvore,2 * indice + 2);
    printf(">");
}


void liberarNo(struct arvore* flagNo){
    if(flagNo == NULL){
        return;
    }
    liberarNo(flagNo->tam);
    liberarNo(flagNo->num);
    free(flagNo);

}

void liberarArvore(Arvore* criada){
    if(criada == NULL){
        liberarNo(criada);
        free(criada);
    }
}

