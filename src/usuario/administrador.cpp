#ifndef ADMINISTRADOR_CPP
#define ADMINISTRADOR_CPP

#include "usuario/administrador.h"
#include <string.h>

/**
 * [Administrador::Administrador -> Construtor da classe Administrador]
 * @param nome  [nome do administrador]
 * @param email [email do administrador, com o qual realiza login no sistema]
 * @param senha [senha do administrador, com o qual realiza login no sistema]
 */
Administrador::Administrador(){
  /*this->_nome = "ADMIN";
  this->_email = "admin1@gmail.com";
  this->_senha = "123tasalvo";*/

  Usuario("ADMIN", "admin1@gmail.com", "123tasalvo");
}

/**
 * [Administrador::produtoCsvToVector -> Classe que pega as informações sobre os
 * produtos do arquivo csv no qual eles estão e insere-as em um vector para
 * fácil manuseio]
 */

void Administrador::produtoCsvToVector(){

  std::string nome;
  std::string codigo;
  std::string media;
  std::string preco;
  std::string categoria; //Acessorios, Canecas, Blusas e Moletons
  std::string categoria_roupa = "Blusas e Moletons";
  std::string categoria_caneca = "Canecas";
  std::string categoria_acessorios = "Acessorio";
  std::string cor;
  std::string descricao;
  std::string material;

  std::ifstream arquivo;
  arquivo.open("produtos.csv", std::ios::in);

  if (!arquivo.is_open()){
   std::cout << "Erro ao abrir arquivo. Tente novamente";
   exit(1);
  }

  while(arquivo.good()){
    std::getline(arquivo, codigo, ',');
    std::getline(arquivo, preco, ',');
    std::getline(arquivo, media, ',');
    std::getline(arquivo, nome, ',');
    std::getline(arquivo, categoria, ',');
    std::getline(arquivo, cor, ',');
    std::getline(arquivo, descricao, ',');
    std::getline(arquivo, material, ',');

    int codigo_do_produto = std::stoi(codigo);
    float media_das_avaliacoes = std::stof(media);
    float preco_do_produto = std::stof(preco);

    if(categoria == categoria_roupa){
      std::string tamanho;
      std::string tipo_de_produto;

      std::getline(arquivo, tamanho, ',');
      std::getline(arquivo, tipo_de_produto, '\n');

      BlusasEMoletom bem = BlusasEMoletom(codigo_do_produto, preco_do_produto, media_das_avaliacoes, nome, categoria, cor, descricao, material, tamanho[0], tipo_de_produto);
      this->_bluemols.push_back(bem);

    }else if(categoria == categoria_caneca){
      std::string diametro;

      std::getline(arquivo, diametro, '\n');

      float diametro_do_produto = std::stof(diametro);

      Caneca can = Caneca(codigo_do_produto, preco_do_produto, media_das_avaliacoes, nome, categoria, cor, descricao, material, diametro_do_produto);
      this->_cans.push_back(can);

    }else if(categoria == categoria_acessorios){
      std::string tipo_de_acessorio;

      std::getline(arquivo, tipo_de_acessorio, '\n');

      Acessorio ace = Acessorio(codigo_do_produto, preco_do_produto, media_das_avaliacoes, nome, categoria, cor, descricao, material, tipo_de_acessorio);
      this->_aces.push_back(ace);
    }
  }

  arquivo.close();
}

/**
 * [Administrador::usuarioCsvToVector -> Classe que pega as informações sobre os
 * usuarios do arquivo csv no qual eles estão e insere-as em um vector para
 * fácil manuseio]
 */

void Administrador::usuarioCsvToVector(){

  std::string nome, email, senha, cpf, endereco;
  std::string numHistorico, numCarrinho, numAvaliacoes, dinheiro;

  std::fstream arquivo;
  arquivo.open("usuarios.csv", std::ios::in);

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

  while (arquivo.good()){

    std::getline(arquivo, nome,',');
    std::getline(arquivo, email,',');
    std::getline(arquivo, senha,',');
    std::getline(arquivo, cpf,',');
    std::getline(arquivo, endereco,',');
    std::getline(arquivo, numCarrinho,',');
    std::getline(arquivo, numHistorico,',');
    std::getline(arquivo, numAvaliacoes,',');
    std::getline(arquivo, dinheiro,'\n');

    int numCarrinho_do_cliente = stoi(numCarrinho);
    int numHistorico_do_cliente = stoi(numHistorico);
    int numAvaliacoes_do_cliente = stoi(numAvaliacoes);
    double dinheiro_do_cliente = (double) std::stof(dinheiro);

    Comprador comp = Comprador(nome, email, senha, cpf, endereco, numCarrinho_do_cliente, numHistorico_do_cliente, numAvaliacoes_do_cliente, dinheiro_do_cliente);
    this->_shoppers.push_back(comp);
  }

  arquivo.close();
}

/**
 * [Administrador::reqCsvToMap -> Classe que pega as informações sobre as
 * requisições do arquivo csv no qual eles estão e insere-as em um map para
 * fácil manuseio]
 */

void Administrador::reqCsvToMap(){
  this->_requisicoes.clear();

  std::string email;
  std::string valor;

  std::ifstream arquivo;
  arquivo.open("requisicoes.csv",std::ios::in);

  while (arquivo.good()){

    std::getline(arquivo, email,',');
    std::getline(arquivo, valor,'\n');

    float valor_da_req = std::stof(valor);

    _requisicoes.insert(std::pair<std::string, float>(email,valor_da_req));
  }

  arquivo.close();

}

/**
 * [Administrador::removeItem description]
 * @param nome_do_produto [description]
 */

void Administrador::removeItem(std::string nome_do_produto){
  //procura no vector se existe algum produto com o nome chamado.
  //Se ele existir, este produto é retirado do estoque. Se não existir, uma mensagem de erro é impressa na tela.

  this->_bluemols.clear();
  this->_cans.clear();
  this->_aces.clear();

  produtoCsvToVector();

  std::string name;
  int indice = -1;
  int bm = 0;
  int cn = 0;
  int ac = 0;

  // Procura o produto dentre os produtos cadastrados
  for(unsigned int i = 0; i<_bluemols.size(); i++){

    name = _bluemols[i].getNome();

    if(nome_do_produto == name){
      indice = i;
      bm = 1;
      break;
    }

  }

  if(indice == -1){
    for(unsigned int i = 0; i<_cans.size(); i++){

      name = _cans[i].getNome();

      if(nome_do_produto == name){
        indice = i;
        cn = 1;
        break;
      }

    }
  }

  if(indice == -1){
    for(unsigned int i = 0; i<_aces.size(); i++){

      name = _aces[i].getNome();

      if(nome_do_produto == name){
        indice = i;
        ac = 1;
        break;
      }

    }
  }

  //Se não achou, imprime uma mensagem de erro. Se achou, procura em qual categoria está o item para fazer a remoção
  if(indice == -1){
    std::cout << "Este produto não existe!" << std::endl;
    return;
  }else if(bm == 1){
    _bluemols.erase(_bluemols.begin() + indice);
  }else if(cn == 1){
    _cans.erase(_cans.begin() + indice);
  }else if(ac == 1){
    _aces.erase(_aces.begin() + indice);
  }

  //Com o produto apagado, o arquivo de produtos é reescrito
  std::ofstream arquivo;

  arquivo.open("produtos.csv", std::ios::trunc | std::ios::out);

  for(unsigned int i = 0; i<_bluemols.size(); i++){
    arquivo << _bluemols[i].getCodigoProduto() << "," << _bluemols[i].getNome() << "," << _bluemols[i].getPreco() << "," << _bluemols[i].getMediaAvaliacoes() << "," << _bluemols[i].getCategoria() << ","  << _bluemols[i].getCor() << "," << _bluemols[i].getDescricao() << "," << _bluemols[i].getMaterial() << "," << _bluemols[i].getTamanho() << "," << _bluemols[i].getTipo() << std::endl;
  }

  for(unsigned int i = 0; i<_cans.size(); i++){
    arquivo << _cans[i].getCodigoProduto() << "," << _cans[i].getNome() << "," << _cans[i].getPreco() << "," << _cans[i].getMediaAvaliacoes() << "," << _cans[i].getCategoria() << ","  << _cans[i].getCor() << "," << _cans[i].getDescricao() << "," << _cans[i].getMaterial() << "," << _cans[i].getDiametro() << std::endl;
  }

  for(unsigned int i = 0; i<_aces.size(); i++){
    arquivo << _aces[i].getCodigoProduto() << "," << _aces[i].getNome() << "," << _aces[i].getPreco() << "," << _aces[i].getMediaAvaliacoes() << "," << _aces[i].getCategoria() << ","  << _aces[i].getCor() << "," << _aces[i].getDescricao() << "," << _aces[i].getMaterial() << "," << _aces[i].getTipo() << std::endl;

  }

  arquivo.close();

}

//FUNÇÃO COM ERROS QUE NÃO SEI CONSERTAR
/*void Administrador::exibirPerfil(){
  limparTela();
  std::cout << "\n" << "----------------------------------------------" << std::endl;
  std::cout << "\t\t Perfil do Usuário" << std::endl;
  std::cout << "----------------------------------------------" << "\n" << std::endl;
  std::cout << "Nome: " << getNome() << std::endl;
  std::cout << "Email: " << getEmail() << std::endl;
  std::cout << "Senha: " << getSenha() << std::endl;

  std::cout << std::endl << "Pressione ENTER para voltar a pagina anterior";
  std::cin.get();
  ecom.menuUsuario();
}*/

/**
 * [Administrador::adicionaPedido description]
 * @param email [description]
 * @param valor [description]
 */

void Administrador::adicionaPedido(std::string email, float valor){
  this->_requisicoes.insert(std::pair<std::string, float>(email,valor));

  std::fstream arquivo;
  arquivo.open("requisicoes.csv", std::ofstream::app);

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir requisicoes.csv! Tente novamente." << std::endl;
    exit(1);
  }

  std::map<std::string, float>::iterator it;
  for (it=_requisicoes.begin(); it!=_requisicoes.end(); ++it){
    arquivo << it->first << "," << it->second << std::endl;
  }

  arquivo.close();
}

/**
 * [Administrador::mostraPedidos description]
 */

void Administrador::mostraPedidos(){
  // Imprime o mapa _requisicoes com o seguinte formato
  // Exemplo: 1 - email@docomprador.com: R$100,00
  std::system("clear||cls");

  reqCsvToMap();

  this->_qntdade_de_requisicoes = this->_requisicoes.size();

  if(this->_qntdade_de_requisicoes <= 0){
    std::cout << "Não há nenhuma requisição de aumento de saldo no momento." << std::endl;

    return;
  }

  std::cout << "----------------------------------------------" << std::endl;
  std::cout << "Estas são as requisições de aumento de saldo pendentes:" << std::endl;

  std::map<std::string, float>::iterator it;
  for(it = this->_requisicoes.begin(); it != this->_requisicoes.end(); it++){
    std::cout << "\n" << "----------------------------------------------" << std::endl;
    std::cout << it->first << " está requisitando um aumento de: R$" << it->second << " em seu saldo." << std::endl;
    std::cout << "\n" << "----------------------------------------------" << std::endl;
  }
}

/**
 * [Administrador::aprovaPedido description]
 * @param email [description]
 */

void Administrador::aprovaPedido(std::string email){
  int aprovacao;
  double valor = 0;
  int indice_comprador = -1;
  //int indice_requisicao = -1;
  std::string email_do_cliente;

  this->_shoppers.clear();

  usuarioCsvToVector();

  //-----> Busca o índice do comprador. Se ele não existir, exibe uma mensagem de erro
  for(int i = 0; i<_shoppers.size(); i++){

    email_do_cliente = _shoppers[i].getEmail();

    if(email_do_cliente == email){
      indice_comprador = i;
      break;
    }
  }

  if(indice_comprador == -1){
    std::cout << "Este usuário não existe!\nInsira um usuário válido." << std::endl;
    return;
  }

  //-----> Busca se existe alguma requisição no email dado. Se não houver, exibe mensagem de erro
  reqCsvToMap();

  std::map<std::string, float>::iterator it;
  for(it = this->_requisicoes.begin(); it != this->_requisicoes.end(); it++){

    if(it->first == email){
      valor = (double) it->second;
    }
  }

  if(valor <= 0){
    std::cout << "Este usuário não fez uma requisição. Portanto, não é possível aumentar o seu saldo" << std::endl;
    return;
  }


  //----->Agora vamos garantir que o administrador realmente deseja aprovar o pedido certo
  std::cout << "Deseja aprovar o pedido de " << email << " para o aumento de R$" << valor << " em seu saldo?" << std::endl;
  std::cout << "Digite:\n1 - aprovar\n2 - reprovar" << std::endl;
  std::cin >> aprovacao;

  if(aprovacao == 1){
    this->_requisicoes.erase(email);

    double novo_saldo = _shoppers[indice_comprador].getDinheiro() + valor;
    _shoppers[indice_comprador].setDinheiro(novo_saldo);
  }

  //Agora reescrevemos o arquivo para atualizar o valor do saldo alterado
  std::ofstream arquivo_user;
  std::ofstream arquivo_req;

  arquivo_user.open("usuarios.csv", std::ios::trunc | std::ios::out);
  arquivo_req.open("requisicoes.csv", std::ios::trunc | std::ios::out);

  for(int i = 0; i<_shoppers.size(); i++){
    arquivo_user << _shoppers[i].getNome() << "," << _shoppers[i].getEmail() << "," << _shoppers[i].getSenha() << "," << _shoppers[i].getCPF() << "," << _shoppers[i].getEndereco() << ","  << _shoppers[i].getNumeroComprasCarrinho() << "," << _shoppers[i].getNumeroComprasHistorico() << "," << _shoppers[i].getNumeroAvaliacoes() << "," << _shoppers[i].getDinheiro() << std::endl;
  }


  std::map<std::string, float>::iterator ite;
  for (ite=_requisicoes.begin(); ite!=_requisicoes.end(); ++ite){
    arquivo_req << it->first << "," << it->second << std::endl;
  }

  arquivo_user.close();
  arquivo_req.close();

}

/**
 * [Administrador::excluiUsuario description]
 * @param email [description]
 */

void Administrador::excluiUsuario(std::string email){
  std::string email_do_cliente;
  int indice = -1;
  this->_shoppers.clear();

  usuarioCsvToVector();

  for(int i = 0; i<_shoppers.size(); i++){

    email_do_cliente = _shoppers[i].getEmail();

    if(email_do_cliente == email){
      indice = i;
      break;
    }

  }

  if(indice == -1){
    std::cout << "Este usuário não existe!\nInsira um usuário válido" << std::endl;
    return;
  }

  _shoppers.erase(_shoppers.begin() + indice);


  //Com o usuário apagado, resta sobrescrever o arquivo com a nova lista de usuarios

  std::ofstream arquivo;

  arquivo.open("usuarios.csv", std::ios::trunc | std::ios::out);

  for(int i = 0; i<_shoppers.size(); i++){
    arquivo << _shoppers[i].getNome() << "," << _shoppers[i].getEmail() << "," << _shoppers[i].getSenha() << "," << _shoppers[i].getCPF() << "," << _shoppers[i].getEndereco() << ","  << _shoppers[i].getNumeroComprasCarrinho() << "," << _shoppers[i].getNumeroComprasHistorico() << "," << _shoppers[i].getNumeroAvaliacoes() << "," << _shoppers[i].getDinheiro() << std::endl;
  }

  arquivo.close();
}

Administrador::~Administrador(){

  _bluemols.clear();
  _cans.clear();
  _aces.clear();
  _shoppers.clear();
  _requisicoes.clear();
}


#endif
