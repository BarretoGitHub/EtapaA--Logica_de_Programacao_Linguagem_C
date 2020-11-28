typedef struct produtos Produto;

typedef struct lista Lista;

Lista* criarLista();

int inserirInicio(Lista* lst);

int inserirFinal(Lista* lst);

int removerInicio(Lista* lst);

int removerFinal(Lista* lst);

int buscarMenorPreco(Lista* lst);

int buscarEstoqueInferior(Lista* lst);

int alterarProduto(Lista* lst);

int relatorioCrescente(Lista* lst);

int relatorioDecrescente(Lista* lst);
