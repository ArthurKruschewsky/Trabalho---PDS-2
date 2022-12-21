#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <iostream>
#include <string>
#include <map>

#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Estoque.hpp"

class Gerenciador{

    protected:

        double caixa = 0.0;

    public:

        std::map<std::string, Funcionario*> funcionarios;

        Estoque estoque;

        Gerenciador();

        void addFuncionario(Funcionario *new_funcionario);

        void rmvFuncionario(std::string email);

        void addTarefa(std::string email, std::string tarefa);

        void updateCaixa(double add);
        
        void printFuncionarios();

        double getCaixa();

};

#endif
