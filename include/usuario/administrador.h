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
#include "produto/acessorio.h"
#include "blusas_e_moletom.h"
#include "caneca.h"

#include "usuario/usuario.h"
#include "usuario/comprador.h"

class Administrador : public Usuario{
  private:
    int _qntdade_de_requisicoes;

    std::vector<BlusasEMoletom> _bluemols;
    std::vector<Caneca> _cans;
    std::vector<Acessorio> _aces;
    std::vector<Compradores> _shoppers;
    std::map<std::string, float> _requisicoes;

  public:

    Administrador(std::string nome, std::string email, std::string senha);

    void removeItem(std::string nome_do_produto);

    void adicionaPedido(std::string email, float valor);
    void mostraPedidos();
    void aprovaPedido(std::string email);

    void excluiUsuario(std::string email);

    ~Administrador();

};

#endif
