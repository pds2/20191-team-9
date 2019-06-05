#include "ecommerce.h"

Ecommerce::Ecommerce(){
  numeroUsuarios = 0;
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
    std::cout << usuario.getNome(usuarios[i]) << " " << usuario.getEmail(usuarios[i]) << " " << usuario.getSenha(usuarios[i]) << "\n";
  }
}

bool Ecommerce::buscarEmail(std::string n){
  Usuario usuario;
  for(int i=0; i < numeroUsuarios; i++){
    if(usuario.getNome(usuarios[i]) == n){
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
