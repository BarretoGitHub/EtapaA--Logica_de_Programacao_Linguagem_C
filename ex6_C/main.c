#include <stdio.h>
#include <stdlib.h>
#include "Retangulos.h"

int main(){
    Lista lista;

    lista = criarLista();

    inserirInicio(lista);
    printf("\n_______________________________________\n");

    inserirFinal(lista);
    printf("\n_______________________________________\n");

    inserirInicio(lista);
    printf("\n_______________________________________\n");

    printf("\n\t<< Lista de Retangulos >>\n\n");
    imprimirLista(lista);

    getch();

    printf("\n\n.....REMOVENDO FINAL.....\n");
    removerFinal(lista);

    /*Caso desejar imprimir*/
    /*imprimirLista(lista); */

    getch();

    printf("\n\n.....REMOVENDO INICIO .....\n");
    removerInicio(lista);

   /*Caso desejar imprimir*/
   /*imprimirLista(lista); */

}
