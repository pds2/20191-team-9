#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>
#include <iostream>

#include "ecommerce.h"
#include "produto/produto.h"
#include "usuario/usuario.h"
#include "usuario/comprador.h"

class Administrador : public Usuario{
  private:
    std::str _requisicoes[];

  public:
    Administrador(std::string nome, std::string email, std::string senha);

    void adicionaItem(std::string nome_do_produto);

    void removeItem(Produto item);

    void mostraPedidos();

    bool aprovaPedido(std::string requisicao, Comprador user);

    void exibeUsuarios();

    void editaUsuario(Comprador user);

    void excluiUsuario(Comprador user);

    void exibeMensagens(Comprador user);

    void respondeMensagens(Comprador user);

    ~Administrador();

};

#endif
