#include "funcao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Variáveis globais para controle de produtos e carrinho
static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

// Exibe as informações de um produto
void infoProduto(Produto prod){
    printf("Código: %d \nNome: %s \nPreço: %.2f\n", prod.codigo, strtok(prod.nome, "\n"), prod.preco);
}

// Retorna um produto pelo código informado
Produto pegarProdutoPorCodigo(int codigo){
    Produto p;
    for(int i = 0; i < contador_produto; i++){
        if(produtos[i].codigo == codigo){
            p = produtos[i];
        }
    }
    return p;
}

// Exibe o menu principal e gerencia as opções
void menu(){
    printf("================ Bem-vindo(a) - Solução Mercado ===========\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Comprar produto\n");
    printf("4 - Visualizar carrinho\n");
    printf("5 - Fechar pedido\n");
    printf("6 - Sair do sistema\n");
    
    int opcao;
    scanf("%d", &opcao);
    getchar();
    
    switch (opcao) {
        case 1:
            cadastrarProduto();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            comprarProduto();
            break;
        case 4:
            visualizarCarrinho();
            break;
        case 5:
            fecharPedido();
            break;
        case 6:
            printf("Volte sempre!\n");
            sleep(2);
            exit(0);
        default:
            printf("Opção inválida.\n");
            sleep(2);
            menu();
            break;
    }
}

// Cadastra um novo produto na lista
void cadastrarProduto(){
    printf("Cadastro de Produto\n====================\n");
    printf("Informe o nome do produto: \n");
    fgets(produtos[contador_produto].nome, 30, stdin);
    printf("Informe o preço do produto: \n");
    scanf("%f", &produtos[contador_produto].preco);
    produtos[contador_produto].codigo = (contador_produto + 1);
    contador_produto++;
    printf("Produto cadastrado com sucesso!\n");
    sleep(2);
    menu();
}

// Lista todos os produtos cadastrados
void listarProdutos(){
    if(contador_produto > 0){
        printf("Listagem de produtos.\n---------------------\n");
        for(int i = 0; i < contador_produto; i++){
            infoProduto(produtos[i]);
            printf("------------------\n");
            sleep(1);
        }
    }else{
        printf("Não temos ainda produtos cadastrados.\n");
    }
    sleep(2);
    menu();
}

// Exibe os produtos no carrinho
void visualizarCarrinho(){
    if(contador_carrinho > 0){
        printf("Produtos do Carrinho\n--------------------\n");
        for(int i = 0; i < contador_carrinho; i++){
            infoProduto(carrinho[i].produto);
            printf("Quantidade: %d\n", carrinho[i].quantidade);
            printf("-----------------\n");
            sleep(1);
        }
    }else{
        printf("Não temos ainda produtos no carrinho.\n");
    }
    sleep(2);
    menu();
}

// Finaliza o pedido e exibe o valor total
void fecharPedido(){
    if(contador_carrinho > 0){
        float valorTotal = 0.0;
        printf("Produtos do Carrinho\n--------------------\n");
        for(int i = 0; i < contador_carrinho; i++){
            Produto p = carrinho[i].produto;
            int quantidade = carrinho[i].quantidade;
            valorTotal += p.preco * quantidade;
            infoProduto(p);
            printf("Quantidade: %d\n", quantidade);
            printf("---------------\n");
            sleep(1);
        }
        printf("Sua fatura é R$ %.2f\n", valorTotal);
        contador_carrinho = 0;
        printf("Obrigado pela preferência.\n");
        sleep(5);
    }else{
        printf("Você não tem nenhum produto no carrinho ainda.\n");
    }
    sleep(3);
    menu();
}
