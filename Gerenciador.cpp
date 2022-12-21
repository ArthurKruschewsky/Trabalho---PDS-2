#include "Gerenciador.hpp"

#include <iterator>

Gerenciador::Gerenciador(){}

void Gerenciador::addFuncionario(Funcionario *new_funcionario){

    this->funcionarios.insert(std::pair<std::string, Funcionario*>(new_funcionario->getEmail(), new_funcionario));

}

void Gerenciador::rmvFuncionario(std::string email){

    std::map<std::string, Funcionario*>::iterator it;

    for(it = this->funcionarios.begin(); it != this->funcionarios.end(); ++it){

        if(it->first == email){

            this->funcionarios.erase(it);

        }

    }

}

void Gerenciador::addTarefa(std::string email, std::string tarefa){

    std::map<std::string, Funcionario*>::iterator it;

    for(it = this->funcionarios.begin(); it != this->funcionarios.end(); ++it){

        if(it->first == email){

            it->second->addTarefa(tarefa);

        }

    }

}
        
void Gerenciador::printFuncionarios(){

    std::cout << "---------- LISTA DE FUNCIONARIOS ATIVOS ----------" << std::endl;

    std::map<std::string, Funcionario*>::iterator it;
    
    for(it = this->funcionarios.begin(); it != this->funcionarios.end(); ++it){

        it->second->printFuncionario();

        it->second->printTarefas();

    }

}

double Gerenciador::getCaixa(){

    return this->caixa;

}

void Gerenciador::updateCaixa(double add){

    this->caixa += add;

}
