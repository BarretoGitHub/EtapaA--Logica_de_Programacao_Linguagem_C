#include <stdio.h>
#include <stdlib.h>
#include "DuplamenteCircular.h"

int main(){

    Lista* lista;
    int op = 0;
    int flag;

    lista = criarLista();

     int lerNumero(){
        int num;
        printf("Insira numero: ");
        scanf("%d",&num);

    return num;
}

    while(op != 7){
        system("CLS"); /*Limpando prompt*/
        printf("\n\t\t<< MENU >>\n");
        printf("[1] - Inserir no inicio\n");
        printf("[2] - Inserir no final\n");
        printf("[3] - Imprimir lista\n");
        printf("[4] - Sair.\n");
        scanf("%d",&op);

        printf("\n\n");

        switch(op){
        case 1:
            insereInicio(lista,lerNumero());
            break;

        case 2:
            inserirFinal(lista,lerNumero());
            break;

        case 3:
            imprimirLista(lista);
            system("PAUSE");
            break;

        case 4:
            printf("\nSaindo........\n");
            system("PAUSE");
            break;

        default:
            printf("ERRO. OPCAO INVALIDA\n");
            system("PAUSE");
            break;
        }
    }



}
