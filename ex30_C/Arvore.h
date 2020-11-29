typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();

void libera_ArvBin(ArvBin *raiz);

int estaVazia_ArvBin(ArvBin *raiz);

int altura_ArvBin(ArvBin *raiz);

int totalNO_ArvBin(ArvBin *raiz);

void preOrdem_ArvBin(ArvBin *raiz);

void emOrdem_ArvBin(ArvBin *raiz);

void posOrdem_ArvBin(ArvBin *raiz);

int insere_ArvBin(ArvBin *raiz, int valor);

int remove_ArvBin(ArvBin *raiz, int valor);

//AUXILIA NA REMOÇÃO
struct NO* remove_atual(struct NO* atual);

int consulta_ArvBin (ArvBin *raiz, int valor);

ArvBin* igual(ArvBin *a, ArvBin *b);



