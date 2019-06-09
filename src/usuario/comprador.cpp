#ifndef COMPRADOR_CPP
#define COMPRADOR_CPP

#include "usuario/comprador.h"
#include "usuario/usuario.h"

Comprador::Comprador(std::string n, std::string em, std::string s, std::string cpf,
   std::string endereco, int numCarr, int numHist, int numAval, double din) :
 Usuario(n, em, s), _CPF(cpf), _endereco(endereco), _numeroComprasCarrinho(numCarr), _numeroComprasHistorico(numHist), _numeroAvaliacoes(numAval), _dinheiro(din){};

Comprador::~Comprador(){
  carrinho.clear();
  historico.clear();
}

Comprador::Comprador(){

}

int Comprador::getTotalCarrinho(){
  return this->_totalCarrinho;
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

void Comprador::adicionarCarrinho(){
  limparTela();

  //imprimir listagem de produtos aqui
  int codProduto, opcao, indice = -1;
  std::cout << "\n" << "Digite o código do produto que deseja adicionar ao seu carrinho: ";
  std::cin >> codProduto;

  //procurar codigo do item na listagem de produtos
  indice = procurarItensCarrinho(codProduto);

  if(indice != -1){
    std::cout << "Este produto já encontra-se em seu carrinho. Deseja adiciona-lo novamente?" << "\nPressione 1 para SIM e 0 para NÃO." << std::endl;
    std::cin >> opcao;

    switch (opcao) {
      case 1:
        // pega cada atributo desse Produto encontrado e cria um novo Produto, registrando ele no carrinho
        //Produto *prod = new Produto("cataprima", "cataprima", "1234", 1, 1, 1, 20);
          //carrinho.push_back(prod);
        //modifica a variavel _totalCarrinho
        return true;
      case 0:
        std::cout << "Este produto já encontra-se em seu carrinho. Você escolheu não adicionar novamente." << std::endl;
        return false;
      default:
        std::cout << "Resposta inválida. Tente novamente." << std::endl;
        return false;
    }
  }
  else{
    std::cout << "\n\nProduto não encontrado no carrinho. Tente novamente.";
    return false;
  }
}
}

bool Comprador::retirarCarrinho(){
  if(_numeroComprasCarrinho == 0){
    std::cout << "\n\nSeu carrinho está vazio. Adicione produtos para continuar.";
    return false;
  }
  else{
    limparTela();

    int codProduto;
    int indice = -1;
    imprimirCarrinho();

    std::cout << "\n" << "Digite o código do produto que deseja retirar do seu carrinho: ";
    std::cin >> codProduto;

    indice = procurarItensCarrinho(codProduto);

    if(indice != -1){
      carrinho.erase(carrinho.begin()+ indice); //apaga o indice elemento a partir do começo do vector
      return true;
    }
    else{
      std::cout << "\n\nProduto não encontrado no carrinho. Tente novamente.";
      return false;
    }
  }
  return false;
}

void Comprador::imprimirCarrinho(){
  int _numeroComprasCarrinho = carrinho.size();

  if(_numeroComprasCarrinho == 0){
    std::cout << "Seu carrinho está vazio. Adicione produtos para continuar.";
  }
  else{
    limparTela();

    std::cout << "\n" << "----------------------------------------------" << std::endl;
    std::cout << "\t\t Carrinho" << std::endl;
    std::cout << "----------------------------------------------" << "\n" << std::endl;

    for(int i=0; i < _numeroComprasCarrinho; i++){

      std::cout << "\n" << "----------------------------------------------" << std::endl;
      std::cout << "\t\t Código " << (carrinho[i]).getCodigoProduto() << std::endl;
      std::cout << "----------------------------------------------" << "\n" << std::endl;
      std::cout << "Nome: " << (carrinho[i]).getNome() << std::endl;
      std::cout << "Categoria: " << (carrinho[i]).getCategoria()  << std::endl;
      std::cout << "Cor: " << (carrinho[i]).getCor()  << std::endl;
      std::cout << "Material: " << (carrinho[i]).getMaterial()  << std::endl;
      std::cout << "Media de Avaliações: " << (carrinho[i]).getMediaAvaliacoes()  << std::endl;
      std::cout << "Preço " << (carrinho[i]).getPreco() << std::endl;
      std::cout << "Descricao: " << (carrinho[i]).getDescricao() << std::endl;

    }

    std::cout << "\n" << "----------------------------------------------" << std::endl;
    std::cout << "\t\t Qntd de Produtos: " << _numeroComprasCarrinho << std::endl;
    std::cout << "\t\t Total: "<< (carrinho[i]).getTotalCarrinho() << std::endl;
    std::cout << "----------------------------------------------" << "\n" << std::endl;
  }
}

void Comprador::imprimirHistorico(){
  int _numeroComprasHistorico = historico.size();
  if(_numeroComprasHistorico == 0){
    std::cout << "Seu histórico está vazio. Compre produtos para continuar.";
  }
  else{
    limparTela();

    std::cout << "\n" << "----------------------------------------------" << std::endl;
    std::cout << "\t\t Histórico" << std::endl;
    std::cout << "----------------------------------------------" << "\n" << std::endl;

    for(int i=0; i < _numeroComprasCarrinho; i++){

      std::cout << "\n" << "----------------------------------------------" << std::endl;
      std::cout << "\t\t Código " << (historico[i]).getCodigoProduto() << std::endl;
      std::cout << "----------------------------------------------" << "\n" << std::endl;
      std::cout << "Nome: " << (historico[i]).getNome() << std::endl;
      std::cout << "Categoria: " << (historico[i]).getCategoria()  << std::endl;
      std::cout << "Cor: " << (historico[i]).getCor()  << std::endl;
      std::cout << "Material: " << (historico[i]).getMaterial()  << std::endl;
      std::cout << "Media de Avaliações: " << (historico[i]).getMediaAvaliacoes()  << std::endl;
      std::cout << "Preço " << (historico[i]).getPreco() << std::endl;
      std::cout << "Descricao: " << (historico[i]).getDescricao() << std::endl;

    }

    std::cout << "\n" << "----------------------------------------------" << std::endl;
    std::cout << "\n";
    std::cout << "----------------------------------------------" << "\n" << std::endl;
  }
}

void Comprador::exibirPerfil(){
  limparTela();
  std::cout << "\n" << "----------------------------------------------" << std::endl;
  std::cout << "\t\t Perfil do Usuário" << std::endl;
  std::cout << "----------------------------------------------" << "\n" << std::endl;
  std::cout << "Nome: " << getNome() << std::endl;
  std::cout << "Email: " << getEmail() << std::endl;
  std::cout << "Senha: " << getSenha() << std::endl;
  std::cout << "Nº Compras do Carrinho: " << getNumeroComprasCarrinho() << std::endl;
  std::cout << "Nº Compras do Histórico: " << getNumeroComprasHistorico() << std::endl;
  std::cout << "Nº Avaliações: " << getNumeroAvaliacoes() << std::endl;
  std::cout << "Qntd Dinheiro: " << getDinheiro() << std::endl;
}

int Comprador::procurarItensHistorico(int codProduto){
  int _numeroHistorico = historico.size();

  for(int indice=0; indice < _numeroHistorico; indice++){
    if((historico[indice]).getCodigoProduto() == codProduto){
      return indice;
    }
  }
  return -1;
}

int Comprador::procurarItensCarrinho(int codProduto){
  int _numeroCarrinho = carrinho.size();

  for(int indice=0; indice < _numeroCarrinho; indice++){
    if((carrinho[indice]).getCodigoProduto() == codProduto){
      return indice;
    }
  }
  return -1;
}

void Comprador::adicionarComentario(){
  limparTela();

  int codProduto;
  int indice = -1;

  imprimirHistorico();

  std::cout << "\n" << "Digite o código do produto para o qual deseja registrar um comentário.";
  std::cin >> codProduto;

  indice = procurarItensHistorico(codProduto);

  if (indice != -1){
    std::string comentario;

    std::cout << "\n" << "Escreva o seu comentário para o produto de código " << codProduto << " : " << std::endl;
    std::getLine(std::cin, comentario);
    setComentario(comentario);
  }
  else{
    std::cout << "\n" << "O produto de código " << codProduto << " não consta em seu histórico então não pode ter um comentário registrado. Tente novamente.";
  }
}

void Comprador::avaliarItem(){
  limparTela();

  int codProduto;
  int indice = -1;

  imprimirHistorico();

  std::cout << "\n" << "Digite o código do produto que deseja avaliar: ";
  std::cin >> codProduto;

  indice = procurarItensHistorico(codProduto);

  if (indice != -1){
    int nota;

    std::cout << "\n" << "De 0 a 5, qual nota deseja dar ao produto de código " << codProduto << "?" << std::endl;
    std::cin >> nota;
    if(nota>=0 || nota<=5){
      (historico[indice])->avaliarProduto(nota);
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

bool Comprador::adicionaDinheiro(double valor, Comprador comp){
  //aqui tem que mandar uma requisicao para o administrador
  return true;
}

#endif
