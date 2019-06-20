#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <exception>
#include <limits>
#include <sstream>

// As funções que desse .h simplesmente verificam casos de exceção e jogam o tipo de exceção específica
// O tratamento específico para cada exceção será tratato em outras funcões
// Ex: excpt_verificar_morto(Pokemon*) joga exceção std::out_of_range()
// Que será tratada na função encerrar_batalha(Pokemon*) presente no batalha.h

// Nada impede de criarmos novos tipos de exceções

// Ex: Todas exceçoes devem começar com "excpt_"

// class excpt_qualquer : public std::exception{
// public:
//		const char *what(){
//			return "Ocorreu Exceção Qualquer\n";
//		}
//};

class Exception_Entrada_Invalida : public std::exception{
public:
	const char *what(){
		return "Por favor, insira uma entrada valida para continuar.\n";
	}
};


class Exception_Codigo_Ja_Registrado : public std::exception{
public:
	const char *what(){
		return "Erro ao registrar produto: codigo de produto ja utilizado. Tente novamente.\n";
	}
};

class Exception_Nenhum_Produto_Arquivo : public std::exception{
public:
	const char *what(){
		return "Ainda nao ha nenhum produto cadastrado.\n";
	}
};

class Exception_Erro_Abrir_Arquivo : public std::exception{
public:
	const char *what(){
		return "Erro ao abrir arquivo. Tente novamente\n";
	}
};


class Exception_Historico_Vazio : public std::exception{
public:
	const char *what(){
		return "Seu histórico está vazio. Compre produtos para continuar.\n";
	}
};

class Exception_Carrinho_Vazio : public std::exception{
public:
    const char *what(){
        return "Seu carrinho está vazio. Adicione produtos para continuar.\n";
    }
};

class Exception_Produto_Fora_do_Historico : public std::exception{
public:
    const char *what(){
        return "O produto não consta em seu histórico então não pode ter um comentário registrado. Tente novamente.\n";
    }
};

void verificar_historico_vazio(int produtosH);

void verificar_carrinho_vazio(int produtosC);


/*
void verificar_dificuldade_valida(int);

void verifica_entrada(std::string);

void verificar_lideranca_valida(int);
int tratamento_lideranca_invalida();

void verificar_nocaute(Pokemon*,Pokemon*);

void verificar_habilidade_valida(std::string,int);
void tratamento_habilidade_invalida(std::string,int);

void verificar_limite_habilidade(std::string, short int *);
void tratamento_limite_habilidade(std::string &, short int *);

void verificar_num_pokemon_valido(Treinador);
Treinador tratamento_num_pokemon_invalido(Treinador);

int verifica_inteiro(std::string);*/

#endif // EXCECOES_H
