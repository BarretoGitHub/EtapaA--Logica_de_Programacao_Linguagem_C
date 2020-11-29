#include <stdio.h>
#include <stdlib.h>
#define C 2000 /* CABEÇAS*/

struct Nascimento{
    int mes;
    int ano;
};

struct Gado{
    int codigo;
    int alimento;
    int leite;
    char abate;
    struct Nascimento nasc;
};

void imprimeMenu(void);
int lerBaseDados(struct Gado[C] ,int);
void verificarAbate(struct Gado[C], int);
int leiteSemanal(struct Gado[C],int);
int alimentoSemanal(struct Gado[C], int);
int leiteAposAbate(struct Gado[C], int);
int alimentoAposabate(struct Gado[C], int);
int cabecasAbate(struct Gado[C], int);

int main(void){
    int i;
    int opcao;
    int posicao = 0;

    int contLeite;
    int contAlimento;
    int contLeiteAposAbate;
    int contAlimentoAposabate;
    int contCabecasAbate;

    struct Gado fazenda[C];

    do{
        imprimeMenu();
        scanf("%d",&opcao);

    }while(opcao != 8);



    switch(opcao){
    case 1:
        posicao = lerBaseDados(fazenda,posicao);
        break;

    case 2:
        verificarAbate(fazenda,posicao);
        break;

    case 3:
        contLeite = leiteSemanal(fazenda,posicao);
        printf("\n\n%d LITROS de leite sao produzidos semanalmente",contLeite);
        break;

    case 4:
        contAlimento = alimentoSemanal(fazenda,posicao);
        printf("\n\n%d QUILOS de alimento sao consumidos semanalmente\n",contAlimento);
        break;

    case 5:
        contLeiteAposAbate = leiteAposAbate(fazenda,posicao);
         printf("\n\n%d QUILOS de alimento usados apos abate\n\n",contLeiteAposAbate);
        break;

    case 6:
        contAlimentoAposabate =  alimentoAposabate(fazenda,posicao);
        printf("\n\n%d QUILOS de alimento usados apos abate\n\n",contAlimentoAposabate);
        break;

    case 7:
        contCabecasAbate = cabecasAbate(fazenda,posicao);
        printf("\n\n%d CABECAS de gado iram para o abate\n\n",contCabecasAbate);
        break;

    case 8:
        printf("\n\nSaindo.....\n\n");
        break;

    }

    return 0;
}


void imprimeMenu(){

    printf("\n\n\t\t<<< MENU >>>\n\n");
    printf("1 - Ler base de dados\n");
    printf("2 - Preencher o campo abate");
    printf("3 - Quantidade de leite produzida por semana\n");
    printf("4 - Quantidade de alimento consumido por semana.\n");
    printf("5 - Quantidade de alimento produzido semanalmente apos abate\n");
    printf("6 - Quantidade de alimento consumido semanalmente apos abate\n");
    printf("7 - Quantidade de cabecas de gado que iram para o abate\n");
    printf("8 - Sair\n\n");

}

int lerBaseDados(struct Gado fazenda[C], int posicao){
    printf("\n\n\\t\tInsira os seguintes Dados\n\n");

    printf("Litros de leite produzidos por cabeca de gado por semana:  ");
    scanf("%d",&fazenda[posicao].leite);

    printf("Quilos de comida consumidas por cabeca ,no periodo semanal: ");
    scanf("%d",&fazenda[posicao].alimento);

    printf("Mes de nascimento da cabeca de gado: ");
	scanf("%d",& fazenda[posicao].nasc.mes);

	printf("Ano de nascimento da cabeca de gado: ");
	scanf("%d",& fazenda[posicao].nasc.ano);

	printf("O codigo dessa cabeca de gado e: %d", posicao + 1);

    posicao = posicao + 1;

    return(posicao);

}

void verificarAbate(struct Gado fazenda[C], int posicao){
    int i;

    for(i = 0; i < posicao; i++){
        if(fazenda[i].nasc.ano >= 5 || fazenda[i].leite < 40 || (fazenda[i].leite > 50 && fazenda[i].leite < 70 && fazenda[i].alimento > 50)){
            fazenda[i].abate = 's'; /*sim*/
        }

        else{
            fazenda[i].abate = 'n'; /*não*/
        }
    }
}

int  leiteSemanal(struct Gado fazenda[C], int posicao){
    int i;
    int somatorio = 0;

    for(i = 0; i < C; i++){
        somatorio = somatorio + fazenda[i].leite;
    }

    return(somatorio);
}

int alimentoSemanal(struct Gado fazenda[C],int posicao){
    int i;
    int somatorio = 0;

    for(i = 0; i < C; i++){
        somatorio = somatorio + fazenda[i].alimento;
    }

    return(somatorio);
}

int leiteAposAbate(struct Gado fazenda[C], int posicao){
    int i;
    int somatorio = 0;

    if(fazenda[posicao-1].abate == 'n' || fazenda[posicao-1].abate == 's'){
		for(i=0; i < posicao; i++){
			if(fazenda[i].abate == 'n'){
				somatorio = somatorio + fazenda[i].leite;
			}
		}
    }
    return(somatorio);
}

int alimentoAposabate(struct Gado fazenda[C],int posicao){
    int i;
    int somatorio = 0;


    if(fazenda[posicao-1].abate == 'n' || fazenda[posicao-1].abate == 's'){
		for(i=0; i < posicao; i++){
			if(fazenda[i].abate == 'n'){
				somatorio = somatorio + fazenda[i].alimento;
			}
		}
    }
    return(somatorio);
}

int cabecasAbate(struct Gado fazenda[C], int posicao){
    int i;
    int somatorio = 0;

    if(fazenda[posicao-1].abate == 'n' || fazenda[posicao - 1].abate == 's'){
		for(i = 0; i < posicao; i++){
			if(fazenda[i].abate == 's'){
				somatorio = somatorio + 1;
			}
		}
    }
    return(somatorio);
}



