#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>

class Produto{

    protected:

        std::string nome;

        double preco;

        unsigned quant;

        unsigned codigo;

    public:

        Produto();

        Produto(std::string nome, double preco, unsigned quant);

        std::string getNome();

        double getPreco();

        unsigned getCodigo();

        void setPreco(double new_preco);

        void setQuant(unsigned quant);

        unsigned getQuant();

        static unsigned code;

};

#endif
