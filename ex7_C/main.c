#include <stdio.h>
#include <stdlib.h>
#include "ListaHeterogenea.h"
#define RET 0
#define TRI 1
#define CIR 2

int main(){
    Lista *L1;

    L1 = criarLista();

    inserirFinal(L1,RET);

    inserirInicio(L1,TRI);

    inserirInicio(L1,CIR);

    inserirFinal(L1,TRI);

    inserirFinal(L1,CIR);

    getch();
    printf("\n\n_______________________________________________\n\n");


    printf("\n<<LISTA >>\n\n");
    imprimirLista(L1);

    getch();
    printf("Removendo Final .............\n");
    removerFinal(L1);
    printf("\n\n_______________________________________________\n\n");

    getch();
    printf("Removendo Inicio .............\n");
    removerInicio(L1);

    printf("\n\n_______________________________________________\n\n");

    printf("\n<< LISTA ATUALIZADA >>\n\n");
    imprimirLista(L1);

}
