#include <iostream>

#include "ecommerce.h"

int main(int argc, char const *argv[]) {

  Ecommerce ecom;
  ecom.listaUsuarioArquivo();
  ecom.cadastrarComprador("arthur", "arthur@gmail", "1234", "1234", "endereco do arthur", 0, 0, 0, 0);
  ecom.imprimirCompradores();
return 0;
}
