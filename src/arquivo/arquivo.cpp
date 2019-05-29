#include "include/arquivo/arquivo.h"
#include "include/usuario/usuario.h"

void Arquivo::RegistraUsuarioArquivo (tuple<std::string, std::string, std::string> usu) const{
  fstream iodados;
  iodados.open("usuarios.txt", ios::ate | ios::out | ios::in);

  iodados.write(get<0>(usu), get<1>(usu), get<2>(usu));//Aqui gravamos o conteúdo do objeto 'usu' em 'usuarios.txt'.

  iodados.seekg(0);
  iodados.close();
}

void Arquivo::ListaUsuarioArquivo() const {
  fstream iodados;
  Usuario users;

  iodados.open("usuarios.txt", ios::ate | ios::out | ios::in);
  ~Usuario();

  while (iodados.read((char *) &users, (char *) em, (char *) sen)){
    CadastraUsuario(users, em, sen);
  }

  ImprimeUsuarios();

  iodados.close();
}

bool Arquivo::BuscarEmailArquivo(std::string em) const {//só usar o sort da estrutura tuple
  fstream iodados;

  iodados.open("usuarios.txt", ios::ate | ios::out | ios::in);

  while (iodados.read((char *) user, (char *) em, (char *) sen)){
    if(user == usu){
      return true;
    }
  }

  iodados.close();
  return false;
}
