#include "usuario/usuario.h"

Usuario::Usuario(std::string n, std::string em, std::string s){
  _nome = n;
  _email = em;
  _senha = s;
};

Usuario::Usuario(){

}

Usuario::~Usuario(){

}

std::string Usuario::getNome(){
  return this->_nome;
}

std::string Usuario::getEmail(){
  return this->_email;
}

std::string Usuario::getSenha(){
  return this->_senha;
}
