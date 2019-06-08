#ifndef COMPRADOR_CPP
#define COMPRADOR_CPP

#include "usuario/comprador.h"

Comprador::Comprador(std::string n, std::string em, std::string s, std::string cpf, std::string end, int numCarr, int numHist, int numAval, double din) :
  Usuario(n, em, s), _CPF(cpf),  _endereco(end), _numeroComprasCarrinho(numCarr), _numeroComprasHistorico(numHist), _numeroAvaliacoes(numAval), _dinheiro(din){};

Comprador::~Comprador(){
  carrinho.clear();
  historico.clear();
}

Comprador::Comprador(){

}

std::string Comprador::getCPF(){
  return this->_CPF;
}

std::string Comprador::getEndereco(){
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

void Comprador::adicionarCarrinho(std::string codProduto){

  //aqui procura o produto pelo codProduto dele, se encontrar não adiciona de novo, se não, prossegue
  // pega cada atributo desse Produto encontrado e cria um novo Produto, registrando ele no carrinho
  //Produto *prod = new Produto("cataprima", "cataprima", "1234", 1, 1, 1, 20);
  //carrinho.push_back(prod);
}

bool Comprador::retirarCarrinho(){
  if(_numeroComprasCarrinho == 0){
    std::cout << "Seu carrinho está vazio. Adicione produtos para continuar.";
    return false;
  }
  else{
    for(int i=0; i < _numeroComprasCarrinho; i++){
      //(*carrinho[i]).getProduto(); aqui chama a funcao que exibe os produtos que estão no carrinho
    }
    int codProduto;
    int indice = -1;
    std::cout << "\n" << "Digite o código do produto que deseja retirar do seu carrinho: ";
    std::cin >> codProduto;

    //aqui precisa verificar se o produto tá no carrinho mesmo
    //indice = funcao que procura pelo produto dado o codigo

    if(indice != -1){
      carrinho.erase(carrinho.begin()+ indice); //apaga o indice elemento a partir do começo do vector
      return true;
    }
    else{
      std::cout << "Produto não encontrado no carrinho. Tente novamente.";
      return false;
    }
  }
  return false;
}

bool Comprador::adicionaDinheiro(double valor, Comprador comp){
  //aqui tem que mandar uma requisicao para o administrador
  return true;
}

void Comprador::imprimirCarrinho(){
  if(_numeroComprasCarrinho == 0){
    std::cout << "Seu carrinho está vazio. Adicione produtos para continuar.";
  }
  else{
    for(int i=0; i < _numeroComprasCarrinho; i++){
      //(*carrinho[i]).getProduto(); aqui chama a funcao que exibe os produtos que estão no carrinho
    }
  }
}

void Comprador::imprimirHistorico(){
  if(_numeroComprasHistorico == 0){
    std::cout << "Seu histórico está vazio. Compre produtos para continuar.";
  }
  else{
    for(int i=0; i < _numeroComprasHistorico; i++){
      //(*historico[i]).getProduto(); aqui chama a funcao que exibe os produtos que estão no historico
    }
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

bool Comprador::procurarItens(){
  /*//aqui chama a funcao de produto que procura itens
  std::vector<Item> vecOfItems = getItemList();
  std::vector<Item>::iterator it;
  it = std::find_if(vecOfItems.begin(), vecOfItems.end(), [](Item const& obj){
  		return obj.getPrice() == 28;
  	} );
  if(it != vecOfItems.end())
  	std::cout<<"Item Price ::"<<it->getPrice()<<" Count :: "<<it->getCount()<<std::endl;
  else
  	std::cout<<"Item not Found"<<std::endl;*/
}

void Comprador::adicionarComentario(){

}

void Comprador::avaliarItem(){
  int codProduto;
  int indice = -1;

  imprimirHistorico();

  std::cout << "\n" << "Digite o código do produto que deseja retirar do seu carrinho: ";
  std::cin >> codProduto;

  // indice = aqui chama a funcao de produto que procura itens por codProduto
  if (indice != -1){
    int nota;

    std::cout << "\n" << "De 0 a 5, qual nota deseja dar ao produto de código " << codProduto << "?" << "\n";
    std::cin >> nota;
    if(nota>=0 || nota<=5){
      (*historico[indice]).avaliarProduto(nota);
    }
    else{
      std::cout << "\n" << "Nota inválida. Tente novamente.";
    }
  }
  else{
    std::cout << "\n" << "O produto de código " << codProduto << " não consta em seu histórico então não pode ser avaliado. Tente novamente.";
  }
}

void Comprador::enviarMensagem(){

}


#endif
