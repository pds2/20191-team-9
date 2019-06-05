#ifndef COMPRADOR_H
#define COMPRADOR_H

#include <string>

#include <vector>
#include <tuple>
#include <iostream>

#include "produto/produto.h"
#include "usuario/usuario.h"

class Comprador : public Usuario {
  private:
    int numeroCompras;
    int numeroAvaliacoes;
    double dinheiro;

    std::vector <Produto> carrinho;
    std::vector <Produto> historico;
  public:
    Comprador();
    ~Comprador();
    bool adicionarCarrinho();
    bool excluirCarrinho();
    bool adicionaDinheiro();

    void exibirPerfil();

};

#endif
