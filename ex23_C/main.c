#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 30
#define N 100


struct Endereco{
    char nomeRua[MAX];
    int numero;
    char complemento[MAX];
    char bairro[MAX];
    char cep[MAX];
    char cidade[MAX];
    char estado[MAX];
    char pais[MAX];

};

struct Aniversario{
    int dia;
    int mes;
    int ano;
};

struct Telefone{
    int dd;
    char numero[MAX];
};

struct Agenda{
    char nome[MAX];
    char email[MAX];
    struct Endereco endereco;
    char estado[MAX];
    struct  Telefone telefone;
    struct Aniversario aniversario;
    char linhaObservacao[MAX];

};

void imprimirMenu();
int inserirDadosAgenda(struct Agenda [N],int);
void buscarNome(struct Agenda [N],int);
void usarToLower(char [MAX]);
void buscarMes(struct Agenda [N], int);
void buscarDiaeMes(struct Agenda [N], int);
void imprimirOrdemAlfabetica(struct Agenda [N], int);
void removerContato(struct Agenda [N], int);
void imprimirItens(struct Agenda [N], int);
void imprimindoTodosDados(struct Agenda [N],int );



int main(void){
    int opcao;
    struct Agenda agenda[N];
    int posicao = 0;

    do{
        system("CLS");
        imprimirMenu();
        scanf("%d",&opcao);



        switch(opcao){
        case 1:
            posicao = inserirDadosAgenda(agenda,posicao);
            break;

        case 2:
            buscarNome(agenda,posicao);
            break;

        case 3:
            buscarMes(agenda,posicao);
            break;

        case 4:
             buscarDiaeMes(agenda,posicao);
             break;

        case 5:
            imprimirOrdemAlfabetica(agenda,posicao);
            break;

        case 6:
            removerContato(agenda,posicao);
            break;

        case 7:
            imprimirItens(agenda,posicao);
            break;



        case 8:
            imprimindoTodosDados(agenda,posicao);
            break;


        case 9:
            printf("Saindo .....");
            break;

        }


     }while(opcao!= 9);


    printf("\n\n\n");
    system("PAUSE");

    return 0;
}

void imprimirMenu(){

    printf("\n\n\t<<<< MENU >>>\n\n");
    printf("1 - Inserir dados\n");
    printf("2 - Buscar NOME agenda\n");
    printf("3 - Buscar MES de aniversario\n");
    printf("4 - Buscar  DIA e MES de aniversario\n");
    printf("5 - Imprimir CONTATOS em ordem alfabetica\n");
    printf("6 - Remover contato\n");
    printf("7 - Imprimir: NOME,E-MAIL e TELEFONE \n");
    printf("8 - Imprimir todos os dados dos contatos\n");
    printf("9 - Sair\n\n");

}

int inserirDadosAgenda(struct Agenda agenda[N],int posicao){
    printf("\n\n\t<<<Insirir DADOS >>\n\n");

    printf("NOME: ");
    fflush(stdin);
    gets(agenda[posicao].nome);

    printf("\nE-MAIL: ");
    fflush(stdin);
    gets(agenda[posicao].email);

    printf("\nEndereco...\n");

    printf("\nRUA: ");
    fflush(stdin);
    gets(agenda[posicao].endereco.nomeRua);

    printf("\nNUMERO: ");
    scanf("%d",&agenda[posicao].endereco.numero);

    printf("\nBAIRRO: ");
    fflush(stdin);
    gets(agenda[posicao].endereco.bairro);

    printf("\nCEP: ");
    fflush(stdin);
    gets(agenda[posicao].endereco.cep);

    printf("\nCIDADE: ");
    fflush(stdin);
    gets(agenda[posicao].endereco.cidade);

    printf("\nESTADO: ");
    fflush(stdin);
    gets(agenda[posicao].endereco.estado);

    printf("\nPAIS: ");
    fflush(stdin);
    gets(agenda[posicao].endereco.pais);

    printf("\n\nTelefone....\n");

    printf("\nDDD: ");
    scanf("%d",&agenda[posicao].telefone.dd);

    printf("\nNUMERO: ");
    fflush(stdin);
    gets(agenda[posicao].telefone.numero);

    printf("\n\nAniversario .......\n");
    printf("\n\nDIA: ");
    scanf("%d",&agenda[posicao].aniversario.dia);

    printf("\nMES: ");
    scanf("%d",&agenda[posicao].aniversario.mes);

    printf("\nANO: ");
    scanf("%d",&agenda[posicao].aniversario.ano);

    printf("\n\nOSERVACAO ESPECIAL: ");
    fflush(stdin);
    gets(agenda[posicao].linhaObservacao);

    posicao = posicao + 1;

    return(posicao);


}

void buscarNome(struct Agenda agenda[N],int posicao){
    int i;
    char nomeX[MAX];
    int flagNome;



    printf("\n\nInsira um Nome: ");
    fflush(stdin);
    gets(nomeX);

    usarToLower(nomeX);

    for(i = 0; i < posicao; i++){
        strcpy(nomeX, agenda[posicao].nome);
        usarToLower(agenda[posicao].nome);

        flagNome = strcmp(nomeX,agenda[posicao].nome);

        if(flagNome == 0 ){

            printf("\n\n\t<<<CONTATO ENCONTRADO >>\n\n");

            imprimirDados(agenda,posicao);

            printf("\n\n---------------------------------------\n\n");
        }


    }

     if(flagNome != 0 && posicao > 0){
        printf("\n\nCONTATO NAO ENCONTRADO\n\n");
    }

    if(posicao == 0){
        printf("\n\n\t<<< OBS: NENHUM CONTATO CADASTRADO >>>\n\n");
    }

    system("PAUSE");

}

void usarToLower(char vet[MAX]){
    int i;

    for(i = 0;i < MAX;i++){
        if(vet[i] == '/o'){
            break;
        }
        vet[i]=tolower(vet[i]);
    }
}

void buscarMes(struct Agenda agenda[N], int posicao){
    int i;
    int mesX;
    int flagMes;

    printf("\n\nInsira um MES: ");
    scanf("%d",&mesX);

    for(i = 0; i < posicao; i++){
        strcpy(mesX,agenda[posicao].aniversario.mes);
        flagMes = strcmp(mesX,agenda[posicao].aniversario.mes);

        if(flagMes == 0){
            printf("\n\n\t<<<CONTATO ENCONTRADO >>\n\n");

            imprimirDados(agenda,posicao);

            printf("\n\n---------------------------------------\n\n");
        }

    }

    if(flagMes != 0 && posicao > 0){
        printf("\n\nCONTATO (NAO) ENCONTRADO\n\n");
    }

    if(posicao == 0){
        printf("\n\n\t<<< OBS: NENHUM CONTATO CADASTRADO >>>\n\n");
    }

    system("PAUSE");


}

void buscarDiaeMes(struct Agenda agenda[N], int posicao){
    int i;
    int diaX;
    int flagDia;
    int mesX;
    int flagMes;

    printf("\n\nInsira um DIA: ");
    scanf("%d",&diaX);

    printf("\n\nInsira um MES: ");
    scanf("%d",&mesX);

    for(i = 0; i < posicao; i++){
        strcpy(diaX,agenda[posicao].aniversario.dia);
        flagDia = strcmp(diaX,agenda[posicao].aniversario.dia);

        strcpy(mesX,agenda[posicao].aniversario.mes);
        flagMes = strcmp(mesX,agenda[posicao].aniversario.mes);

        if(flagDia == 0 && flagMes == 0){
            printf("\n\n\t<<<CONTATO ENCONTRADO >>\n\n");

            imprimirDados(agenda,posicao);

            printf("\n\n---------------------------------------\n\n");
        }

    }

   if(flagDia != 0 && flagMes != 0 && posicao > 0){
        printf("\n\nCONTATO (NAO) ENCONTRADO\n\n");
    }

    if(posicao == 0){
        printf("\n\n\t<<< OBS: NENHUM CONTATO CADASTRADO >>>\n\n");
    }

    system("PAUSE");


}

void imprimirDados(struct Agenda agenda[N], int posicao){

    if(posicao == 0){
        printf("\n\n\t<<< OBS: NENHUM CONTATO CADASTRADO >>>\n\n");
    }

    else{
            printf("\n\nNOME: ");
            puts(agenda[posicao].nome);

            printf("\nE-MAIL: ");
            puts(agenda[posicao].email);

            printf("\nEndereco...\n");

            printf("\nRUA: ");
            puts(agenda[posicao].endereco.nomeRua);

            printf("\nNUEMRO: ");
            printf("%d", agenda[posicao].endereco.numero);

            printf("\nBAIRRO: ");
            puts(agenda[posicao].endereco.bairro);

            printf("\nCEP: ");
            puts(agenda[posicao].endereco.cep);

            printf("\nCIDADE: ");
            puts(agenda[posicao].endereco.cidade);

            printf("\nESTADO: ");
            puts(agenda[posicao].endereco.estado);

            printf("\nPAIS: ");
            puts(agenda[posicao].endereco.pais);

            printf("\n\nTelefone....\n");

            printf("\nDDD: ");
            printf("%d",agenda[posicao].telefone.dd);

            printf("\nNUMERO: ");
            puts(agenda[posicao].telefone.numero);

            printf("\n\nAniversario .......\n");
            printf("\n\nDIA: ");
            printf("%d",agenda[posicao].aniversario.dia);

            printf("\nMES: ");
            printf("%d",agenda[posicao].aniversario.mes);

            printf("\nANO: ");
            printf("%d",agenda[posicao].aniversario.ano);

            printf("\n\nOSERVACAO ESPECIAL: ");
            puts(agenda[posicao].linhaObservacao);
    }

    system("PAUSE");

}

void imprimirOrdemAlfabetica(struct Agenda agenda[N] , int posicao){


}

void removerContato(struct Agenda agenda[N], int posicao){
	int i;
 	int var;


    i = inserirDadosAgenda(agenda,posicao);

 	printf("Processando.....");
 	printf("\n\nRemover contato:[ %d ]",i+1);

 	do{

 		system("CLS");
  		printf("\n\n1 - Excluir contato");
 		printf("\n2 - Cancelar operacao\n");
 		scanf("%d",&var);

 	}while(var < 1 || var > 2);

 	if(var == 1){
 		agenda[i].nome = NULL;
 		agenda[i].email = NULL;
 		agenda[i]. endereco.nomeRua = NULL;
        agenda[i].endereco.numero = NULL;
        agenda[i].endereco.bairro = NULL;
        agenda[i].endereco.cep = NULL;
        agenda[i].endereco.cidade = NULL;
        agenda[i].endereco.estado = NULL;
        agenda[i].endereco.pais = NULL;
        agenda[i].telefone.dd = NULL;
        agenda[i].telefone.numero = NULL;
        agenda[i].aniversario.dia = NULL;
        agenda[i].aniversario.mes = NULL;
        agenda[i].aniversario.ano = NULL;
        agenda[i].linhaObservacao = NULL;


 		printf("\n\nOperacao efetuada com sucesso. Conta EXCLUIDA !\n\n");

 	}

 	else{
 		printf("\n\nErro! Operacao nao finalizada !\n\n\n\n");

 	}

 	system("PAUSE");



}


}


void imprimirItens(struct Agenda agenda[N], int posicao){
    int i;

    if(posicao == 0){
        printf("\n\n\t<<< OBS: NENHUM CONTATO CADASTRADO >>>\n\n");
    }

    else {

        printf("\n\n\t<<<NOME, E-MAIL e TELEFONE>>>\n\n");

        for(i = 0; i < posicao; i++){
            printf("\n\nNOME: ");
            puts(agenda[posicao].nome);

            printf("\nE-MAIL: ");
            puts(agenda[posicao].email);

            printf("\n\nTelefone....\n");

            printf("\nDDD: ");
            printf("%d",agenda[posicao].telefone.dd);

            printf("\nNUMERO: ");
            puts(agenda[posicao].telefone.numero);
        }
    }

    system("PAUSE");

}

void imprimindoTodosDados(struct Agenda agenda[N], int posicao){
    int i;


    if(posicao == 0){
        printf("\n\n\t<<< OBS: NENHUM CONTATO CADASTRADO >>>\n\n");
    }
    else{
        printf("\n\n\t<<TOTOS OD CONTATOS >>>\n\n");
        for(i = 0; i < posicao; i++){
        imprimirDados(agenda,posicao);
        }
    }

    system("PAUSE");
}

