#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 30
#include "arvore.h"

struct aluno{
    int matricula;
    char nome[MAX];
    float nota1,nota2,nota3;
};

struct arvore{
    int tam; /*TAMANHO*/
    struct aluno* elemento;
};


Arvore* criarArvore(int altura){
    Arvore* criada = (Arvore*) malloc(sizeof(Arvore));

    criada->tam = (pow (2,altura) ) - 1;

    criada->elemento = (struct aluno*) malloc(criada->tam*sizeof(struct aluno));
    int i;
    for(i = 0; i < criada->tam; i++){
        criada->elemento[i].matricula = 0;
    }

    return criada;
}


int inserirElemento1(Arvore* arvore){
        int opcao = 1;
        int indice;

        system("CLS"); /*LIMPANDO TELA*/
        while(opcao != 0){
            printf("\n\nInsira um indice: ");
            scanf("%d",&indice);

            if(indice < 0 || indice >= pow(MAX,2) - 1){
                printf("ERRO.INDICE INVALIDO\n");
                getch();
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

            if(arvore->elemento[paiArvore].matricula == 0){
                flag = 1;
                break;
            }
        }
    }


	if(flag == 1){
		printf("\n\nERRO.INDICE INVALIDO !\n\n");
        getch();

		system("PAUSE");
		return 0;
	}
	else{
		int mat = 0;
		while(mat == 0){
			printf("\nMATRICULA: ");
			scanf("%d",&mat);

			if(mat == 0){
				printf("\n\nERRO.NUMERO INVALIDO.\n");
				getch();
			}
		}

		printf("\nNOME: ");
		fflush(stdin);
		fgets(arvore->elemento[indice].nome,40,stdin);

		printf("\n\n\t<< Notas de Prova >>\n");
		printf("PROVA 1: ");
		scanf("%f",&arvore->elemento[indice].nota1);

		printf("PROVA 2: ");
		scanf("%f",&arvore->elemento[indice].nota2);

		printf("PROVA 3: ");
		scanf("%f",&arvore->elemento[indice].nota3);

		arvore->elemento[indice].matricula = mat;
	}

    system("PAUSE");
	return 1;
}

int imprimeArvore(Arvore* arvore,int elementos){

    if(elementos == 0){
        imprimeArvoreRecursiva(arvore,0);

        return 1;
    }
    else{
        imprimeArvoreRecursiva(arvore,0);

        int i;
        for(i = 0; i < arvore->tam; i++){
            if(arvore->elemento[i].matricula != 0){
                printf("\n\t\t<< DADOS - ALUNO %d >>\n\n",i);

                printf("\nMATRICULA: %d\n",arvore->elemento[i].matricula);
                printf("NOME: %s",arvore->elemento[i].nome);
                printf("NOTA 1: %0.2f\n",arvore->elemento[i].nota1);
                printf("NOTA 2: %0.2f\n",arvore->elemento[i].nota2);
                printf("NOTA 3: %0.2f\n",arvore->elemento[i].nota3);
            }
        }
    }
}


int imprimeArvoreRecursiva(Arvore* arvore,int indice){
    if(arvore->tam-1 < indice){
        return 0;
    }
    printf("<%d",indice);
    imprimeArvoreRecursiva(arvore, 2 * indice+1);
    imprimeArvoreRecursiva(arvore, 2 * indice+2);
    printf(">");
}








