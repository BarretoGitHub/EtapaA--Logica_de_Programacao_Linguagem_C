#include <stdio.h>
#include <stdlib.h>
#include "complexos.h"

int main(){
    Complexo* numero1;
    Complexo* numero2;
    Complexo* somar;
    Complexo* subtrair;
    Complexo* multiplicar;
    Complexo* dividir;

    /*Criando 2 numeros complexos*/
    numero1 = criarComplexo(2,6);
    numero2 = criarComplexo(1,9);

    /*Operações matematicas com COMPLEXOS */
    somar = somarComplexos(numero1,numero2);

    subtrair = subtrairComplexos(numero1,numero2);

    multiplicar = multiplicarComplexos(numero1,numero2);

    dividir = dividirComplexos(numero1,numero2);

    printf("\n\t\t<< Numeros COMPLEXOS criados >>\n");
    printf("\nNumero 1: ");
    imprimirComplexo(numero1);

    printf("\nNumero 2: ");
    imprimirComplexo(numero2);

    printf("\n_________________________________________________________\n");

    printf("\n\n\t<< Efetuando operacoes Matematicas com os COMPLEXOS criados >>\n");

    printf("\nSoma: ");
    imprimirComplexo(somar);

    printf("\nSubtracao: ");
    imprimirComplexo(subtrair);

    printf("\nMultiplicacao: ");
    imprimirComplexo(multiplicar);

    printf("\nDivisao: ");
    imprimirComplexo(dividir);


    printf("\n_________________________________________________________\n");

    system("PAUSE");
}
