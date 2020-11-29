#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main(){
    ArvBin* a = cria_ArvBin();
    ArvBin* b = cria_ArvBin();

    insere_ArvBin(a, 12);
    insere_ArvBin(a, 12);

    insere_ArvBin(b, 10);
    insere_ArvBin(b, 12);

    //CHAMADA DA FUN��O QUE VERIFICA SE AS DUAS �RVORES BIN�RIAS S�O IGUAIS
    igual(a, b);

    libera_ArvBin(a);
    libera_ArvBin(b);

    printf("\n\n\n");

    return 0;
}
