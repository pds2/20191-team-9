#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <iostream>

TEST_CASE("Declaracão produto") {
    CHECK_NOTHROW(BlusasEMoletom blusa(2, 60, 4.5, "Moletom amarelo", "Moletom", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", M, "Tipo tiposo"));
    CHECK_NOTHROW(BlusasEMoletom blusa ());
}

TEST_CASE("Get produto") {
    BlusasEMoletom m(2, 60, 4.5, "Moletom amarelo", "Moletom", "Amarelo", "Amarelo que nem o raiar do sol", "Algodao", M, "Tipo tiposo");
    CHECK_EQ(m.getCodigoProduto(),2);
    CHECK_EQ(m.getPreco(),60);
    CHECK_EQ(m.getMediaAvaliacoes(),4.5);
    CHECK_EQ(m.getNome(),"Moletom Amarelo");
    CHECK_EQ(m.getCategoria(),"Moletom");
    CHECK_EQ(m.getCor(),"Amarelo");
    CHECK_EQ(m.getDescricao(),"Amarelo que nem o raiar do sol");
    CHECK_EQ(m.getMaterial(),"Algodao");
    CHECK_EQ(m.getTamanho(), M);
    CHECK_EQ(m.getTipo(),"Tipo tiposo");
}
