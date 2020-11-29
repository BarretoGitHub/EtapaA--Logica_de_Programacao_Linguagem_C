#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"



int main(){
    Pilha* pilha;
    int movimento;

    pilha = criarPilha();

    while(movimento != 5){
        system("CLS");

        printf("\n\n\t<< ESCOLHA O MOVIMENTO DO ROBO>>\n\n");
        printf("1 - Frente.\n");
        printf("2 - Direita.\n");
        printf("3 - Esquerda.\n");
        printf("4 - Retornar.\n");
        printf("5 - Sair.\n");

        scanf("%d",&movimento);

        switch(movimento){
        case 1:
            pushPilha(pilha,movimento);
            break;

        case 2:
            pushPilha(pilha,movimento);
            break;

        case 3:
            pushPilha(pilha,movimento);
            break;

        case 4:
            comandoRetornar(pilha);
            system("PAUSE");
            break;

        case 5:
            printf("\nSaindo.............\n\n\n");
            system("PAUSE");
            break;

        default:
            printf("\n\n<< Erro. Movimento invalido >>\n");
            system("PAUSE");
            break;
        }
    }
}
