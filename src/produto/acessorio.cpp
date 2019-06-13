#ifndef ACESSORIO_CPP
#define ACESSORIO_CPP

#include "produto/acessorio.h"

Acessorio::Acessorio(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, std::string tipo):Produto(cod, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material){
    this->_tipo = tipo;
}

Acessorio::~Acessorio(){

}

std::string Acessorio::getTipo(){
    return this->_tipo;
}

void Acessorio::imprimeProduto(){

    std::cout << "------------------------------" << std::endl;
    std::cout << "Nome do produto:\t" << getNome() << std::endl;
    std::cout << "Preco:\t\t\tR$ "<< getPreco() << std::endl;
    std::cout << "Cor:\t\t\t" << getCor() << std::endl;
    std::cout << "Media de avaliacoes:\t" << getMediaAvaliacoes() << std::endl;
    std::cout << "Categoria:\t\t" << getCategoria() << std::endl;
    std::cout << "Descricao:\t\t" << getDescricao() << std::endl;
    std::cout << "Material:\t\t" << getMaterial() << std::endl;
    std::cout << "Tipo:\t\t\t" << getTipo() << std::endl;

}

#endif
