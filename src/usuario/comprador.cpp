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

bool Comprador::adicionarCarrinho(){
  Ecommerce ecom;
  std::string codProduto;

  ecom.imprimirUsuarios();  //faz a listagem dos produtos aqui

  std::cout << "----------Escolha um produto para adiciona-lo ao seu carrinho----------"<< "\n";
  std::cout << "Código do Produto: "<< "\n";  //usuario escolhe qual produto vai querer aqui;
  std::cin >> codProduto;

  if(ecom.buscarEmail(codProduto) == true){
    Usuario *comp = new Usuario("teste", "teste", "teste");
    carrinho.push_back(comp);
    _numeroComprasCarrinho++;
    std::cout << "Produto adicionado ao carrinho com sucesso!"<< "\n";
    imprimirCarrinho();
  }
  else{
    std::cout << "Produto escolhido não foi encontrado. Tente novamente mais tarde."<< "\n";
  }
}

bool Comprador::excluirCarrinho(){

}

bool Comprador::adicionaDinheiro(double valor, Comprador comp){

}

void Comprador::imprimirCarrinho(){
  Ecommerce ecom;
  ecom.imprimirUsuarios();
  /*for(int i=0; i < _numeroComprasCarrinho; i++){
    std::cout << "testando o carrinho " << i+1 << "\n";
  }*/
}

void Comprador::imprimirHistorico(){
  for(int i=0; i < _numeroComprasHistorico; i++){
    std::cout << "testando o historico " << i+1 << "\n";
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
