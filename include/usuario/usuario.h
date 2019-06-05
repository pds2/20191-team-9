#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include <vector>
#include <tuple>
#include <iostream>

class Usuario{

private:
    std::vector<std::tuple<std::string, std::string, std::string> > usuarios;

public:
    Usuario(std::string n, std::string em, std::string s);
    ~Usuario();

    std::string getNome(std::tuple<std::string, std::string, std::string> usu);
    std::string getEmail(std::tuple<std::string, std::string, std::string> usu);
    std::string getSenha(std::tuple<std::string, std::string, std::string> usu);

    bool checaNome(std::string n);
    bool checaEmail(std::string em);
    bool checaSenha(std::string s);

    void CadastraUsuario (std::string n, std::string em, std::string s);
    bool BuscarEmailVector(std::string n);
    void ImprimeUsuarios();
};

#endif
