#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "produto/blusas_e_moletom.h"
#include "produto/caneca.h"
#include "produto/acessorio.h"
#include "usuario/comprador.h"
#include "usuario/administrador.h"
#include "ecommerce.h"


TEST_CASE("Declaracão produto") {
    CHECK_NOTHROW(Produto p(2, 60, 5, "Produto Diferenciavel", "Teste", "Verde", "Produto otimo para ser utilizado em casos de teste", "Radiacao"));
    CHECK_THROWS(Produto p(-2, 60, 5, "Produto Diferenciavel", "Teste", "Verde", "Produto otimo para ser utilizado em casos de teste", "Radiacao"));
    CHECK_THROWS(Produto p(3, 60, -5, "Produto Diferenciavel", "Teste", "Verde", "Produto otimo para ser utilizado em casos de teste", "Radiacao"));
    CHECK_THROWS(Produto p(2, 60, 6, "Produto Diferenciavel", "Teste", "Verde", "Produto otimo para ser utilizado em casos de teste", "Radiacao"));
}

TEST_CASE("Get produto - BlusasEMoletom") {
    BlusasEMoletom m(2, 60, 4.5, "Moletom Amarelo", "Moletom", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", 'M', "Tipo tiposo");
    CHECK_EQ(m.getCodigoProduto(),2);
    CHECK_EQ(m.getPreco(),60);
    CHECK_EQ(m.getMediaAvaliacoes(),4.5);
    CHECK_EQ(m.getNome(),"Moletom Amarelo");
    CHECK_EQ(m.getCategoria(),"Moletom");
    CHECK_EQ(m.getCor(),"Amarelo");
    CHECK_EQ(m.getDescricao(),"Amarelo que nem o raiar do sol");
    CHECK_EQ(m.getMaterial(),"Algodao");
    CHECK_EQ(m.getTamanho(), 'M');
    CHECK_EQ(m.getTipo(),"Tipo tiposo");
}

TEST_CASE("Get produto - Caneca") {
    Caneca c(3, 15, 4.5, "Caneca formosa", "Caneca", "Branca", "Caneca fofa de Star Wars", "Porcelana", 5.5);
    CHECK_EQ(c.getCodigoProduto(),3);
    CHECK_EQ(c.getPreco(),15);
    CHECK_EQ(c.getMediaAvaliacoes(),4.5);
    CHECK_EQ(c.getNome(),"Caneca formosa");
    CHECK_EQ(c.getCategoria(),"Caneca");
    CHECK_EQ(c.getCor(),"Branca");
    CHECK_EQ(c.getDescricao(),"Caneca fofa de Star Wars");
    CHECK_EQ(c.getMaterial(),"Porcelana");
    CHECK_EQ(c.getDiametro(), 5.5);
}

TEST_CASE("Get produto - Acessorios") {
    Acessorio a(4, 20, 4, "Pulseira GOT", "Pulseira", "Vermelha", "Pulseira Dracarys", "Couro", "Tiposo");
    CHECK_EQ(a.getCodigoProduto(),4);
    CHECK_EQ(a.getPreco(),20);
    CHECK_EQ(a.getMediaAvaliacoes(),4);
    CHECK_EQ(a.getNome(),"Pulseira GOT");
    CHECK_EQ(a.getCategoria(),"Pulseira");
    CHECK_EQ(a.getCor(),"Vermelha");
    CHECK_EQ(a.getDescricao(),"Pulseira Dracarys");
    CHECK_EQ(a.getMaterial(),"Couro");
    CHECK_EQ(a.getTipo(),"Tiposo");
}

TEST_CASE("Ecommerce - Cadastrar Acessorios"){
    Ecommerce ecom;
    CHECK_NOTHROW(ecom.cadastrarAcessorio(2, 5.5, 5, "Chaveiro", "Azul", "Chaveiro muito descolado.", "Ferro", "Chaves"));
    CHECK_THROWS(ecom.cadastrarCaneca(2, 10, 5, "Caneca Frozen", "Azul", "Canecao da disney", "Porcelana", 5)); //mesmo código
    Produto p = ecom.buscaProdutos(2);
    CHECK_EQ(p.getCodigoProduto(),2);
    CHECK_EQ(p.getPreco(),5.5);
    CHECK_EQ(p.getMediaAvaliacoes(),5);
    CHECK_EQ(p.getCategoria(),"Acessorios");
    CHECK_EQ(p.getCor(),"Azul");

}

TEST_CASE("Ecommerce - Cadastrar Caneca"){
    Ecommerce ecom;
    CHECK_NOTHROW(ecom.cadastrarCaneca(3, 10, 5, "Caneca Frozen", "Azul", "Canecao da disney", "Porcelana", 5));
    CHECK_THROWS(ecom.cadastrarAcessorio(3, 5.5, 5, "Chaveiro", "Azul", "Chaveiro muito descolado.", "Ferro", "Chaves")); //mesmo código
    Produto p = ecom.buscaProdutos(3);
    CHECK_EQ(p.getCodigoProduto(),3);
    CHECK_EQ(p.getPreco(),10);
    CHECK_EQ(p.getMediaAvaliacoes(),5);
    CHECK_EQ(p.getCategoria(),"Canecas");
    CHECK_EQ(p.getCor(),"Azul");
}

TEST_CASE("Ecommerce - Cadastrar Blusas e Moletons"){
    Ecommerce ecom;
    CHECK_NOTHROW(ecom.cadastrarBlusasEMoletom(5, 25, 5, "Blusa Simples", "Branco", "Blusa simples casual", "Algodao", 'P', "Blusa"));
    CHECK_THROWS(ecom.cadastrarAcessorio(5, 5.5, 5, "Chaveiro", "Azul", "Chaveiro muito descolado.", "Ferro", "Chaves")); //mesmo código
    Produto p = ecom.buscaProdutos(5);
    CHECK_EQ(p.getCodigoProduto(),5);
    CHECK_EQ(p.getPreco(),25);
    CHECK_EQ(p.getMediaAvaliacoes(),5);
    CHECK_EQ(p.getCategoria(),"Blusas e Moletons");
    CHECK_EQ(p.getCor(),"Branco");
}

//-----> Testes COMPRADOR

TEST_CASE("Cadastrar Comprador") {
    Ecommerce ecom;
    CHECK_NOTHROW(ecom.cadastrarComprador("Arthur Moura", "arthur.moura@gmail.com", "1234", "123456789", "Rua Washington, 80. Copacabana.", 0, 0, 0, 0.0));
    CHECK_NOTHROW(ecom.cadastrarComprador("Carolina Enya", "carolina.enya@gmail.com", "1234", "222222222", "Rua Washington, 90. Copacabana.", 0, 0, 0, 0.0));
    CHECK_NOTHROW(ecom.cadastrarComprador("Rita Caldas", "rita.caldas@gmail.com", "1234", "33333333333", "Rua Washington, 100. Copacabana.", 0, 0, 0, 0.0));
    CHECK_NOTHROW(ecom.cadastrarComprador("Tula Valentina", "tula.valentina@gmail.com", "1234", "444444444", "Rua Washington, 110. Copacabana.", 0, 0, 0, 0.0));
}

TEST_CASE("Get - Dados do Comprador") {
    Comprador comp ("Catarina Enya", "catarina.edp@gmail.com", "1234", "555555555", "Rua Washington, 120. Copacabana.", 0, 0, 0, 0.0);
    CHECK_EQ(comp.getNome(), "Catarina Enya");
    CHECK_EQ(comp.getEmail(), "catarina.edp@gmail.com");
    CHECK_EQ(comp.getSenha(), "1234");
    CHECK_EQ(comp.getCPF(), "555555555");
    CHECK_EQ(comp.getNumeroComprasCarrinho(), 0);
    CHECK_EQ(comp.getNumeroComprasHistorico(), 0);
    CHECK_EQ(comp.getNumeroAvaliacoes(), 0);
    CHECK_EQ(comp.getDinheiro(), 0.0);
}

//-----> Testes ADMINISTRADOR
TEST_CASE("Administrador - Criar o Administrador"){
  Administrador adm = Administrador();
  CHECK_EQ(adm.getNome(), "ADMIN");
  CHECK_EQ(adm.getEmail(), "admin1@gmail.com");
  CHECK_EQ(adm.getSenha(), "123tasalvo");
}

TEST_CASE("Administrador - Remover item do estoque"){
   Administrador adm = Administrador();
   BlusasEMoletom teste(697, 45, 3.5, "blusazul", "Blusas e Moletoms", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", 'M', "Tipo tiposo");

   CHECK_NOTHROW(adm.removeItem("blusazul"));
   CHECK_THROWS(adm.removeItem("blusauzul"));
}

TEST_CASE("Administrador - Remover item que não existe"){
  Administrador adm = Administrador();

  CHECK_EQ(adm.removeItem("naoexiste"), -1);
}

TEST_CASE("Administrador - Aumentar saldo de usuário que não existe"){
  Administrador adm = Administrador();

  CHECK_EQ(adm.aprovaPedido("naoexiste"), -1);
}

TEST_CASE("Administrador - Aumentar saldo de usuário que não requisitou o aumento"){
  Administrador adm = Administrador();
  Ecommerce ecom;
  ecom.cadastrarComprador("semaumento","sem@aumento.com","senha123","44565564","nãoaumenta",6,6,4,5);
  CHECK_EQ(admin.aprovaPedido("sem@aumento.com"), -2);
}

TEST_CASE("Administrador - Excluir usuário que não existe"){
  Administrador adm = Administrador();

  CHECK_EQ(adm.excluiUsuario("naoexiste"), -1);
}

TEST_CASE("Administrador - Excluir um usuário"){
    Ecommerce ecom;
    Administrador adm = Administrador();
    ecom.cadastrarComprador("excluir","ex@cluir.com","excluido","000000","exclui",7,6,3,9);

    CHECK_NOTHROW(adm.excluiUsuario("ex@cluir.com"));
    CHECK_THROWS(adm.excluiUsuario("ex@cluir.com"));
}
