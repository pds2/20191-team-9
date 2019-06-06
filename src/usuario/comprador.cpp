#ifndef COMPRADOR_CPP
#define COMPRADOR_CPP

#include "usuario/comprador.h"

Comprador::Comprador(std::string n, std::string em, std::string s) :
  Usuario(n, em, s), _numeroComprasCarrinho(0), _numeroComprasHistorico(0), _numeroAvaliacoes(0), _dinheiro(0){};

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
  Usuario *usu = new Usuario("cataprima", "cataprima", "1234");
  carrinho.push_back(usu);
  _numeroComprasCarrinho++;
}

bool Comprador::excluirCarrinho(){
  return true;
}

bool Comprador::adicionaDinheiro(double valor, Comprador comp){
  return true;
}

void Comprador::imprimirCarrinho(){
  for(int i=0; i < _numeroComprasCarrinho; i++){
    std::cout << "testando";
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
