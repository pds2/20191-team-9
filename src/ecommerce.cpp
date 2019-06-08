#include "ecommerce.h"

Ecommerce::Ecommerce(){
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

    //numCarrinho = std::stoi(nC);
    //numHistorico = std::stoi(nH);
    //numAvaliacoes = std::stoi(nA);
    //dinheiro = std::stod(d);

    Comprador comp = Comprador(nome, email, senha, cpf, endereco, 1, 1, 1, 0.0);
    compradores.push_back(comp);

    imprimirCompradores();
  }

  arquivo.close();
}

void Ecommerce::cadastrarUsuario (std::string n, std::string em, std::string s){
  if(checaNome(n) && checaEmail(em) && checaSenha(s)){
    if(procurarUsuario(em)==false){
      Usuario usu = Usuario(n, em, s);
      usuarios.push_back(usu);
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
  int numeroUsuarios = usuarios.size();
  for(int i=0; i < numeroUsuarios; i++){
    std::cout << (usuarios[i]).getNome() << " " << (usuarios[i]).getEmail() << " " << (usuarios[i]).getSenha() << "\n";
  }
}

void Ecommerce::imprimirCompradores(){
  int numeroCompradores = compradores.size();
  for(int i=0; i < numeroCompradores; i++){
    std::cout << (compradores[i]).getNome() << " " << (compradores[i]).getEmail() << " " << (compradores[i]).getSenha() << "\n";
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
  int numeroUsuarios = usuarios.size();
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
