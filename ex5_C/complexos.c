#include <stdio.h>
#include <stdlib.h>
#include "complexos.h"

struct complexo{
    int a;
    int b;
};

Complexo* criarComplexo(int a, int b){
    Complexo* criado = (Complexo*) malloc(sizeof(Complexo));

    criado->a = a;
    criado->b = b;

    return criado;
}

Complexo* somarComplexos(Complexo* num1, Complexo* num2){
    Complexo* criado = (Complexo*) malloc(sizeof(Complexo));

    criado->a = num1->a + num2->a;
    criado->b = num1->b + num2->b;

    return criado;
}

Complexo* subtrairComplexos(Complexo* num1, Complexo* num2){
    Complexo* criado = (Complexo*) malloc(sizeof(Complexo));

    criado->a = num1->a - num2->a;
    criado->b = num1->b - num2->b;

    return criado;
}

Complexo* multiplicarComplexos(Complexo* num1, Complexo* num2){
    Complexo* criado = (Complexo*) malloc(sizeof(Complexo));

    criado->a = (num1->a * num2->a) - (num1->b * num2->b);
    criado->b = (num1->a * num2->b) + (num1->b * num2->a);

    return criado;
}

Complexo* dividirComplexos(Complexo* num1, Complexo* num2){
    Complexo* criado = (Complexo*) malloc(sizeof(Complexo));

    int nume1,nume2;
    int den;

    nume1 = num1->a * num2->a - num1->b * num2->b;
    nume2 = num1->a * num2->b + num2->a * num1->b;

    den = num2->a*num2->a + num2->b*num2->b;

    criado->a = nume1 / den;
    criado->b = nume2 / den;

    return criado;
}

void imprimirComplexo(Complexo* num){

    if(num->b >= 0){
        printf("(%d + %di)\n",num->a, num->b);
    }
    else{
        printf("(%d %di)\n",num->a, num->b);
    }
}


