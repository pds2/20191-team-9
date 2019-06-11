#ifndef CANECA_CPP
#define CANECA_CPP

#include "produto/caneca.h"
#include "produto/produto.h"

Caneca::Caneca(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, float diametro):Produto(cod, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material){

        this->_diametro = diametro;
}

Caneca::~Caneca(){
}

float Caneca::getDiametro(){
        return this->_diametro;
}

void Caneca::imprimeProduto(){
        std::cout << "------------------------------" << std::endl;
        std::cout << "Nome do produto:\t" << getNome() << std::endl;
        std::cout << "Preco:\t\t\tR$ "<< getPreco() << std::endl;
        std::cout << "Cor:\t\t\t" << getCor() << std::endl;
        std::cout << "Media de avaliacoes:\t" << getMediaAvaliacoes() << std::endl;
        std::cout << "Categoria:\t\t" << getCategoria() << std::endl;
        std::cout << "Descricao:\t\t" << getDescricao() << std::endl;
        std::cout << "Material:\t\t" << getMaterial() << std::endl;
        std::cout << "Diametro:\t\t" << getDiametro() << " cm" << std::endl;
}
#endif
