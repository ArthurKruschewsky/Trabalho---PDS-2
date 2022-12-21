#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <string>
#include <map>

#include "Produto.hpp"

class Estoque{

    public:

        Estoque();

        std::map<std::string, Produto> itens;

        void addItem(std::string item, Produto produto);

        void rmvItem(std::string item, unsigned quant);

        void printStock();

        void printMenu();

};

#endif
