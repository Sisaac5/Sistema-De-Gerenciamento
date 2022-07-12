#include "Operador.h"

#define AUMENTO_BASE 5 //Aumento de 5% do salário, o qual é concedido a pedidodo usuário

Operador::Operador(){

    setDesignacao(0); //Atribui a designacao(string) ao instanciar um objeto do tipo operador
}

Operador::Operador(string txt)
:Funcionario(txt){

    setDesignacao(0);
}

Operador::~Operador()
{
    //dtor
}

/*M�todo que funciona com base no polimorfismo do m�todo encontrado na classe funcionario,
  da qual a classe operador herda*/
void Operador::aumentaSalario(){
    double salarioAtualizado;

    salarioAtualizado = salario + (salario * (AUMENTO_BASE / 100.0));

    salario = salarioAtualizado;
}
