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
    int _totalCarrinho;
    float _dinheiro;

    std::string _CPF;
    std::string _endereco;

    //dps mudar de Usuario para Produto quando estiver pronto
    std::vector <Produto> carrinho;
    std::vector <Produto> historico;

  public:
    Comprador(std::string n, std::string em, std::string s, std::string cpf, std::string endereco, int numCarr, int numHist, int numAval, double din);

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

    int procurarItensHistorico(int codProduto);
    int procurarItensCarrinho(int codProduto);
    void adicionarComentario();
    void avaliarItem();

    void limparTela();
};

#endif
