#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "produto/blusas_e_moletom.h"
#include "produto/caneca.h"
#include "produto/acessorio.h"
#include "usuario/comprador.h"

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

/*
//-----> Testes ADMINISTRADOR
TEST_CASE("Criar o Administrador"){
  Administrador admin();
  CHECK_EQ(admin.getNome(), "ADMIN");
  CHECK_EQ(admin.getEmail(), "admin1@gmail.com");
  CHECK_EQ(admin.getSenha(), "123tasalvo");
}
//implementar pós exceções
TEST_CASE("Remover item do estoque"){
  BlusasEMoletom teste(697, 45, 3.5, "blusazul", "Blusa e Moletom", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", M, "Tipo tiposo");
}

TEST_CASE("Remover item que não existe"){
  CHECK_EQ(removeItem(naoexiste), -1);
}

TEST_CASE("Aumentar saldo de usuário que não existe"){
  CHECK_EQ(aprovaPedido(naoexiste), -1);
}

TEST_CASE("Aumentar saldo de usuário que não requisitou o aumento"){
  Comprador shops("semaumento","sem@aumento.com","senha123","44565564","nãoaumenta",6,6,4,5);
  CHECK_EQ(aprovaPedido(sem@aumento.com), -2);
}
//implementar pós exceções
TEST_CASE("Aprovar um pedido"){

}

TEST_CASE("Excluir usuário que não existe"){
  CHECK_EQ(excluiUsuario(naoexiste), -1);
}
//implementar pós exceções
TEST_CASE("Excluir um usuário"){
  Comprador bye("excluir","ex@cluir.com","excluido","000000","exclui",7,6,3,9);
}
*/
//-----> Testes COMPRADOR

TEST_CASE("Cadastrar Comprador") {
    CHECK_NOTHROW(Comprador comp ("Arthur Moura", "arthur.moura@gmail.com", "1234", "123456789", "Rua Washington, 80. Copacabana.", 0, 0, 0, 0.0));
    CHECK_NOTHROW(Comprador comp ("Carolina Enya", "carolina.enya@gmail.com", "1234", "222222222", "Rua Washington, 90. Copacabana.", 0, 0, 0, 0.0));
    CHECK_NOTHROW(Comprador comp ("Rita Caldas", "rita.caldas@gmail.com", "1234", "33333333333", "Rua Washington, 100. Copacabana.", 0, 0, 0, 0.0));
    CHECK_NOTHROW(Comprador comp ("Tula Valentina", "tula.valentina@gmail.com", "1234", "444444444", "Rua Washington, 110. Copacabana.", 0, 0, 0, 0.0));
}
TEST_CASE("Get - Dados do Comprador") {
    Comprador comp ("Catarina Enya", "catarina.edp@gmail.com", "1234", "555555555", "Rua Washington, 120. Copacabana.", 0, 0, 0, 0.0));
    CHECK_EQ(comp.getNome(), "Catarina Enya");
    CHECK_EQ(comp.getEmail(), "catarina.edp@gmail.com");
    CHECK_EQ(comp.getSenha(), "1234");
    CHECK_EQ(comp.getCPF(), "555555555");
    CHECK_EQ(comp.getNumeroComprasCarrinho(), 0);
    CHECK_EQ(comp.getNumeroComprasHistorico(), 0);
    CHECK_EQ(comp.getNumeroAvaliacoes(), 0);
    CHECK_EQ(comp.getDinheiro(), 0.0);
}

TEST_CASE("Adicionar Produto ao Carrinho do Comprador") {
  Comprador comp ("Arthur Moura", "arthur.moura@gmail.com", "1234", "123456789", "Rua Washington, 80. Copacabana.", 0, 0, 0, 0.0);
  BlusasEMoletom m(2, 60, 4.5, "Moletom Amarelo", "Moletom", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", 'M', "Tipo tiposo");
  Caneca c(3, 15, 4.5, "Caneca formosa", "Caneca", "Branca", "Caneca fofa de Star Wars", "Porcelana", 5.5);
  Acessorio a(4, 20, 4, "Pulseira GOT", "Pulseira", "Vermelha", "Pulseira Dracarys", "Couro", "Tiposo");
  comp.adicionarCarrinho();
}

TEST_CASE("Realizar Busca por Produto no Carrinho do Comprador") {
  Comprador comp ("Carolina Enya", "carolina.enya@gmail.com", "1234", "222222222", "Rua Washington, 90. Copacabana.", 0, 0, 0, 0.0)
  BlusasEMoletom m(2, 60, 4.5, "Moletom Amarelo", "Moletom", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", 'M', "Tipo tiposo");
  Caneca c(3, 15, 4.5, "Caneca formosa", "Caneca", "Branca", "Caneca fofa de Star Wars", "Porcelana", 5.5);
  Acessorio a(4, 20, 4, "Pulseira GOT", "Pulseira", "Vermelha", "Pulseira Dracarys", "Couro", "Tiposo");
  comp.buscaCarrinho();
}

TEST_CASE("Realizar Busca por Produto no Histórico do Comprador") {
  Comprador comp ("Rita Caldas", "rita.caldas@gmail.com", "1234", "33333333333", "Rua Washington, 100. Copacabana.", 0, 0, 0, 0.0)
  BlusasEMoletom m(2, 60, 4.5, "Moletom Amarelo", "Moletom", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", 'M', "Tipo tiposo");
  Caneca c(3, 15, 4.5, "Caneca formosa", "Caneca", "Branca", "Caneca fofa de Star Wars", "Porcelana", 5.5);
  Acessorio a(4, 20, 4, "Pulseira GOT", "Pulseira", "Vermelha", "Pulseira Dracarys", "Couro", "Tiposo");
  comp.buscaHistorico();
}

/*
bool adicionarCarrinho();
void fazerCompras();
bool retirarCarrinho();
bool adicionaDinheiro();

void exibirPerfil();
void imprimirCarrinho();
void imprimirHistorico();

int procurarItensHistorico(int codProduto);
int procurarItensCarrinho(int codProduto);
void adicionarComentario();
void avaliarItem();

Produto buscaHistorico(int codProduto);
Produto buscaCarrinho(int codProduto);*/
