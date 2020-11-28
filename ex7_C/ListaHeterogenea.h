typedef struct lista *Lista;

Lista* criarLista();

int inserirInicio(Lista* inicio, int tipo);

int inserirFinal(Lista* inicio, int tipo);

int imprimirLista(Lista* inicio);

int removerInicio(Lista* inicio);

int removerFinal(Lista* inicio);

