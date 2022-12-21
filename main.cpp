#include <iostream>

#include "Cliente.hpp"
#include "Estoque.hpp"
#include "Funcionario.hpp"
#include "Gerente.hpp"
#include "Gerenciador.hpp"
#include "Pessoa.hpp"
#include "Produto.hpp"
#include "Clientes.hpp"

int main(){

    std::cout << "GERENCIADOR DE VENDAS - PDS2 FINAL WORK" << std::endl;
    std::cout << "Authors: Arthur F. N. KRUSCHEWSKY; Arthur V. LANNA" << std::endl << std::endl;

    char user;
    char option;

    unsigned numItens;

    std::string item;
    unsigned quantidade;

    std::string nome;
    std::string email;
    std::string senha;
    std::string endereco;
    unsigned salario;

    Estoque *estoque = new Estoque;
    Clientes *clientes = new Clientes;
    Gerenciador *gerenciador = new Gerenciador;

    Gerente gerente = Gerente(gerenciador);

    std::cout << "\nSelecione o tipo de usuario:" << std::endl;

    std::cout << "a) Cliente" << std::endl;

    std::cout << "b) Funcionario" << std::endl;

    std::cout << "c) Gerente\n" << std::endl;

    std::cout << "Opcao: ";

    while(std::cin >> user){

        switch (user){
            
            case 'a':

                std::cout << "\nO que voce deseja fazer?" << std::endl;

                std::cout << "a) Novo cadastro" << std::endl;

                std::cout << "b) Acessar conta e fazer pedido" << std::endl;

                std::cout << "c) Acessar conta e remover do pedido" << std::endl;

                std::cout << "d) Confirmar pedido\n";

                std::cout << "Opcao: ";

                std::cin >> option;
 
                switch (option){

                    case 'a':
                            
                        std::cout << "\n\nNome: ";
                        std::cin >> nome;

                        std::cout << "E-mail: ";
                        std::cin >> email;

                        std::cout << "Senha: ";
                        std::cin >> senha;

                        clientes->addCliente(Cliente(Pessoa(nome, email, senha), estoque));

                        break;

                    case 'b':

                        std::cout << "\nE-mail: ";
                        std::cin >> email;

                        std::cout << "Senha: ";
                        std::cin >> senha;

                        if(senha == clientes->clientes[email].getSenha()){

                            gerente.gerenciador.estoque.printMenu();

                            std::cout << "\nFaca seu pedido. Endereco: ";

                            std::cin >> endereco;

                            clientes->clientes[email].setEndereco(endereco);
                                
                            std::cout << "Quantos itens deseja pedir: ";

                            std::cin >> numItens;

                            for(unsigned i = 0; i < numItens; i++){

                                std::cout << "Item: ";
                                std::cin >> item;

                                std::cout << "Quantidade: ";
                                std::cin >> quantidade;

                                clientes->clientes[email].addPedido(item, quantidade);

                            }

                        }

                        break;

                    case 'c':

                        std::cout << "\nE-mail: ";
                        std::cin >> email;

                        std::cout << "Senha: ";
                        std::cin >> senha;

                        if(senha == clientes->clientes[email].getSenha()){

                            std::cout << "\nRemova do seu pedido.";
                                
                            std::cout << "Quantos itens deseja remover: ";

                            std::cin >> numItens;

                            for(unsigned i = 0; i < numItens; i++){

                                std::cout << "\nItem: ";
                                std::cin >> item;

                                std::cout << "Quantidade: ";
                                std::cin >> quantidade;

                                clientes->clientes[email].rmvPedido(item, quantidade);

                            }

                        }

                        break;

                    case 'd':

                        std::cout << "\nE-mail: ";
                        std::cin >> email;

                        std::cout << "Senha: ";
                        std::cin >> senha;

                        if(senha == clientes->clientes[email].getSenha()){

                            clientes->clientes[email].confirmarPedido();

                            std::cout << "Pedido confirmado!\n" << std::endl;

                            gerente.gerenciador.updateCaixa(clientes->clientes[email].calcPreco());

                        }

                        break;
                        
                    default:
                        std::cout << "Opcao invalida! Tente outra vez!" << std::endl;
                        break;
                    }

                break;

            case 'b':

                std::cout << "\nO que voce deseja fazer?" << std::endl;

                std::cout << "a) Ver tarefas" << std::endl;

                std::cout << "b) Ver dados" << std::endl;

                std::cout << "c) Ver estoque" << std::endl;

                std::cout << "Opcao: ";

                std::cin >> option;

                switch(option){

                    case 'a':

                        std::cout << "\nE-mail: ";
                        std::cin >> email;

                        std::cout << "Senha: ";
                        std::cin >> senha;

                        if(senha == gerente.gerenciador.funcionarios[email]->getSenha()){

                            gerente.gerenciador.funcionarios[email]->printTarefas();

                        }

                        break;

                    case 'b':

                        std::cout << "\nE-mail: ";
                        std::cin >> email;

                        std::cout << "Senha: ";
                        std::cin >> senha;

                        if(senha == gerente.gerenciador.funcionarios[email]->getSenha()){

                            gerente.gerenciador.funcionarios[email]->printFuncionario();

                        }

                        break;

                    case 'c':

                        std::cout << "\nE-mail: ";
                        std::cin >> email;

                        std::cout << "Senha: ";
                        std::cin >> senha;

                        if(senha == gerente.gerenciador.funcionarios[email]->getSenha()){

                            gerente.gerenciador.estoque.printStock();

                        }

                        break;
                        
                    default:
                        std::cout << "Opcao invalida! Tente outra vez!" << std::endl;
                        break;
                    }

                break;

            case 'c':
                
                std::cout << "\nO que voce deseja fazer?" << std::endl;

                std::cout << "a) Adicionar funcionario novo" << std::endl;

                std::cout << "b) Remover funcionario" << std::endl;

                std::cout << "c) Ver valor do caixa" << std::endl;

                std::cout << "Opcao: ";

                std::cin >> option;

                switch(option){

                    case 'a':

                        std::cout << "\nE-mail: ";
                        std::cin >> email;

                        std::cout << "Senha: ";
                        std::cin >> senha;

                        if(senha == gerente.getSenha()){

                            std::cout << "\n\nNome: ";
                            std::cin >> nome;

                            std::cout << "E-mail: ";
                            std::cin >> email;

                            std::cout << "Senha: ";
                            std::cin >> senha;

                            std::cout << "Salario: ";
                            std::cin >> salario;

                            gerente.gerenciador.addFuncionario(new Funcionario(nome, email, senha, salario));

                        }

                        break;

                    case 'b':

                        std::cout << "\nE-mail: ";
                        std::cin >> email;

                        std::cout << "Senha: ";
                        std::cin >> senha;

                        if(senha == gerente.getSenha()){

                            std::cout << "E-mail: ";
                            std::cin >> email;

                            gerente.gerenciador.rmvFuncionario(email);

                        break;

                    case 'c':

                        std::cout << "\nE-mail: ";
                        std::cin >> email;

                        std::cout << "Senha: ";
                        std::cin >> senha;

                        if(senha == gerente.getSenha()){

                            std::cout << "\nO valor do caixa: R$" << gerente.gerenciador.getCaixa() << std::endl;

                        }

                        break;
                        
                    default:
                        std::cout << "Opcao invalida! Tente outra vez!" << std::endl;
                        break;
                    }
                
                }

                break;
            
            default:
                std::cout << "Opcao invalida! Tente outra vez!" << std::endl;
                break;

        }

    }

    return 0;

}
