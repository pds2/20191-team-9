#include "usuario/usuario.h"
//#include "include/arquivo/arquivo.h"

Usuario::Usuario(std::string n, std::string em, std::string s){
  _nome = n;
  _email = em;
  _senha = s;
};

Usuario::Usuario(){

}

Usuario::~Usuario(){
  usuarios.clear();
}

std::string Usuario::getNome(Usuario usu){
  return usu._nome;
}

std::string Usuario::getEmail(Usuario usu){
  return usu._email;
}

std::string Usuario::getSenha(Usuario usu){
  return usu._senha;
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
  for(int i=0; i < usuarios.size(); i++){
    std::cout << getNome(usuarios[i]) << " " << getEmail(usuarios[i]) << " " << getSenha(usuarios[i]) << "\n";
  }
}

bool Usuario::BuscarEmailVector(std::string n){
  for(int i=0; i < usuarios.size(); i++){
    if(getNome(usuarios[i]) == n){
      return true;
    }
  }
  return false;
}

void Usuario::CadastraUsuario (std::string n, std::string em, std::string s){

  if(checaNome(n) && checaEmail(em) && checaSenha(s)){
    if(BuscarEmailVector(em)==false){
      Usuario usu = new Usuario(n, em, s);
      usuarios.push_back(usu);
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
