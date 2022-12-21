#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

class Pessoa{

    protected:

        std::string nome;

        std::string email;

        std::string senha = "0000";

    public:

        Pessoa();

        Pessoa(std::string nome, std::string email, std::string senha);

        void setSenha(std::string old_pass, std::string new_pass);

        std::string getEmail();

        std::string getNome();

        std::string getSenha();

};

#endif
