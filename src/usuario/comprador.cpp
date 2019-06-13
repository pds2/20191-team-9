#ifndef COMPRADOR_CPP
#define COMPRADOR_CPP

#include "usuario/comprador.h"
#include "ecommerce.h"

Comprador::Comprador(std::string n, std::string em, std::string s, std::string cpf,
   std::string endereco, int numCarr, int numHist, int numAval, double din) :
 Usuario(n, em, s), _CPF(cpf), _endereco(endereco), _numeroComprasCarrinho(numCarr), _numeroComprasHistorico(numHist), _numeroAvaliacoes(numAval), _dinheiro(din){};

Comprador::~Comprador(){
  carrinho.clear();
  historico.clear();
}

Comprador::Comprador(){

}

void Comprador::setDinheiro(float valor){
  this->_dinheiro = valor;
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

float Comprador::getDinheiro(){
  return this->_dinheiro;
}

bool Comprador::adicionarCarrinho(){
  Ecommerce ecom;
  limparTela();

  //imprimir listagem de produtos aqui
  ecom.imprimirProdutos();

  int codProduto, opcao, indice = -1;
  std::cout << "\n" << "Digite o código do produto que deseja adicionar ao seu carrinho: ";
  std::cin >> codProduto;

  //procurar codigo do item na listagem de produtos
  indice = ecom.buscaIndiceProdutos(codProduto);

  if(indice != -1){
    std::cout << "Este produto já encontra-se em seu carrinho. Deseja adiciona-lo novamente?" << "\n0 - NÃO.\n1 - SIM." << std::endl;
    std::cin >> opcao;

    switch (opcao) {
      case 1:
        // pega cada atributo desse Produto encontrado e cria um novo Produto, registrando ele no carrinho
        //(ecom.produtos[indice]).get
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

bool Comprador::retirarCarrinho(){
  _numeroComprasCarrinho = carrinho.size();
  if(_numeroComprasCarrinho == 0){
    std::cout << "\n\nSeu carrinho está vazio. Adicione produtos para continuar.";
    return false;
  }
  else{
    limparTela();

    int codProduto;
    int indice = -1;
    //imprimirCarrinho();

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
  _numeroComprasCarrinho = carrinho.size();
  double totalCarrinho=0;

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
      totalCarrinho += (carrinho[i]).getPreco();

    }

    std::cout << "\n" << "----------------------------------------------" << std::endl;
    std::cout << "\t\t Qntd de Produtos: " << _numeroComprasCarrinho << std::endl;
    std::cout << "\t\t Total: "<< totalCarrinho << std::endl;
    std::cout << "----------------------------------------------" << "\n" << std::endl;
  }
}

void Comprador::imprimirHistorico(){
  _numeroComprasHistorico = historico.size();
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

  int digito
  std::cout << "Pressione qualquer tecla para voltar ao menu: ";
  std::cin >> digito
  if (true) { menuInicial(); }
}

void Comprador::procurarProduto(int codProduto){
  _numeroProdutos = produtos.size();

  for(int indice=0; indice < _numeroProdutos; indice++){
    if((produtos[indice]).getCodigoProduto() == codProduto){
      produtos[indice].getComentarios();
    }
  }
}

int Comprador::procurarItensHistorico(int codProduto){
  _numeroComprasHistorico = historico.size();

  for(int indice=0; indice < _numeroComprasHistorico; indice++){
    if((historico[indice]).getCodigoProduto() == codProduto){
      return indice;
    }
  }
  return -1;
}

int Comprador::procurarItensCarrinho(int codProduto){
  _numeroComprasCarrinho = carrinho.size();

  for(int indice=0; indice < _numeroComprasCarrinho; indice++){
    if((carrinho[indice]).getCodigoProduto() == codProduto){
      return indice;
    }
  }
  return -1;
}

void Comprador::adicionarComentario(){
  limparTela();

  int codProduto;
  int indice = -1

  //imprimirHistorico(); SE FOR PRA CONSULTA SO NAO LIMPAR A TELA

  std::cout << "\n" << "Digite o código do produto para o qual deseja registrar um comentário.";
  std::cin >> codProduto;

  indice = procurarItensHistorico(codProduto);

  if (indice != -1){
    std::string comentario;

    std::cout << "\n" << "Escreva o seu comentário para o produto de código " << codProduto << " : " << std::endl;
    std::getline(std::cin, comentario);
    //(historico[indice])->setComentario(comentario);
    //aqui altera o comentario do produto
    ecom.impHistorico();
  }
  else{
    std::cout << "\n" << "O produto de código " << codProduto << " não consta em seu histórico então não pode ter um comentário registrado. Tente novamente.";
  }
}

void Comprador::avaliarItem(){
  limparTela();

  int codProduto;
  int indice = -1;

  //imprimirHistorico();

  std::cout << "\n" << "Digite o código do produto que deseja avaliar: ";
  std::cin >> codProduto;

  indice = procurarItensHistorico(codProduto);

  Ecommerce ecom;

  if (indice != -1){
    int nota;

    std::cout << "\n" << "De 0 a 5, qual nota deseja dar ao produto de código " << codProduto << "?" << std::endl;
    std::cin >> nota;
    if(nota>=0 || nota<=5){
      (historico[indice]).avaliarProduto(nota);
      ecom.imprimirHistorico();
    }
    else{
      std::cout << "\n" << "Nota inválida. Tente novamente.";
    }
  }
  else{
    std::cout << "\n" << "O produto de código " << codProduto << " não consta em seu histórico então não pode ser avaliado. Tente novamente.";
    avaliarItem();
  }
}

bool Comprador::adicionaDinheiro(double valor, Comprador comp){
  //aqui tem que mandar uma requisicao para o administrador
  return true;
}

void Comprador::limparTela(){
  std::system("clear||cls");
}

/*
  Generic function to find an element in vector and also its position.
  It returns a pair of bool & int i.e.
  bool : Represents if element is present in vector or not.
  int : Represents the index of element in vector if its found else -1
*/
template < typename T>
std::pair<bool, int > findInVector(const std::vector<T>  & vecOfElements, const T  & element){
  std::pair<bool, int > result;
  // Find given element in vector
  auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);
  if (it != vecOfElements.end()){
  result.second = distance(vecOfElements.begin(), it);
  result.first = true;
  }
  else{
  result.first = false;
  result.second = -1;
  }
  return result;
}

void Comprador::fazerCompras(){
  std::cout << "Você está comprando " << carrinho.size() << " produtos, cujo valor total é " << _totalCarrinho << ". Deseja confirmar sua compra?" << std::endl;
  std::cout << "0 - NÃO\n1 - SIM" << std::endl;
  int opçao;
  Ecommerce ecom;
  std::cin >> opçao;
  switch (opcao) {
    case 0:
      std::cout << "Compra não realizada. Você ainda possui produtos te esperando em seu carrinho!" << std::endl;
      ecom.impCarrinho();
      break;
    case 1:
    {
      if(_dinheiro>=_totalCarrinho){
        carrinho.clear();
        _dinheiro = _dinheiro - _totalCarrinho;
        ecom.menuInicial();
      }
      else{
        std::cout << "Compra não realizada pois seu saldo é insuficiente! Você possui R$ " << _dinheiro << std::endl;
        ecom.impCarrinho();
      }
      break
    }
    default:
      std::cout << "Opção inválida. Tente novamente" << std::endl;
      fazerCompras();
      break;
  }
}

#endif
