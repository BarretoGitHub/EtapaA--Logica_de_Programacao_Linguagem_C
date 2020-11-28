#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(){
    Lista *Lista1;
    Lista *Lista2;
    Lista *Uniao;

    Lista1 = criarLista();

    /*inserindo valores na lista 1*/

    inserirInicio(Lista1,2);

    inserirInicio(Lista1,4);

    inserirFinal(Lista1,12);

    inserirInicio(Lista1,6);

    printf("\n\t\t<<LISTA 1 >>\n\n");
    imprimirLista(Lista1);

    printf("\n\n________________________________________________\n");

    Lista2 = criarLista();

    /*inserindo valores na lista 2*/

    inserirInicio(Lista2,7);

    inserirInicio(Lista2,8);

    inserirFinal(Lista2,9);

    inserirInicio(Lista2,10);

    printf("\n\t\t<<LISTA 2 >>\n\n");
    imprimirLista(Lista2);

    printf("\n\n________________________________________________\n");

    Uniao = unionListas(Lista1,Lista2);

    printf("\n\t\t<< UNIAO DAS LISTAS >>\n\n");
    imprimirLista(Uniao);

    printf("\n\n\n");
    system("PAUSE");
}
