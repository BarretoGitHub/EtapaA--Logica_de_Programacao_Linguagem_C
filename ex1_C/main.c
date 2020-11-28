#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(){
    Lista* lista;
    int op = 0;
    int flag;

    lista=criarLista();

    while(op != 7){
        system("CLS"); /*Limpando prompt*/
        printf("\n\t\t<< MENU >>\n");
        printf("[1] - Inserir no inicio\n");
        printf("[2] - Inserir no final\n");
        printf("[3] - Remover no inicio\n");
        printf("[4] - Remover no final\n");
        printf("[5] - Imprimir lista\n");
        printf("[6] - Verificar Ordem\n");
        printf("[7] - Sair.\n");

        scanf("%d",&op);

        printf("\n\n");

        switch(op){
        case 1:
            inserirInicio(lista,lerNumero());
            break;

        case 2:
            inserirFinal(lista,lerNumero());
            break;

        case 3:
            removerInicio(lista);
            break;

        case 4:
            removerFinal(lista);
            break;

        case 5:
            imprimirLista(lista);
            system("PAUSE");
            break;

        case 6:

            if(verificarOrdem(lista) == 1){
                    printf("\n<< LISTA ORDENADA >>>\n\n");

            }
            else{
                printf("\n<< LISTA NAO ORDENADA >>\n\n");
            }

            system("PAUSE");
            break;

        case 7:
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

int lerNumero(){
    int num;
    printf("Insira numero: ");
    scanf("%d",&num);

    return num;
}
