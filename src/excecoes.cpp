#include "excecoes.h"

#include <string>
#include <vector>

void verificar_historico_vazio(int produtosH){
    if(produtosH == 0){
        Exception_Historico_Vazio HV;
        throw HV;
    };
}

void verificar_carrinho_vazio(int produtosC){
    if(produtosC == 0){
        Exception_Carrinho_Vazio CV;
        throw CV;
    };
}
/*
void tratamento_habilidade_invalida(std::string escolha, int lideranca){
    if(lideranca == 3){
        std::cout << "Voc� s� tem lideran�a o suficiente para ter acesso �s habilidades 1,2 e 3.\n";
        escolha = escolha_um_a_tres();
    }
    if(lideranca == 2){
        std::cout << "Voc� s� tem lideran�a o suficiente para ter acesso �s habilidades 1 e 2.\n";
        escolha = escolha_um_a_dois();
    }
    else{
        std::cout << "Voc� � um novato! S� consegue utilizar a primeira habilidade.\n";
        escolha = escolha_um_a_um();
    }
}

void verificar_limite_habilidade(std::string escolha, short int *limite){
    int escolha_int = escolha[0] - '0';
    if(escolha_int > 1){
        if(limite[escolha_int - 1] == 0){
            Excpt_Limite_Habilidade z;
            throw z;
        }
    }
}

void tratamento_limite_habilidade(std::string &escolha, short int *limite){
    do{
        do{
        std::cout << "A habilidade escolhida esgotou! Escolha outra: ";
        std::getline(std::cin, escolha);
        }while(escolha[0] != '1' && escolha[0] != '2' && escolha[0] != '3' && escolha[0] != '4');
    }while(limite[(escolha[0]-'0')-1]<=0);
}

void verificar_lideranca_valida(int lideranca){
    if(lideranca<=0||lideranca>4){
        Excpt_Lideranca_Invalida z;
        throw z;
    }
}

int tratamento_lideranca_invalida(){
    std::string escolha = escolha_um_a_quatro();
    return (escolha[0] - '0');
}

void verificar_dificuldade_valida(int dificuldade){
    if(dificuldade<=0||dificuldade>4){
        Excpt_Dificuldade_Invalida z;
        throw z;
    }
}

void verificar_num_pokemon_valido(Treinador jogador){
    if(jogador._lista_de_pokemon.size()>=9){
        Excpt_Num_Pokemon_Invalido z;
        throw z;
	}
}

Treinador tratamento_num_pokemon_invalido(Treinador jogador){
    int doacao = doar_pokemon(jogador);
    jogador._lista_de_pokemon.erase(jogador._lista_de_pokemon.begin()+doacao);
    return jogador;
}

int verifica_inteiro(std::string enunciado){
  int escolha;
  while (true) {
    std::cout << enunciado;
    std::cin >> escolha;
    if(!std::cin) {
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       std::cout << "\nPor favor, digite um número inteiro!\n\n";
       continue;
    } else {
        return escolha;
        break;
    }
  }
}

void verifica_entrada(std::string p) {
    if ((p[0] != '1') || (p[0] != '2') || (p[0] != '3')) {
        Excpt_Entrada_Inicial x;
        throw x;
    }
}
*/
