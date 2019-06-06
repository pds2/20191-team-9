#include "ecommerce.h"

Ecommerce::Ecommerce(){
  numeroUsuarios = 0;
}

Ecommerce::~Ecommerce(){
  usuarios.clear();
}

void Ecommerce::cadastrarUsuario (std::string n, std::string em, std::string s){
  if(checaNome(n) && checaEmail(em) && checaSenha(s)){
    if(buscarEmail(em)==false){
      Usuario *usu = new Usuario(n, em, s);
      usuarios.push_back(usu);
      numeroUsuarios++;
    }
    else{
      std::cout << "Endereço de email já cadastrado. Tente novamente." << std::endl;
    }
  }
  else{
    std::cout << "Dados inválidos. Tente novamente." << std::endl;
  }
  //RegistraUsuarioArquivo(make_tuple(n, em, s));
}

void Ecommerce::imprimirUsuarios(){
  Usuario usuario;
  for(int i=0; i < numeroUsuarios; i++){
    std::cout << (*usuarios[i]).getNome() << " " << (*usuarios[i]).getEmail() << " " << (*usuarios[i]).getSenha() << "\n";
  }
}

void Ecommerce::adicionarCarrinho(){
  Comprador comp;
  std::string email;

  limparTela();

  imprimirUsuarios(); //faz a listagem dos produtos aqui

  std::cout << "\n\n" << "----Escolha um produto para adiciona-lo ao seu carrinho----"<< "\n";
  std::cout << "Código do Produto: ";  //usuario escolhe qual produto vai querer aqui;

  std::getline (std::cin, email);

  if(buscarEmail(email) == true){
    comp.adicionarCarrinho(email);
    std::cout << "Produto adicionado ao carrinho com sucesso!"<< "\n";
  }
  else{
      std::cout << "Produto escolhido não foi encontrado. Tente novamente mais tarde.";
  }
}

bool Ecommerce::buscarEmail(std::string em){
  Usuario usuario;
  for(int i=0; i < numeroUsuarios; i++){
    if((*usuarios[i]).getEmail() == em){
      return true;
    }
  }
  return false;
}

bool Ecommerce::checaNome(std::string n){
  return true;
}

bool Ecommerce::checaEmail(std::string em){
  return true;
}

bool Ecommerce::checaSenha(std::string s){
  return true;
}

void Ecommerce::limparTela(){
  std::system("clear||cls");
}
