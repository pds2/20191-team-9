#include <iostream>

#include "ecommerce.h"

int main(int argc, char const *argv[]) {

  Ecommerce ecom;
  ecom.limparTela();
  ecom.cadastrarComprador("nome", "cat", "senha", "cpf", "endereco", 0, 0, 0, 0);
  ecom.cadastrarComprador("nome", "catarina", "senha", "cpf", "endereco", 0, 0, 0, 0);

  ecom.imprimirCompradores();
  ecom.listaUsuarioArquivo();
return 0;
}
