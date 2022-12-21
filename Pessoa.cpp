#include "Pessoa.hpp"

Pessoa::Pessoa(){}

Pessoa::Pessoa(std::string nome, std::string email, std::string senha){

    this->nome = nome;

    this->email = email;

    this->senha = senha;

}

void Pessoa::setSenha(std::string old_pass, std::string new_pass){

    if(old_pass == this->senha){

        this->senha = new_pass;

        std::cout << "A senha foi alterada!" << std::endl;

    }

    else{

        std::cout << "Senha atual incorreta: a senha não foi alterada!" << std::endl;

    }

}

std::string Pessoa::getEmail(){

    return this->email;

}

std::string Pessoa::getNome(){

    return this->nome;

}

std::string Pessoa::getSenha(){

    return this->senha;

}
