#ifndef CANECA_H
#define CANECA_H

#include <iostream>
#include <string>
#include <vector>

#include "produto/produto.h"

class Caneca : public Produto{
    private:
        float _diametro;

    public:
        Caneca(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, float diametro);
        ~Caneca();
        float getDiametro();
        virtual void imprimeProduto() override;

};

#endif
