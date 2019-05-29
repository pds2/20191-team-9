#ifndef USUARIO_H
#define USUARIO_H

#include <string>

#include <vector>
#include <tuple>
#include <iostream>

class Usuario{

private:
    const vector<tuple<std::string, std::string, std::string> > usuarios;

public:
    Usuario(std::string n, std::string em, std::string s);
    ~Usuario();

    std::string getNome(vector<tuple<std::string, std::string, std::string> > usu) const;
    std::string getEmail(vector<tuple<std::string, std::string, std::string> > usu) const;
    std::string getSenha(vector<tuple<std::string, std::string, std::string> > usu) const;

    bool checaNome(std::string n) const;
    bool checaEmail(std::string em) const;
    bool checaSenha(std::string s) const;

    void CadastraUsuario (std::string n, std::string em, std::string s) const;
    void ImprimeUsuarios();

};

#endif
