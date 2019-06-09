#ifndef CANECA_CPP
#define CANECA_CPP

#include "produto/caneca.h"
#include "produto.cpp"

Caneca::Caneca(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, int diametro):Produto(preco, mediaAvaliacoes, nome, categoria, cor, descricao, material){

        _diametro = diametro;
}

Caneca::~Caneca(){
}

void Caneca::setProduto(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material, int diametro){

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
        _diametro = diametro;
}

void Caneca::getDiametro(){
    std::cout<<"Diametro:/t"<<_diametro;

#endif
