#ifndef ECOMMERCE_H
#define ECOMMERCE_H

#include <string>
#include <vector>
#include <sstream>

#include <cstdlib>

#include <math.h>

#include <fstream>
#include <iostream>

#include "usuario/comprador.h"

class Ecommerce{
  private:
    int numeroUsuarios;
    std::vector <Usuario> usuarios;
    std::vector <Comprador> compradores;

  public:
    Ecommerce();
    ~Ecommerce();

    void cadastrarUsuario (std::string n, std::string em, std::string s);
    bool procurarUsuario(std::string email);
    void imprimirUsuarios();

    bool checaNome(std::string n);
    bool checaEmail(std::string em);
    bool checaSenha(std::string s);

    void addCarrinho();
    void limparTela();

    void impCarrinho();
    void impHistorico();
    void listaUsuarioArquivo();
};

#endif
