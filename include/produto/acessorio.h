#ifndef ACESSORIO_H
#define ACESSORIO_H

#include <iostream>
#include <string>
#include <vector>
#include "produto.h"

class Acessorio : public Produto{
    public:
        int _tamanho;
        
        void setProduto(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, int tamanho);
        void getProduto();
};

#endif
