#include <iostream>

#include "ecommerce.h"

int main(int argc, char const *argv[]) {

  Ecommerce ecom;
  ecom.listaUsuarioArquivo();
  ecom.cadastrarComprador("arthur", "arthur@gmail", "1234", "1234", "endereco do arthur", 0, 0, 0, 0);
  ecom.imprimirCompradores();
//Esta função contem o "main", mas eu preciso dela no ecommerce para que outras funções possam ser redirecionadas para essa pagina
  ecom.inicio();

return 0;
}
