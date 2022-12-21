#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>
#include <vector>

#include "Pessoa.hpp"

class Funcionario : public Pessoa{

    protected:

        double salario;

        std::vector<std::string> tarefas;

    public:

        Funcionario();

        Funcionario(std::string nome, std::string email, std::string senha, double salario);

        void addTarefa(std::string tarefa);

        void printFuncionario();

        void printTarefas();

};

#endif
