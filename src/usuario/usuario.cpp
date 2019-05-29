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

Usuario::~Usuario(){
  usuarios.clear();
}

void CadastraUsuario (std::string n, std::string em, std::string s) const{
  if(checaNome(n) && checaEmail(em) && checaSenha){
    if(BuscarEmailArquivo(em)==false){
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

std::string Usuario::getNome(vector<tuple<std::string, std::string, std::string> > usu) const{
  return get<0>(usu);
}

std::string Usuario::getEmail(vector<tuple<std::string, std::string, std::string> > usu) const{
  return get<1>(usu);
}

std::string Usuario::getSenha(vector<tuple<std::string, std::string, std::string> > usu) const{
  return get<2>(usu);
}

bool Usuario::checaNome(std::string n) const{
  std::all_of(std::begin(n), std::end(n),
  [](char c){ return std::isalpha(c);});
}

bool Usuario::checaEmail(std::string &em) const{
  // Locate '@'
  auto at = std::find(em.begin(), em.end(), '@');
  // Locate '.' after '@'
  auto dot = std::find(at, em.end(), '.');
  // make sure both characters are present

  //precisa procurar se o email já está cadastrado para algum usuário
  return (at != em.end()) && (dot != em.end());
}

bool Usuario::checaSenha(std::string s) const{
  std::all_of(std::begin(s), std::end(s),
  [](char c){ return std::isalnum(c);});
}

void Usuario::ImprimeUsuarios(){
    for (int i = 0; i < usuarios.size(); i++)
          cout << get<0>(users[i]) << " "
               << get<1>(users[i]) << " "
               << get<2>(users[i]) << "\n";
}
