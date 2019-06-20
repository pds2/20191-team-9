#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <exception>
#include <limits>
#include <sstream>

// As funções que desse .h simplesmente verificam casos de exceção e jogam o tipo de exceção específica
// O tratamento específico para cada exceção será tratato em outras funcões
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
		return "Entrada inválida: Por favor, insira uma entrada valida para continuar.\n";
	}
};

class Exception_Codigo_Ja_Registrado : public std::exception{
public:
	const char *what(){
		return "Erro ao registrar produto: Código de produto ja utilizado. Tente novamente.\n";
	}
};

class Exception_Nenhum_Produto_Arquivo : public std::exception{
public:
	const char *what(){
		return "Erro ao ler produtos do arquivo: Ainda não há nenhum produto cadastrado.\n";
	}
};

class Exception_Erro_Abrir_Arquivo : public std::exception{
public:
	const char *what(){
		return "Erro ao abrir arquivo: Tente novamente\n";
	}
};

class Exception_Historico_Vazio : public std::exception{
public:
	const char *what(){
		return "Erro ao exibir histórico: Seu histórico está vazio. Compre produtos para continuar.\n";
	}
};

class Exception_Carrinho_Vazio : public std::exception{
public:
    const char *what(){
        return "Erro ao exibir carrinho: Seu carrinho está vazio. Adicione produtos para continuar.\n";
    }
};

class Exception_Produto_Fora_do_Historico : public std::exception{
public:
    const char *what(){
        return "Erro ao comentar produto: O produto não consta em seu histórico então não pode ter um comentário registrado. Tente novamente.\n";
    }
};

class Exception_Usuario_Ja_Cadastrado : public std::exception{
public:
	const char *what(){
		return "Erro ao cadastrar comprador: Email de comprador já está em uso. Tente novamente.\n";
	}
};

class Exception_Produto_Ja_Consta_No_Carrinho : public std::exception{
public:
	const char *what(){
		return "Erro ao adicionar produto ao carrinho: Produto já consta em seu carrinho. Tente novamente.\n";
	}
};

class Exception_Produto_Nao_Encontrado : public std::exception{
public:
	const char *what(){
		return "Erro ao adicionar produto ao carrinho: Produto não encontrado. Tente novamente.\n";
	}
};

class Exception_Saldo_Comprador_Insuficiente : public std::exception{
public:
	const char *what(){
		return "Erro ao confirmar compra: Saldo Insuficiente. Tente novamente.\n";
	}
};

class Exception_Compra_Nao_Realizada : public std::exception{
public:
	const char *what(){
		return "Erro ao confirmar compra: A compra não pode ser efetuada. Tente novamente.\n";
	}
};

class Exception_Nota_Invalida : public std::exception{
public:
	const char *what(){
		return "Erro ao avaliar item: Nota inválida. Tente novamente.\n";
	}
};

class Exception_Opcao_Menu_Fazer_Compras_Invalida : public std::exception{
public:
	const char *what(){
		return "Erro ao finalizar compra: Opção inválida. Tente novamente.\n";
	}
};

void verificar_historico_vazio(int produtosH);

void verificar_carrinho_vazio(int produtosC);

void verificar_usuario_existente(std::string email);

void verificar_produto_ja_no_carrinho(int codProduto);

void verificar_produto_cadastrado(int codProduto);

void verificar_saldo_insuficiente(float dinheiroComprador, float totalCompras);

void verificar_produto_fora_do_historico(int indice);

void verificar_nota_invalida(int nota);

void verificar_opcao_menu_fazer_compras_invalida(int opcao);


#endif // EXCECOES_H
