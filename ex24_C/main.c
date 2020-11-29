#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#include"Exercicio24.h"
#define MAX 6

int main(){

    int elemento;
    int flag;
    int vet[MAX];
    int i,j = 1;

    printf("<< Insira %d elementos inteiros >>\n",MAX);

    for(i = 0; i < MAX ; i++){
        printf("\n%d elemento: ",j++);
        scanf("%d", &vet[i]);
    }

    printf("\n\nInsira um elemento para ser buscado\n");
    scanf("%d", &elemento);


/*___________________________________________________________*/
    flag = buscaLinear(vet,MAX,elemento);

    printf("\n\n\nExecutando......\n");
    printf("\n\t\t<<<BUSCA LINEAR >>>\n");

    printf("\n\n Elemento encontrado na posicao: %d\n", flag);


/*___________________________________________________________*/

    flag = buscaOrdenada(vet,MAX,elemento);

    printf("\n\n\nExecutando......\n");
    printf("\n\t\t<< BUSCA ORDENADA >>>");

    printf("\n\n Elemento encontrado na posicao: %d\n", flag);

/*___________________________________________________________*/

    flag = buscaBinaria(vet,MAX,elemento);

    printf("\n\n\nExecutando......\n");
    printf("\n\t\t<< BUSCA BINARIA >>");

    printf("\n\n Elemento encontrado na posicao: %d\n", flag);


    printf("\n\n\n\n\n");
    system("PAUSE");

    return 0;
}

