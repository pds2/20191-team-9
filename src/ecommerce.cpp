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

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

  while (arquivo.good()){
    std::string nome, email, senha, cpf, endereco;
    int numHistorico, numCarrinho, numAvaliacoes;
    double dinheiro;

    std::getline(arquivo, nome,',');
    std::getline(arquivo, email,',');
    std::getline(arquivo, senha,',');
    std::getline(arquivo, cpf,',');
    std::getline(arquivo, endereco,',');
    /*std::getline(arquivo, numCarrinho,',');
    std::getline(arquivo, numHistorico,',');
    std::getline(arquivo, numAvaliacoes,',');
    std::getline(arquivo, dinheiro,'\n');*/

    Comprador comp = Comprador(nome, email, senha, cpf, endereco, numCarrinho, numHistorico, numAvaliacoes, dinheiro);
    Usuario usu = Usuario(nome, email, senha);
    usuarios.push_back(usu);
    compradores.push_back(comp);
  }
  imprimirCompradores();
  arquivo.close();
}

void Ecommerce::gravaUsuarioArquivo(){
  std::fstream arquivo;

  arquivo.open("usuarios.csv");

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

  int numeroCompradores = compradores.size();
  for(int i=0; arquivo.good() && i < numeroCompradores-1; i++){
    arquivo << (compradores[i]).getNome() << "," << (compradores[i]).getEmail() << "," << (compradores[i]).getSenha() << "," << (compradores[i]).getNumeroComprasCarrinho() << "," << (compradores[i]).getNumeroComprasHistorico() << "," << (compradores[i]).getNumeroAvaliacoes() << "," << (compradores[i]).getEndereco() << "," << (compradores[i]).getDinheiro() << "\n"
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
}

void Ecommerce::cadastrarComprador (std::string n, std::string em, std::string s, std::string cpf,
  std::string endereco, int numCarr, int numHist, int numAval, double din){
   if(checaNome(n) && checaEmail(em) && checaSenha(s)){
    if(procurarUsuario(em)==false){
      Comprador comp = Comprador(n, em, s, cpf, endereco, numCarr, numHist, numAval, din);
      Usuario usu = Usuario(n, em, s);
      usuarios.push_back(usu);
      compradores.push_back(comp);
      gravaUsuarioArquivo();
     }
     else{
      std::cout << "Endereço de email já cadastrado. Tente novamente." << std::endl;
     }
  }
  else{
    std::cout << "Dados inválidos. Tente novamente." << std::endl;
  }
}

void Ecommerce::imprimirUsuarios(){
  limparTela();
  int numeroUsuarios = usuarios.size();
  for(int i=0; i < numeroUsuarios-1; i++){
    std::cout << "\n" << "----------------------------------------------" << std::endl;
    std::cout << "\t\t Usuário " << i+1 << std::endl;
    std::cout << "----------------------------------------------" << "\n" << std::endl;
    std::cout << "Nome: " << (usuarios[i]).getNome() << std::endl;
    std::cout << "Email: " << (usuarios[i]).getEmail() << std::endl;
    std::cout << "Senha: " << (usuarios[i]).getSenha() << std::endl;
  }
}

void Ecommerce::imprimirCompradores(){
  limparTela();
  int numeroCompradores = compradores.size();
  for(int i=0; i < numeroCompradores-1; i++){
    std::cout << "\n" << "----------------------------------------------" << std::endl;
    std::cout << "\t\t Comprador " << i+1 << std::endl;
    std::cout << "----------------------------------------------" << "\n" << std::endl;
    std::cout << "Nome: " << (compradores[i]).getNome() << std::endl;
    std::cout << "Email: " << (compradores[i]).getEmail() << std::endl;
    std::cout << "Senha: " << (compradores[i]).getSenha() << std::endl;
    std::cout << "Carrinho: " << (compradores[i]).getNumeroComprasCarrinho() << std::endl;
    std::cout << "Histórico: " << (compradores[i]).getNumeroComprasHistorico() << std::endl;
    std::cout << "Avaliações: " << (compradores[i]).getNumeroAvaliacoes() << std::endl;
    std::cout << "Endereço: " << (compradores[i]).getEndereco() << std::endl;
    std::cout << "Dinheiro: " << (compradores[i]).getDinheiro() << std::endl;
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
