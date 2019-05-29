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

    std::string getNome() const;
    std::string getEmail() const;
    std::string getSenha() const;

    bool checaNome(std::string n) const;
    bool checaEmail(std::string &em) const;
    bool checaSenha(std::string s) const;

    void CadastraUsuario (std::string n, std::string em, std::string s) const;

};

#endif
