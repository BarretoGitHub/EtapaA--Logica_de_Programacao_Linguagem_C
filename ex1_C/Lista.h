typedef struct lista Lista;

Lista* criarLista();

int inserirFinal(Lista* lst,int num);

int inserirInicio(Lista* lst,int num);

int inserirOrdem(Lista* lst,int num);

int removerFinal(Lista* lst);

int removerInicio(Lista* lst);

int receberTam(Lista* lst);

int verificarOrdem(Lista* lst);

void imprimirLista(Lista* lst);

void copiarLista(Lista* lst1, Lista* lst2);
