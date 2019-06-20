#ifndef ECOMMERCE_CPP
#define ECOMMERCE_CPP

#include "ecommerce.h"
#include "excecoes.h"

Administrador admin;
admin.Administrador();

/**
 * [Ecommerce::Ecommerce Construtor da classe Ecommerce]
 * @method Ecommerce::Ecommerce
 */

Ecommerce::Ecommerce(){
  limparTela();
}

/**
 * [Ecommerce Destrutor da classe Ecommerce]
 * @method Ecommerce
 */

Ecommerce::~Ecommerce(){
  usuarios.clear();
  compradores.clear();
  produtos.clear();
}

/**
 * [Ecommerce::listaComentariosArquivo função que lista os comentários de cada produto registrados no arquivo]
 * @method Ecommerce::listaComentariosArquivo
 */

void Ecommerce::listaComentariosArquivo(){
  produtos.clear();

  std::fstream arquivo;
  arquivo.open("comentarios.csv",std::ios::in);

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

    int linhas = tamanhoArquivo("comentarios.csv");
      if (tamanhoArquivo("comentarios.csv") == 0){
        std::cout << "Nenhum comentario foi feito ainda." << std::endl;
        return;
      }

      while (arquivo.good()){
        int cod, num;
        std::vector<std::string> coments;

        std::string codigoS, numS, cmt;

        std::getline(arquivo, codigoS,',');
        std::getline(arquivo, numS, ',');

        if (codigoS == ""){
            break;
        }

        cod = std::stoi(codigoS);
        num = std::stoi(numS);

        std::cout << "Codigo e numero de comentarios = " << cod << " " << num << std::endl;

            if (num == 0){
                std::cout << "Esse produto nao recebeu nenhum comentario ainda." << std::endl;
            }
            else{
                int aux;
                for(aux=0; aux<num-1; aux++){
                    std::getline(arquivo, cmt,',');

                    std::cout << "Comentario " << aux << " = "  << cmt << std::endl;

                    adicionarComentario(cod, cmt);
                }
                std::getline(arquivo, cmt);

                adicionarComentario(cod, cmt);
            }
        }
  arquivo.close();
}

/**
 * [Ecommerce::gravaComentariosArquivo função que registra os comentários de cada produto no arquivo]
 * @method Ecommerce::gravaComentariosArquivo
 */

void Ecommerce::gravaComentariosArquivo(){
  std::remove("comentarios.cvs");

  std::fstream arquivo;
  arquivo.open("comentarios.csv", std::ofstream::app);

  if (!arquivo.is_open()){
    std::cout << "Erro ao abrir arquivo. Tente novamente";
    exit(1);
  }

  int numeroProdutos = produtos.size();

  for(int i=0; arquivo.good() && i < numeroProdutos; i++){

        arquivo << (produtos[i]).getCodigoProduto() << ",";

        int n = produtos[i].retornaNumComentarios();

        arquivo << n << ",";
        if (n == 0){ //Arquivo não possui comentarios
            arquivo << "0" << std::endl;
        } else{
            int aux;
            for(aux=0; aux < n-1; aux++){
               arquivo << "\"" << produtos[i]._comentarios[aux] << "\"" << ",";
            }

            arquivo << "\"" << produtos[i]._comentarios[aux] << "\"" << "\n";
        }
  }
  arquivo.close();
}

/**
 * [Ecommerce::adicionarComentario função que registra um comentário para um produto específico]
 * @method Ecommerce::adicionarComentario
 * @param  cod                           [código único que representa o produto]
 * @param  coment                        [comentário a ser registrado para o produto]
 */

void Ecommerce::adicionarComentario(long int cod, std::string coment){
    int x = buscaIndiceProdutos(cod);
    if ( x != -1){
    produtos[x].setComentario(coment);
    }
}

/**
 * [Ecommerce::tamanhoArquivo função que registra o tamanho do arquivo a ser lido]
 * @method Ecommerce::tamanhoArquivo
 * @param  file_name                 [nome do arquivo a ser lido]
 * @return                           [quantidade de linhas do arquivo lido]
 */

int Ecommerce::tamanhoArquivo(const char* file_name){
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}

/**
 * [Ecommerce::geradorCod função que gera codigos aleatorios para novos produto]
 * @method Ecommerce::geradorCod
 * @return                           [codigo de ate oito digitos]
 */

long int Ecommerce::geradorCod(){
  long int codProduto;
  srand(time(0));
  do {
    codProduto = rand()%99999999;
  } while(!checaCodigo(codProduto));
  return codProduto;
}

/**
 * [Ecommerce::checaCodigo função que checa se o codigo gerado para um produto já existe]
 * @method Ecommerce::checaCodigo
 * @param  cod                       [codigo gerado]
 * @return                           [false se o codigo ja existia, true se o codigo não existia]
 */

bool Ecommerce::checaCodigo(long int cod){
    int x = produtos.size();
    int aux;

    for (aux = 0; aux < x; aux++){
        if(produtos[aux].getCodigoProduto()== cod){
            return false;
        }
    }

    return true;
}

void Ecommerce::cadastrarCaneca(long int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, float diametro){
    if (checaCodigo(cod)){
        Caneca can(cod, preco, mediaAvaliacoes, nome, "Canecas", cor, descricao, material, diametro);
        Produto prod(cod, preco, mediaAvaliacoes, nome, "Canecas", cor, descricao, material);
        canecas.push_back(can);
        produtos.push_back(prod);
        std::cout << "Produto cadastrado com sucesso!" << std::endl;

    } else {
        Exception_Codigo_Ja_Registrado CJR;
        throw CJR;
    }
}

void Ecommerce::cadastrarAcessorio(long int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, std::string tipo){
    if(checaCodigo(cod)){
        Acessorio ac(cod, preco, mediaAvaliacoes, nome, "Acessorios", cor, descricao, material, tipo);
        Produto prod(cod, preco, mediaAvaliacoes, nome, "Acessorios", cor, descricao, material);
        acessorios.push_back(ac);
        produtos.push_back(prod);
        std::cout << "Produto cadastrado com sucesso!" << std::endl;

    } else {
        Exception_Codigo_Ja_Registrado CJR;
        throw CJR;
    }
}

void Ecommerce::cadastrarBlusasEMoletom(long int cod, float preco, float mediaAvaliacoes, std::string nome, std::string cor, std::string descricao, std::string material, char tamanho, std::string tipo){
    if(checaCodigo(cod)){
        BlusasEMoletom b(cod, preco, mediaAvaliacoes, nome, "Blusas e Moletons", cor, descricao, material, tamanho, tipo);
        Produto prod(cod, preco, mediaAvaliacoes, nome, "Blusas e Moletons", cor, descricao, material);
        blusasEmoletons.push_back(b);
        produtos.push_back(prod);
        std::cout << "Produto cadastrado com sucesso!" << std::endl;

    } else {
        Exception_Codigo_Ja_Registrado CJR;
        throw CJR;
    }
}

void Ecommerce::listaProdutosArquivo(){
  produtos.clear();

  std::fstream arquivo;
  arquivo.open("produtos.csv",std::ios::in);

  if (!arquivo.is_open()){
    Exception_Erro_Abrir_Arquivo EAA;
    throw EAA;
  }

  int linhas = tamanhoArquivo("produtos.csv");
  if (tamanhoArquivo("produtos.csv") == 0){
    Exception_Nenhum_Produto_Arquivo NPA;
    throw NPA;
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

int Ecommerce::buscaIndiceCaneca(long int cod){
    int x;
    for(x = 0; x < canecas.size(); x++){
        if(canecas[x].getCodigoProduto() == cod){
            return x;
        }
    }
    return -1;
}

int Ecommerce::buscaIndiceBlusasEMoletom(long int cod){
    int x;
    for(x = 0; x < blusasEmoletons.size(); x++){
        if(blusasEmoletons[x].getCodigoProduto() == cod){
            return x;
        }
    }
    return -1;
}

int Ecommerce::buscaIndiceAcessorio(long int cod){
    int x;
    for(x = 0; x < acessorios.size(); x++){
        if(acessorios[x].getCodigoProduto() == cod){
            return x;
        }
    }
    return -1;
}

int Ecommerce::buscaIndiceProdutos(long int cod){
    int x;
    for(x = 0; x < produtos.size(); x++){
        if(produtos[x].getCodigoProduto() == cod){
            return x;
        }
    }
    return -1;
}

Produto Ecommerce::buscaProdutos(long int cod){
  int x, codigo;
  std::string nome, categoria, cor, descricao, material;
  float preco, mediaAvaliacoes;
  for(x = 0; x < produtos.size(); x++){
    if(produtos[x].getCodigoProduto() == cod){
      codigo = (produtos[x]).getCodigoProduto();
      nome = (produtos[x]).getNome();
      categoria = (produtos[x]).getCategoria();
      cor = (produtos[x]).getCor();
      descricao = (produtos[x]).getDescricao();
      material = (produtos[x]).getMaterial();
      preco = (produtos[x]).getPreco();
      mediaAvaliacoes = (produtos[x]).getMediaAvaliacoes();
    }
  }

  Produto prod = Produto(codigo, preco, mediaAvaliacoes, nome, categoria, cor, descricao, material);
  return prod;
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

/**
 * [Ecommerce::listaUsuarioArquivo função que lista os usuários registrados no arquivo]
 * @method Ecommerce::listaUsuarioArquivo
 */

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
    float din=0.0;

    std::getline(arquivo, nome,',');
    std::getline(arquivo, email,',');
    std::getline(arquivo, senha,',');
    std::getline(arquivo, cpf,',');
    std::getline(arquivo, endereco,',');
    std::getline(arquivo, numCarrinhoS,',');
    std::getline(arquivo, numHistoricoS,',');
    std::getline(arquivo, numAvaliacoesS,',');
    std::getline(arquivo, dinheiroS);

    if(email==""){
      break;
    }

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
  arquivo.close();
}

/**
 * [Ecommerce::gravaUsuarioArquivo função que grava os usuários do vector no arquivo]
 * @method Ecommerce::gravaUsuarioArquivo
 */

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

/**
 * [Ecommerce::cadastrarComprador  função que cadastra um comprador, considerando as informações dadas na hora do registro do mesmo, e adicionando-o ao vector de usuarios]
 * @method Ecommerce::cadastrarComprador
 * @param  n                             [nome do comprador]
 * @param  em                            [email do comprador]
 * @param  s                             [senha do comprador]
 * @param  cpf                           [cpf do comprador]
 * @param  endereco                      [endereco do comprador]
 * @param  numCarr                       [numero de itens no carrinho do comprador]
 * @param  numHist                       [numero de itens no histórico do comprador]
 * @param  numAval                       [numero de avaliações realizadas pelo comprador]
 * @param  din                           [quantidade de dinheiro que o comprador possui]
 */

void Ecommerce::cadastrarComprador (std::string n, std::string em, std::string s, std::string cpf, std::string endereco, int numCarr, int numHist, int numAval, double din){
  limparTela();
  listaUsuarioArquivo();
  if(checaNome(n) && checaEmail(em) && checaSenha(s)){
    if(procurarComprador(em)==false){
      Comprador comp = Comprador(n, em, s, cpf, endereco, numCarr, numHist, numAval, din);
      Usuario usu = Usuario(n, em, s);
      usuarios.push_back(usu);
      compradores.push_back(comp);
      gravaUsuarioArquivo();
      std::cout << "Cadastro executado com sucesso!" << std::endl;
      comp.imprimirHistorico();
     }
     else{
      std::cout << "Endereço de email já cadastrado. Tente novamente." << std::endl;
     }
  }
  else{
    std::cout << "Dados inválidos. Tente novamente." << std::endl;
  }
}

/**
 * [Ecommerce::imprimirUsuarios função que imprime os usuários cadastrados no ecommerce]
 * @method Ecommerce::imprimirUsuarios
 */

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

/**
 * [Ecommerce::imprimirCompradores função que imprime os usuários do tipo comprador cadastrados no ecommerce]
 * @method Ecommerce::imprimirCompradores
 */

void Ecommerce::imprimirCompradores(){
  limparTela();
  int numeroCompradores = compradores.size();

  listaUsuarioArquivo();
  if(numeroCompradores>0){
    for(int i=0; i < numeroCompradores; i++){
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

/**
 * [Ecommerce::geradorCod função que adiciona produtos no carrinho do usuario e retorna a pagina anterior]
 * @method Ecommerce::geradorCod
 */

void Ecommerce::addCarrinho(){
  procurarCompradorObj(userLogged).adicionarCarrinho();
  impProdutos();
}

/**
 * [Ecommerce::impProdutos função que cria um menu de opçoes para compradores na pagina de produtos]
 * @method Ecommerce::impProdutos
 */

void Ecommerce::impProdutos(){
  limparTela();
  imprimirProdutos();
  std::cout << "Para ver comentarios sobre um produto, digite 1" << std::endl;
  std::cout << "Para adicionar um produto ao carrinho, digite 2" << std::endl;
  std::cout << "Para voltar ao menu, digite 3" << std::endl;
  int digito;
  std::cin >> digito;
  int codProduto;
  switch (digito) {
    case 1:
    {
      std::cout << "\n" << "Digite o código do produto: ";
      std::cin >> codProduto;
      Produto prod = buscaProdutos(codProduto);
      prod.getComentarios();
      std::cout << std::endl << "Pressione ENTER para voltar a pagina anterior";
      std::cin.get();
      std::cin.get();
      menuComprador();
      impProdutos();
      break;
    }
    case 2:
    {
      std::cout << "\n" << "Digite o código do produto que deseja adicionar ao seu carrinho: ";
      std::cin >> codProduto;
      addCarrinho();
      std::cout << std::endl << "Pressione ENTER para voltar a pagina anterior";
      std::cin.get();
      std::cin.get();
      menuComprador();
      impProdutos();
      break;
    }
    case 3:
    {
      menuComprador();
      break;
    }
    default:
    {
      std::cout << "Opção inválida. Tente novamente" << std::endl;
      std::cin.get();
      std::cin.get();
      impProdutos();
    }
      break;
  }
}

/**
 * [Ecommerce::impCarrinho função que cria um menu de opçoes para compradores na pagina do carrinho]
 * @method Ecommerce::impCarrinho
 */

void Ecommerce::impCarrinho(){
  limparTela();
  procurarCompradorObj(userLogged).imprimirCarrinho();
  std::cout << "Para procurar um item, digite 1" << std::endl
  << "Para remover um item, digite 2" << std::endl
  << "Para finalizar a compra, digite 3" << std::endl
  << "Para voltar ao menu, digite 4" << std::endl;
  int digito;
  std::cin >> digito;
  while((digito != 1) && (digito != 2) && (digito != 3)){
    std::cout << "Essa opcao nao existe! Digite um numero valido: ";
    std::cin >> digito;
  }

  switch (digito) {
    case 1:
    {
      int cod;
      std::cout << "Digite o codigo do produto que voce procura: ";
      std::cin >> cod;
      Produto prod = procurarCompradorObj(userLogged).buscaCarrinho(cod);
      prod.imprimeProduto();
      std::cout << std::endl << "Pressione ENTER para voltar a pagina anterior";
      std::cin.get();
      std::cin.get();
      impCarrinho();
      break;
    }
    case 2:
    {
      int cod;
      std::cout << "Digite o codigo do produto que voce deseja remover: ";
      std::cin >> cod;
      procurarCompradorObj(userLogged).retirarCarrinho(cod);
      std::cout << std::endl << "Pressione ENTER para voltar a pagina anterior";
      std::cin.get();
      std::cin.get();
      impCarrinho();
    }
    case 3:
    {
      procurarCompradorObj(userLogged).fazerCompras();
      std::cout << std::endl << "Pressione ENTER para voltar a pagina anterior";
      std::cin.get();
      std::cin.get();
      impCarrinho();
      break;
    }
    case 4:
    {
      menuComprador();
      break;
    }
  }
}

/**
 * [Ecommerce::impHistorico função que cria um menu de opçoes para compradores na pagina do historico]
 * @method Ecommerce::impHistorico
 */

void Ecommerce::impHistorico(){
  procurarCompradorObj(userLogged).imprimirHistorico();
  std::cout << "Para procurar um item, digite 1" << std::endl
  << "Para avaliar um item, digite 2" << std::endl
  << "Para comentar um item, digite 3" << std::endl
  << "Para voltar ao menu, digite 4" << std::endl;
  int digito;
  std::cin >> digito;
  while((digito != 1) && (digito != 2) && (digito != 3) && (digito != 4)) {
    std::cout << "Essa opcao nao existe! Digite um numero valido: ";
    std::cin >> digito;
  }
  switch (digito) {
    case 1:
      int cod;
      std::cout << "Digite o codigo do produto que voce procura: ";
      std::cin >> cod;
      procurarCompradorObj(userLogged).procurarItensHistorico(cod);
      break;
    case 2:
      procurarCompradorObj(userLogged).avaliarItem();
      break;
    case 3:
      procurarCompradorObj(userLogged).adicionarComentario();
      break;
    case 4:
      menuComprador();
      break;
  }
}

/**
 * [Ecommerce::mostraProdutos função que cria um menu de opçoes para o administrador na pagina de produtos]
 * @method Ecommerce::mostraProdutos
 */

void Ecommerce::mostraProdutos(){
  limparTela();
  imprimirProdutos();
  std::cout << "Para ver comentarios sobre um produto, digite 1" << std::endl;
  std::cout << "Para adicionar um produto, digite 2" << std::endl;
  std::cout << "Para excluir um produto, digite 3" << std::endl;
  std::cout << "Para voltar ao menu, digite 4" << std::endl;
  int digito;
  std::cin >> digito;
  switch (digito) {
    case 1:
    {
      int codProduto;
      std::cout << "\n" << "Digite o código do produto: ";
      std::cin >> codProduto;
      Produto prod = buscaProdutos(codProduto);
      prod.getComentarios();
      std::cout << std::endl << "Pressione ENTER para voltar a pagina anterior";
      std::cin.get();
      std::cin.get();
      mostraProdutos();
      break;
    }
    case 2:
    {
      dadosProduto();
      break;
    }
    case 3:
    {
      std::string nomeProduto;
      std::cout << "\n" << "Digite o nome do produto que deseja remover: ";
      std::cin >> nomeProduto;
      admin.removeItem(nomeProduto);
      break;
    }
    case 4:
    {
      menuUsuario();
      break;
    }
    default:
      {
      std::cout << "Opção inválida. Tente novamente" << std::endl;

      break;
    }
  }
}

/**
 * [Ecommerce::mostraUsuarios função que cria um menu de opçoes para o administrador na pagina de usuarios]
 * @method Ecommerce::mostraUsuarios
 */

void Ecommerce::mostraUsuarios(){
  limparTela();
  imprimirUsuarios();
  std::cout << "Para excluir um usuario, digite 1" << std::endl;
  std::cout << "Para voltar ao menu, digite 9" << std::endl;
  int digito;
  std::cin >> digito;
  switch (digito) {
    case 1:
    {
      std::string emUsuario;
      std::cout << "\n" << "Digite o email do usuário que deseja remover: ";
      std::cin >> emUsuario;
      admin.excluiUsuario(emUsuario);    
      break;
    }
    case 9:
    {
      menuUsuario();
      break;
    }
    default:
      {
      std::cout << "Opção inválida. Tente novamente" << std::endl;

      break;
    }
  }
}

/**
 * [Ecommerce::procurarUsuario função que procura um usuário dado o email do mesmo]
 * @method Ecommerce::procurarUsuario
 * @param  em                         [email do usuário]
 * @return                            [true se o usuário for encontrado e false, em caso contrário]
 */

bool Ecommerce::procurarUsuario(std::string em){
  int numeroUsuarios = usuarios.size();
  for(int i=0; i < numeroUsuarios; i++){
    if((usuarios[i]).getEmail() == em){
      return true;
    }
  }
  return false;
}

/**
 * [Ecommerce::procurarComprador função que procura um comprador dado o email do mesmo]
 * @method Ecommerce::procurarComprador
 * @param  em                           [email do comprador]
 * @return                              [true se o comprador for encontrado e false, em caso contrário]
 */

bool Ecommerce::procurarComprador(std::string em){
  int numeroCompradores = compradores.size();
  for(int i=0; i < numeroCompradores; i++){
    if((compradores[i]).getEmail() == em){
      return true;
    }
  }
  return false;
}

Comprador Ecommerce::procurarCompradorObj(std::string em){
  int x, numeroComprasCarrinho, numeroComprasHistorico, numeroAvaliacoes;
  std::string nome, email, senha, cpf, endereco;
  float dinheiro;
  for(x = 0; x < produtos.size(); x++){
    if(compradores[x].getEmail() == em){
      nome = (compradores[x]).getNome();
      email = (compradores[x]).getEmail();
      senha = (compradores[x]).getSenha();
      endereco = (compradores[x]).getEndereco();
      cpf = (compradores[x]).getCPF();
      numeroComprasCarrinho = (compradores[x]).getNumeroComprasCarrinho();
      numeroComprasHistorico = (compradores[x]).getNumeroComprasHistorico();
      numeroAvaliacoes = (compradores[x]).getNumeroAvaliacoes();
      dinheiro = (compradores[x]).getDinheiro();
    }
  }

  Comprador comp = Comprador(nome, email, senha, cpf, endereco, numeroComprasCarrinho, numeroComprasHistorico, numeroAvaliacoes, dinheiro);
  return comp;
}

/**
 * [Ecommerce::checaEmail função que checa se o email fornecido possui o formato aceito]
 * @method Ecommerce::checaEmail
 * @param  em                    [email fornecido]
 * @return                       [true se o formato do email fornecido for correto e false, em caso contrário]
 */

bool Ecommerce::checaEmail(const char *em){
  int i, em_size;
  bool arroba = false, dotcom = false; 
  em_size = strlen(em);
  for(i = 0; i < em_size - 3; i++){
    if(em[i] == 64){ // after this interval we have the ASCII numbers
      arroba = true;
    }
    if((em[i] == 46) && (em[i+1] == 99) && (em[i+2] == 111) && (em[i+3] == 109)){
      dotcom = true;
    }
  }
  return arroba + dotcom;
}

/**
 * [Ecommerce::validaAlfanumerica função que checa se a senha e o nome fornecidos possuem o formato aceito]
 * @method Ecommerce::validaAlfanumerica
 * @param  s                     [string fornecida]
 * @return                       [true se o formato da senha fornecida for correto e false, em caso contrário]
 */

bool Ecommerce::validaAlfanumerica(const char *s){
  int i, s_size, aux;
  s_size = strlen(s);
  for(i = 0; i < s_size; i++){
    aux = s[i];
    if((aux >= 0) && (aux <= 47)){ // after this interval we have the ASCII numbers
      return false;
    }else if((aux >= 58) && (aux <= 64)){ // after this interval we have ASCII capital letters
      return false;
    }else if((aux >= 91) && (aux <= 96)){ // after this interval we have ASCII letters
      return false;
    }else if((aux >= 123) && (aux <= 127)){ // the rest of ASCII
      return false;
    }
  }
  return true;
}

/**
 * [Ecommerce::limparTela função que limpa a tela do ecommerce]
 * @method Ecommerce::limparTela
 */

void Ecommerce::limparTela(){
  std::system("clear||cls");
}

/*_____*
 * [Ecommerce::tamanhoArquivo função que registra o tamanho do arquivo a ser lido]
 * @method Ecommerce::tamanhoArquivo
 * @param  file_name                 [nome do arquivo a ser lido]
 * @return                           [quantidade de linhas do arquivo lido]
 */

void Ecommerce::loginUsuario(){
  limparTela();
  std::string email, senha;
  std::cout << "Insira seu email: ";
  std::cin >> email;
  std::cout << std::endl << "Insira sua senha: ";
  std::cin >> senha;
  limparTela();

  if(email == "adminl@gmail.com"){
    if (senha == "123tasalvo"){
      userLogged = email;
      menuUsuario();
    }
    else {
      std::cout << "Senha incorreta!"<< std::endl;
      std::cin.get();
      std::cin.get();
      inicio();
    }
  }
  else{
    int numeroUsuarios = usuarios.size();
    for(int i=0; i < numeroUsuarios; i++){
      if((usuarios[i]).getEmail() == email){
        if ((usuarios[i]).getSenha() == senha){
          userLogged = email;
          menuComprador();
        break;
        }
        else{
          std::cout << "Senha incorreta!"<< std::endl;
          std::cin.get();
          std::cin.get();
          inicio();
        }
      }
    }
  }

  if (userLogged == ""){
    std::cout << "Email nao encontrado!" << std::endl;
    std::cin.get();
    std::cin.get();
    inicio();
  }
}

/*_____*
 * [Ecommerce::tamanhoArquivo função que registra o tamanho do arquivo a ser lido]
 * @method Ecommerce::tamanhoArquivo
 * @param  file_name                 [nome do arquivo a ser lido]
 * @return                           [quantidade de linhas do arquivo lido]
 */

void Ecommerce::logoutUsuario(){
  std::cout << "Se voce tem certeza que gostaria de sair desta conta, digite OUT" << std::endl
  << "Se voce gostaria de voltar ao menu, digite MENU" << std::endl;
  std::string confirma;
  std::cin >> confirma;
  if (confirma == "OUT"){
    userLogged = "";
    inicio();
  }
  else if (confirma == "MENU"){
    if (userLogged == "adminl@gmail.com"){
      menuUsuario();
    }
    else {
      menuComprador();
    }
  }
  else {
    std::cout << "Entrada invalida. Por favor tente novamente...";
    std::cin.get();
    std::cin.get();
    logoutUsuario();
  }
}

/*_____*
 * [Ecommerce::tamanhoArquivo função que registra o tamanho do arquivo a ser lido]
 * @method Ecommerce::tamanhoArquivo
 * @param  file_name                 [nome do arquivo a ser lido]
 * @return                           [quantidade de linhas do arquivo lido]
 */

void Ecommerce::inicio(){
  int digito;
  limparTela();

  userLogged = "";

  std::cout << "\n" << "-------------------------------------------------------------" << std::endl;
  std::cout << "\t\t Bem vindo à nossa loja!" << std::endl;
  std::cout << "-------------------------------------------------------------" << "\n" << std::endl;

  std::cout << "1 - Já possuo uma conta." << std::endl;
  std::cout << "2 - Desejo me cadastrar." << std::endl;
  std::cout << "3 - Quero sair do programa." << std::endl;
  std::cout << "\nEscolha uma opcao: ";
  std::cin >> digito;
  switch (digito){
    case 1:
      loginUsuario();
      break;
    case 2:
      dadosComprador();
      break;
    case 3:
      std::cout << "Se voce tem certeza que gostaria de sair da loja, digite OUT" << std::endl;
      std::string confirma;
      std::cin >> confirma;
      if (confirma == "OUT"){
        exit(1);
      }
      else {
        inicio();
      }
    break;
    default:
      std::cout << "Opção inválida. Tente novamente" << std::endl;
      inicio();
      break;
  }
}

/*_____*
 * [Ecommerce::tamanhoArquivo função que registra o tamanho do arquivo a ser lido]
 * @method Ecommerce::tamanhoArquivo
 * @param  file_name                 [nome do arquivo a ser lido]
 * @return                           [quantidade de linhas do arquivo lido]
 */

void Ecommerce::dadosComprador(){
  limparTela();
  std::string nome, senha, confSenha, email, endereco, cpf;
  std::cout << "Insira seu nome de usuário: \nPor favor use apenas letras e numeros!";
  std::cin >> nome;
  std::cout << std::endl << "Insira uma senha: \nPor favor use apenas letras e numeros!";
  std::cin >> senha;
  std::cout << std::endl << "Confirme sua senha: ";
  std::cin >> confSenha;
  std::cout << std::endl << "Insira seu email: ";
  std::cin >> email;
  std::cout << std::endl << "Insira seu CPF: ";
  std::cin >> cpf;
  std::cout << std::endl << "Insira seu endereco: ";
  std::cin >> endereco;
  cadastrarComprador(nome, email, senha, cpf, endereco, 0, 0, 0, 0);
  loginUsuario();
}

/*_____*
 * [Ecommerce::tamanhoArquivo função que registra o tamanho do arquivo a ser lido]
 * @method Ecommerce::tamanhoArquivo
 * @param  file_name                 [nome do arquivo a ser lido]
 * @return                           [quantidade de linhas do arquivo lido]
 */

void Ecommerce::dadosProduto(){
  limparTela();
  std::string nome, cor, material, descricao;
  float preco;
  int opcao;
  long int codigo;
  codigo = geradorCod();
  std::cout << std::endl << "Se você deseja cadastrar uma caneca, digite 1" << std::endl
  << "Se você deseja cadastrar uma blusa ou moletom, digite 2" << std::endl
  << "Se você deseja cadastrar um acessorio, digite 3" << std::endl
  << "Se você deseja voltar a pagina de produtos, digite 0" << std::endl;
  std::cin >> opcao;
  std::cout << "Insira o nome do produto: ";
  std::cin >> nome;
  std::cout << std::endl << "Insira o preço do produto: ";
  std::cin >> preco;
  std::cout << std::endl << "Informe a cor do produto: ";
  std::cin >> cor;
  std::cout << std::endl << "Informe o material do produto: ";
  std::cin >> material;
  std::cout << std::endl << "Faça uma breve descricao do produto: ";
  std::cin >> descricao;
  switch (opcao){
    case 1:
      {
        float diametro;
        std::cout << std::endl << "Insira o diametro do produto: ";
        std::cin >> diametro;
        cadastrarCaneca(codigo, preco, 0, nome, cor, descricao, material, diametro);
        std::cout << std::endl << "Pressione ENTER para voltar a pagina anterior";
        std::cin.get();
        std::cin.get();
        break;
      }
    case 2:
      {
        std::string tipo;
        std::cout << std::endl << "Insira o tipo do produto: ";
        std::cin >> tipo;
        char tamanho;
        std::cout << std::endl << "Insira o tamanho do produto: ";
        std::cin >> tamanho;
        cadastrarBlusasEMoletom(codigo, preco, 0, nome, cor, descricao, material, tamanho, tipo);
        std::cout << std::endl << "Pressione ENTER para voltar a pagina anterior";
        std::cin.get();
        std::cin.get();
        break;
      }
    case 3:
      {
        std::string tipo;
        std::cout << std::endl << "Insira o tipo do produto: ";
        std::cin >> tipo;
        cadastrarAcessorio(codigo, preco, 0, nome, cor, descricao, material, tipo);
        std::cout << std::endl << "Pressione ENTER para voltar a pagina anterior";
        std::cin.get();
        std::cin.get();
        break;
      }
    case 0:
      {
        mostraProdutos();
        break;
      }
  }
}

/*_____*
 * [Ecommerce::tamanhoArquivo função que registra o tamanho do arquivo a ser lido]
 * @method Ecommerce::tamanhoArquivo
 * @param  file_name                 [nome do arquivo a ser lido]
 * @return                           [quantidade de linhas do arquivo lido]
 */

void Ecommerce::menuComprador(){
  limparTela();
  std::cout << "Para ver nossos produtos, digite 1" << std::endl
  << "Para ver seu perfil, digite 2" << std::endl
  << "Para ver seu carrinho, digite 3" << std::endl
  << "Para ver seu histórico de compras, digite 4" << std::endl
  << "Para requisitar mais dinheiro, digite 5" << std::endl
  << "Para sair desta conta, digite 9" << std::endl;
  int digito;
  std::cin >> digito;
  switch (digito) {
    case 1:
      impProdutos();
      break;
    case 2:
      procurarCompradorObj(userLogged).exibirPerfil();
      std::cin.get();
      std::cin.get();
      menuComprador();
      break;
    case 3:
      impCarrinho();
      break;
    case 4:
      impHistorico();
      break;
    case 5:
      procurarCompradorObj(userLogged).adicionaDinheiro();
      std::cin.get();
      std::cin.get();
      menuComprador();
      break;
    case 9:
      logoutUsuario();//Confirmar logout
      break;
    default:
      std::cout << "Opção inválida. Tente novamente" << std::endl;
      std::cin.get();
      std::cin.get();
      menuComprador();
      break;
  }
}

/*_____*
 * [Ecommerce::tamanhoArquivo função que registra o tamanho do arquivo a ser lido]
 * @method Ecommerce::tamanhoArquivo
 * @param  file_name                 [nome do arquivo a ser lido]
 * @return                           [quantidade de linhas do arquivo lido]
 */

void Ecommerce::menuUsuario(){
  limparTela();
  std::cout << "Para ver as requisições pendentes, digite 1" << std::endl
  << "Para ver os produtos oferecidos, digite 2" << std::endl
  << "Para ver os compradores cadastrados, digite 3" << std::endl
  << "Para ver seu perfil, digite 4" << std::endl
  << "Para sair desta conta, digite 9" << std::endl;
  int digito;
  std::cin >> digito;
  switch (digito) {
    case 1:
      admin.mostraPedidos();
      break;
    case 2:
      mostraProdutos();
      break;
    case 3:
      mostraUsuarios();
      break;
    case 4:
      admin.exibirPerfil();
      break;
    case 9:
      logoutUsuario();
      break;
    default:
      std::cout << "Opção inválida. Tente novamente" << std::endl;
      std::cin.get();
      std::cin.get();
      menuUsuario();
      break;
  }
}

#endif