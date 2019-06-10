#ifndef ADMINISTRADOR_CPP
#define ADMINISTRADOR_CPP

#include "usuario/administrador.hpp"

Administrador::Administrador(std::string nome, std::string email, std::string senha){
  this->_nome = nome;
  this->_email = email;
  this->_senha = senha;
}

void Administrador::adicionaItem(std::string nome_do_produto){
  //procura no estoque.txt se existe algum produto com o nome dado.
  //Se ele não existir, este produto é adicionado ao estoque. Se existir, uma mensagem de erro é impressa na tela.

  if(/*nome existe no arquivo*/){
    std::cout << "Este produto já existe!" << std::endl;

    return;
  }

  // Inicializa as e coleta variáveis comuns à todos os produtos
  int tipo_de_produto;
  int codigo_do_produto;
  float media_das_avaliacoes;
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

  // Agora é preciso entender que tipo de produto o administrador deseja adicionar,
  // pois cada produto possui alguns atributos próprios.
  // A entrada é dada por um int para que possamos comparará-la e validá-la com mais facilidade.

  std::cout << "Qual tipo de produto deseja adicionar?Digite:\n1 - Blusas e Moletons\n2 - Canecas\n3 - Acessórios" << std::endl;
  std::cin >> tipo_de_produto;

  if(tipo_de_produto < 1 || tipo_de_produto > 3){
    std::cout << "O número digitado é inválido! Por favor, digite um número entre 1 e 3" << std::endl;
  }

  switch (tipo_de_produto) {
    case 1:
      char tamanho;
      std::cout << "Por favor, informe o tamanho do produto:" << std::endl;
      std::cin >> tamanho;

      int tipo_de_peca;
      std::cout << "Por favor, informe o tipo da peça que deseja adicionar. Digite:\n1 - Blusa\n2 - Moletom" << std::endl;

      break;
    case 2;

      break;
    case 3;

      break;
  }
}

void Administrador::removeItem(Produto item){
  //procura no estoque.txt se existe algum produto com o nome chamado.
  //Se ele existir, este produto é retirado do estoque. Se não existir, uma mensagem de erro é impressa na tela.



}

void Administrador::mostraPedidos(){}

bool Administrador::aprovaPedido(std::string requisicao, Comprador user){}

void Administrador::exibeUsuarios(){}

void Administrador::editaUsuario(Comprador user){}

void Administrador::excluiUsuario(Comprador user){}

void Administrador::exibeMensagens(Comprador user){}

void Administrador::respondeMensagens(Comprador user){}

Administrador::~Administrador(){}

#endif
