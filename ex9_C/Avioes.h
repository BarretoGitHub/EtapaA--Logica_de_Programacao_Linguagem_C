typedef struct noDescritor Fila;

typedef struct aviao avioes;

Fila* criarFila();

int inserirFila(Fila* fila);

int removerFila(Fila* fila);

avioes consultarFila(Fila* fila);

int imprimeFila(Fila* fila);

void liberaFila(Fila* fila);

int tamanhoFila(Fila* fila);


