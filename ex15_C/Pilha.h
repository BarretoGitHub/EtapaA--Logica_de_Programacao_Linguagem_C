#define MAX 40
typedef struct pilha *Pilha;

Pilha* criarPilha();

void inicializarComandos(Pilha* pilha);

void inverterString(Pilha* pilha,char vet[MAX]);

void invertePalavra(Pilha* pilha,char vet[MAX],int t1,int t2);

void lerString(char vet[MAX]);

int pilhaPush(Pilha* topo, char letra);

char pilhaPop(Pilha* topo);

char pilhaPop(Pilha* topo);


