
#ifndef ADMINISTRADOR_CPP
#define ADMINISTRADOR_CPP

#include "../../include/usuario/administrador.h"

Administrador::Administrador(std::string nome, std::string email, std::string senha){
  this->_nome = nome;
  this->_email = email;
  this->_senha = senha;
}

void Administrador::produtoCsvToVector(){

  std::string nome;
  std::string codigo_do_produto;
  std::string media_das_avaliacoes;
  std::string preco;
  std::string categoria; //Acessorios, Canecas, Blusas e Moletons
  std::string cor;
  std::string descricao;
  std::string material;

  std::ifstream arquivo;
  arquivo.open("produtos.csv", ios::in);

  if (!arquivo.is_open()){
   std::cout << "Erro ao abrir arquivo. Tente novamente";
   exit(1);
  }

  while(arquivo.good()){
    std::getline(arquivo, codigo_do_produto, ',');
    std::getline(arquivo, preco, ',');
    std::getline(arquivo, media_das_avaliacoes, ',');
    std::getline(arquivo, nome, ',');
    std::getline(arquivo, categoria, ',');
    std::getline(arquivo, cor, ',');
    std::getline(arquivo, descricao, ',');
    std::getline(arquivo, material, ',');

    std::stoi(codigo_do_produto);
    std::stof(media_das_avaliacoes);
    std::stof(preco);

    if(std::strcomp(categoria, "Blusas e Moletons") == 0){
      std::string tamanho;
      std::string tipo_de_produto;

      std::getline(arquivo, tamanho, ',');
      std::getline(arquivo, tipo_de_produto, '\n');

      BlusasEMoletom bem = BlusasEMoletom(codigo_do_produto, preco, media_das_avaliacoes, nome, categoria, cor, descricao, material, tamanho,);
      this->bluemols.push_back(bem);

    }else if(std::strcomp(categoria, "Canecas") == 0){
      std::string diametro;

      std::getline(arquivo, diametro, '\n');

      Caneca can = Caneca(codigo_do_produto, preco, media_das_avaliacoes, nome, categoria, cor, descricao, material, diametro);
      this->cans.push_back(can);

    }else if(std::strcomp(categoria, "Acessorio") == 0){
      std::string tipo_de_acessorio;

      std::getline(arquivo, diametro, '\n');

      Acessorio ace = Acessorio(codigo_do_produto, preco, media_das_avaliacoes, nome, categoria, cor, descricao, material, tipo_de_acessorio);
      this->aces.push_back(ace);
    }
  }

  arquivo.close();
}

void Administrador::usuarioCsvToVector(){

  std::string nome, email, senha, cpf, endereco;
  std::string numHistorico, numCarrinho, numAvaliacoes, dinheiro;

  std::fstream arquivo;
  arquivo.open("usuarios.csv", ios::in);

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

    std::stof(dinheiro);

    Comprador comp = Comprador(nome, email, senha, cpf, endereco, numCarrinho, numHistorico, numAvaliacoes, dinheiro);
    this->shoppers.push_back(comp);
  }

  arquivo.close();
}

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
  for(int i = 0; i<_bluemols.size(); i++){

    name = _bluemols[i].getNome();

    if(strcomp(nome_do_produto, name) == 0){
      indice = i;
      bm = 1;
      break;
    }

  }

  if(indice == -1){
    for(int i = 0; i<_cans.size(); i++){

      name = _cans[i].getNome();

      if(strcomp(nome_do_produto, name) == 0){
        indice = i;
        cn = 1;
        break;
      }

    }
  }

  if(indice == -1){
    for(int i = 0; i<_aces.size(); i++){

      name = _aces[i].getNome();

      if(strcomp(nome_do_produto, name) == 0){
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

  for(int i = 0; i<_bluemols.size(); i++){
    arquivo << _bluemols[i].getCodigoProduto() << "," << bluemols[i].getNome() << "," << bluemols[i].getPreco() << "," << bluemols[i].getMediaAvaliacoes() << "," << bluemols[i].getCategoria() << ","  << bluemols[i].getCor() << "," << bluemols[i].getDescricao() << "," << bluemols[i].getMaterial() << "," << bluemols[i].getTamanho() << "," << bluemols[i].getTipo() << std::endl;
  }

  for(int i = 0; i<_cans.size(); i++){
    arquivo << _cans[i].getCodigoProduto() << "," << cans[i].getNome() << "," << cans[i].getPreco() << "," << cans[i].getMediaAvaliacoes() << "," << cans[i].getCategoria() << ","  << cans[i].getCor() << "," << cans[i].getDescricao() << "," << cans[i].getMaterial() << "," << cans[i].getDiametro() << std::endl;
  }

  for(int i = 0; i<_aces.size(); i++){
    arquivo << _aces[i].getCodigoProduto() << "," << aces[i].getNome() << "," << aces[i].getPreco() << "," << aces[i].getMediaAvaliacoes() << "," << aces[i].getCategoria() << ","  << aces[i].getCor() << "," << aces[i].getDescricao() << "," << aces[i].getMaterial() << "," << aces[i].getTipo() << std::endl;

  }

  arquivo.close();

}

/*
void Administrador::mostraPedidos(){
  // Imprime o mapa _requisicoes com o seguinte formato
  // Exemplo: 1 - email@docomprador.com: R$100,00
  if(_qntdade_de_requisicoes <= 0){
    std::cout << "Não há nenhuma requisição de aumento de saldo no momento." << std::endl;

    return;
  }

  for(int i = 0; i < _qntdade_de_requisicoes; i++){
    std::cout << (i+1) << " - " << this->_requisicoes[i] << ": R$" << std::endl;
  }
}

void Administrador::aprovaPedido(std::string email, float valor){
  int aprovacao;

  std::cout << "Deseja aprovar o pedido de " << email << " para o aumento de R$" << valor << "em seu saldo?" << std::endl;
  std::cout << "Digite:\n1 - aprovar\n2 - reprovar" << std::endl;
  std::cin >> aprovacao;

  if(aprovacao == 1){
    int novo_saldo = user.getDinheiro() + valor;
    user.setDinheiro(novo_saldo);
  }

}
*/

void Administrador::exibeUsuarios(){
  std::ifstream lista_de_usuarios;
  lista_de_usuarios.open("usuarios.csv", std::ios::in);

  if(lista_de_usuarios.is_open()){
    std::string linha;

    while(getLine(lista_de_usuarios, linha)){
      std::cout << linha << std::endl;
    }
  }

  lista_de_usuarios.close();
}

void Administrador::excluiUsuario(std::string email){
  std::string email_do_cliente;
  int indice = -1;
  this->_shoppers.clear();

  usuarioCsvToVector();

  for(int i = 0; i<_shoppers.size(); i++){

    email_do_cliente = _shoppers[i].getEmail();

    if(strcomp(email_do_cliente, email) == 0){
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
