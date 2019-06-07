#ifndef ACESSORIO_CPP
#define ACESSORIO_CPP

#include "produto/acessorio.h"
#include "produto.cpp"

Acessorio::Acessorio(){
}
Acessorio::~Acessorio(){
}

void Acessorio::setProduto(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, std::string tipo){

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
}

void Acessorio::getProduto(){
    std::cout <<"Nome:\t" <<_nome << std::endl << "Preco:\t"<< _preco << std::endl << "Media:\t" <<_mediaAvaliacoes << std::endl << "Categoria:\t" << _categoria << std::endl << "Cor:\t" <<_cor << std::endl << "Descricao:\t" << _descricao << std::endl << "Material:\t" <<_material << std::endl << "Tipo:\t" << _tipo << std::endl;
}

#endif
*/
