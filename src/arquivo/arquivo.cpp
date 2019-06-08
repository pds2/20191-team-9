/*#include "arquivo/arquivo.h"

void Arquivo::registraUsuarioArquivo (){
/*  std::fstream arquivo;
  arquivo.open("usuarios::ios.txt", std::ios::ate | std::ios::out | std::ios::in);

  arquivo.write(get<0>(usu), get<1>(usu), get<2>(usu));//Aqui gravamos o conteúdo do objeto 'usu' em 'usuarstd::ios.txt'.

  arquivo.seekg(0);
  arquivo.close();

}
*/
/*
void Arquivo::listaUsuarioArquivo(){
  std::fstream arquivo;

  arquivo.open("usuarios.csv");

  if (!arquivo.is_open()) std::cout << "Erro ao abrir arquivo. Tente novamente";

  while (arquivo.good()){
    std::string nome, email, senha, cpf, endereco;
    int numHistorico, numCarrinho, numAvaliacoes;
    double dinheiro;

    getline(arquivo, nome,',');
    getline(arquivo, email,',');
    getline(arquivo, senha,',');
    getline(arquivo, cpf,',');
    getline(arquivo, endereco,',');
    getline(arquivo, numCarrinho,',');
    getline(arquivo, numHistorico,',');
    getline(arquivo, numAvaliacoes,',');
    getline(arquivo, dinheiro,'\n');

    Ecommerce *ecom = new Ecom();
    Comprador *comp = Comprador(nome, email, senha, cpf, endereco, std::stoi(numCarrinho),
      std::stoi(numHistorico), std::stoi(numAvaliacoes), std::stod(dinheiro));

    compradores.push_back(comp);
  }

  arquivo.close();
}
*/
