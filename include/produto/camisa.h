#include <iostream>
#include <string>
#include <vector>
#include "produto.h"

class Camisas : public Produtos{
    public:
        char _tamanho;
    private:
       Camisas();
       ~Camisas();
       std::string setCamisa(float, float, std::string,
       std::string, std::string, std::string, std::string, char); 
       std::string getCamisa();
};
