#include <stdio.h>
#include <stdlib.h>
#include "avioes.h"

int main(){
    Fila* fila;

    fila = criarFila();

    inserirFila(fila);

    inserirFila(fila);

    inserirFila(fila);

    inserirFila(fila);

    imprimeFila(fila);

    getch();
    printf("Removendo Lista.................\n\n");
    removerFila(fila);

    printf("\n\n\t\t<< Lista Atualizada >>\n\n");
    imprimeFila(fila);
}
