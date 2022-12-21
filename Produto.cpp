#include "Produto.hpp"

unsigned Produto::code = 1;

Produto::Produto(){}

Produto::Produto(std::string nome, double preco, unsigned quant){

    this->nome = nome;

    this->preco = preco;

    this->quant = quant;

    this->codigo = code++;

}

unsigned Produto::getCodigo(){

    return this->codigo;

}

std::string Produto::getNome(){

    return this->nome;

}

double Produto::getPreco(){

    return this->preco;

}

void Produto::setPreco(double new_preco){

    this->preco = new_preco;

}

void Produto::setQuant(unsigned quant){

    this->quant = quant;

}

unsigned Produto::getQuant(){

    return this->quant;

}
