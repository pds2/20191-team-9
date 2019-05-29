#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <vector>

class Produtos{
    public:
        float _preco;
        std::vector<int> _avaliacoes;
        float _mediaAvaliacoes;
        std::vector<std::string> _comentarios;
        std::string _nome;
        std::string _categoria; //(Tema) [string]
        std::string _cor; // [string]
        std::string _descricao;// [string]
        std::string _material;// [string]
        Produtos(float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material);
        ~Produtos();
        std::string getProduto(); //exibe produto
        /*std::string setProduto(float, float, std::string,
        std::string, std::string, std::string, std::string); //cria produto*/
        void avaliarProduto(); //salva avaliacao na lista e depois modifica a media
        void getComentarios(); //imprime comentarios
        void setComentario(); //salva comentario
};

#endif
