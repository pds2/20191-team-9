#ifndef ECOMMERCE_H
#define ECOMMERCE_H

#include <string>
#include <vector>
#include <tuple>
#include <iostream>

#include "usuario/usuario.h"
#include "usuario/comprador.h"

class Ecommerce{
  private:
    int numeroUsuarios;
    std::vector<Usuario *> usuarios;

  public:
    Ecommerce();
    ~Ecommerce();

    void cadastrarUsuario (std::string n, std::string em, std::string s);
    bool buscarEmail(std::string n);
    void imprimirUsuarios();

    bool checaNome(std::string n);
    bool checaEmail(std::string em);
    bool checaSenha(std::string s);

    void adicionarCarrinho();
};

#endif
