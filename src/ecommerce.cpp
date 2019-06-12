#ifndef ECOMMERCE_CPP
#define ECOMMERCE_CPP

#include "ecommerce.h"

Ecommerce::Ecommerce(){
  //inicio();
}

Ecommerce::~Ecommerce(){
  usuarios.clear();
  compradores.clear();
  produtos.clear();
}


int Ecommerce::tamanhoArquivo(const char* file_name){
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

bool Ecommerce::checaCodigo(int cod){
    int x = produtos.size();
    int aux;

    for (aux = 0; aux < x; aux++){
        if(produtos[aux].getCodigoProduto()== cod){
            return false;
        }
    }

    return true;
}

void Ecommerce::cadastrarCaneca(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, float diametro){
    if (checaCodigo(cod)){
        Caneca can(cod, preco, mediaAvaliacoes, nome, "Canecas", cor, descricao, material, diametro);
        Produto prod(cod, preco, mediaAvaliacoes, nome, "Canecas", cor, descricao, material);
        canecas.push_back(can);
        produtos.push_back(prod);
    } else {
        std::cout << "Codigo de produto ja cadastrado. Tente novamente." << std::endl;
    }
}

void Ecommerce::cadastrarAcessorio(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, std::string tipo){
    if(checaCodigo(cod)){
        Acessorio ac(cod, preco, mediaAvaliacoes, nome, "Acessorios", cor, descricao, material, tipo);
        Produto prod(cod, preco, mediaAvaliacoes, nome, "Acessorios", cor, descricao, material);
        acessorios.push_back(ac);
        produtos.push_back(prod);
    } else {
        std::cout << "Codigo de produto ja cadastrado. Tente novamente." << std::endl;
    }
}

void Ecommerce::cadastrarBlusasEMoletom(int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, char tamanho, std::string tipo){
    if(checaCodigo(cod)){
        BlusasEMoletom b(cod, preco, mediaAvaliacoes, nome, "Blusas e Moletons", cor, descricao, material, tamanho, tipo);
        Produto prod(cod, preco, mediaAvaliacoes, nome, "Blusas e Moletons", cor, descricao, material);
        blusasEmoletons.push_back(b);
        produtos.push_back(prod);
    } else {
        std::cout << "Codigo de produto ja cadastrado. Tente novamente." << std::endl;
    }
}


void Ecommerce::listaProdutosArquivo(){
  produtos.clear();

  std::fstream arquivo;
  arquivo.open("produtos.csv",std::ios::in);

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

int linhas = tamanhoArquivo("produtos.csv");
  if (tamanhoArquivo("produtos.csv") == 0){
    std::cout << "Ainda nao ha nenhum produto cadastrado." << std::endl;
    return;
  }

  while (arquivo.good()){
    int cod;
    std::string nome, categoria, cor, descricao, material;
    float preco, mediaAvaliacoes;

    std::string codigoS, precoS, mediaS;

    std::getline(arquivo, codigoS,',');
    std::getline(arquivo, nome,',');
    std::getline(arquivo, precoS,',');
    std::getline(arquivo, mediaS,',');
    std::getline(arquivo, categoria,',');
    std::getline(arquivo, cor,',');
    std::getline(arquivo, descricao,',');
    std::getline(arquivo, material,',');

    if (codigoS == ""){
        break;
    }

    std::istringstream iss(codigoS);
    cod = std::stoi(codigoS);
    preco = std::stof(precoS);
    mediaAvaliacoes = std::stof(mediaS);

    if (categoria == "Acessorios"){
      std::string tipo;
      std::getline(arquivo, tipo);

      Acessorio ac(cod, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material, tipo);
      acessorios.push_back(ac);

    }

    if (categoria == "Canecas"){
      float diametro;
      std::string diametroS;
      std::getline(arquivo, diametroS);

      diametro = std::stof(diametroS);
      Caneca can(cod, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material, diametro);
      canecas.push_back(can);

    }

    if (categoria == "Blusas e Moletons"){
      char tamanho;
      std::string tp, tam;

      std::getline(arquivo, tam,',');
      std::getline(arquivo, tp);

      tamanho = tam[0];
      BlusasEMoletom bM(cod, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material, tamanho, tp);
      blusasEmoletons.push_back(bM);
    }

    Produto prod(cod, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material);
    produtos.push_back(prod);
    }
  arquivo.close();
}

void Ecommerce::imprimirProdutos(){
    int x = produtos.size();
    int aux, c, i;
    for(aux = 0; aux < x; aux++){

        if (produtos[aux].getCategoria()=="Canecas"){
            c = produtos[aux].getCodigoProduto();
            i = buscaIndiceCaneca(c);
            canecas[i].imprimeProduto();
        }
        if (produtos[aux].getCategoria()=="Blusas e Moletons"){
            c = produtos[aux].getCodigoProduto();
            i = buscaIndiceBlusasEMoletom(c);
            blusasEmoletons[i].imprimeProduto();
        }
        if (produtos[aux].getCategoria()=="Acessorios"){
            c = produtos[aux].getCodigoProduto();
            i = buscaIndiceAcessorio(c);
            acessorios[i].imprimeProduto();
        }
        std::cout << "Codigo do Produto:\t" << produtos[aux].getCodigoProduto() << std::endl;
        }
}

int Ecommerce::buscaIndiceCaneca(int cod){
    int x;
    for(x = 0; x < canecas.size(); x++){
        if(canecas[x].getCodigoProduto() == cod){
            return x;
        }
    }
    return -1;
}

int Ecommerce::buscaIndiceBlusasEMoletom(int cod){
    int x;
    for(x = 0; x < blusasEmoletons.size(); x++){
        if(blusasEmoletons[x].getCodigoProduto() == cod){
            return x;
        }
    }
    return -1;
}

int Ecommerce::buscaIndiceAcessorio(int cod){
    int x;
    for(x = 0; x < acessorios.size(); x++){
        if(acessorios[x].getCodigoProduto() == cod){
            return x;
        }
    }
    return -1;
}

int Ecommerce::buscaIndiceProdutos(int cod){
    int x;
    for(x = 0; x < produtos.size(); x++){
        if(produtos[x].getCodigoProduto() == cod){
            return x;
        }
    }
    return -1;
}


void Ecommerce::gravaProdutosArquivo(){
  std::remove("produtos.csv");

  std::fstream arquivo;
  arquivo.open("produtos.csv", std::ofstream::app);

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

  int numeroProdutos = produtos.size();

  for(int i=0; arquivo.good() && i < numeroProdutos; i++){

     //if(checaCodigo(produtos[i].getCodigoProduto())){
        arquivo << (produtos[i]).getCodigoProduto() << "," << (produtos[i]).getNome() << "," << (produtos[i]).getPreco() << "," << (produtos[i]).getMediaAvaliacoes() << "," << (produtos[i]).getCategoria() << ","  << (produtos[i]).getCor() << "," << (produtos[i]).getDescricao() << "," << (produtos[i]).getMaterial() << ",";
        int x = 0;
        if (produtos[i].getCategoria()=="Acessorios"){
            int x = produtos[i].getCodigoProduto();
            int i = buscaIndiceAcessorio(x);
            if(i != -1){
                   arquivo << (acessorios[i]).getTipo() << std::endl;
             } else {
                std::cout << "Erro. Tente novamente." << std::endl;
                }
        }
        if (produtos[i].getCategoria()=="Blusas e Moletons"){
            int x = produtos[i].getCodigoProduto();
            int i = buscaIndiceBlusasEMoletom(x);
            if(i != -1){
                   arquivo << (blusasEmoletons[i]).getTamanho() << "," << (blusasEmoletons[i]).getTipo() << std::endl;
             } else {
                std::cout << "Erro. Tente novamente." << std::endl;
                }
        }
        if (produtos[i].getCategoria()=="Canecas"){
          int x = produtos[i].getCodigoProduto();
          int i = buscaIndiceCaneca(x);
          if(i != -1){
                arquivo << (canecas[i]).getDiametro() << std::endl;
              } else {
                std::cout << "Erro. Tente novamente." << std::endl;
                }
        }
    //}
  }
  arquivo.close();
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
    std::string numHistoricoS, numCarrinhoS, numAvaliacoesS, dinheiroS;
    int numH, numC, numA;
    float din;

    std::getline(arquivo, nome,',');
    std::getline(arquivo, email,',');
    std::getline(arquivo, senha,',');
    std::getline(arquivo, cpf,',');
    std::getline(arquivo, endereco,',');
    std::getline(arquivo, numCarrinhoS,',');
    std::getline(arquivo, numHistoricoS,',');
    std::getline(arquivo, numAvaliacoesS,',');
    std::getline(arquivo, dinheiroS,',');

    std::istringstream iss1(numHistoricoS);
    numH = std::stoi(numHistoricoS);
    std::istringstream iss2(numCarrinhoS);
    numC = std::stoi(numCarrinhoS);
    std::istringstream iss3(numAvaliacoesS);
    numA = std::stoi(numAvaliacoesS);

    din = std::stof(dinheiroS);

    Comprador comp = Comprador(nome, email, senha, cpf, endereco, numC, numH, numA, din);
    Usuario usu = Usuario(nome, email, senha);
    usuarios.push_back(usu);
    compradores.push_back(comp);
  }
  imprimirCompradores();
  arquivo.close();
}

void Ecommerce::gravaUsuarioArquivo(){
  std::remove("usuarios.csv");

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
      //loginUsuario();
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
      std::cout << "Cadastro executado com sucesso!" << std::endl;
      //loginUsuario();
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
  std::string email, senha;
  std::cout << "Insira seu email: ";
  std::cin >> email;
  std::cout << std::endl << "Insira sua senha: ";
  std::cin >> senha;
  limparTela();

  int numeroUsuarios = usuarios.size();
  for(int i=0; i < numeroUsuarios; i++){
    if((usuarios[i]).getEmail() == email){
      if ((usuarios[i]).getSenha() == senha){
        *userLogged = usuarios[i];
      break;
      }
      else{
        std::cout << "Senha incorreta!"<< std::endl;        //loginUsuario();
      }
    }
  }

  if (userLogged == nullptr){
    std::cout << "Email nao encontrado!" << std::endl;      //loginUsuario();
  }
}

void Ecommerce::logoutUsuario(){
  userLogged = nullptr;
  inicio();
}

void Ecommerce::inicio(){
  int digito;
  limparTela();

  std::cout << "\n" << "-------------------------------------------------------------" << std::endl;
  std::cout << "\t\t Bem vindo à nossa loja!" << std::endl;
  std::cout << "-------------------------------------------------------------" << "\n" << std::endl;

  std::cout << "1 - Já possuo uma conta." << std::endl;
  std::cout << "2 - Desejo me cadastrar." << std::endl;
  std::cout << "\nEscolha uma opção: ";
  std::cin >> digito;
  menuSumario(1, digito);
}

void Ecommerce::menuSumario(int idMenu, int opcao){

  switch (idMenu) {

    case 1:
    {
      switch (opcao){
        case 1:
          //loginUsuario();
          break;
        case 2:
          int op;
          std::cout << "Para se cadastrar como administrador, digite 1" << "\n" << "Para se cadastrar como comprador, digite 2" << std::endl;
          std::cin >> op;
          menuSumario(2, op);
          break;
      }
      break;

    }

    case 2:
    {
      switch (opcao){
        case 1:
          {
            std::string adminPass;
            std::cout << "Insira a senha de administrador: ";
            std::cin >> adminPass;
            limparTela();
            if(adminPass == SENHADMIN){
              std::string nome, senha, confSenha, email;
              std::cout << "Insira seu nome de usuário: ";
              std::cin >> nome;
              std::cout << std::endl << "Insira uma senha: ";
              std::cin >> senha;
              std::cout << std::endl << "Confirme sua senha: ";
              std::cin >> confSenha;
              std::cout << std::endl << "Insira seu email: ";
              std::cin >> email;
              limparTela();
              cadastrarUsuario(nome, email, senha);
            }
            else{
              std::cout << "Senha de administrador incorreta!";
              menuSumario(2, 1);
            }
            break;
          }
        case 2:
            std::string nome, senha, confSenha, email, endereco, cpf;
            std::cout << "Insira seu nome de usuário: ";
            std::cin >> nome;
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
            cadastrarComprador(nome, email, senha, cpf, endereco, 0, 0, 0, 0);
            break;
      }
      break;
    }

    case 3:
    {
      switch (opcao){
        case 1:
          limparTela();
          //fazerCompras();
          break;
        case 2:
          limparTela();
          impCarrinho();
          break;
        case 3:
          limparTela();
          //exibirPerfil();
          break;
      }
      break;
    }

    case 4:
      {
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
          case 4:
            limparTela();
            //mostraPedidos(); aqui insere a listagem de produtos
            break;
          case 5:
            limparTela();
            //imrprimirMensagens();
            break;
        }
        break;
      }

    case 5: //admin produtos, usuarios, verprodutos
      {
          switch (opcao){
            case 1:
              break;
            case 2:
              break;
          }
          break;
      }
  }
}
#endif
