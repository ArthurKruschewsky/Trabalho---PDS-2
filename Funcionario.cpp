#include "Funcionario.hpp"

#include <iomanip>

Funcionario::Funcionario(){}

Funcionario::Funcionario(std::string nome, std::string email, std::string senha, double salario){

    this->nome = nome;

    this->email = email;

    this->senha = senha;

    this->salario = salario;

}

void Funcionario::addTarefa(std::string tarefa){

    this->tarefas.push_back(tarefa);

}

void Funcionario::printFuncionario(){

    std::cout << "Nome: " << this->nome << std::endl;

    std::cout << "E-mail: " << this->email << std::endl;

    std::cout << "Salario: " << this->salario << std::endl;

}

void Funcionario::printTarefas(){

    for(unsigned i = 0; i < this->tarefas.size(); i++){

        std::cout << i << ") " << this->tarefas[i] << std::endl;

    }

}
