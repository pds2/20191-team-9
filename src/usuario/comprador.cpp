#ifndef COMPRADOR_CPP
#define COMPRADOR_CPP

#include "usuario/comprador.h"

Comprador::Comprador(std::string n, std::string em, std::string s, std:string cpf, std::string end, int numCarr, int numHist, int numAval, double din) :
  Usuario(n, em, s), _CPF(cpf),  _endereco(end), _numeroComprasCarrinho(numCarr), _numeroComprasHistorico(numHist), _numeroAvaliacoes(numAval), _dinheiro(din){};

Comprador::~Comprador(){
  carrinho.clear();
  historico.clear();
}

Comprador::Comprador(){

}

std::string getCPF(){
  return this->_CPF;
}

std::string getEndereco(){
  return this->_endereco;
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
  Comprador *comp = new Comprador("cataprima", "cataprima", "1234", 1, 1, 1, 20);
  carrinho.push_back(comp);
  comp = new Comprador("catarina", "catarina", "1234", 1, 1, 1, 20);
  carrinho.push_back(comp);

  for(int i=0; i < 2; i++){
    std::cout << (*carrinho[i]).getNome() << " " << (*carrinho[i]).getEmail() << " " << (*carrinho[i]).getSenha() << "\n";
  }
}

bool Comprador::excluirCarrinho(){
  return true;
}

bool Comprador::adicionaDinheiro(double valor, Comprador comp){
  return true;
}

void Comprador::imprimirCarrinho(){
  std::cout <<  "\n" << carrinho.size()  << "\n";
  for(int i=0; i < _numeroComprasCarrinho; i++){
    std::cout << (*carrinho[i]).getNome() << " " << (*carrinho[i]).getEmail() << " " << (*carrinho[i]).getSenha() << "\n";
  }
}

void Comprador::imprimirHistorico(){
  Usuario usuario;
  for(int i=0; i < _numeroComprasHistorico; i++){
    std::cout << (*historico[i]).getNome() << " " << (*historico[i]).getEmail() << " " << (*historico[i]).getSenha() << "\n";
  }
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
