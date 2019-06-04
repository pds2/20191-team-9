#ifndef CAMISA_H
#define CAMISA_H

#include <iostream>
#include <string>
#include <vector>
#include "produto.h"

class Camisa : public Produto{
    public:
        char _tamanho;
        std::string _tipo;
    
        void setProduto(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, char tamanho, std::string tipo);
        void getProduto();
};

#endif
