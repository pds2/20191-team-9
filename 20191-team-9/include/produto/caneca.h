#include <iostream>
#include <string>
#include <vector>
#include "produto.h"


class Canecas : public Produtos{
    public:
        int _tamanho;
    private:
       Canecas();
       ~Canecas();
       std::string setCaneca(float, float, std::string,
       std::string, std::string, std::string, std::string, int); 
       std::string getCaneca();
};
