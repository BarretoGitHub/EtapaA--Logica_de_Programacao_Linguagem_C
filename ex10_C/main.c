#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int main(){
    Pilha* pilha;

    pilha = criaPilha();

    pushPilha1(pilha,10); /*Empilhando*/
    pushPilha1(pilha,20); /*Empilhando*/
    pushPilha1(pilha,30); /*Empilhando*/
    pushPilha1(pilha,40); /*Empilhando*/
    pushPilha1(pilha,50); /*Empilhando*/

     printf("\n\n\t\t<< PILHA 1 >>\n");
    imprimePilha1(pilha);

    pushPilha2(pilha,10); /*Empilhando*/
    pushPilha2(pilha,20); /*Empilhando*/
    pushPilha2(pilha,30); /*Empilhando*/
    pushPilha2(pilha,40); /*Empilhando*/
    pushPilha2(pilha,50); /*Empilhando*/

    printf("\n________________________________________\n");
    printf("\t\t<< PILHA 2 >>\n\n");
    imprimePilha2(pilha);

    popPilha1(pilha); /*Desempilhando*/

    pushPilha2(pilha,60); /*Empilhando*/
    pushPilha2(pilha,70); /*Empilhando*/


    printf("\n...............Atualizando PILHAS.............");
    printf("\n\n\t\t<< PILHA 1 ATUALIZADA >>\n");
    imprimePilha1(pilha);

    printf("\n________________________________________\n");
    printf("\n\t\t<<PILHA 2 ATUALIZADA >>\n\n");
    imprimePilha2(pilha);

    printf("\n\n");
    system("PAUSE");
}
