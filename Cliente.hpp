#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
#include <map>

#include "Pessoa.hpp"
#include "Estoque.hpp"

class Cliente : public Pessoa{

    private:

        Estoque &estoque;

        std::map<std::string, unsigned> carrinho;

        std::string endereco;

    public:

        Cliente();

        Cliente(Pessoa pessoa, Estoque *estoque);

        void printPedido();

        void setEndereco(std::string endereco);

        std::string getEndereco();

        void addPedido(std::string item, unsigned quant);

        void rmvPedido(std::string item, unsigned quant);

        double calcPreco();

        void confirmarPedido();


};

#endif
