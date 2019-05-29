#include <string>
#include <stdio.h>
#include <ctype.h>

#include <fstream.h>
#include <cstdlib>

#include "include/usuario/usuario.h"
#include "include/arquivo/arquivo.h"

Usuario::Usuario(std::string n, std::string em, std::string s){
  usuarios.push_back(make_tuple(n, em, s));
  RegistraUsuarioArquivo(make_tuple(n, em, s));
};

void CadastraUsuario (std::string n, std::string em, std::string s) const{
  if(checaNome(n) && checaEmail(em) && checaSenha){
    Usuario(n, em, s);
  }
  else{
    std::cout << "Dados inválidos. Tente novamente." << std::endl;
  }
}

std::string Usuario::getNome(vector<tuple<std::string, std::string, std::string> > usu) const{
  return get<0>(usu);
}

std::string Usuario::getEmail(vector<tuple<std::string, std::string, std::string> > usu) const{
  return get<1>(usu);
}

std::string Usuario::getSenha(vector<tuple<std::string, std::string, std::string> > usu) const{
  return get<2>(usu);
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
