#ifndef CLIENTES_H
#define CLIENTES_H

#include <iostream>
#include <string>
#include <map>

#include "Cliente.hpp"

class Clientes{

    public:

        std::map<std::string, Cliente> clientes;

        Clientes();

        void addCliente(Cliente cliente);


};

#endif
