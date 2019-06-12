#include <iostream>

#include "ecommerce.h"

int main(int argc, char const *argv[]) {

  Ecommerce ecom;
  ecom.limparTela();
  ecom.cadastrarComprador("nome", "cat", "senha", "cpf", "endereco", 1, 1, 1, 1);
  ecom.cadastrarComprador("nome", "catarina", "senha", "cpf", "endereco", 1, 1, 1, 1);

  ecom.imprimirUsuarios();
  ecom.listaUsuarioArquivo();
return 0;
}
