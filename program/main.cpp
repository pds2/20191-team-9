#include <iostream>
#include "usuario/usuario.h"
#include "ecommerce.h"

int main(int argc, char const *argv[]) {

  Ecommerce ecom;
  ecom.cadastrarUsuario("cat", "cat", "1234");
  ecom.imprimirUsuarios();

  return 0;
}
