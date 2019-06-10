#ifndef ADMINISTRADOR_CPP
#define ADMINISTRADOR_CPP

#include "usuario/administrador.hpp"
#include <fstream>

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

  // Agora é preciso entender que tipo de produto o administrador deseja adicionar,
  // pois cada produto possui alguns atributos próprios.
  // A entrada é dada por um int para que possamos comparará-la e validá-la com mais facilidade.

  std::cout << "Qual tipo de produto deseja adicionar?Digite:\n1 - Blusas e Moletons\n2 - Canecas\n3 - Acessórios" << std::endl;
  std::cin >> tipo_de_produto;

  if(tipo_de_produto < 1 || tipo_de_produto > 3){
    std::cout << "O número digitado é inválido! Por favor, digite um número entre 1 e 3" << std::endl;
  }

  switch (tipo_de_produto) {
    case 1: //Produto é uma blusa ou um moletom
      char tamanho;
      std::cout << "Por favor, informe o tamanho do produto:" << std::endl;
      std::cin >> tamanho;

      int tipo_de_peca;
      std::cout << "Por favor, informe o tipo da peça que deseja adicionar. Digite:\n1 - Blusa\n2 - Moletom" << std::endl;

      if(tipo_de_peca == 1){
        BlusasEMoletom::BlusasEMoletom(codigo_do_produto, preco, media_das_avaliacoes, nome, categoria, cor, descricao, material, tamanho, "BLUSA");
      }else if(tipo_de_peca == 2){
        BlusasEMoletom::BlusasEMoletom(codigo_do_produto, preco, media_das_avaliacoes, nome, categoria, cor, descricao, material, tamanho, "MOLETOM");
      }
      break;

    case 2: //Produto é uma caneca
      float diametro;
      std::cout << "Por favor, informe o diâmetro da caneca:" << std::endl;
      std::cin >> diametro;

      Caneca::Caneca(codigo_do_produto, preco, media_das_avaliacoes, nome, categoria, cor, descricao, material, diametro);
      break;

    case 3: //Produto é um acessório
      std::string tipo_de_acessorio;

      std::cout << "Por favor, informe que tipo de acessório é este produto:" << std::endl;
      std::cin >> tipo_de_acessorio;

      for(int i = 0; int i < std::strlen(tipo_de_acessorio); i++){
        tipo_de_acessorio[i] = std::toupper(tipo_de_acessorio[i]);
      }
      Acessorio::Acessorio(codigo_do_produto, preco, media_das_avaliacoes, nome, categoria, cor, descricao, material, tipo_de_acessorio);
      break;
  }
}

void Administrador::removeItem(Produto item){
  //procura no estoque.txt se existe algum produto com o nome chamado.
  //Se ele existir, este produto é retirado do estoque. Se não existir, uma mensagem de erro é impressa na tela.

}

void Administrador::mostraPedidos(){
  if(_qntdade_de_requisicoes <= 0){
    std::cout << "Não há nenhuma requisição de aumento de saldo no momento." << std::endl;

    return;
  }

  for(int i = 0; i < _qntdade_de_requisicoes; i++){
    std::cout << (i+1) << " - " << this->_requisicoes[i] << std::endl;
  }
}

void Administrador::aprovaPedido(float valor, Comprador user){
  int aprovacao;

  std::cout << "Deseja aprovar o pedido de " << user._nome << " para o aumento de R$" << valor << "em seu saldo?" << std::endl;
  std::cout << "Digite:\n1 - aprovar\n2 - reprovar" << std::endl;
  std::cin >> aprovacao;

  if(aprovacao == 1){
    user._dinheiro += valor;
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

void Administrador::editaUsuario(Comprador user){}

void Administrador::excluiUsuario(Comprador user){}

void Administrador::exibeMensagens(Comprador user){}

void Administrador::respondeMensagens(Comprador user){}

Administrador::~Administrador(){}

#endif
