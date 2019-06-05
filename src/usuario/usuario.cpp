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
