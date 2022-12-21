#include "Clientes.hpp"

Clientes::Clientes(){}

void Clientes::addCliente(Cliente cliente){

    this->clientes.insert(std::pair<std::string, Cliente>(cliente.getEmail(), cliente));

}
