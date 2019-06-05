#ifndef ACESSORIO_H
#define ACESSORIO_H

#include <iostream>
#include <string>
#include <vector>
#include "produto.h"

class Acessorio : public Produto{
    public:
        std::string _tipo;
        
        void setProduto(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, std::string tipo);
        void getProduto();
};

#endif
