typedef struct lista Lista;
typedef struct listaM ListaM;

Lista* criarLista();

int inserirInicio(Lista* lista, int numero);

int inserirFinal(Lista* lista, int numero);

int inserirOrdenado(Lista* lista, int numero);

int ordenarLista(Lista* lista);

int imprimirLista(Lista* lista);

int imprimirListaMerge(ListaM* lista);

ListaM* mergeListas(Lista* lista1, Lista* lista2);


