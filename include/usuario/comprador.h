#ifndef COMPRADOR_H
#define COMPRADOR_H

#include <string>

#include <vector>
#include <tuple>
#include <iostream>
#include <map>

#include <iterator>

#include "usuario/usuario.h"
#include "produto/produto.h"
#include "usuario/comprador.h"

class Comprador : public Usuario{

  private:

    int _numeroComprasHistorico;
    int _numeroComprasCarrinho;
    int _numeroAvaliacoes;
    float _totalCarrinho;
    float _dinheiro;

    std::string _CPF;
    std::string _endereco;

    std::vector <Produto> carrinho;
    std::map <std::string, Produto> historico;

  public:
    Comprador(std::string nome, std::string email, std::string senha, std::string cpf, std::string endereco, int numComprasCarrinho, int numComprasHistorico, int numAvaliacaoes, double dinheiro);
    Comprador();
    ~Comprador();

    int getNumeroComprasHistorico();
    int getNumeroComprasCarrinho();

    std::string getCPF();
    std::string getEndereco();

    float getTotalCarrinho();

    int getNumeroAvaliacoes();
    float getDinheiro();
    void setDinheiro(float valor);

    bool adicionarCarrinho();
    void fazerCompras();
    bool retirarCarrinho();
    bool adicionaDinheiro();

    void exibirPerfil();
    void imprimirCarrinho();
    void imprimirHistorico();

    int procurarItensHistorico(long int codProduto);
    int procurarItensCarrinho(long int codProduto);
    void adicionarComentario();
    void avaliarItem();

    void listaHistoricoArquivo();

    void gravaHistoricoArquivo();

    void limparTela();

    Produto buscaHistorico(long int codProduto);
    Produto buscaCarrinho(long int codProduto);
};

#endif
