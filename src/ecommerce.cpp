#include "ecommerce.h"

Ecommerce::Ecommerce(){
  numeroUsuarios = 0;
}

Ecommerce::~Ecommerce(){
  usuarios.clear();
  compradores.clear();
}

void Ecommerce::listaUsuarioArquivo(){
  std::fstream arquivo;

  arquivo.open("usuarios.csv");

  if (!arquivo.is_open()) std::cout << "Erro ao abrir arquivo. Tente novamente";

  while (arquivo.good()){
    std::string nome, email, senha, cpf, endereco, nH, nC, nA, d;
    int numHistorico, numCarrinho, numAvaliacoes;
    double dinheiro;

    std::getline(arquivo, nome,',');
    std::getline(arquivo, email,',');
    std::getline(arquivo, senha,',');
    std::getline(arquivo, cpf,',');
    std::getline(arquivo, endereco,',');
    std::getline(arquivo, nC,',');
    std::getline(arquivo, nH,',');
    std::getline(arquivo, nA,',');
    std::getline(arquivo, d,'\n');

    numCarrinho = std::stoi(nC);
    numHistorico = std::stoi(nH);
    numAvaliacoes = std::stoi(nA);
    //dinheiro = std::stod(d);

    Comprador comp = Comprador(nome, email, senha, cpf, endereco, numCarrinho, numHistorico, numAvaliacoes, dinheiro);
    compradores.push_back(comp);

    std::cout << "\n" << nome << std::endl;
    std::cout << email << std::endl;
    std::cout << senha << std::endl;
    std::cout << cpf << std::endl;
    std::cout << endereco << std::endl;
    std::cout << numCarrinho << std::endl;
    std::cout << numHistorico << std::endl;
    std::cout << numAvaliacoes << std::endl;
    std::cout << dinheiro << std::endl;
  }

  arquivo.close();
}

void Ecommerce::cadastrarUsuario (std::string n, std::string em, std::string s){
  if(checaNome(n) && checaEmail(em) && checaSenha(s)){
    if(procurarUsuario(em)==false){
      Usuario usu = Usuario(n, em, s);
      usuarios.push_back(usu);
      numeroUsuarios++;
    }
    else{
      std::cout << "Endereço de email já cadastrado. Tente novamente." << std::endl;
    }
  }
  else{
    std::cout << "Dados inválidos. Tente novamente." << std::endl;
  }
  //RegistraUsuarioArquivo(make_tuple(n, em, s));
}

void Ecommerce::imprimirUsuarios(){
  for(int i=0; i < numeroUsuarios; i++){
    std::cout << (usuarios[i]).getNome() << " " << (usuarios[i]).getEmail() << " " << (usuarios[i]).getSenha() << "\n";
  }
}

void Ecommerce::addCarrinho(){
  Comprador comp;
  comp.adicionarCarrinho();
}

void Ecommerce::impCarrinho(){
  Comprador comp;
  comp.imprimirCarrinho();
}

void Ecommerce::impHistorico(){
  Comprador comp;
  comp.imprimirHistorico();
}

bool Ecommerce::procurarUsuario(std::string em){
  for(int i=0; i < numeroUsuarios; i++){
    if((usuarios[i]).getEmail() == em){
      return true;
    }
  }
  return false;
}

bool Ecommerce::checaNome(std::string n){
  return true;
}

bool Ecommerce::checaEmail(std::string em){
  return true;
}

bool Ecommerce::checaSenha(std::string s){
  return true;
}

void Ecommerce::limparTela(){
  std::system("clear||cls");
}
