#include <iostream>
#include <string>
#include <vector>
#include "produto.h"

class Acessorios : public Produtos{
    public:
        std::string _tipo;
    private:
        Acessorios();
        ~Acessorios();
        std::string setAcessorio(float, float, std::string,
        std::string, std::string, std::string, std::string, std::string);
        std::string getAcessorio();
};
