#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 10

void inserirNumeros(int *, int *);
int vetor(int,int [MAX]);
void vetorCrescente(int [MAX], int);
int contarDigitos(int [MAX], int);
int permutar(int [MAX], int, int [MAX],int);

int main(){
    int n1,n2;
    int flag1, flag2;
    int vet1[MAX], vet2[MAX];
    int cont1 = 0, cont2 = 0;
    int permutacao;

    inserirNumeros(&n1,&n2);

    flag1 = vetor(n1,vet1);
    flag2 = vetor(n2,vet2);

    vetorCrescente(vet1,flag1);
    vetorCrescente(vet2,flag2);

    cont1 = contarDigitos(vet1, flag1);
    cont2 = contarDigitos(vet2, flag2);
    permutacao = permutar(vet1, flag1, vet2, flag2);


    return 0;
}

void inserirNumeros(int *n1, int *n2){
    printf("Insira dois numeros inteiros: \n");
    scanf("%d",&*n1);
    scanf("%d",&*n2);
}

int vetor(int numero, int vet[MAX]){
    int i,j;
    int flag;
    int contCasas = 1;

    flag = numero;
    do{
        i = i * MAX;
        contCasas = contCasas + 1 ;

    }while((flag = flag/MAX) >= MAX);

	for(j = 0; i > 0 ; i = i/MAX, j++){
        vet[j] = numero / i;
        numero = numero % i;
	}
	return(contCasas);
}

void vetorCrescente(int vet[MAX], int casas){
    int i;
    int j;
    int auxiliar;

    for(j = 0; j < casas; j++){
		for(i = 0; i < casas - 1; i++){
			if(vet[i] > vet[i + 1]){
				auxiliar = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = auxiliar;
			}
		}
	}
}

int contarDigitos(int vet[MAX], int casas){
    int i;
    int numero;
    int cont = 0;

    printf("Insira um numero inteiro: ");
    scanf("%d",&numero);

    for(i = 0; i < casas; i++){
		if(vet[i] == numero){
			cont = cont + 1;
		}
	}
	return(cont);
}

int permutar(int vet1[MAX], int casa1, int vet2[MAX], int casa2){
    int i;
    int troca = FALSE;

    if(casa1 == casa2){
        troca = TRUE;
        for(i = 0; i< casa1; i++){
            if(vet1[i] != vet2[i]){
                troca = FALSE;
                break;
            }
        }
    }

    if(troca == TRUE){
			printf("\n\nOs numeros digitados sao permutacoes.\n");
		}

		else{
			printf("\n\nOs numeros digitados nao sao permutacoes.\n");
		}


		printf("\n\nOs numeros digitados nao tem o mesmo numero de casas, por isso nao podem ser permutacao.\n");


	return(troca);
}


