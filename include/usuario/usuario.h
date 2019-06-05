#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include <vector>
#include <tuple>
#include <iostream>

#include "produto/produto.h"

class Usuario{

private:
    std::string _nome;
    std::string _email;
    std::string _senha;

    std::vector <Produto> carrinho;
    std::vector <Produto> historico;

public:
    Usuario(std::string n, std::string em, std::string s);
    Usuario();
    ~Usuario();

    std::string getNome(Usuario usu);
    std::string getEmail(Usuario usu);
    std::string getSenha(Usuario usu);
};

#endif
