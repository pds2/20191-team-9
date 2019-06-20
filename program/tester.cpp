#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "produto/blusas_e_moletom.h"
#include "produto/caneca.h"
#include "produto/acessorio.h"

TEST_CASE("Declaracão produto") {
    CHECK_NOTHROW(Produto p(2, 60, 5, "Produto Diferenciavel", "Teste", "Verde", "Produto otimo para ser utilizado em casos de teste", "Radiacao"));
    CHECK_THROWS(Produto p(-2, 60, 5, "Produto Diferenciavel", "Teste", "Verde", "Produto otimo para ser utilizado em casos de teste", "Radiacao"));
    CHECK_THROWS(Produto p(3, 60, -5, "Produto Diferenciavel", "Teste", "Verde", "Produto otimo para ser utilizado em casos de teste", "Radiacao"));    
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
