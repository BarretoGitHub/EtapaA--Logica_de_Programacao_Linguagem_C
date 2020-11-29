#include <stdio.h>
#include <stdlib.h>

#include"Exercicio3.h"
#define MAX 10

 main(){

    int i = 0;

    //Atribuindo dados dos alunos
    struct aluno a[MAX] = {  {22,"Maria Fernanda", 9.59, 7.8, 8.5},
                             {20,"Tommy Emmanuel", 7.5, 8.79, 6.8},
                             {18,"Marcos Fernandes", 9.7, 6.79, 8.4},
                             {12,"Marcio Antonio", 5.7, 6, 7.9},
                             {10,"Guilherme Ferreira", 5.79, 6.1, 6.4},
                             {16,"Gustavo Barreto", 5.08, 8,7},
                             {14,"Clara Tavares", 8.7, 8.1, 7.4},
                             {12,"Denis Buerdos ", 8.89, 6.8, 8.4},
                             {10,"Fernanda Takada",3.7, 9.1, 7.4},
                             {8,"Julia Vasconcelos",9.76, 9.1, 9.4},
                          };

    Lista* li = cria_lista();

    for(i = 0; i < MAX; i++){
        insere_lista(li, a[i]);
    }

    printf("\n\t\t++++++++++++ <<  Dados dos Alunos - MATRICULAS DESORDENADAS >>> ++++++++++++\n");
    imprime_lista(li);

    mergeSort(li,0,MAX-1);

    printf("\n_______________________________________________________________________________________________________________\n");
    printf("\n\n\t\t++++++++++++ <<  Dados dos Alunos - MATRICULAS ORDENADAS >>>  ++++++++++++\n");
    imprime_lista(li);

}
