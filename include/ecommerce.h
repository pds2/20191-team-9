#ifndef ECOMMERCE_H
#define ECOMMERCE_H

#include <string>
#include <vector>
#include <sstream>

#include <cstdlib>

#include <math.h>

#include <fstream>
#include <iostream>

#include "usuario/comprador.h"
#include "produto/produto.h"

#include "produto/acessorio.h"
#include "produto/blusas_e_moletom.h"
#include "produto/caneca.h"

class Ecommerce{
  private:
    std::vector <Usuario> usuarios;
    std::vector <Comprador> compradores;

  /*  std::vector <Produto> produtos;
    std::vector <Caneca> canecas;
    std::vector <Acessorio> acessorios;
    std::vector <BlusasEMoletom> blusasEmoletons;*/


  public:
    Ecommerce();
    ~Ecommerce();

    void cadastrarUsuario (std::string n, std::string em, std::string s);
    void cadastrarComprador (std::string n, std::string em, std::string s, std::string cpf, std::string endereco, int numCarr, int numHist, int numAval, double din);
    //void cadastrarCaneca(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, float diametro);
    //void cadastrarAcessorio(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, std::string tipo);
    //void cadastrarBlusasEMoletom(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, char tamanho, std::string tipo);

    bool procurarUsuario(std::string email);
    bool procurarComprador(std::string em);
    void imprimirUsuarios();
    void imprimirCompradores();
    void imprimirProdutos();

    bool checaCodigo(int cod); //verifica se já existe um produto com o mesmo codigo cadastrado, caso sim retorna false
    bool checaNome(std::string n);
    bool checaEmail(std::string em);
    bool checaSenha(std::string s);

    /*int buscaIndiceCaneca(int cod);
    int buscaIndiceAcessorio(int cod);
    int buscaIndiceBlusasEMoletom(int cod);*/

    void addCarrinho();
    void limparTela();

    void impCarrinho();
    void impHistorico();
    void listaUsuarioArquivo();
    void gravaUsuarioArquivo();
    //void listaProdutosArquivo();    //ERRO
    //void gravaProdutosArquivo();

};

#endif
