#include <iostream>

#include "ecommerce.h"

int main(int argc, char const *argv[]) {

  Ecommerce ecom;
  ecom.imprimirCompradores();
  ecom.cadastrarCaneca(3, 15, 4.5, "Caneca formosa", "Branca", "Caneca fofa de Star Wars", "Porcelana", 5.5);
  ecom.cadastrarAcessorio(4, 20, 4, "Pulseira GOT", "Vermelha", "Pulseira Dracarys", "Couro", "Tiposo");
  ecom.cadastrarBlusasEMoletom(2, 60, 4.5, "Moletom Amarelo", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", 'M', "Tipo tiposo");
<<<<<<< HEAD
  Comprador comp = ecom.buscaComprador("rita.caldas@gmail.com");
  //std::cout << comp.getNumeroComprasCarrinho();
  comp.imprimirCarrinho();
=======
  ecom.imprimirProdutos();
  //Esta função contem o "main", mas eu preciso dela no ecommerce para que outras funções possam ser redirecionadas para essa pagina
  ecom.inicio();
>>>>>>> dc738173207860e95ca45a92efdbe3fd2e5f0f98

  //Comprador comp;
  //comp.adicionarCarrinho();;

return 0;
}
