#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 70
#define TRUE 1
#define FALSE 0

struct Locadora{
    int codigo;
    char titulo[MAX];
    char sinopse[MAX];
    char diretor[MAX];
    int ano;
    char genero[MAX];

};

void imprimirMenu(void);
void cadastrarFilme(struct Locadora[MAX]);
void alterarFilme(struct Locadora[MAX]);
void listarFilme(struct Locadora[MAX]);
void listarFilmeAno(struct Locadora[MAX]);
void procurarFilmeNome(struct Locadora[MAX]);
void inicializandoCodigos(struct Locadora[MAX]);


int main(void){
    int opcao;
    struct Locadora filme[MAX];


    inicializandoCodigos(filme);

    do{
        system("CLS");
        imprimirMenu();
        scanf("%d",&opcao);



        switch(opcao){

        case 1:
            cadastrarFilme(filme);
            break;

        case 2:
            alterarFilme(filme);
            break;

        case 3:
            listarFilme(filme);
            break;

        case 4:
            listarFilmeAno(filme);
            break;

        case 5:
            procurarFilmeNome(filme);
            break;

        case 6:
            printf("\n\nSaindo......\n\n");
            break;
        }

    }while(opcao != 6);

    printf("\n\n\n");
    system("PAUSE");

    return 0;
}

void imprimirMenu(void){

    printf("\n\n\t<<< MENU >>>\n\n");
    printf("1 - Cadastrar filme\n");
    printf("2 - Alterar filme\n");
    printf("3 - Listar filmes\n");
    printf("4 - Listar filmes por ano\n");
    printf("5 - Procurar filme por nome\n");
    printf("6 - SAIR\n\n");

}

void cadastrarFilme(struct Locadora filme[MAX]){
    int i;
    int codigoJaExiste = FALSE;

    printf("\n\n\t<<< CADASTRAMENTO >>\n\n");

    for(i = 0; i < MAX; i++){
        if(filme[i].codigo == 0){
            break;
        }
    }

    if(i == MAX && codigoJaExiste == FALSE){
        printf("\n\nLIMITE DE FILMES ALCANCADOS\n\n");
    }

    else{

        printf("\n\nInsira os dados do filme:\n");
        filme[i].codigo = i + 1;

        printf("\n\nCODIGO: ");
        scanf("%d",&filme[i].codigo);

        printf("\n\nTITULO: ");
        fflush(stdin);
        gets(filme[i].titulo);

        printf("\n\n SINOPSE: ");
        fflush(stdin);
        gets(filme[i].sinopse);

        printf("\n\nDIRETOR: ");
        fflush(stdin);
        gets(filme[i].diretor);

        printf("\n\nANO: ");
        scanf("%d",&filme[i].ano);

        printf("\n\nGENERO: ");
        fflush(stdin);
        gets(filme[i].genero);

    }
}

void alterarFilme(struct Locadora filme[MAX]){
    int i, codigos;


        printf("Insira o CODIGO: ");
        scanf("%d",&codigos);

    if(filme[codigos - 1].codigo!= codigos || codigos == 0){
        printf("CODIGO INVALIDO");
        system("PAUSE");
    }

    else{
        codigos--;
        printf("Insira os NOVOS DADOS:\n\n");

        printf("\n\nTITULO: ");
        fflush(stdin);
        gets(filme[i].titulo);

        printf("\n\nSINOPSE: ");
        fflush(stdin);
        gets(filme[i].sinopse);

        printf("\n\nDIRETOR: ");
        fflush(stdin);
        gets(filme[i].diretor);

        printf("\n\nANO: ");
        scanf("%d",&filme[i].ano);

        printf("\n\nGENERO: ");
        fflush(stdin);
        gets(filme[i].genero);


        printf("\n\nAteracao CONCLUIDA\n\n");
        printf("Finalizado operacao.........\n\n");
    }


}

void listarFilme(struct Locadora filme[MAX]){
    int i;

    printf("n\n\t\t<<LISTANDO FILMES >>>\n");

    for(i = 0; i < MAX; i++){
        if(filme[i].codigo != 0){

            printf("\n\n\t\tCODIGO: ");
            printf("%d",filme[i].codigo);

            printf("\n\n\t\tTITULO: ");
            puts(filme[i].titulo);

            printf("\n\n\t\tSINOPSE: ");
            puts(filme[i].sinopse);

            printf("\n\n\t\tDIRETOR: ");
            puts(filme[i].diretor);

            printf("\n\n\t\tANO: ");
            printf("%d",filme[i].ano);

            printf("\n\n\t\tGENERO: ");
            puts(filme[i].genero);



        }
    }

    system("PAUSE"); /*Pause no prompt-comando*/

}

void listarFilmeAno(struct Locadora filme[MAX]){
    int i,j;
    int anoAtual = 2018;
    int anoX;

    for(i = 0; i < MAX; i++){
        if(i == 0){
            anoX = filme[i].ano;
        }

        else if(anoX > filme[i].ano){
            anoX = filme[i].ano;
        }
    }

    for(i = anoX; i < anoAtual; i++){
        for(j = 0; j < MAX; j++){
            if(filme[i].codigo != 0 && j == filme[i].ano){
                printf("\n\n\t<< FILME ENCONTRADO >>\n\n");

                printf("\n\nTITULO: ");
                puts(filme[i].titulo);

                printf("\n\nCODIGO: ");
                printf("%d",filme[i].codigo);

                printf("\n\nANO: ");
                printf("%d",filme[i].ano);

                printf("\n\nGENERO: ");
                puts(filme[i].genero);

                printf("\n\nDIRETO: ");
                puts(filme[i].diretor);

                printf("\n\nSINOPSE: ");
                puts(filme[i].sinopse);
            }
        }
    }
    system("PAUSE"); /*Pause no prompt-comando*/
}

void procurarFilmeNome(struct Locadora filme[MAX]){
    int i,j;
    char nomeFilme[MAX],nome[MAX];
    int teste;
    int var = FALSE;

    printf("Insira o nome do filme: ");
    fflush(stdin);
    gets(nomeFilme);

    /*convertendo todos os caracteres do vetor via tolower*/
    for(i = 0; i < MAX; i++){
        nomeFilme[i] = tolower(nomeFilme[i]);

    }

    for(i = 0; i < MAX; i++){
        strcpy(nome,filme[i].titulo);
        for(j = 0; j < MAX; j++){
            nome[j] = tolower(nome[j]);
        }
        teste = strcmp(nomeFilme,nome);
        if(teste == 0){
            var = TRUE;
            break;
        }
    }

    if(var == TRUE){
        printf("\n\n\t<< FILME ENCONTRADO >>\n\n");

        printf("\n\nTITULO: ");
        puts(filme[i].titulo);

        printf("\n\nCODIGO: ");
        printf("%d",filme[i].codigo);

        printf("\n\nANO: ");
        printf("%d",filme[i].ano);

        printf("\n\nGENERO: ");
        puts(filme[i].genero);

        printf("\n\nDIRETOR: ");
        puts(filme[i].diretor);

        printf("\n\nSINOPSE: ");
        puts(filme[i].sinopse);

        system("PAUSE");
    }

    else{
         printf("\n\n...Procura concluida... Filme NAO encontrado!\n\n");
          system("PAUSE");
    }
}

void inicializandoCodigos(struct Locadora filme[MAX]){
    int i;

    for(i = 0; i < MAX; i++){
        filme[i].codigo = 0;
    }


}
