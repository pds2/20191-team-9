#include "produto.h"

Produtos::Produtos(float preco, float mediaAvaliacoes,
  std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material){

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

Produtos::~Produtos(){

}

std::string Produtos::getProduto(){
    std::cout<< _preco << std::endl <<_mediaAvaliacoes << std::endl <<_nome << std::endl <<_categoria << std::endl <<_cor << std::endl << _descricao << std::endl <<_material << std::endl;
}

void Produtos::avaliarProduto(int nota){

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

void Produtos::getComentarios(){
    int size = _comentarios.size();
    int i;
    for(i=0; i<size; i++){
        std::cout << _comentarios[i] << std::endl;
    }
}

void Produtos::setComentario(std::string comentario){
    _comentarios.push_back(comentario);
}
