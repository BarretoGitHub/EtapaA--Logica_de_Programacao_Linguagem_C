typedef struct lista *Lista;

Lista* criarLista();

int inserirInicio(Lista* inicio, int num);

int imprimirLista(Lista* inicio);

Lista* unionListas(Lista* inicio1, Lista* inicio2);

int removerInicio(Lista* inicio);

int removerFinal(Lista* inicio);


