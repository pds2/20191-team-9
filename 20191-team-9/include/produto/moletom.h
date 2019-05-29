#include <iostream>
#include <string>
#include <vector>
#include "produto.h"

class Moletom : public Produtos{
    public:
        char _tamanho;
    private:
       Moletom();
       ~Moletom();
       std::string setMoletom(float, float, std::string,
       std::string, std::string, std::string, std::string, char); 
       std::string getMoletom();
};
