/*#ifndef BLUSAS_E_MOLETOM_CPP
#define BLUSAS_E_MOLETOM_CPP

#include "produto/blusas_e_moletom.h"
#include "produto.cpp"

BlusasEMoletom::BlusasEMoletom(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, char tamanho, std::string tipo) : Produto(cod, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material){
        this->_tipo = tipo;
        this->_tamanho = tamanho;
}

BlusasEMoletom::~BlusasEMoletom(){

}

std::string BlusasEMoletom::getTipo(){
        return this->_tipo;
}

char BlusasEMoletom::getTamanho(){
        return this->_tamanho;
}

void BlusasEMoletom::imprimeProduto(){

        std::cout << "------------------------------" << std::endl;
        std::cout << "Nome do produto:\t" << getNome() << std::endl;
        std::cout << "Preco:\t\t\tR$ "<< getPreco() << std::endl;
        std::cout << "Tamanho: \t\t" << getTamanho() << std::endl;
        std::cout << "Tipo:\t\t\t" << getTipo() << std::endl;
        std::cout << "Cor:\t\t\t" << getCor() << std::endl;
        std::cout << "Media de avaliacoes:\t" << getMediaAvaliacoes() << std::endl;
        std::cout << "Categoria:\t\t" << getCategoria() << std::endl;
        std::cout << "Descricao:\t\t" << getDescricao() << std::endl;
        std::cout << "Material:\t\t" << getMaterial() << std::endl;

}

#endif
*/
