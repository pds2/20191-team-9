#include "ecommerce.h"

Ecommerce::Ecommerce(){
  inicio();
}

Ecommerce::~Ecommerce(){
  usuarios.clear();
  compradores.clear();
}

void Ecommerce::listaUsuarioArquivo(){
  usuarios.clear();
  compradores.clear();

  std::fstream arquivo;

  arquivo.open("usuarios.csv");

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

  while (arquivo.good()){

    std::string nome, email, senha, cpf, endereco;
    std::string numHistorico, numCarrinho, numAvaliacoes, dinheiro;
    int numH, numC, numA;
    float din;

    std::getline(arquivo, nome,',');
    std::getline(arquivo, email,',');
    std::getline(arquivo, senha,',');
    std::getline(arquivo, cpf,',');
    std::getline(arquivo, endereco,',');
    std::getline(arquivo, numCarrinho,',');
    std::getline(arquivo, numHistorico,',');
    std::getline(arquivo, numAvaliacoes,',');
    std::getline(arquivo, dinheiro,',');

    din = std::stof(dinheiro);
    numH = std::stoi(numHistorico);
    numC = std::stoi(numCarrinho);
    numA = std::stoi(numAvaliacoes);

    Comprador comp = Comprador(nome, email, senha, cpf, endereco, numC, numH, numA, din);
    Usuario usu = Usuario(nome, email, senha);
    usuarios.push_back(usu);
    compradores.push_back(comp);
  }
  imprimirCompradores();
  arquivo.close();
}

void Ecommerce::gravaUsuarioArquivo(){
  std::remove("usuarios.cvs");

  std::fstream arquivo;
  arquivo.open("usuarios.csv", std::ofstream::app);

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

  int numeroCompradores = compradores.size();
  for(int i=0; arquivo.good() && i < numeroCompradores; i++){
    arquivo << (compradores[i]).getNome() << "," << (compradores[i]).getEmail() << "," << (compradores[i]).getSenha() << "," << (compradores[i]).getCPF() << ","  << (compradores[i]).getEndereco() << "," << (compradores[i]).getNumeroComprasCarrinho() << "," << (compradores[i]).getNumeroComprasHistorico() << "," << (compradores[i]).getNumeroAvaliacoes() << "," << (compradores[i]).getDinheiro() << "\n";
  }

  arquivo.close();
}

void Ecommerce::cadastrarUsuario (std::string n, std::string em, std::string s){
  if(checaNome(n) && checaEmail(em) && checaSenha(s)){
    if(procurarUsuario(em)==false){
      Usuario usu = Usuario(n, em, s);
      usuarios.push_back(usu);
      std::cout << "Cadastro executado com sucesso!";
      loginUsuario();
    }
    else{
      std::cout << "Endereço de email já cadastrado. Tente novamente." << std::endl;
    }
  }
  else{
    std::cout << "Dados inválidos. Tente novamente." << std::endl;
  }
}

void Ecommerce::cadastrarComprador (std::string n, std::string em, std::string s, std::string cpf, std::string endereco, int numCarr, int numHist, int numAval, double din){
  if(checaNome(n) && checaEmail(em) && checaSenha(s)){
    if(procurarComprador(em)==false){
      Comprador comp = Comprador(n, em, s, cpf, endereco, numCarr, numHist, numAval, din);
      Usuario usu = Usuario(n, em, s);
      usuarios.push_back(usu);
      compradores.push_back(comp);
      gravaUsuarioArquivo();
      std::cout << "Cadastro executado com sucesso!";
      loginUsuario();
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
  if(numeroUsuarios>0){
    for(int i=0; i < numeroUsuarios; i++){
      std::cout << "\n" << "----------------------------------------------" << std::endl;
      std::cout << "\t\t Usuário " << i+1 << std::endl;
      std::cout << "----------------------------------------------" << "\n" << std::endl;
      std::cout << "Nome: " << (usuarios[i]).getNome() << std::endl;
      std::cout << "Email: " << (usuarios[i]).getEmail() << std::endl;
      std::cout << "Senha: " << (usuarios[i]).getSenha() << std::endl;
    }
  }
  else{
    std::cout << "Não há usuários cadastrados." << std::endl;
  }
}

void Ecommerce::imprimirCompradores(){
  limparTela();
  int numeroCompradores = compradores.size();
  if(numeroCompradores>0){
    for(int i=0; i < numeroCompradores-1; i++){
      std::cout << "\n" << "----------------------------------------------" << std::endl;
      std::cout << "\t\t Comprador " << i+1 << std::endl;
      std::cout << "----------------------------------------------" << "\n" << std::endl;
      std::cout << "Nome: " << (compradores[i]).getNome() << std::endl;
      std::cout << "Email: " << (compradores[i]).getEmail() << std::endl;
      std::cout << "Senha: " << (compradores[i]).getSenha() << std::endl;
      std::cout << "Cpf: " << (compradores[i]).getCPF() << std::endl;
      std::cout << "Endereço: " << (compradores[i]).getEndereco() << std::endl;
      std::cout << "Carrinho: " << (compradores[i]).getNumeroComprasCarrinho() << std::endl;
      std::cout << "Histórico: " << (compradores[i]).getNumeroComprasHistorico() << std::endl;
      std::cout << "Avaliações: " << (compradores[i]).getNumeroAvaliacoes() << std::endl;
      std::cout << "Dinheiro: " << (compradores[i]).getDinheiro() << std::endl;
    }
  }
  else{
    std::cout << "Não há compradores cadastrados." << std::endl;
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

bool Ecommerce::procurarComprador(std::string em){
  int numeroCompradores = compradores.size();
  for(int i=0; i < numeroCompradores; i++){
    std::cout << (compradores[i]).getEmail() << " " << em;
    if((compradores[i]).getEmail() == em){
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

bool checaSenhaAdmin(std::string sAdmin){
  return true;
}

void Ecommerce::limparTela(){
  std::system("clear||cls");
}

void Ecommerce::loginUsuario(){

  std::string nome, senha;
  std::cout << "Insira seu nome de usuário: ";
  std::cin >> name;
  limparTela();
  std::cout << std::endl << "Insira sua senha: ";
  std::cin >> senha;
  limparTela();

  int numeroUsuarios = usuarios.size();
  for(int i=0; i < numeroUsuarios; i++){
    if((usuarios[i]).getNome() == nome){
      if ((usuarios[i]).getSenha() == senha){
        *userLogged = usuarios[i];
      break;
      }
      else{
        std::cout << "Senha incorreta!"
        loginUsuario();
      }
    }
  }

  if (*userLogged = NULL){
    std::cout << "Nome de usuario nao encontrado!"
    loginUsuario();
  }
}

void Ecommerce::logoutUsuario(){
  *userLogged = NULL;
  inicio();
}

void Ecommerce::inicio(){
  int digito;
    std::cout << "Bem vindo à nossa loja!" << std::endl
    << "Se você já tem uma conta, digite 1" << std::endl
    << "Para se cadastrar, digite 2" << std::endl;
    std::cin >> digito;
    menuSumario(1, digito);
}

void Ecommerce::menuSumario(int idMenu, int opcao){

  switch (idMenu) {

    case 1:

      switch (opcao){
        case 1:
          loginUsuario();
          break;
        case 2:
          int op;
          std::cout << "Para se cadastrar como administrador, digite 1" << std::endl
          << "Para se cadastrar como comprador, digite 2" << std::endl
          std::cin >> op;
          menuSumario(2, op);
          break;
      }
      break;

    case 2:

      switch (opcao){
        case 1:
          std::string adminPass;
          std::cout << "Insira a senha de administrador: "
          std::cin << adminPass;
          limparTela();
          if(adminPass == SENHADMIN){
            std::string nome, senha, confSenha, email;
            std::cout << "Insira seu nome de usuário: ";
            std::cin >> name;
            limparTela();
            std::cout << std::endl << "Insira uma senha: ";
            std::cin >> senha;
            limparTela();
            std::cout << std::endl << "Confirme sua senha: ";
            std::cin >> confSenha;
            limparTela();
            std::cout << std::endl << "Insira seu email: ";
            std::cin >> email;
            limparTela();
            cadastrarUsuario(nome, email, senha);
          else{
            std::cout << "Senha de administrador incorreta!"
            menuSumario(2, 1);
          }
          break;
        case 2:
          std::string nome, senha, confSenha, email, endereco, cpf;
          std::cout << "Insira seu nome de usuário: ";
          std::cin >> name;
          limparTela();
          std::cout << std::endl << "Insira uma senha: ";
          std::cin >> senha;
          limparTela();
          std::cout << std::endl << "Confirme sua senha: ";
          std::cin >> confSenha;
          limparTela();
          std::cout << std::endl << "Insira seu email: ";
          std::cin >> email;
          limparTela();
          std::cout << std::endl << "Insira seu CPF: ";
          std::cin >> cpf;
          limparTela();
          std::cout << std::endl << "Insira seu endereco: ";
          std::cin >> endereco;
          limparTela();
          cadastrarComprador(nome, email, senha, cpf, endereco);
          break;
      }
      break;

    case 3:
      switch (opcao){
        case 1:
          limparTela();
          fazerCompras();
          break;
        case 2:
          limparTela();
          impCarrinho();
          break;
        case 3:
          limparTela();
          exibirPerfil();
          break;
      }
      break;

    case 4:
      switch (opcao){
        case 1:
          limparTela();
          //imprimirProdutos();
          break;
        case 2:
          limparTela();
          imprimirUsuarios();
          break;
        case 3:
          limparTela();
          //exibirPerfil();
          break;
        case 3:
          limparTela();
          mostraPedidos();
          break;
        case 4:
          limparTela();
          //imrprimirMensagens();
          break;
      }
      break;

    case 5: //admin produtos, usuarios, verprodutos

      switch (opcao){
        case 1:
          break;
        case 2:
          break;
      }
      break;
  }
}
