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
#include "produto/blusas_e_moletom.h"
#include "produto/caneca.h"

#include "usuario/usuario.h"
#include "usuario/comprador.h"

class Administrador : public Usuario{
  private:
    int _qntdade_de_requisicoes;

    std::vector<BlusasEMoletom> _bluemols;
    std::vector<Caneca> _cans;
    std::vector<Acessorio> _aces;
    std::vector<Comprador> _shoppers;
    std::map<std::string, float> _requisicoes;

  public:

    Administrador();

    void produtoCsvToVector();
    void usuarioCsvToVector();
    void reqCsvToMap();

    void removeItem(std::string nome_do_produto);

    void adicionaPedido(std::string email, float valor);
    void mostraPedidos();
    void aprovaPedido(std::string email);
    void exibirPerfil();

    void excluiUsuario(std::string email);

    ~Administrador();

};

#endif
