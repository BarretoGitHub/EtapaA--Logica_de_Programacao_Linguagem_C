#include <stdio.h>
#include <stdlib.h>

int escolherTermo();
int funcaoRecursiva(int);

int main(){
    int termo;
    int i;

    termo = escolherTermo();


    for(i = 0; i < termo; i++){
        printf("\nTermo (%d) = (%d)\n",(i + 1),funcaoRecursiva(i));
    }


    printf("\n\n");
    system("PAUSE");

    return 0;
}

int escolherTermo(){
    int termo;

    printf("Insira o termo de FIBONACCI: ");
    scanf("%d",&termo);


    return(termo);
}

int funcaoRecursiva(int termo){
    int flag;

    if(termo == 0){
        flag = 0;
    }

    else if(termo == 1 || termo == 2){
        flag = 1;
    }

    else{
        flag = funcaoRecursiva(termo - 1) + funcaoRecursiva(termo - 2);
    }

    return (flag);
}
