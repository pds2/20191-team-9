#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>

class Arquivo{

public:
    void RegistraUsuarioArquivo ( <tuple<std::string, std::string, std::string> usu) const;
    void ListaUsuarioArquivo() const;
    bool BuscarEmailArquivo(std::string usu) const;
};

#endif
