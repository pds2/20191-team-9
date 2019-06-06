#ifndef COMPRADOR_CPP
#define COMPRADOR_CPP

#include "usuario/comprador.h"

Comprador::Comprador(std::string n, std::string em, std::string s, int numCarr, int numHist, int numAval, double din) :
  Usuario(n, em, s), _numeroComprasCarrinho(numCarr), _numeroComprasHistorico(numHist), _numeroAvaliacoes(numAval), _dinheiro(din){};

Comprador::~Comprador(){
  carrinho.clear();
  historico.clear();
}

Comprador::Comprador(){

}

int Comprador::getNumeroComprasHistorico(){
  return this->_numeroComprasHistorico;
}

int Comprador::getNumeroComprasCarrinho(){
  return this->_numeroComprasCarrinho;
}

int Comprador::getNumeroAvaliacoes(){
  return this->_numeroAvaliacoes;
}

double Comprador::getDinheiro(){
  return this->_dinheiro;
}

void Comprador::adicionarCarrinho(std::string email){

}

bool Comprador::excluirCarrinho(){
  return true;
}

bool Comprador::adicionaDinheiro(double valor, Comprador comp){
  return true;
}

void Comprador::imprimirCarrinho(){

}

void Comprador::imprimirHistorico(){

}

void Comprador::exibirPerfil(){
  std::cout << "----------Perfil ----------"<< "\n";
  std::cout << "Nome: " << getNome() << "\n";
  std::cout << "Email: " << getEmail() << "\n";
  std::cout << "Senha: " << getSenha() << "\n";
  std::cout << "Nº Compras do Carrinho: " << getNumeroComprasCarrinho() << "\n";
  std::cout << "Nº Compras do Histórico: " << getNumeroComprasHistorico() << "\n";
  std::cout << "Nº Avaliações: " << getNumeroAvaliacoes() << "\n";
  std::cout << "Qntd Dinheiro: " << getDinheiro() << "\n";
}


#endif
