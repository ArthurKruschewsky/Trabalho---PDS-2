#include "Estoque.hpp"

#include <iterator>

Estoque::Estoque(){}

void Estoque::addItem(std::string item, Produto produto){

    if(this->itens[item].getNome() == item){

        this->itens[item].setQuant(this->itens[item].getQuant() + produto.getQuant());

    }

    else{

        this->itens.insert(std::pair<std::string, Produto>(item, produto));

    }

}

void Estoque::rmvItem(std::string item, unsigned quant){

    if(this->itens[item].getNome() == item && this->itens[item].getQuant() > 0){

        this->itens[item].setQuant(this->itens[item].getQuant() - quant);

    }

}

void Estoque::printStock(){

    std::map<std::string, Produto>::iterator it;

    std::cout << "---------- ESTOQUE ----------" << std::endl;

    for(it = this->itens.begin(); it != this->itens.end(); ++it){

        std::cout << "Item: " << it->first << std::endl;

        std::cout << "- Preco: RS" << it->second.getPreco() << std::endl;

        std::cout << "- Quantidade disponivel: " << it->second.getQuant() << std::endl;

        std::cout << "- Codigo: " << it->second.getCodigo() << std::endl;

    }

}

void Estoque::printMenu(){

    std::map<std::string, Produto>::iterator it;

    std::cout << "---------- MENU ----------" << std::endl;

    for(it = this->itens.begin(); it != this->itens.end(); ++it){

        std::cout << "- " << it->first << "(RS" << it->second.getPreco() << ")" << std::endl;

    }

}
