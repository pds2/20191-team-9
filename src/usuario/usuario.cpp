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

void Usuario::imprimirUsuarios(){
  Ecommerce ecom;
  ecom.imprimirUsuarios();
}

bool Usuario::buscarEmail(std::string em){
  Ecommerce ecom;
  ecom.buscarEmail(em);
}
