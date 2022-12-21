#include "Cliente.hpp"

#include <iterator>
#include <iomanip>

Cliente::Cliente(Pessoa pessoa, Estoque *estoque) : estoque(*estoque){

    this->nome = pessoa.getNome();

    this->email = pessoa.getSenha();

    this->senha = pessoa.getSenha();

}

void Cliente::printPedido(){

    std::map<std::string, unsigned>::iterator it;

    std::cout << std::setprecision(2) << std::fixed;

    std::cout << "---------- RESUMO DO PEDIDO ----------" << std::endl;

    for(it = this->carrinho.begin(); it != this->carrinho.end(); ++it){

        std::cout << "- " << it->first << "(R$" << this->estoque.itens[it->first].getPreco() * it->second << ")" << std::endl;

    }

    std::cout << "---------- Valor Total: R$" << this->calcPreco() << "----------" << std::endl;

}

void Cliente::setEndereco(std::string endereco){

    this->endereco = endereco;

}

std::string Cliente::getEndereco(){

    return this->endereco;

}

void Cliente::addPedido(std::string item, unsigned quant){

    std::map<std::string, unsigned>::iterator it;

    bool exist, done = false;

    for(it = this->carrinho.begin(); it != this->carrinho.end(); ++it){

        if(it->first == item){

            if(this->estoque.itens[item].getQuant() >= quant){

                it->second += quant;

                exist = true;
                
                done = true;

            }

        }

    }

    if(!exist && this->estoque.itens[item].getQuant() >= quant){

        this->carrinho.insert(std::pair<std::string,unsigned>(item, quant));

        done = true;

    }

    if(!done){

        std::cout << "Quantidade pedida indisponivel no estoque!" << std::endl;

    }

}

void Cliente::rmvPedido(std::string item, unsigned quant){

    std::map<std::string, unsigned>::iterator it;

    for(it = this->carrinho.begin(); it != this->carrinho.end(); ++it){

        if(it->first == item){

            it->second -= quant;

        }

    }

}

double Cliente::calcPreco(){

    double total = 0.0;

    std::map<std::string, unsigned>::iterator it;

    std::map<std::string, Produto>::iterator it2;

    for(it = this->carrinho.begin(); it != this->carrinho.end(); ++it){

        for(it2 = this->estoque.itens.begin(); it2 != this->estoque.itens.end(); ++it2){

            if(it->first == it2->first){

                total += it->second * it2->second.getPreco();

            }

        }

    }

    return total;

}

void Cliente::confirmarPedido(){

    std::map<std::string, unsigned>::iterator it;

    std::map<std::string, Produto>::iterator it2;

    for(it = this->carrinho.begin(); it != this->carrinho.end(); ++it){

        for(it2 = this->estoque.itens.begin(); it2 != this->estoque.itens.end(); ++it2){

            if(it->first == it2->first){

                this->estoque.rmvItem(it->first, it->second);

                this->carrinho.erase(it);

            }

        }

    }

}
