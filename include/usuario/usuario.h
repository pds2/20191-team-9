#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include <vector>
#include <tuple>
#include <iostream>

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
};

#endif
