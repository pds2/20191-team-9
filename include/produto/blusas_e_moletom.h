#ifndef BLUSAS_E_MOLETOM_H
#define BLUSAS_E_MOLETOM_H

#include <iostream>
#include <string>
#include <vector>

#include "produto/produto.h"

class BlusasEMoletom : public Produto{
    private:
        char _tamanho;
        std::string _tipo; //Se é uma blusa ou um moletom

    public:
        BlusasEMoletom(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, char tamanho, std::string tipo);
        ~BlusasEMoletom();
        char getTamanho();
        std::string getTipo();
        void imprimeProduto();

};

#endif
