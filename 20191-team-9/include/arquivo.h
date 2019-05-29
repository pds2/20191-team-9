#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>

class Arquivo{

public:
    void RegistraUsuarioArquivo (Usuario usu) const;
    void ListaUsuarioArquivo() const;
    bool BuscarEmailArquivo(std::string usu) const;

};

#endif
