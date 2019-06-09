#ifndef PRODUTO_CPP
#define PRODUTO_CPP
#include "produto/produto.h"

Produto::Produto(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material){
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

void Produto::getPreco(){
    std::cout<<"Preco:/t"<<_preco;
}
void Produto::getMediaAvaliacoes(){
    std::cout<<"Media de Avaliacoes:/t"<< _mediaAvaliacoes;
}
void Produto::getNome(){
    std::cout<<"Nome:/t"<< _nome;
}
void Produto::getCategoria(){
    std::cout<<"Categoria:/t"<< _categoria
}
void Produto::getCor(){
    std::cout<<"Cor:/t"<< _cor;
}
void Produto::getDescricao(){
    std::cout<<"Descricao:/t"<< _descricao;
}
void Produto::getMaterial(){
    std::cout<<"Material:/t"<< _material;
}
#endif
