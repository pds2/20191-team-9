#include <iostream>
#include "usuario/usuario.h"
#include "ecommerce.h"

int main(int argc, char const *argv[]) {

  Ecommerce ecom;
  ecom.cadastrarUsuario("cat", "cat", "1234");
  ecom.cadastrarUsuario("catarina", "catarina", "1234");
  ecom.cadastrarUsuario("catau", "catau", "1234");
  ecom.cadastrarUsuario("kitkat", "kitkat", "1234");
  ecom.cadastrarUsuario("catalinda", "catalinda", "1234");
  ecom.cadastrarUsuario("cataprima", "cataprima", "1234");

  ecom.imprimirUsuarios();
  ecom.adicionarCarrinho();
  return 0;
}
