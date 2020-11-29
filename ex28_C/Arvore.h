typedef struct arvore Arvore;

Arvore* criarArvore(int altura);

int imprimeArvore(Arvore* arvore,int indice);

int inserirElemento(Arvore* arvore, int indice);

void liberarNo(struct arvore* flagNo);

void liberarArvore(Arvore* criada);

