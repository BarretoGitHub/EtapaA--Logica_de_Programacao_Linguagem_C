#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define M 15 /*MARCA*/
#define C 10 /*COR*/

struct Revendedora{
    char marca[M];
    int ano;
    char cor[C];
    float preco;
};

void imprimeMenu(void);
void cadastrarVeiculos(struct Revendedora[MAX],int);
void listarVeiculosPreco(struct Revendedora[MAX],int);
void consultarMarcas(struct Revendedora[MAX], int);
void procurarVeiculo(struct Revendedora[MAX],int);


int main(void){

    int opcao;
    int POSICAO = 0;
    struct Revendedora veiculo[MAX];

    do{
        system("CLS"); /*Limpando o prompt*/
        imprimeMenu();
        scanf("%d",&opcao);

        switch(opcao){
            case 1:
                cadastrarVeiculos(veiculo,POSICAO);
                break;

            case 2:
                listarVeiculosPreco(veiculo,POSICAO);
                break;

            case 3:
                consultarMarcas(veiculo,POSICAO);
                break;

            case 4:
                procurarVeiculo(veiculo,POSICAO);
                break;

            case 5:
                printf("\n\nSaindo........");
                break;

            }

    }while(opcao!= 5);

    return 0;
}

void imprimeMenu(){

    printf("\n\n\t\t<<< MENU >>>\n\n");
    printf("1 - Cadastrar veiculos\n");
    printf("2 - Listar veiculos - Preco\n");
    printf("3 - Consultar veiculos\n");
    printf("4 - Listagem especifica\n");
    printf("5 - Sair\n\n");

}

void cadastrarVeiculos(struct Revendedora veiculo[MAX],int posicao){
    int i;

    printf("\n\nInsira os dados do veiculo:\n\n");

    printf("MARCA: ");
    fflush(stdin);
    gets(veiculo[i].marca);

    printf("\n\nANO: ");
    scanf("%d",&veiculo[i].ano);

    printf("\n\nCOR: ");
    fflush(stdin);
    gets(veiculo[i].cor);

    printf("\n\nPRECO: ");
    scanf("%f",&veiculo[i].preco);

    /*Incrementando a posicao a cada cadastro*/
    posicao = posicao + 1;

    printf("\n\nFinalizando cadastro.......\n\n");
    system("PAUSE");
}

void listarVeiculosPreco(struct Revendedora veiculo[MAX],int posicao){
    int i;
    float valor;
    int iteracao = 0;

    printf("\n\nInforme o preco: ");
    scanf("%f",&valor);

    printf("\n\nListando.....\n\n");
    for(i = 0; i < posicao; i++){
            if(veiculo[i].preco <= valor){

                printf("\n\n\t\tMARCA: ");
                puts(veiculo[i].marca);

                printf("\n\n\t\tCOR: ");
                puts(veiculo[i].cor);

                printf("\n\n\t\tANO: ");
                printf("%d",veiculo[i].ano);

                printf("\n\n\t\tPRECO: ");
                printf("%d",veiculo[i].preco);

                iteracao = iteracao + 1; /* iteracao++ */
            }

    }
    if(iteracao == 0){
        printf("ERRO!. Nenhum veiculo encontrado com esta faixa de preco\n\n");

    }
}

void consultarMarcas(struct Revendedora veiculo[MAX], int posicao){
    int i,flag;
    char nomeMarca[M];
    char vetor[M];

    printf("Insira a Marca : ");
    fflush(stdin);
    gets(nomeMarca);


    for(i = 0; i < posicao; i++){
        strcpy(vetor,veiculo[i].marca);
        flag = strcmp(nomeMarca, vetor);

        if(flag == 0){
            printf("\n\n\t\t<<< MARCA ENCONTRADA >>\n\n");

            printf("\n\nMARCA: ");
            puts(veiculo[i].marca);

            printf("\n\nCOR: ");
            puts(veiculo[i].cor);

            printf("\n\nANO: ");
            printf("%d",veiculo[i].ano);

            printf("\n\nPRECO: R$ ");
            printf("%.2f",veiculo[i].preco);
        }
    }
}

void procurarVeiculo(struct Revendedora veiculo[MAX], int posicao){
    int i;
    char marcaX[M],corX[C];
    int anoX;
    int flafCor,flagMarca;

    printf("\n\n\t\t<<< INSIRA OS DADOS >>>\n\n");

    printf("\nMARCA: ");
    fflush(stdin);
    gets(marcaX);

    printf("\n\nCOR: ");
    fflush(stdin);
    gets(corX);

    printf("\n\nANO: ");
    scanf("%d",&anoX);

    for(i = 0; i < posicao; i++){
        strcpy(marcaX, veiculo[i].marca);
        strcpy(corX, veiculo[i].cor);

        flagMarca = strcmp(marcaX, veiculo[i].marca);
        flafCor = strcmp(corX, veiculo[i].cor);

        if(flagMarca == 0 && flafCor == 0 && anoX == veiculo[i].ano){

            printf("\n\nMARCA: ");
            puts(veiculo[i].marca);

            printf("\n\nCOR: ");
            puts(veiculo[i].cor);

            printf("\n\nANO: ");
            printf("%d",veiculo[i].ano);

            printf("\n\nPRECO: R$");
            printf("%.2f",veiculo[i].preco);
        }

        else{
            printf("Erro. veiculo nao encontrado\n\n");
        }
    }
     system("PAUSE");

}
