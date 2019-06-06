#ifndef COMPRADOR_H
#define COMPRADOR_H

#include <string>

#include <vector>
#include <tuple>
#include <iostream>

#include "usuario/usuario.h"
#include "ecommerce.h"

class Comprador : public Usuario{
  private:
    int _numeroComprasHistorico=0;
    int _numeroComprasCarrinho=0;
    int _numeroAvaliacoes=0;
    double _dinheiro=0;

    //dps mudar de Usuario para Produto quando estiver pronto
    std::vector<Usuario *> carrinho;
    std::vector<Usuario *> historico;

  public:
    Comprador(std::string n, std::string em, std::string s);
    Comprador();
    ~Comprador();

    int getNumeroComprasHistorico();
    int getNumeroComprasCarrinho();

    int getNumeroAvaliacoes();
    double getDinheiro();

    void adicionarCarrinho(std::string email);
    bool excluirCarrinho();
    bool adicionaDinheiro(double valor, Comprador comp);

    void exibirPerfil();
    void imprimirCarrinho();
    void imprimirHistorico();
};

#endif
