#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

int main(){
    Lista* L1;
    Lista* L2;

    L1 = criarLista();
    inserirFinal(L1);
    system("CLS"); /*Limpando TELA*/

    inserirFinal(L1);
    system("CLS"); /*Limpando TELA*/

    inserirFinal(L1);
    system("CLS"); /*Limpando TELA*/

    buscarMenorPreco(L1);
    system("CLS"); /*Limpando TELA*/

    buscarEstoqueInferior(L1);
    system("CLS"); /*Limpando TELA*/

    alterarProduto(L1);
    system("CLS"); /*Limpando TELA*/

    relatorioCrescente(L1);
    system("CLS"); /*Limpando TELA*/

    relatorioDecrescente(L1);

    L2 = criarLista();
    inserirFinal(L2);
    system("CLS"); /*Limpando TELA*/

    inserirFinal(L2);
    system("CLS"); /*Limpando TELA*/

    inserirFinal(L2);
    system("CLS"); /*Limpando TELA*/

    buscarMenorPreco(L2);
    system("CLS"); /*Limpando TELA*/

    buscarEstoqueInferior(L2);
    system("CLS"); /*Limpando TELA*/

    alterarProduto(L2);
    system("CLS"); /*Limpando TELA*/

    relatorioCrescente(L2);
    system("CLS"); /*Limpando TELA*/

    relatorioDecrescente(L2);
}
