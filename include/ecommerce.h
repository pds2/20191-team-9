#ifndef ECOMMERCE_H
#define ECOMMERCE_H

#include <string>
#include <vector>
#include <sstream>

#include <cstdlib>

#include <math.h>

#include <fstream>
#include <iostream>

#include "usuario/comprador.h"

class Ecommerce{
  private:
    std::vector <Usuario> usuarios;
    std::vector <Comprador> compradores;
    const std::string SENHADMIN = "Ecom@Geek42";
    Usuario *userLogged = NULL;

  public:
    Ecommerce();
    ~Ecommerce();

    void cadastrarUsuario (std::string n, std::string em, std::string s);
    void cadastrarComprador (std::string n, std::string em, std::string s, std::string cpf, std::string endereco, int numCarr, int numHist, int numAval, double din);
    bool procurarUsuario(std::string email);
    bool procurarComprador(std::string em);
    void imprimirUsuarios();
    void imprimirCompradores();

    //void imprimirProdutos();
    //void imprimirMensagens();

    bool checaNome(std::string n);
    bool checaEmail(std::string em);
    bool checaSenha(std::string s);
    bool checaSenhaAdmin(std::string sAdmin);
    //Validar e form cadastro usuario e cadastrarUsuario
    //Falso volta pra ecommerce()

    void addCarrinho();
    void limparTela();
    void impCarrinho();
    void impHistorico();
    void listaUsuarioArquivo();
    void gravaUsuarioArquivo();

    void loginUsuario(std::string n, std::string s);
    void loginUsuario();
    void logoutUsuario();
    void inicio();
    void menuSumario(int idMenu, int opcao);
    //opção voltar
    //opção logout geral
    void menuUsuario();
    void menuComprador();
};

#endif
