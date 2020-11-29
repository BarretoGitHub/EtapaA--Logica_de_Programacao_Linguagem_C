#include <stdio.h>
#include <stdlib.h>

#include"Ex27.h"
#define TAM1 6
#define TAM2 12
#define TAM3 10

int main(){

    int vetA[TAM1] = {7, 14, 16, 23, 6, 9};
    int vetB[TAM1] = {83, 9, 7, 5, 3, -2 };
    int vetC[TAM1] = {5, 7, 2, 47, -3, 6 };
    int vetD[TAM2] = {2, 4, 6, 8, 10, 21, 17, 9, 7, 5, 3, -1};
    int vetE[TAM2] = {3, 4, 6, 8, 23, 12, -2, 3, 5, 7, 9, 27};
    int vetF[TAM3] = {18, 19, 17, 19, 13, 12, 13, 18, 14, 16};
    int vetG[TAM3] = {809, 709, 302, 308, 406, 206, 403, 308, 302, 709};


    printf("\n\t<< VETOR A >>");
    printf("\n*************************************");
    printf("\nELEMENTOS INSERIDOS: ");
    imprimeVetor(vetA,TAM1);
    imprimirTabela(vetA,TAM1);

    printf("\n\t<< VETOR B >>");
    printf("\n*************************************");
    printf("\nELEMENTOS INSERIDOS: ");
    imprimeVetor(vetB,TAM1);
    imprimirTabela(vetB,TAM1);

    printf("\n\t<< VETOR C >>");
    printf("\n*************************************");
    printf("\nELEMENTOS INSERIDOS: ");
    imprimeVetor(vetC,TAM1);
    imprimirTabela(vetC,TAM1);

    printf("\n\t<< VETOR D >>");
    printf("\n*************************************");
    printf("\nELEMENTOS INSERIDOS: ");
    imprimeVetor(vetD,TAM2);
    imprimirTabela(vetD,TAM2);

    printf("\n\t<< VETOR E >>");
    printf("\n*************************************");
    printf("\nELEMENTOS INSERIDOS: ");
    imprimeVetor(vetE,TAM2);
    imprimirTabela(vetE,TAM2);

    printf("\n\t<< VETOR F >>");
    printf("\n*************************************");
    printf("\nELEMENTOS INSERIDOS: ");
    imprimeVetor(vetF,TAM3);
    imprimirTabela(vetF,TAM3);

    printf("\n\t<< VETOR G >>");
    printf("\n*************************************");
    printf("\nELEMENTOS INSERIDOS: ");
    imprimeVetor(vetF,TAM3);
    imprimirTabela(vetF,TAM3);

    printf("\n\n\n");
    system("PAUSE");

    return 0;
}
