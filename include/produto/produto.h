#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <vector>

class Produto{
    public:
        float _preco;
        std::vector<int> _avaliacoes;
        float _mediaAvaliacoes;
        std::vector<std::string> _comentarios;
        std::string _nome;
        std::string _categoria; //(Tema) 
        std::string _cor; 
        std::string _descricao;
        std::string _material;
        
        void setProduto();
        void getProduto(); //exibe produto 
        void avaliarProduto(int nota); //salva avaliacao na lista e depois modifica a media
        void getComentarios(); //imprime comentarios
        void setComentario(std::string comentario); //salva comentario
};

#endif
