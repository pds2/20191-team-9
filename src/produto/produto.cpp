/*
#include "../../include/produto/produto.h"

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
    for(i=0; i<size; i++){
        std::cout << _comentarios[i] << std::endl;
    }
}

void Produto::setComentario(std::string comentario){
    _comentarios.push_back(comentario);
}
*/
