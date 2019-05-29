#include <string>
#include <stdio.h>
#include <ctype.h>

#include <fstream.h>
#include <cstdlib>

#include "include/usuario/usuario.h"

Usuario::Usuario(std::string n, std::string em, std::string s):
    _nome(n), _email(em), _senha(s){};

void CadastraUsuario (std::string n, std::string em, std::string s) const{
  if(checaNome(n) && checaEmail(em) && checaSenha){
    Usuario(n, em, s);
  }
  else{
    std::cout << "Dados inválidos. Tente novamente." << std::endl;
  }
}

std::string Usuario::getNome() const{
  return _nome;
}

std::string Usuario::getEmail() const{
  return _email;
}

std::string Usuario::getSenha() const{
  return _senha;
}

void Usuario::setNome(std::string n) const{
  this->_nome = n;
}

void Usuario::setEmail(std::string em) const{
  this->_email = em;
}

void Usuario::setSenha(std::string s) const{
  this->_senha = s;
}

bool checaNome(std::string n) const{
  std::all_of(std::begin(n), std::end(n),
  [](char c){ return std::isalpha(c);});
}

bool checaEmail(std::string &em) const{
  // Locate '@'
  auto at = std::find(em.begin(), em.end(), '@');
  // Locate '.' after '@'
  auto dot = std::find(at, em.end(), '.');
  // make sure both characters are present

  //precisa procurar se o email já está cadastrado para algum usuário
  return (at != em.end()) && (dot != em.end());
}

bool checaSenha(std::string s) const{
  std::all_of(std::begin(s), std::end(s),
  [](char c){ return std::isalnum(c);});
}
