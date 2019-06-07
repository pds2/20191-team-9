#ifndef BLUSAS_E_MOLETOM_H
#define BLUSAS_E_MOLETOM_H

#include <iostream>
#include <string>
#include <vector>
#include "produto.h"

class BlusasEMoletom : public Produto{
    public:
        char _tamanho;
        std::string _tipo; //Se é uma blusa ou um moletom
        BlusasEMoletom();
        ~BlusasEMoletom();
        void setProduto(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, char tamanho, std::string tipo);
        void getProduto();
};

#endif
