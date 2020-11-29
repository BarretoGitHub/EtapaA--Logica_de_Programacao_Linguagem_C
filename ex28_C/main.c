#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#define MAX 3

int main(){
    Arvore* arvore;
    arvore = criarArvore(MAX);
    int opcao = 0;

    while(opcao != 3){
    	system("CLS"); /*LIMPANDO A TELA*/

        printf("\n\t\t<<< MENU >>>\n");
    	printf("\n1 - Inserir Elemento");
    	printf("\n2 - Imprimir Arvore");
    	printf("\n3 - Sair\n");

    	scanf("%d",&opcao);


    	switch(opcao){
    		case 1:
    			inserirElemento1(arvore);
    			break;
    		case 2:

                printf("\n\n\t\t<<< ARVORE >>>\n\n");
    			imprimeArvore(arvore,0);

    			printf("\n\n");
    			getch();
    			break;

    		case 3:
    			printf("\n\nSaindo........\n");
    			liberarArvore(arvore);
    			getch();
    			break;

    		default:
    			printf("\n\nERRO.NUMERO INVALIDO!!");
    			getch();

    	}
    }
}

