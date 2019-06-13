#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include <vector>

class Produto{
    private:
        float _preco;
        std::vector<int> _avaliacoes;
        float _mediaAvaliacoes;
        std::string _nome;
        std::string _categoria; //(Tema)
        std::string _cor;
        std::string _descricao;
        std::string _material;
        int _codigoProduto;

    public:
        Produto(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material);
        ~Produto();
        
        std::vector<std::string> _comentarios;
        float getPreco();
        float getMediaAvaliacoes();
        std::string getNome();
        std::string getCategoria();
        std::string getCor();
        std::string getDescricao();
        std::string getMaterial();
        int getCodigoProduto();

        void avaliarProduto(int nota); //salva avaliacao na lista e depois modifica a media
        void getComentarios(); //imprime comentarios
        void setComentario(std::string comentario); //salva comentario
        int retornaNumComentarios();

};

#endif
