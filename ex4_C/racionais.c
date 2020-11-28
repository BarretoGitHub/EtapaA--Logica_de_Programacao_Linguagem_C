#include <stdio.h>
#include <stdlib.h>
#include "racionais.h"

struct racional{
    int numerador;
    int denominador;
};

Numero* criarRacional(int num,int den){

    Numero* numero = (Numero*) malloc(sizeof(Numero));

    numero->numerador = num;
    numero->denominador = den;

    return numero;
}

Numero* somarRacional(Numero* Num1,Numero* Num2){

    Numero* soma = (Numero*) malloc(sizeof(Numero));

    int resto,aux=0;
    int a,b;

    a = Num1->denominador;
    b = Num2->denominador;

	for(resto = 1;resto != 0; ){
		resto = a%b;
		a = b;
		b = resto;
	}
    soma->denominador=(Num1->denominador * Num2->denominador)/a;

    soma->numerador= ((soma->denominador/Num1->denominador)*Num1->numerador)+((soma->denominador/Num2->denominador)*Num2->numerador);

    printf("\nSOMA: %d/%d\n",soma->numerador,soma->denominador);

    return soma;
}

Numero* multiplicarRacional(Numero* Num1, Numero* Num2){

    Numero* multiplicacao = (Numero*) malloc(sizeof(Numero));

    multiplicacao->numerador=Num1->numerador*Num2->numerador;
    multiplicacao->denominador=Num1->denominador*Num2->denominador;

    printf("\nMULTIPLICACAO: %d/%d\n",multiplicacao->numerador, multiplicacao->denominador);

    return multiplicacao;
}

int testarRacionais(Numero* Num1, Numero* Num2){

    printf("\nVerificando racionais criados: ");

    if(Num1->numerador == Num2->numerador){
        if(Num1->denominador == Num2->denominador){

            printf("NUMEROS IGUAIS!!\n");

            return 1;
        }
    }
    printf("NUMEROS DISTINTOS!\n");

    return 0;
}


int imprimirRacional(Numero* num){

    printf("%d/%d\n",num->numerador,num->denominador);

    return 1;
}


