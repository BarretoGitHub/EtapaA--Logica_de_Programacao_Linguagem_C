#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};


ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));

    if(raiz != NULL){
        *raiz = NULL;
    }

    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL){
        return;
    }

    libera_NO(no->esq);//percorre todos para esquerda
    libera_NO(no->dir);//percorro todos as esquerda
    free(no);//já liberei esquerda e direita, libero o nó em si

    no = NULL;
}


void libera_ArvBin(ArvBin *raiz){
    if (raiz == NULL){
        return;
    }

    libera_NO(*raiz);//libera cada um dos nós
    free(raiz);//libera raiz depois de todos os nós liberados
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return 1;
    }

    if(*raiz == NULL){
        return 1;
    }

    return 0;
}


int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL){
        return 0;
    }

    if(*raiz == NULL){
        return 0;
    }

    int alt_esq = altura_ArvBin(&((*raiz)-> esq));
    int alt_dir = altura_ArvBin(&((*raiz)-> dir));

    if(alt_esq > alt_dir){
        return (alt_esq + 1);
    }else{
        return(alt_dir + 1);
    }
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL){
        return 0;
    }

    if(*raiz == NULL){
        return 0;
    }

    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));

    return(alt_esq + alt_dir + 1);
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }

    if(*raiz != NULL){
        //printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}


void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }

    if(*raiz != NULL){
        preOrdem_ArvBin(&((*raiz)->esq));
        //printf("%d\n", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}


void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL){
        return;
    }

    if(*raiz != NULL){
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
        //printf("%d\n", (*raiz)->info);
    }
}


int insere_ArvBin(ArvBin *raiz, int valor){
    if (raiz == NULL){
        return 0;
    }

    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL){
        return 0;
    }

    //cria o nó novo
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    //procura onde inserir
    if(*raiz == NULL){// se a arvore for vazia e só inserir, senão tem que procurar
        *raiz = novo;
    }else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){//enquanto o tual for diferente de null eu desço na arvore
            ant = atual; //anterior recebe atual
            if(valor == atual->info){//comparo ambos, se for igual, não posso salver nós repetidos
                free(novo);
                return 0;
            }
            if(valor > atual->info){//se o valor for maior, caio para direita
                atual = atual->dir;
            }else{
                atual = atual->esq;//senão caio para esquerda
            }
        }
        //se chegou aqui, atual == NULL e ant igual folha

        if(valor > ant->info){//se o valor for maior que o folha, salvo na direita
            ant->dir = novo;
        }else{
            ant->esq = novo;//senão salvo na esquerda
        }
    }
    return 1;
}

//REMOVE O FILHO DA SUB-ARVORE A ESQUEDA QUE ESTÁ MAIS A DIREITA

int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }

    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){//faço a busca
        if(valor == atual->info){//achou o nó a ser removido. trata o lado da remoção
            if(atual == *raiz){//estou removendo a raiz
                *raiz = remove_atual(atual);
            }else{//estou removendo a direita ou a esquerda de alguém
                if(ant->dir == atual){
                    ant->dir = remove_atual(atual);
                }else{
                    ant->esq = remove_atual(atual);
                }
            }
            return 1;
        }
        //continua andando na arvore a procura do no a ser removido

        ant = atual;
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}

struct NO* remove_atual(struct NO* atual){
    struct NO *no1, *no2;

    //sem filho da esquerda. Apontar para o filho da direita (no folha e nó com 1 filho)
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
    }

    //procura o filho mais a direita na sub árvore da esquerda
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }//NO FINAL DESTE WHILE ---> no2 = null e no1 é o filho mais a direita que eu quero

    //COPIA O FILHO MAIS A DIREITA NA SUBARVORE DA ESQUERDA PARA O LUGAR DO NÓ REMOVIDO
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return(no2);// NOVO NÓ PARA OCUPAR O LUGAR DO ATUAL
};

//CONSULTA SE O VALOR EXISTE NA ÁRVORE
int consulta_ArvBin (ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}


ArvBin* igual(ArvBin *a, ArvBin *b){
    struct NO *no1, *no2;
    no1 = a;
    no2 = b;
    int x = 0;

    if(*a != NULL){
        preOrdem_ArvBin(&((*a)->esq));
        preOrdem_ArvBin(&((*a)->dir));
        x = consulta_ArvBin(b, (*a)->info);
    }

    if(*b != NULL){
        preOrdem_ArvBin(&((*b)->esq));
        preOrdem_ArvBin(&((*b)->dir));
        x = consulta_ArvBin(a, (*b)->info);
    }

    if(x == 1){
        printf("\n\t\t<< Arvores IGUAIS >>\n");
    }else{
        printf("\n\t\t<<Arvores DIFERENTES!! >>>\n");
    }
}








