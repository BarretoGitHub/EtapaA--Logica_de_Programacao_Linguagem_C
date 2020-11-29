#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TOTAL_CONTAS 50
#define TRUE 1
#define FALSE 0



struct Pessoa{
	char nome[TOTAL_CONTAS];
	int numConta;
	float saldoBancario;
	int espacoLiberado;
};


void imprimeMenu(void);
void casdastrarConta(struct Pessoa []);
int  inserirConta(struct Pessoa []);
void removerConta(struct Pessoa []);
void efetuarDeposito(struct Pessoa []);
void efetuarSaque(struct Pessoa []);


int main(void){

    setlocale(LC_ALL,"Portuguese");
	int opcao;
	struct Pessoa contas[TOTAL_CONTAS];

	do{

		do{
			system("CLS");
			imprimeMenu();
			scanf("%d",&opcao);

		}while(opcao < 1 || opcao > 6);



		switch(opcao){

			case 1:
                casdastrarConta(contas);
			break;

			case 2:
                removerConta(contas);
			break;

			case 3:
			    efetuarDeposito(contas);
            break;

            case 4:
                efetuarSaque(contas);
            break;

			case 5:
                consultarConta(contas);
                break;

            case 6:
                printf("Saindo.........");
                break;

		}

	}while(opcao != 6);

	printf("\n\n\n\n");

    return 0;
}





void imprimeMenu(){

	printf("\n\n\t<<BEM-VINDO AO MENU>>\n\n");

	printf("1 - Cadastramento da Conta\n");
	printf("2 - Remocao da Conta\n");
	printf("3 - Deposito\n");
	printf("4 - Saque\n");
	printf("5 - Consulta\n");
	printf("6 - SAIR do sistema\n\n");

}



void casdastrarConta(struct Pessoa c[TOTAL_CONTAS]){
	int i;
	int certificacao = FALSE;

	for(i = 0; i < TOTAL_CONTAS; i++){
		if(c[i].espacoLiberado){
			certificacao = TRUE;
			break;
		}
	}

	if(certificacao == FALSE){
		printf("Erro. Seviço indisponível");
	}

	else{
		printf("\n\nInsira os Dados....\n\n");
		printf("Nome: ");
		fflush(stdin);
		gets(c[i].nome);

		c[i].numConta = i + 1;
		c[i].espacoLiberado = FALSE;

		printf("\n\nEfetuando cadastro..............");
		printf("\n\nCadastro efetuado com sucesso!");
		printf("\n\nNOME: ");
		puts(c[i].nome);
		printf("\nNumero do CADASTRO: [ %d ]",c[i].numConta);


		getchar();

	}
}



int inserirConta(struct Pessoa contas[TOTAL_CONTAS]){
    int numConta;
    int certificacao = FALSE;

    do{
        printf("Insira o numero da conta: ");
        scanf("%d",&numConta);

        if(contas[numConta - 1].espacoLiberado == FALSE){
            certificacao = TRUE;
        }

        else{
            printf("");
        }
    }while(certificacao == FALSE);

    return(numConta - 1);

}




void removerConta(struct Pessoa contas[TOTAL_CONTAS]){
	int i;
 	int var;


    i = inserirConta(contas);

 	printf("Processando.....");
 	printf("\n\nRemover conta:[ %d ]",i+1);

 	do{

 		system("CLS");
  		printf("\n\n1 - Excluir conta");
 		printf("\n2 - Cancelar operacao\n");
 		scanf("%d",&var);

 	}while(var < 1 || var > 2);

 	if(var == 1){
 		contas[i].saldoBancario = 0;
 		contas[i].numConta = 0;
 		contas[i].espacoLiberado = TRUE;

 		printf("\n\nOperacao efetuada com sucesso. Conta EXCLUIDA !\n\n");

 	}

 	else{
 		printf("\n\nErro! Operacao nao finalizada !\n\n\n\n");

 	}

 	system("PAUSE");



}



void consultarConta(struct Pessoa contas[TOTAL_CONTAS]){
    int i;

    i = inserirConta(contas);

    printf("\n\nCLIENTE: ");
    puts(contas[i].nome);

    printf("\nSALDO: %.2f\n\n",contas[i].saldoBancario);

    system("PAUSE");


}



void efetuarDeposito(struct Pessoa contas[TOTAL_CONTAS]){
    float valorDeposito;
    int i;

    i = inserirConta(contas);

    printf("\n\nProcessando Deposito....");

    printf("\n\nValor: ");
    scanf("%f",&valorDeposito);

    contas[i].saldoBancario = contas[i].saldoBancario + valorDeposito;

    printf("\n\nDEPÓSITO REALIZADO COM SUCESSO !\n\n");

    system("PAUSE");


}

void efetuarSaque(struct Pessoa contas[TOTAL_CONTAS]){
    int i,j;
    float valorSaque;
    int certificacao = FALSE;

    i = inserirConta(contas);

    printf("Processando Saque....\n\n");

    while(certificacao == TRUE){

        printf("\nValor: ");
        scanf("%f",&valorSaque);

        if(valorSaque < contas[i].saldoBancario && valorSaque > 0){

            contas[i].saldoBancario = contas[i].saldoBancario - valorSaque;
            printf("Saque realizado com sucesso\n\n");
            certificacao = TRUE;
            break;
        }

        else{
            printf("Saque invalido\n\n");
        }

    }
   system("PAUSE");

}


