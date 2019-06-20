#include "excecoes.h"

#include <string>
#include <vector>

void verificar_historico_vazio(int produtosH){
    if(produtosH == 0){
        Exception_Historico_Vazio HV;
        throw HV;
    };
}

void verificar_carrinho_vazio(int produtosC){
    if(produtosC == 0){
        Exception_Carrinho_Vazio CV;
        throw CV;
    };
}

void verificar_usuario_existente(int indiceComprador){
  if(indiceComprador != -1){
    Exception_Usuario_Ja_Cadastrado UJC;
    throw UJC;
  }
}

void verificar_produto_ja_no_carrinho(int indiceProduto){
  if(indiceProduto != -1){
    Exception_Produto_Ja_Consta_No_Carrinho PNC;
    throw PNC;
  }
}

void verificar_produto_cadastrado(int indiceProduto){
  if(indiceProduto == -1){
    Exception_Produto_Nao_Encontrado PNE;
    throw PNE;
  }
}

void verificar_saldo_insuficiente(float dinheiroComprador, float totalCompras){
  if(totalCompras > dinheiroComprador){
    Exception_Saldo_Comprador_Insuficiente SCI;
    throw SCI;
  }
}

void verificar_produto_fora_do_historico(int indiceProdutoHistorico){
  if(indiceProdutoHistorico == -1){
    Exception_Produto_Fora_do_Historico PFH;
    throw PFH;
  }
}

void verificar_nota_invalida(int nota){
  if(nota!=0 && nota!=1 && nota!=2 && nota!=3 && nota!=4 && nota!=5){
    Exception_Nota_Invalida NI;
    throw NI;
  }
}

void verificar_opcao_menu_fazer_compras_invalida(int opcao){
  if(opcao!=0 && opcao!=1){
    Exception_Opcao_Menu_Fazer_Compras_Invalida OMCI;
    throw OMCI;
  }
}
