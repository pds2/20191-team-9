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



void Administrador::adicionaItem(std::string nome_do_produto){
  // importa informações sobre itens de um arquivo csv para um vector, para manusear os dados mais facilmente
  // procura no estoque.vector se existe algum produto com o nome dado.
  // Se ele não existir, este produto é adicionado ao estoque. Se existir, uma mensagem de erro é impressa na tela.

  this->bluemols.clear();
  this->cans.clear();
  this->aces.clear();

  produtoCsvToVector();

  std::string name;
  int indice = -1;
  int iterador;


  for(int i = 0; i<bluemols.size(); i++){

    name = bluemols[i].getNome();

    if(strcomp(nome_do_produto, name) == 0){
      indice = i;
      break;
    }

  }

  if(indice == -1){
    for(int i = 0; i<cans.size(); i++){

      name = cans[i].getNome();

      if(strcomp(nome_do_produto, name) == 0){
        indice = i;
        break;
      }

    }
  }

  if(indice == -1){
    for(int i = 0; i<aces.size(); i++){

      name = aces[i].getNome();

      if(strcomp(nome_do_produto, name) == 0){
        indice = i;
        break;
      }

    }
  }

    if(indice != -1){
    std::cout << "Já existe um produto com este nome!" << std::endl;

    return;
  }

  // Inicializa as e coleta variáveis comuns à todos os produtos
  int tipo_de_produto;
  int codigo_do_produto;
  float media_das_avaliacoes = 0;
  float preco;
  std::string categoria;
  std::string cor;
  std::string descricao;
  std::string material;

  std::cout << "Por favor, informe o código do produto:" << std::endl;
  std::cin >> codigo_do_produto;

  std::cout << "Por favor, informe a categoria do produto:" << std::endl;
  std::cin >> categoria;

  std::cout << "Por favor, informe a cor:" << std::endl;
  std::cin >> cor;

  std::cout << "Por favor, dê uma descrição para o produto:" << std::endl;
  std::cin >> descricao;

  std::cout << "Por favor, informe o material do produto:" << std::endl;
  std::cin >> material;

  std::cout << "Por favor, informe o preco do produto:" << std::endl;
  std::cin >> preco;

  // Agora construiremos o novo produto de acordo com sua categoria
  switch (categoria) {
    case 1: //Produto é uma blusa ou um moletom
      char tamanho;
      std::cout << "Por favor, informe o tamanho do produto:" << std::endl;
      std::cin >> tamanho;

      int tipo_de_peca;
      std::cout << "Por favor, informe o tipo da peça que deseja adicionar. Digite:\n1 - Blusa\n2 - Moletom" << std::endl;

      if(tipo_de_peca == 1){
        BlusasEMoletom::BlusasEMoletom(codigo_do_produto, preco, media_das_avaliacoes, nome_do_produto, categoria, cor, descricao, material, tamanho, "BLUSA");
      }else if(tipo_de_peca == 2){
        BlusasEMoletom::BlusasEMoletom(codigo_do_produto, preco, media_das_avaliacoes, nome_do_produto, categoria, cor, descricao, material, tamanho, "MOLETOM");
      }
      break;

    case 2: //Produto é uma caneca
      float diametro;
      std::cout << "Por favor, informe o diâmetro da caneca:" << std::endl;
      std::cin >> diametro;

      Caneca::Caneca(codigo_do_produto, preco, media_das_avaliacoes, nome_do_produto, categoria, cor, descricao, material, diametro);
      break;

    case 3: //Produto é um acessório
      std::string tipo_de_acessorio;

      std::cout << "Por favor, informe que tipo de acessório é este produto:" << std::endl;
      std::cin >> tipo_de_acessorio;

      for(int i = 0; int i < std::strlen(tipo_de_acessorio); i++){
        tipo_de_acessorio[i] = std::toupper(tipo_de_acessorio[i]);
      }
      Acessorio::Acessorio(codigo_do_produto, preco, media_das_avaliacoes, nome_do_produto, categoria, cor, descricao, material, tipo_de_acessorio);
      break;
  }
}

/*
void Administrador::removeItem(Produto item){
  //procura no estoque.txt se existe algum produto com o nome chamado.
  //Se ele existir, este produto é retirado do estoque. Se não existir, uma mensagem de erro é impressa na tela.

}

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
