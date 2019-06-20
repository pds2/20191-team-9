#include <iostream>

#include "ecommerce.h"

int main(int argc, char const *argv[]) {

  Ecommerce ecom;
  ecom.listaUsuarioArquivo();
  ecom.imprimirCompradores();
  ecom.cadastrarCaneca(3, 15, 4.5, "Caneca formosa", "Branca", "Caneca fofa de Star Wars", "Porcelana", 5.5);
  ecom.cadastrarAcessorio(4, 20, 4, "Pulseira GOT", "Vermelha", "Pulseira Dracarys", "Couro", "Tiposo");
  ecom.cadastrarBlusasEMoletom(2, 60, 4.5, "Moletom Amarelo", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", 'M', "Tipo tiposo");
  ecom.imprimirProdutos();
  //Esta função contem o "main", mas eu preciso dela no ecommerce para que outras funções possam ser redirecionadas para essa pagina
  ecom.inicio();

  //Comprador comp;
  //comp.adicionarCarrinho();;

return 0;
}
