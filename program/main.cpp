#include <iostream>
#include "usuario/usuario.h"
#include "ecommerce.h"

int main(int argc, char const *argv[]) {

  Ecommerce ecom;
/* ecom.cadastrarUsuario("cat", "cat", "1234");
  ecom.cadastrarUsuario("catarina", "catarina", "1234");
  ecom.cadastrarUsuario("catau", "catau", "1234");
  ecom.cadastrarUsuario("kitkat", "kitkat", "1234");
  ecom.cadastrarUsuario("catalinda", "catalinda", "1234");
  ecom.cadastrarUsuario("cataprima", "cataprima", "1234");
*/
//  Arquivo arq;
//  arq.listaUsuarioArquivo();
/*  std::string email;
  std::cout << "Email: ";
  std::getline(std::cin, email);*/

//  std::cout << ecom.buscarEmail(email);
//  ecom.adicionarCarrinho();
  //ecom.imprimirCarrinho();

//  ecom.imprimirUsuarios();
  //ecom.adicionarCarrinho();*/

ecom.listaUsuarioArquivo();

return 0;
}
