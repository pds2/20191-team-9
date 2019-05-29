#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario{

private:
    const std::string _nome;
    const std::string _email;
    const std::string _senha;
public:
    Usuario(std::string n, std::string em, std::string s);

    std::string getNome() const;
    std::string getEmail() const;
    std::string getSenha() const;

    void setNome(std::string n) const;
    void setEmail(std::string em) const;
    void setSenha(std::string s) const;

    bool checaNome(std::string n) const;
    bool checaEmail(std::string &em) const;
    bool checaSenha(std::string s) const;

    void CadastraUsuario (std::string n, std::string em, std::string s) const;

};

#endif
