#include "Gerente.h"

#define AUMENTO_BASE 10 /*Aumento de 10% do ssl�rio do gerente, sendo
                          atribudio a pedido do usu�rio*/

Gerente::Gerente()
{
    setDesignacao(1); //Atribui a designcao(string) ao instanciar um elemento do tipo gerente
}

Gerente::Gerente(std::string areaSupervisao)
{
    setDesignacao(1);
    setAreasupervisao(areaSupervisao);
}

Gerente:: Gerente(string txt, int i){

    setDesignacao(1);

    codigo = Clean_CSV(txt, ";", 1);
    nome = Clean_CSV(txt, ";", 1);
    endereco = Endereco(Clean_CSV(txt, ";", 4), 1);
    telefone = Clean_CSV(txt, ";", 1);
    dataAdmissao = Data(Clean_CSV(txt, ";", 1));
    salario = stod(Clean_CSV(txt, ";", 1));
    areaSupervisao = Clean_CSV(txt, ";", 1);
    areaSupervisao = txt;

}

Gerente::~Gerente(){

}

std::string Gerente::getAreasupervisao(){
    return areaSupervisao;
}

void Gerente::setAreasupervisao(std::string areaSupervisao){
   this->areaSupervisao = areaSupervisao;
}

/*M�todo que funciona a partir do polimorfismo do m�todo encontrado na classe funcionario,
  da qual a classe gerente herda*/
void Gerente::aumentaSalario(){
    double salarioAtualizado;

    salarioAtualizado = salario + (salario * (AUMENTO_BASE / 100.0));

    salario = salarioAtualizado;
}

std::string Gerente::to_txt(){
    return getDesignacao() + ";" + getCodigo() + ";" + getNome() + ";" + getEndereco().to_txt() + ";" + getTelefone() + ";" + getDataAdmissao().to_txt() + ";" + to_string(getSalario()) + ";" + getAreasupervisao() + "\n";
}
