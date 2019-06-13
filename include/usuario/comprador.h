#ifndef COMPRADOR_H
#define COMPRADOR_H

#include <string>

#include <vector>
#include <tuple>
#include <iostream>

#include <iterator>

#include "usuario/usuario.h"
#include "produto/produto.h"

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
    std::vector <Produto> historico;

  public:
    Comprador(std::string nome, std::string email, std::string senha, std::string cpf, std::string endereco, int numComprasCarrinho, int numComprasHistorico, int numAvaliacaoes, double dinheiro);

    Comprador();
    ~Comprador();

    int getNumeroComprasHistorico();
    int getNumeroComprasCarrinho();

    std::string getCPF();
    std::string getEndereco();

    int getTotalCarrinho();

    int getNumeroAvaliacoes();
    float getDinheiro();
    void setDinheiro(float valor);


    bool adicionarCarrinho();
    void fazerCompras();
    bool retirarCarrinho();
    bool adicionaDinheiro(double valor, Comprador comp);

    void exibirPerfil();
    void imprimirCarrinho();
    void imprimirHistorico();

    void procurarProduto(int codProduto);
    int procurarItensHistorico(int codProduto);
    int procurarItensCarrinho(int codProduto);
    void adicionarComentario();
    void avaliarItem();

    void limparTela();
};

#endif
