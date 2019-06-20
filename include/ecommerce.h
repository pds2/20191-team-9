#ifndef ECOMMERCE_H
#define ECOMMERCE_H

#include <string>
#include <vector>

#include <cstdlib>

#include <math.h>

#include <fstream>
#include <iostream>

#include <sstream>

#include "usuario/comprador.h"

#include "usuario/administrador.h"
#include "produto/produto.h"
#include "produto/acessorio.h"
#include "produto/caneca.h"
#include "produto/blusas_e_moletom.h"
#include "excecoes.h"

class Ecommerce{
  private:
    std::vector <Usuario> usuarios;
    std::vector <Comprador> compradores;
    std::vector <Produto> produtos;
    std::vector <Caneca> canecas;
    std::vector <Acessorio> acessorios;
    std::vector <BlusasEMoletom> blusasEmoletons;

  public:
    Ecommerce();
    ~Ecommerce();

    void cadastrarUsuario (std::string n, std::string em, std::string s);
    void cadastrarComprador (std::string n, std::string em, std::string s, std::string cpf, std::string endereco, int numCarr, int numHist, int numAval, double din);

    void cadastrarCaneca(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, float diametro);
    void cadastrarAcessorio(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, std::string tipo);
    void cadastrarBlusasEMoletom(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, char tamanho, std::string tipo);

    bool procurarUsuario(std::string email);
    bool procurarComprador(std::string em);

    void imprimirUsuarios();
    void imprimirCompradores();
    void imprimirProdutos();

    bool checaNome(std::string n);
    bool checaEmail(std::string em);
    bool checaSenha(std::string s);
    bool checaSenhaAdmin(std::string sAdmin);

    int buscaIndiceCaneca(int cod);
    int buscaIndiceAcessorio(int cod);
    int buscaIndiceBlusasEMoletom(int cod);
    int buscaIndiceProdutos(int cod);
    Produto buscaProdutos(int cod);
    Comprador buscaComprador(std::string em);

    int tamanhoArquivo(const char* file_name); //se o arquivo tiver vazio retorna 0

    void addCarrinho();
    void limparTela();
    void impCarrinho();
    void impHistorico();
    void impProdutos();
    void mostraProdutos();

    void listaUsuarioArquivo();
    void gravaUsuarioArquivo();

    long int geradorCod();
    bool checaCodigo(int cod); //verifica se ja existe um produto com o mesmo codigo cadastrado, caso sim retorna false
    void listaProdutosArquivo();
    void gravaProdutosArquivo();

    void listaComentariosArquivo();
    void gravaComentariosArquivo();
    void adicionarComentario(int cod, std::string coment); //procura produto no vector pelo codigo e adiciona comentario

    void loginUsuario(std::string n, std::string s);
    void loginUsuario();
    void logoutUsuario();
    void inicio();
    void menuInicial();
    void menuUsuario();
    void menuComprador();
    void dadosComprador();
    void dadosProduto();

    Comprador procurarCompradorObj(std::string email);

};

#endif
