#ifndef GERENTE_H
#define GERENTE_H

#include <iostream>
#include <string>

#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Gerenciador.hpp"

class Gerente : public Funcionario{

    public:

        Gerenciador &gerenciador;

        explicit Gerente(Gerenciador *gerenciador);

};

#endif
