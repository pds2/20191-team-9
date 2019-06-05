#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include <vector>
#include <tuple>
#include <iostream>

class Usuario{

private:
    std::vector<Usuario> usuarios;
    std::string _nome;
    std::string _email;
    std::string _senha;

public:
    Usuario(std::string n, std::string em, std::string s);
    Usuario::Usuario();
    ~Usuario();

    std::string getNome(Usuario usu);
    std::string getEmail(Usuario usu);
    std::string getSenha(Usuario usu);

    bool checaNome(std::string n);
    bool checaEmail(std::string em);
    bool checaSenha(std::string s);

    bool BuscarEmailVector(std::string n);
    void imprimirUsuarios();
};

#endif
