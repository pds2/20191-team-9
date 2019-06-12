#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <fstream>

#include "ecommerce.h"
#include "produto/produto.h"
#include "usuario/usuario.h"
#include "usuario/comprador.h"

class Administrador : public Usuario{
  private:
    int _qntdade_de_requisicoes;

    std::vector<BlusasEMoletom> bluemols;
    std::vector<Caneca> cans;
    std::vector<Acessorio> aces;
    std::vector<Compradores> shoppers;
    std::map<std::string, float> _requisicoes;



  public:

    Administrador(std::string nome, std::string email, std::string senha);

    void removeItem(std::string nome_do_produto);

    void mostraPedidos();

    void aprovaPedido(float valor, Comprador user);

    void exibeUsuarios();

    void editaUsuario(std::string email);

    void excluiUsuario(std::string email);

    void exibeMensagens(std::string email);

    void respondeMensagens(std::string email);

    ~Administrador();

};

#endif
