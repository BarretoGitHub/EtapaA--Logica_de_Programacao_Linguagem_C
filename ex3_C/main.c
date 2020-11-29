#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(){

    Lista* L1;
    Lista* L2;
    ListaM* merge;

    L1 = criarLista();

    inserirInicio(L1,12);

    inserirInicio(L1,23);

    inserirFinal(L1,34);

    inserirFinal(L1,45);

    inserirInicio(L1,56);

    inserirInicio(L1,67);

    printf("\n______________________________________\n");
    imprimirLista(L1);


    L2 = criarLista();

    inserirInicio(L2,78);

    inserirInicio(L2,89);

    inserirFinal(L2,90);

    inserirFinal(L2,98);

    inserirInicio(L2,87);

    inserirInicio(L2,76);


    printf("\n______________________________________\n");

    imprimirLista(L2);

    printf("\n______________________________________\n");

    merge = mergeListas(L1,L2);


    printf("\n\n\t<< MERGE DAS LISTAS >> \n\n");
    imprimirListaMerge(merge);

    printf("\n______________________________________\n");
}
