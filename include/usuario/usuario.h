#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include <vector>
#include <tuple>
#include <iostream>

#include "produto/produto.h"
#include "ecommerce.h"

class Usuario{

private:
    std::string _nome;
    std::string _email;
    std::string _senha;

public:
    Usuario(std::string n, std::string em, std::string s);
    Usuario();
    ~Usuario();

    std::string getNome();
    std::string getEmail();
    std::string getSenha();

    void Usuario::imprimirUsuarios();
    bool Usuario::buscarEmail(std::string em);

};

#endif
