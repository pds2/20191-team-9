#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "produto/blusas_e_moletom.h"


TEST_CASE("Declaracão produto") {
    CHECK_NOTHROW(BlusasEMoletom blusa(2, 60, 4.5, "Moletom amarelo", "Moletom", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", 'M', "Tipo tiposo"));
    CHECK_THROWS(BlusasEMoletom blusa(-2, 60, 4.5, "Moletom amarelo", "Moletom", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", 'M', "Tipo tiposo"));
    CHECK_THROWS(BlusasEMoletom blusa(1, 60, -1, "Moletom amarelo", "Moletom", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", 'M', "Tipo tiposo"));    

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
    Caneca m(3, 15, 4.5, "Caneca formosa", "Caneca", "Branca", "Caneca fofa de Star Wars", "Porcelana", 7);
    CHECK_EQ(m.getCodigoProduto(),3);
    CHECK_EQ(m.getPreco(),15);
    CHECK_EQ(m.getMediaAvaliacoes(),4.5);
    CHECK_EQ(m.getNome(),"Caneca formosa");
    CHECK_EQ(m.getCategoria(),"Caneca");
    CHECK_EQ(m.getCor(),"Branca");
    CHECK_EQ(m.getDescricao(),"Caneca fofa de Star Wars");
    CHECK_EQ(m.getMaterial(),"Porcelana");
    CHECK_EQ(m.getDiametro(), 7);

}


TEST_CASE("Get produto - Acessorios") {
    Caneca m(4, 20, 4, "Pulseira GOT", "Pulseira", "Vermelha", "Pulseira Dracarys", "Couro", "Tiposo");
    CHECK_EQ(m.getCodigoProduto(),4);
    CHECK_EQ(m.getPreco(),20);
    CHECK_EQ(m.getMediaAvaliacoes(),4);
    CHECK_EQ(m.getNome(),"Pulseira GOT");
    CHECK_EQ(m.getCategoria(),"Pulseira");
    CHECK_EQ(m.getCor(),"Vermelha");
    CHECK_EQ(m.getDescricao(),"Pulseira Dracarys");
    CHECK_EQ(m.getMaterial(),"Couro");
    CHECK_EQ(m.getTipo(),"Tiposo");

}
