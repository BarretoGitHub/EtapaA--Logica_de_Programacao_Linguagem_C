#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(){
    Lista* lista;

    lista = criarLista();

    inserirLista(lista);
    inserirLista(lista);
    inserirLista(lista);
    inserirLista(lista);
    inserirLista(lista);

    printf("\n______________________________\n");
    printf("\n\t\t << LISTA DE NUMEROS >>\n\n");
    imprimirLista(lista);


    removerLista(lista);
    printf("\n\nRemovendo NUMERO da Lista..........\n\n");
    getch();

    printf("\n\n\t\t<< Lista Atualizada >>>\n\n");
    imprimirLista(lista);
}
