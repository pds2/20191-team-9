#include "usuario/usuario.h"

/**
 * [Usuario::Usuario Construtor da classe Usuario]
 * @method Usuario::Usuario
 * @param  n                [representa o nome do usuário]
 * @param  em               [representa o email do usuário]
 * @param  s                [representa a senha do usuário]
 */
Usuario::Usuario(std::string n, std::string em, std::string s){
  _nome = n;
  _email = em;
  _senha = s;
};

/**
 * [Usuario::Usuario Construtor vazio da classe Usuario]
 * @method Usuario::Usuario
 */
Usuario::Usuario(){

}

/**
 * [Usuario Destrutor da classe Usuario]
 * @method Usuario
 */

Usuario::~Usuario(){

}
/**
 * [Usuario::getNome função que retorna o nome do usuário]
 * @method Usuario::getNome
 * @return [nome do usuário]
 */

std::string Usuario::getNome(){
  return this->_nome;
}

/**
 * [Usuario::getEmail função que retorna o email do usuário]
 * @method Usuario::getEmail
 * @return [email do usuário]
 */

std::string Usuario::getEmail(){
  return this->_email;
}

/**
 * [Usuario::getSenha função que retorna a senha do usuário]
 * @method Usuario::getSenha
 * @return [senha do usuário]
 */

std::string Usuario::getSenha(){
  return this->_senha;
}
