#include "Diretor.h"

#define AUMENTO_BASE 20 /*Aumento de 20% no sal�rio dos funcion�rios de cargo de diretor
                          sendo adicionado � pedido do usu�rio*/

Diretor::Diretor(){

    setDesignacao(2); //Atribui a designacao(string) ao instanciar um elemento do tipo gerente

}

Diretor::Diretor(std::string areaSupervisao, std::string areaFormacao){

    setDesignacao(2);
    setAreasupervisao(areaSupervisao);
    setAreaformacao(areaFormacao);
}

Diretor::Diretor(std::string txt){

    setDesignacao(2);

    codigo = Clean_CSV(txt, ";", 1);
    nome = Clean_CSV(txt, ";", 1);
    endereco = Endereco(Clean_CSV(txt, ";", 4), 1);
    telefone = Clean_CSV(txt, ";", 1);
    dataAdmissao = Data(Clean_CSV(txt, ";", 1));
    salario = stod(Clean_CSV(txt, ";", 1));
    areaSupervisao = Clean_CSV(txt, ";", 1);
    areaFormacao = txt;
}

Diretor::~Diretor(){}

std::string Diretor::getAreasupervisao(){
    return areaSupervisao;
}

std::string Diretor::getAreaformacao(){
    return areaFormacao;
}

void Diretor::setAreasupervisao(std::string areaSupervisao){
   this->areaSupervisao = areaSupervisao;
}

void Diretor::setAreaformacao(std::string areaFormacao){
   this->areaFormacao = areaFormacao;
}

//aumentaSalario funciona com polimorfismo a partir da heran�a da classe funcionario
void Diretor::aumentaSalario(){
    double salarioAtualizado;

    /*O sal�rio ser� aumentado usando a porcentagem cadastrada no pr�prio c�digo,
      a qual est� declarada no #define AUMENTO_BASE*/
    salarioAtualizado = salario + (salario * (AUMENTO_BASE / 100.0));

    salario = salarioAtualizado;
}

std::string Diretor::to_txt(){
    return getDesignacao() + ";" + getCodigo() + ";" + getNome() + ";" + getEndereco().to_txt() + ";" + getTelefone() + ";" + getDataAdmissao().to_txt() + ";" + to_string(getSalario()) + ";" + getAreasupervisao() + ";" + getAreaformacao() + "\n";
}
