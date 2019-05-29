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
  Usuario usuarios;
  iodados.open("usuarios.txt", ios::ate | ios::out | ios::in);

  while (iodados.read((char *) &usu, (char *) em, (char *) sen)){

    std::cout << usu->getNome() << " " << usu->getEmail() << " " << usu->getSenha() << std::endl;
  }

  iodados.close();
}

bool Arquivo::BuscarEmailArquivo(std::string usu) const {
  fstream iodados;
  iodados.open("usuarios.txt", ios::ate | ios::out | ios::in);
  while (iodados.read((char *) &usu, (char *) em, (char *) sen)){
    if(usu->getNome() == usu){
      return true;
    }
  }
  iodados.close();
  return false;
}
