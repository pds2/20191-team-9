#ifndef COMPRADOR_CPP
#define COMPRADOR_CPP

#include "usuario/comprador.h"
#include "usuario/administrador.h"
#include "ecommerce.h"

/**
 * [Comprador::Comprador Construtor da classe Comprador]
 * @method Comprador::Comprador
 * @param  nome                 [nome do comprador]
 * @param  email                [email do comprador, pelo qual o mesmo realiza login no sistema]
 * @param  senha                [senha do comprador, pela qual o mesmo realiza login no sistema]
 * @param  cpf                  [cpf do comprador]
 * @param  endereco             [endereco do comprador, para onde os itens comprados deverão ser enviados]
 * @param  numComprasCarrinho   [numero de itens adicionados ao carrinho do comprador]
 * @param  numComprasHistorico  [numero de itens adquiridos do comprador]
 * @param  numAvaliacaoes       [numero de itens avaliados pelo comprador]
 * @param  dinheiro             [quantidade de dinheiro que o comprador possui]
 */

Comprador::Comprador(std::string nome, std::string email, std::string senha, std::string cpf,
   std::string endereco, int numComprasCarrinho, int numComprasHistorico, int numAvaliacaoes, double dinheiro) :
 Usuario(nome, email, senha), _CPF(cpf), _endereco(endereco), _numeroComprasCarrinho(numComprasCarrinho), _numeroComprasHistorico(numComprasHistorico), _numeroAvaliacoes(numAvaliacaoes), _dinheiro(dinheiro){};

/**
 * [Comprador Destrutor da classe Comprador ]
 * @method Comprador
 */

Comprador::~Comprador(){
  carrinho.clear();
  historico.clear();
}

/**
 * [Comprador::Comprador Construtor sem parâmetros da classe Comprador]
 * @method Comprador::Comprador
 */

Comprador::Comprador(){

}

/**
 * [Comprador::setDinheiro função que modifica a quantidade de dinheiro que o comprador possui]
 * @method Comprador::setDinheiro
 * @param  valor                  [parâmetro que define a nova quantidade de dinheiro que o comprador possui]
 */
void Comprador::setDinheiro(float valor){
  this->_dinheiro = valor;
}

/**
 * [Comprador::getTotalCarrinho função que retorna o valor total dos itens adicionados ao carrinho do comprador]
 * @method Comprador::getTotalCarrinho
 * @return [valor total dos itens adicionados ao carrinho do comprador]
 */

float Comprador::getTotalCarrinho(){
  return this->_totalCarrinho;
}

/**
 * [Comprador::getCPF função que retorna o cpf do comprador]
 * @method Comprador::getCPF
 * @return [cpf do comprador]
 */
std::string Comprador::getCPF(){
  return this->_CPF;
}

/**
 * [Comprador::getEndereco função que retorna o endereço do comprador]
 * @method Comprador::getEndereco
 * @return [endereço do comprador]
 */

std::string Comprador::getEndereco(){
  return this->_endereco;
}

/**
 * [Comprador::getNumeroComprasHistorico função que retorna a quantidade de itens adquiridos anteriormente pelo comprador]
 * @method Comprador::getNumeroComprasHistorico
 * @return [quantidade de itens adquiridos anteriormente pelo comprador]
 */

int Comprador::getNumeroComprasHistorico(){
  return this->_numeroComprasHistorico;
}

/**
 * [Comprador::getNumeroComprasCarrinho função que retorna a quantidade de itens adicionados ao carrinho pelo comprador]
 * @method Comprador::getNumeroComprasCarrinho
 * @return [quantidade de itens adicionados ao carrinho pelo comprador]
 */

int Comprador::getNumeroComprasCarrinho(){
  return this->_numeroComprasCarrinho;
}

/**
 * [Comprador::getNumeroAvaliacoes função que retorna o numero de avaliações realizadas pelo comprador]
 * @method Comprador::getNumeroAvaliacoes
 * @return [numero de avaliações realizadas pelo comprador]
 */

int Comprador::getNumeroAvaliacoes(){
  return this->_numeroAvaliacoes;
}

/**
 * [Comprador::getDinheiro função que retorna a quantidade de dinheiro que comprador possui]
 * @method Comprador::getDinheiro
 * @return [quantidade de dinheiro que comprador possui]
 */

float Comprador::getDinheiro(){
  return this->_dinheiro;
}

/**
 * [Comprador::adicionarCarrinho função que adiciona ao carrinho um novo item, a ser escolhido pelo comprador]
 * @method Comprador::adicionarCarrinho
 * @return [true no caso da adição ao carrinho ter sido bem sucedida e false, em caso contrário]
 */

bool Comprador::adicionarCarrinho(){
  Ecommerce ecom;
  limparTela();

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
        int cod;
        std::string nome, categoria, cor, descricao, material;
        float preco, mediaAvaliacoes;

        cod = (ecom.produto[indice]).getCodigoProduto();
        nome = (ecom.produto[indice]).getNome();
        categoria = (ecom.produto[indice]).getCategoria();
        cor = (ecom.produto[indice]).getCor();
        descricao = (ecom.produto[indice]).getDescricao();
        material = (ecom.produto[indice]).getMaterial();
        preco = (ecom.produto[indice]).getPreco();
        mediaAvaliacoes = (ecom.produto[indice]).getMediaAvaliacoes();

        Produto prod = Produto(cod, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material)
        carrinho.push_back(prod);
        _totalCarrinho = _totalCarrinho + preco;
        return true;
      case 0:
        std::cout << "Este produto já encontra-se em seu carrinho. Você escolheu não adicionar novamente." << std::endl;
        return false;
        break;
      default:
        std::cout << "Resposta inválida. Tente novamente." << std::endl;
        return false;
        break;
    }
  }
  else{
    std::cout << "\n\nProduto não encontrado no carrinho. Tente novamente.";
    return false;
  }
}

/**
 * [Comprador::retirarCarrinho função que retira um item do carrinho, a ser escolhido pelo comprador]
 * @method Comprador::retirarCarrinho
 * @return [true no caso da remoção do carrinho ter sido bem sucedida e false, em caso contrário]
 */

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

/**
 * [Comprador::imprimirCarrinho função que imprime os itens que constam no carrinho do comprador]
 * @method Comprador::imprimirCarrinho
 */

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

/**
 * [Comprador::imprimirHistorico função que imprime os itens que constam no histórico do comprador]
 * @method Comprador::imprimirHistorico
 */

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

    for(int i=0; i < _numeroComprasHistorico; i++){
      if((historico[i].first) == this->_email){
        std::cout << "\n" << "----------------------------------------------" << std::endl;
        std::cout << "\t\t Email do Comprador: " << (historico[i].first) << std::endl;
        std::cout << "----------------------------------------------" << "\n" << std::endl;
        std::cout << "Código: " << (historico[i].second).getCodigoProduto() << std::endl;
        std::cout << "Nome: " << (historico[i].second).getNome() << std::endl;
        std::cout << "Preço " << (historico[i].second).getPreco() << std::endl;
      }
    }

    std::cout << "\n" << "----------------------------------------------" << std::endl;
    std::cout << "\n";
    std::cout << "----------------------------------------------" << "\n" << std::endl;
  }
}

/**
 * [Comprador::exibirPerfil função que exibe o perfil do comprador, com todas as informações que foram registradas durante o seu cadastro]
 * @method Comprador::exibirPerfil
 */

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

/**
 * [Comprador::procurarProduto função que imprime os comentários registrados para um item específico, localizando o item através de uma pesquisa utilizando o código do produto]
 * @method Comprador::procurarProduto
 * @param  codProduto                 [código único que representa um produto]
 */

void Comprador::procurarProduto(int codProduto){
  _numeroProdutos = produtos.size();

  for(int indice=0; indice < _numeroProdutos; indice++){
    if((produtos[indice]).getCodigoProduto() == codProduto){
      produtos[indice].getComentarios();
    }
  }
}

/**
 * [Comprador::procurarItensHistorico função que localiza um item no histórico do comprador, através de uma pesquisa utilizando o código do produto]
 * @method Comprador::procurarItensHistorico
 * @param  codProduto                        [código úndico que representa um produto]
 * @return                                   [indice no histórico em que o produto se encontra]
 */

int Comprador::procurarItensHistorico(int codProduto){
  _numeroComprasHistorico = historico.size();

  for(int indice=0; indice < _numeroComprasHistorico; indice++){
    if((historico[indice]).getCodigoProduto() == codProduto){
      return indice;
    }
  }
  return -1;
}

/**
 * [Comprador::procurarItensCarrinho função que localiza um item no carrinho do comprador, através de uma pesquisa utilizando o código do produto]
 * @method Comprador::procurarItensCarrinho
 * @param  codProduto                       [código único que representa um produto]
 * @return                                  [indice no carrinho em que o produto se encontra]
 */

int Comprador::procurarItensCarrinho(int codProduto){
  _numeroComprasCarrinho = carrinho.size();

  for(int indice=0; indice < _numeroComprasCarrinho; indice++){
    if((carrinho[indice]).getCodigoProduto() == codProduto){
      return indice;
    }
  }
  return -1;
}

/**
 * [Comprador::adicionarComentario função que localiza um item no histórico do comprador, através de uma pesquisa utilizando o código do produto, e em seguida registra um comentário realizado pelo comprador para este mesmo produto]
 * @method Comprador::adicionarComentario
 */

void Comprador::adicionarComentario(){

  int codProduto;
  int indice = -1;

  std::cout << "\n" << "Digite o código do produto para o qual deseja registrar um comentário.";
  std::cin >> codProduto;

  indice = procurarItensHistorico(codProduto);

  if (indice != -1){
    std::string comentario;

    std::cout << "\n" << "Escreva o seu comentário para o produto de código " << codProduto << " : " << std::endl;
    std::getline(std::cin, comentario);

    (historico[indice]).setComentario(comentario);
    std::cout << "\n" << "Comentário para o produto de código " << codProduto << " registrado com sucesso! " << std::endl;
    ecom.impHistorico();
  }
  else{
    std::cout << "\n" << "O produto de código " << codProduto << " não consta em seu histórico então não pode ter um comentário registrado. Tente novamente.";
  }
}

/**
 * [Comprador::avaliarItem função que localiza um item no histórico do comprador, através de uma pesquisa utilizando o código do produto, e em seguida permite que o comprador avalie este mesmo produto]
 * @method Comprador::avaliarItem
 */

void Comprador::avaliarItem(){
  limparTela();

  int codProduto;
  int indice = -1;

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

/**
 * [Comprador::limparTela função responsável por limpar a tela do sistema]
 * @method Comprador::limparTela
 */

void Comprador::limparTela(){
  std::system("clear||cls");
}

/**
 * [Comprador::fazerCompras função que confimar a compra dos produtos adicionados ao carrinho do comprador]
 * @method Comprador::fazerCompras
 */

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
        _numeroComprasHistorico++;

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

/**
 * [Comprador::adicionaDinheiro função que envia uma requsição ao administrador para aumento de saldo do comprador]
 * @method Comprador::adicionaDinheiro
 * @param  valor                       [valor que o comprador deseja adicionar ao seu dinheiro atual]
 * @param  comp                        [comprador que está solicitando a requisição de aumento de saldo]
 * @return                             [true em caso da requisicao ter sido bem sucedida e false, em caso contrário]
 */

bool Comprador::adicionaDinheiro(double valor, Comprador comp){
  //aqui tem que mandar uma requisicao para o administrador
  return true;
}

/**
 * [Comprador::listaHistoricoArquivo função que lista o histórico de compras registrados no arquivo]
 * @method Comprador::listaHistoricoArquivo
 */

void Comprador::listaHistoricoArquivo(){
  std::fstream arquivo;

  arquivo.open("historico.csv");
  std::string email;

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

  while (arquivo.good()){

    std::string nomeProduto, codigoProduto, precoProduto, numeroComprasHistorico;
    int codigo, nCH;
    float preco=0.0;

    std::getline(arquivo, email,',');
    std::getline(arquivo, numeroComprasHistorico, ',');

    if(email==""){
      break;
    }

    std::istringstream iss0(numeroComprasHistorico);
    nCH = std::stoi(numeroComprasHistorico);

    if(nCH > 0){
      for (int i = 0; i < nCH; i++) {
        std::getline(arquivo, codigoProduto);
        std::getline(arquivo, nomeProduto);
        std::getline(arquivo, precoProduto);

        std::istringstream iss1(codigoProduto);
        codigo = std::stoi(codigoProduto);

        preco = std::stof(precoProduto);

        int indice = buscaIndiceProdutos(codigo);

        cod = (ecom.produto[indice]).getCodigoProduto();
        nome = (ecom.produto[indice]).getNome();
        categoria = (ecom.produto[indice]).getCategoria();
        cor = (ecom.produto[indice]).getCor();
        descricao = (ecom.produto[indice]).getDescricao();
        material = (ecom.produto[indice]).getMaterial();
        preco = (ecom.produto[indice]).getPreco();
        mediaAvaliacoes = (ecom.produto[indice]).getMediaAvaliacoes();

        Produto prod = Produto(cod, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material);
        historico.insert(std::pair<std::string, Produto>(email, prod));
      }
    }
  }
  imprimirHistorico();
  arquivo.close();
}

/**
 * [Comprador::gravaHistoricoArquivo função que grava o histórico de compras do vector no arquivo]
 * @method Comprador::gravaHistoricoArquivo
 */

void Comprador::gravaHistoricoArquivo(){
  std::remove("historico.csv");

  std::fstream arquivo;
  arquivo.open("historico.csv", std::ofstream::app);

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

  _numeroComprasHistorico = historico.size();
  for(int i=0; arquivo.good() && i < _numeroComprasHistorico; i++){
    int indice = procurarComprador((historico[i].first);
    arquivo << (historico[i].first) << "," << (comprador[indice]).getNumeroComprasHistorico() << ",";
    arquivo << << (historico[i].second).getCodigoProduto() << "," << (historico[i].second).getNome() << "," << (historico[i].second).getPreco();
  }

  arquivo.close();
}


#endif
