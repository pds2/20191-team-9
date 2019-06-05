#include "usuario/usuario.h"
//#include "include/arquivo/arquivo.h"

Usuario::Usuario(std::string n, std::string em, std::string s){
  usuarios.push_back(make_tuple(n, em, s));
  //RegistraUsuarioArquivo(make_tuple(n, em, s));
};

Usuario::~Usuario(){
  usuarios.clear();
}

std::string Usuario::getNome(std::tuple<std::string, std::string, std::string> usu){
  return std::get<0>(usu);
}

std::string Usuario::getEmail(std::tuple<std::string, std::string, std::string> usu){
  return std::get<1>(usu);
}

std::string Usuario::getSenha(std::tuple<std::string, std::string, std::string> usu){
  return std::get<2>(usu);
}

bool Usuario::checaNome(std::string n){
  return true;
}

bool Usuario::checaEmail(std::string em){
  return true;
}

bool Usuario::checaSenha(std::string s){
  return true;
}

void Usuario::ImprimeUsuarios(){
  for(const auto &i : usuarios){
    std::cout << std::get<0>(i) << " " << std::get<1>(i) << " " << std::get<2>(i) << "\n";
  }
}

bool Usuario::BuscarEmailVector(std::string n){
  for(const auto &i : usuarios){
    if(std::get<1>(i) == n){
      return true;
    }
  }
  return false;
}

void Usuario::CadastraUsuario (std::string n, std::string em, std::string s){
  if(checaNome(n) && checaEmail(em) && checaSenha(s)){
    if(BuscarEmailVector(em)==false){
      Usuario(n, em, s);
    }
    else{
      std::cout << "Endereço de email já cadastrado. Tente novamente." << std::endl;
    }
  }
  else{
    std::cout << "Dados inválidos. Tente novamente." << std::endl;
  }
}
