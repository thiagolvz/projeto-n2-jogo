#ifndef FUNCAO_H  // Previne múltiplas inclusões do cabeçalho
#define FUNCAO_H

#include "produto.h"
#include "carrinho.h"

// Declaração das funções principais
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
void fecharPedido();
Produto pegarProdutoPorCodigo(int codigo);
int * temNoCarrinho(int codigo);

#endif // Fim da verificação de múltipla inclusão