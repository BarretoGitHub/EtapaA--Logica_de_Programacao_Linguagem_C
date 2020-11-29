#include <stdio.h>
#include <stdlib.h>

#include"Exercicio26.h"
#define MAX 16

int main(){


    int vet[MAX] = { 5, 6, 11, 456, 7, 0, 4, 90, 9, 69, 8, -3, 11, 10, 7, 78};

    int n = MAX;
    int opcao;

    printf("\t\t<< MENU - ORDENACAO >>\n\n");
    printf("[1] - Bubble Sort\n");
    printf("[2] - Selection Sort\n");
    printf("[3] - Insertion Sort\n");
    printf("[4] - Merge Sort\n");
    printf("[5] - Sair\n");

    scanf("%d", &opcao);

    if(opcao == 1){
        imprimeVetor(vet, n);

        bubbleSort(vet, n);
        printf("\nORDENANDO VIA BUBLLE SORT ......\n");

        imprimeCrescente(vet,n);
        imprimeDecrescente(vet, n);

    }
    else if(opcao == 2){
            imprimeVetor(vet, n);

            selectionSort(vet, n);
            printf("\nORDENANDO VIA SELECTION SORT ......\n\n");

            imprimeCrescente(vet,n);
            imprimeDecrescente(vet, n);
    }

    else if(opcao == 3){
            printf("\n\n\t\t<<ELEMENTOS INSERIDOS>>\n");
            imprimeVetor(vet, n);

            insertionSort(vet, n);
            printf("\nORDENANDO VIA INSERTION SORT ......\n\n");

            imprimeCrescente(vet,n);
            imprimeDecrescente(vet, n);

        }
    else if(opcao == 4){
            printf("\n\n\t\t<<ELEMENTOS INSERIDOS>>\n");
            imprimeVetor(vet, n);


            mergeSort(vet, 0, n);
            printf("\nORDENANDO VIA MERGE SORT ......\n\n");

            imprimeCrescente(vet,n);
            imprimeDecrescente(vet, n);

        }

        else if(opcao < 1 || opcao > 4){
            printf("Erro.Opcao invalida!\n");
        }

        else {
            printf("\n\nSaindo d aplicacao .....\n\n");
        }

        printf("\n\n\n\n");
        system("PAUSE");

    return 0;
}
