#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int calcularMDC(int, int);
void calcularMDCVetor();

int main(void){
    int n1,n2;
    int mdcNumeros;

    printf("Insira dois numeros inteiros\n");

    printf("\nNumero 1: ");
    scanf("%d", &n1);

    printf("\nNumero 2: ");
    scanf("%d",&n2);
    mdcNumeros = calcularMDC(n1,n2);

    printf("MDC(%d,%d) = %d",n1,n2,mdcNumeros);

    calcularMDCVetor();


    printf("\n\n\n");
    system("PAUSE");

    return 0;
}

int calcularMDC(int n1, int n2){
    int resto;
    int auxiliar = 0;

    if(n2 > n1){
        auxiliar = n1;
        n1 = n2;
        n2 = auxiliar;
    }

    for(resto = 1; resto != 0 ; /*resto++*/){
        resto = n1 % n2;
        n1 = n2;
        n2 = resto;
    }
    return(n1);
}

void calcularMDCVetor(){
    int i;
    int casa;
    int vetor[MAX];
    int flag;

    printf("\n\nInsira numeros inteiros NAO NEGATIVOS\n");

    for(i = 0 ; i < MAX; i++){
        scanf("%d", &vetor[i]);

        if(vetor[i] < 0){
            printf("\nNumero negativo digitado !");
            break;
        }
    }

    casa = i;
    flag = vetor[0];
    for(i = 1; i < casa; i++){
        flag = calcularMDC(flag,vetor[i]);
    }

    printf("\n\n<<< MDC do vetor: %d >>",flag);


}
