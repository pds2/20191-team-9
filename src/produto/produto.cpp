/*#ifndef PRODUTO_CPP
#define PRODUTO_CPP
#include "produto/produto.h"

Produto::Produto(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material){
        std::vector<std::string> vazio;
        std::vector<int> nada;

        this->_codigoProduto = cod;
        this->_preco = preco;
        this->_mediaAvaliacoes = mediaAvaliacoes;
        this->_nome = nome;
        this->_categoria = categoria;
        this->_cor = cor;
        this->_descricao = descricao;
        this->_material = material;
        this->_comentarios = vazio;
        this->_avaliacoes = nada;
}

Produto::~Produto(){
}

void Produto::avaliarProduto(int nota){
    if (nota>=1 && nota<=5){
    _avaliacoes.push_back(nota);
    }
    int size = _avaliacoes.size();
    int i, soma;
    soma = 0;
    for (i = 0; i < size; i++){
        soma += _avaliacoes[i];
	  }
    _mediaAvaliacoes = (float)soma/size;
}

void Produto::getComentarios(){
    int size = _comentarios.size();
    int i;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Comentarios sobre esse produto:" << std::endl;
    for(i=0; i<size; i++){
        std::cout << _comentarios[i] << std::endl;
    }
}

void Produto::setComentario(std::string comentario){
    _comentarios.push_back(comentario);
}

float Produto::getPreco(){
    return this->_preco;
}

float Produto::getMediaAvaliacoes(){
    return this-> _mediaAvaliacoes;
}

std::string Produto::getNome(){
    return this->_nome;
}

std::string Produto::getCategoria(){
    return this-> _categoria;
}

std::string Produto::getCor(){
    return this-> _cor;
}

std::string Produto::getDescricao(){
    return this->_descricao;
}

std::string Produto::getMaterial(){
    return this->_material;
}

int Produto::getCodigoProduto(){
    return this->_codigoProduto;
}

#endif
*/
