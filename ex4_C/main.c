 #include <stdio.h>
#include <stdlib.h>
#include "racionais.h"

int main(){
    Numero* numero1;
    Numero* numero2;
    Numero* numero3;
    Numero* numero4;
    Numero* somar1;
    Numero* multiplicar1;
    Numero* somar2;
    Numero* multiplicar2;

    /* Crindo e atribuindo valores aos racionais--> DISTINTOS*/
    numero1 = criarRacional(5,15);
    numero2 = criarRacional(-3,8);

    printf("\n\t<< Racionais criados >>\n");

    printf("\nPRIMEIRO racional: ");
    imprimirRacional(numero1);

    printf("\nSEGUNDO racional: ");
    imprimirRacional(numero2);

    testarRacionais(numero1,numero2);

    printf("\n___________________________________________");

    printf("\n\n\t<< Efetuando operacoes matematicas >>\n");
    somar1 = somarRacional(numero1,numero2);
    multiplicar1 = multiplicarRacional(numero1,numero2);


    printf("\n___________________________________________");

    /* Crindo e atribuindo valores aos racionais --> IGUAIS*/
    numero3 = criarRacional(4,2);
    numero4 = criarRacional(4,2);

    printf("\n\n\t<< Racionais criados >>\n");

    printf("\nTERCEIRO racional: ");
    imprimirRacional(numero3);

    printf("\nQUARTO racional: ");
    imprimirRacional(numero4);

    testarRacionais(numero3,numero4);

    printf("\n___________________________________________");

    printf("\n\n\t<< Efetuando operacoes matematicas >>\n\n");
    somar2 = somarRacional(numero3,numero4);
    multiplicar2 = multiplicarRacional(numero3,numero4);

    printf("\n___________________________________________");

    printf("\n\n");
    system("PAUSE"); /*Pausando prompt*/

    return 0;
}
