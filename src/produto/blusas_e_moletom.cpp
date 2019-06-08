/*#ifndef BLUSAS_E_MOLETOM_CPP
#define BLUSAS_E_MOLETOM_CPP

#include "produto/blusas_e_moletom.h"
#include "produto.cpp"



BlusasEMoletom::BlusasEMoletom(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, char tamanho, std::string tipo) : Produto(preco, mediaAvaliacoes, nome, categoria, cor, descricao, material){
        _tipo = tipo;
        _tamanho = tamanho;
}

BlusasEMoletom::~BlusasEMoletom(){

}

/*void BlusasEMoletom::setProduto(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, char tamanho, std::string tipo){

        std::vector<std::string> vazio;
        std::vector<int> nada;

        _preco = preco;
        _mediaAvaliacoes = mediaAvaliacoes;
        _nome = nome;
        _categoria = categoria;
        _cor = cor;
        _descricao = descricao;
        _material = material;
        _comentarios = vazio;
        _avaliacoes = nada;
        _tipo = tipo;
        _tamanho = tamanho;
}*/
/*
void BlusasEMoletom::getProduto(){
    std::cout <<"Nome:\t" <<_nome << std::endl << "Preco:\t"<< _preco << std::endl << "Media:\t" <<_mediaAvaliacoes << std::endl << "Categoria:\t" << _categoria << std::endl << "Cor:\t" <<_cor << std::endl << "Descricao:\t" << _descricao << std::endl << "Material:\t" <<_material << std::endl << "Tipo:\t" << _tipo << std::endl<< "Tamanho:\t" << _tamanho << std::endl;
}

#endif
*/
