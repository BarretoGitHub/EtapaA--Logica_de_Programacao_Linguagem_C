#define MAX 100
#define NOME 100

struct aluno{
    int matricula;
    char nome[NOME];
    float n1,n2,n3;
};

typedef struct lista Lista;

Lista* cria_lista();

int insere_lista(Lista* li, struct aluno al);

void mergeSort(Lista *V, int inicio, int fim);

void merge(Lista*V, int inicio, int meio, int fim);

void imprime_lista(Lista* li);


