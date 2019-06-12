/*
#ifndef ADMINISTRADOR_CPP
#define ADMINISTRADOR_CPP

#include "usuario/administrador.hpp"

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

  if(this->bluemols.size() == 0 || this->cans.size() == 0 || this->aces.size() == 0){

    this->bluemols.clear();
    this->cans.clear();
    this->aces.clear();

    produtoCsvToVector();



  }

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

void Administrador::exibeUsuarios(){
  ifstream lista_de_usuarios("usuarios.txt");

  if(lista_de_usuarios.is_open()){
    std::string linha;

    while(getLine(lista_de_usuarios, linha)){
      std::cout << linha << std::endl;
    }
  }

  lista_de_usuarios.close();
}

void Administrador::excluiUsuario(std::string email){

}

Administrador::~Administrador(){}

#endif
*/
