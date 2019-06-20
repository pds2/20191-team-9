#ifndef COMPRADOR_CPP
#define COMPRADOR_CPP

#include "ecommerce.h"
#include "usuario/comprador.h"

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

  /*try{
    //verificar entrada invalida
  }
  catch{
    //lança excecao de entrada invalida
  }*/

  try{
    verificar_produto_cadastrado(indice);
  }
  catch(Exception_Produto_Nao_Encontrado &e){
    std::cout<<e.what();
  }

  try{
    verificar_produto_ja_no_carrinho(indice);
  }
  catch(Exception_Produto_Ja_Consta_No_Carrinho &e){
    std::cout<<e.what();
  }

  Produto prod = buscaCarrinho(codProduto);

  /*
  int cod;
  std::string nome, categoria, cor, descricao, material;
  float preco, mediaAvaliacoes;

  cod = prod.getCodigoProduto();
  nome = prod.getNome();
  categoria = prod.getCategoria();
  cor = prod.getCor();
  descricao = prod.getDescricao();
  material = prod.getMaterial();
  preco = prod.getPreco();
  mediaAvaliacoes = prod.getMediaAvaliacoes();

  Produto prod = Produto(cod, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material);*/

  carrinho.push_back(prod);
  _totalCarrinho = _totalCarrinho + prod.getPreco();
  return true;
}

/**
 * [Comprador::retirarCarrinho função que retira um item do carrinho, a ser escolhido pelo comprador]
 * @method Comprador::retirarCarrinho
 * @return [true no caso da remoção do carrinho ter sido bem sucedida e false, em caso contrário]
 */

bool Comprador::retirarCarrinho(){
  _numeroComprasCarrinho = carrinho.size();

  try{
    verificar_carrinho_vazio(_numeroComprasCarrinho);
  }
  catch(Exception_Carrinho_Vazio &e){
    std::cout<<e.what();
  }

  int codProduto;
  int indice = -1;
  imprimirCarrinho();
  limparTela();

  std::cout << "\n" << "Digite o código do produto que deseja retirar do seu carrinho: ";
  std::cin >> codProduto;

  /*try{
    //verificar entrada invalida
  }
  catch{
    //lança excecao de entrada invalida
  }*/

  indice = procurarItensCarrinho(codProduto);

  try{
    verificar_produto_cadastrado(indice);
  }
  catch(Exception_Produto_Nao_Encontrado &e){
    std::cout<<e.what();
  }

  carrinho.erase(carrinho.begin()+ indice); //apaga o indice elemento a partir do começo do vector
  return true;
}

/**
 * [Comprador::imprimirCarrinho função que imprime os itens que constam no carrinho do comprador]
 * @method Comprador::imprimirCarrinho
 */

void Comprador::imprimirCarrinho(){
  _numeroComprasCarrinho = carrinho.size();
  double totalCarrinho=0;

  try{
    verificar_carrinho_vazio(_numeroComprasCarrinho);
  }
  catch(Exception_Carrinho_Vazio &e){
    std::cout<<e.what();
  }

  limparTela();
  std::cout << "\n" << "----------------------------------------------" << std::endl;
  std::cout << "\t\t Carrinho do Comprador: " << this->getNome() << std::endl;
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

/**
 * [Comprador::imprimirHistorico função que imprime os itens que constam no histórico do comprador]
 * @method Comprador::imprimirHistorico
 */

void Comprador::imprimirHistorico(){
  _numeroComprasHistorico = historico.size();

  try{
    verificar_historico_vazio(_numeroComprasHistorico);
  }
  catch(Exception_Historico_Vazio &e){
    std::cout<<e.what();
  }

  limparTela();
  listaHistoricoArquivo();

  std::cout << "\n" << "----------------------------------------------" << std::endl;
  std::cout << "\t\t Histórico do Comprador " << this->getNome() << std::endl;
  std::cout << "----------------------------------------------" << "\n" << std::endl;

  std::map<std::string, Produto>::iterator ite;

  for (ite=historico.begin(); ite!=historico.end(); ++ite){
    if(ite->first == this->getEmail()){
      std::cout << "\t\tCódigo " << (ite->second).getCodigoProduto() << std::endl;
      std::cout << "\t\tNome: " << (ite->second).getNome() << std::endl;
      std::cout << "\t\tPreço: " << (ite->second).getPreco() << std::endl;
      }
  }
    std::cout << "\n" << "----------------------------------------------" << std::endl;
    std::cout << "\n";
    std::cout << "----------------------------------------------" << "\n" << std::endl;
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
  std::cout << "Nome: " << this->getNome() << std::endl;
  std::cout << "Email: " << this->getEmail() << std::endl;
  std::cout << "Senha: " << this->getSenha() << std::endl;
  std::cout << "Nº Compras do Carrinho: " << this->getNumeroComprasCarrinho() << std::endl;
  std::cout << "Nº Compras do Histórico: " << this->getNumeroComprasHistorico() << std::endl;
  std::cout << "Nº Avaliações: " << this->getNumeroAvaliacoes() << std::endl;
  std::cout << "Qntd Dinheiro: " << this->getDinheiro() << std::endl;
}

/**
 * [Comprador::procurarItensHistorico função que localiza um item no histórico do comprador, através de uma pesquisa utilizando o código do produto]
 * @method Comprador::procurarItensHistorico
 * @param  codProduto                        [código úndico que representa um produto]
 * @return                                   [indice no histórico em que o produto se encontra]
 */

int Comprador::procurarItensHistorico(int codProduto){
  int indice = 0;
  std::map<std::string, Produto>::iterator ite;

  for (ite=historico.begin(); ite!=historico.end(); ++ite){
    if((ite->second).getCodigoProduto() == codProduto){
      return indice;
    }
    indice++;
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

  /*try{
    //verificar entrada invalida
  }
  catch{
    //lança excecao de entrada invalida
  }*/
  listaHistoricoArquivo();
  indice = procurarItensHistorico(codProduto);

  try{
    verificar_produto_fora_do_historico(indice);
  }
  catch(Exception_Produto_Fora_do_Historico &e){
    std::cout<<e.what();
  }

  Produto prod = buscaHistorico(codProduto);

  std::string comentario;

  std::cout << "\n" << "Escreva o seu comentário para o produto de código " << codProduto << " : " << std::endl;
  std::getline(std::cin, comentario);

  prod.setComentario(comentario);
  std::cout << "\n" << "Comentário para o produto de código " << codProduto << " registrado com sucesso! " << std::endl;
}

/**
 * [Comprador::avaliarItem função que localiza um item no histórico do comprador, através de uma pesquisa utilizando o código do produto, e em seguida permite que o comprador avalie este mesmo produto]
 * @method Comprador::avaliarItem
 */

void Comprador::avaliarItem(){

  limparTela();
  imprimirHistorico();

  int codProduto;
  int indice = -1;

  std::cout << "\n" << "Digite o código do produto que deseja avaliar: ";
  std::cin >> codProduto;

  /*try{
    //verificar entrada invalida
  }
  catch{
    //lança excecao de entrada invalida
  }*/

  indice = procurarItensHistorico(codProduto);

  try{
    verificar_produto_fora_do_historico(indice);
  }
  catch(Exception_Produto_Fora_do_Historico &e){
    std::cout<<e.what();
  }

  int nota;

  std::cout << "\n" << "Como deseja avaliar o produto " << codProduto << "?" << std::endl;
  std::cout << "\n" << "Escolha uma das opções: |0|1|2|3|4|5|" << std::endl;
  std::cin >> nota;

  try{
    verificar_nota_invalida(nota);
  }
  catch(Exception_Nota_Invalida &e){
    std::cout<<e.what();
  }

  Produto prod = buscaHistorico(codProduto);
  prod.avaliarProduto(nota);

}

/**
 * [Comprador::fazerCompras função que confimar a compra dos produtos adicionados ao carrinho do comprador]
 * @method Comprador::fazerCompras
 */

void Comprador::fazerCompras(){
  int opcao;
  std::cout << "Você está comprando " << carrinho.size() << " produtos, cujo valor total é " << _totalCarrinho << ". Deseja confirmar sua compra?" << std::endl;
  std::cout << "0 - NÃO\n1 - SIM" << std::endl;
  std::cin >> opcao;

  /*try{
    //verificar entrada invalida
  }
  catch{
    //lança excecao de entrada invalida
  }*/

  try{
    verificar_opcao_menu_fazer_compras_invalida(opcao);
  }
  catch(Exception_Opcao_Menu_Fazer_Compras_Invalida &e){
    std::cout<<e.what();
  }

  try{
    verificar_saldo_insuficiente(this->getDinheiro(), this->getTotalCarrinho());
  }
  catch(Exception_Saldo_Comprador_Insuficiente &e){
    std::cout<<e.what();
  }

  carrinho.clear();
  _dinheiro = _dinheiro - _totalCarrinho;
  _numeroComprasHistorico++;
}

/**
 * [Comprador::adicionaDinheiro função que envia uma requsição ao administrador para aumento de saldo do comprador]
 * @method Comprador::adicionaDinheiro
 * @param  valor                       [valor que o comprador deseja adicionar ao seu dinheiro atual]
 * @param  comp                        [comprador que está solicitando a requisição de aumento de saldo]
 * @return                             [true em caso da requisicao ter sido bem sucedida e false, em caso contrário]
 */

bool Comprador::adicionaDinheiro(){
  //aqui tem que mandar uma requisicao para o administrador

  float valor;
  std::cout << "Digite o valor que deseja adicionar a carteira: " << std::endl;
  std::cin >> valor;

  /*try{
    //verificar entrada invalida e tbm se o valor não é negativo
  }
  catch{
    //lança excecao de entrada invalida
  }*/

  Administrador admin;
  admin.adicionaPedido(this->getEmail(), valor);
  return true;
}

/**
 * [Comprador::listaHistoricoArquivo função que lista o histórico de compras registrados no arquivo]
 * @method Comprador::listaHistoricoArquivo
 */

void Comprador::listaHistoricoArquivo(){
  Ecommerce ecom;
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

        Produto prod = ecom.buscaProdutos(codigo);

        historico.insert(std::pair<std::string, Produto>(email, prod));
      }
    }
  }
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

  std::map<std::string, Produto>::iterator ite;
  Ecommerce ecom;

  for (ite=historico.begin(); ite!=historico.end(); ++ite){
    Comprador comp = ecom.procurarCompradorObj(ite->first);

    arquivo << ite->first << "," << comp.getNumeroComprasHistorico() << std::endl;
    arquivo << (ite->second).getCodigoProduto() << "," << (ite->second).getNome() << "," << (ite->second).getPreco() << std::endl;
  }

  arquivo.close();
}

Produto Comprador::buscaHistorico(int codProduto){
  int x, codigo;
  std::string nome, categoria, cor, descricao, material;
  float preco, mediaAvaliacoes;

  std::map<std::string, Produto>::iterator ite;

  for (ite=historico.begin(); ite!=historico.end(); ++ite){
    if(ite->first == this->getEmail() && (ite->second).getCodigoProduto() == codProduto){

      codigo = (ite->second).getCodigoProduto();
      nome = (ite->second).getNome();
      categoria = (ite->second).getCategoria();
      cor = (ite->second).getCor();
      descricao = (ite->second).getDescricao();
      material = (ite->second).getMaterial();
      preco = (ite->second).getPreco();
      mediaAvaliacoes = (ite->second).getMediaAvaliacoes();
    }
  }
  Produto prod = Produto(codigo, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material);
  return prod;
}

Produto Comprador::buscaCarrinho(int codProduto){
  int x, codigo;
  std::string nome, categoria, cor, descricao, material;
  float preco, mediaAvaliacoes;

  for(int i=0; i < _numeroComprasCarrinho; i++){
    if(carrinho[i].getCodigoProduto() == codProduto){
      codigo = carrinho[i].getCodigoProduto();
      nome = carrinho[i].getNome();
      categoria = carrinho[i].getCategoria();
      cor = carrinho[i].getCor();
      descricao = carrinho[i].getDescricao();
      material = carrinho[i].getMaterial();
      preco = carrinho[i].getPreco();
      mediaAvaliacoes = carrinho[i].getMediaAvaliacoes();
    }
  }
  Produto prod = Produto(codigo, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material);
  return prod;
}

/**
 * [Comprador::limparTela função responsável por limpar a tela do sistema]
 * @method Comprador::limparTela
 */

void Comprador::limparTela(){
  std::system("clear||cls");
}

#endif
