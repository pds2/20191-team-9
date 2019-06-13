#ifndef PRODUTO_CPP
#define PRODUTO_CPP

#include "produto/produto.h"
#include "excecoes.h"

/**
 * [Produto::Produto Construtor da classe Produto]
 * @method Produto::Produto
 * @param  cod                  [Código de identificação do produto]
 * @param  preco                [Preço do produto]
 * @param  mediaAvaliacoes      [Média de avaliações do produto]
 * @param  nome                 [Nome do produto]
 * @param  categoria            [Categoria do produto]
 * @param  cor                  [Cor do produto]
 * @param  descricao            [Descrição do produto]
 * @param  material             [numero de itens avaliados pelo comprador]
 */

Produto::Produto(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string categoria, std::string cor, std::string descricao, std::string material){
        std::vector<std::string> vazio;
        std::vector<int> nada;
        if((cod < 0)||(preco < 0)||(mediaAvaliacoes < 0)){
            throw ArgumentoInvalido();
        }

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

/**
 * [Produto Destrutor da classe Produto ]
 * @method Produto
 */
Produto::~Produto(){

}

/**
 * [Produto::avaliarProduto função que adiciona uma nota ao produto e modifica sua media de avaliações]
 * @method Produto::avaliarProduto
 * @param  nota                  [parâmetro representa uma nota a ser atribuida ao produto]
 */

void Produto::avaliarProduto(int nota){
    if (nota>=1 && nota<=5){
    _avaliacoes.push_back(nota);
    } else{
        throw ArgumentoInvalido();
    }

    int size = _avaliacoes.size();
    int i, soma;
    soma = 0;
    for (i = 0; i < size; i++){
        soma += _avaliacoes[i];
	  }
    _mediaAvaliacoes = (float)soma/size;
}

/**
 * [Produto::getComentarios função que imprime todos os comentarios já atribuidos ao produto]
 * @method Produto::getCometarios
 */
void Produto::getComentarios(){
    int size = _comentarios.size();
    int i;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Comentarios sobre esse produto:" << std::endl;
    for(i=0; i<size; i++){
        std::cout << _comentarios[i] << std::endl;
    }

    int digito
    std::cout << "Pressione qualquer tecla para voltar ao menu: ";
    std::cin >> digito
    if (true) { menuInicial(); }
}
/**
 * [Produto::setComentario função que adiciona um comentário ao produto]
 * @method setComentario::setComentario
 * @param  comentario                  [parâmetro que representa o comentário a ser atribuido ao produto]
 */
void Produto::setComentario(std::string comentario){
    _comentarios.push_back(comentario);
}

/**
 * [Produto::getPreco função que retorna o preco do produto]
 * @method Produto::getPreco
 * @return [valor do produto]
 */
float Produto::getPreco(){
    return this->_preco;
}
/**
 * [Produto::getMediaAvaliacoes função que retorna a média de avaliações do produto]
 * @method Produto::getMediaAvaliacoes
 * @return [média de avaliações do produto]
 */
float Produto::getMediaAvaliacoes(){
    return this-> _mediaAvaliacoes;
}
/**
 * [Produto::getNome função que retorna o nome do produto]
 * @method Produto::getNome
 * @return [nome do produto]
 */

std::string Produto::getNome(){
    return this->_nome;
}
/**
 * [Produto::getCategoria função que retorna a categoria do produto]
 * @method Produto::getCategoria
 * @return [categoria do produto]
 */
std::string Produto::getCategoria(){
    return this-> _categoria;
}
/**
 * [Produto::getCor função que retorna a cor do produto]
 * @method Produto::getCor
 * @return [cor do produto]
 */
std::string Produto::getCor(){
    return this-> _cor;
}
/**
 * [Produto::getDescricao função que retorna a descrição do produto]
 * @method Produto::getDescricao
 * @return [descrição do produto]
 */
std::string Produto::getDescricao(){
    return this->_descricao;
}
/**
 * [Produto::getMaterial função que retorna o material do produto]
 * @method Produto::getMaterial
 * @return [material do produto]
 */
std::string Produto::getMaterial(){
    return this->_material;
}
/**
 * [Produto::getCodigoProduto função que retorna o código de identificação do produto]
 * @method Produto::getCodigoProduto
 * @return [código de identificação do produto]
 */
int Produto::getCodigoProduto(){
    return this->_codigoProduto;
}
/**
 * [Produto::retornaNumComentarios função que retorna o numero de comentários atribuidos ao produto]
 * @method Produto::retornaNumComentarios
 * @return [número de comentários atribuidos ao produto]
 */
int Produto::retornaNumComentarios(){
    return _comentarios.size();
}
#endif
