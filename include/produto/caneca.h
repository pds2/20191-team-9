#ifndef CANECA_H
#define CANECA_H

#include <iostream>
#include <string>
#include <vector>
#include "produto.h"

class Caneca : public Produto{
    public:
        int _diametro;
        
        void setProduto(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, int diametro);
        void getProduto();
};

#endif
