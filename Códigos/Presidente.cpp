#include "Presidente.h"

#define AUMENTO_BASE 30 /*Aumento de 30% no sal�rio do funcion�rio, sendo concedido
                          a partir da decisao do usu�rio*/

Presidente::Presidente(){

    setDesignacao(3); //Atribui a designacao(string) ao instanciar um objeto do tipo presidente

}

Presidente:: Presidente(string txt){

    setDesignacao(3);

    codigo = Clean_CSV(txt, ";", 1);
    nome = Clean_CSV(txt, ";", 1);
    endereco = Endereco(Clean_CSV(txt, ";", 4), 1);
    telefone = Clean_CSV(txt, ";", 1);
    dataAdmissao = Data(Clean_CSV(txt, ";", 1));
    salario = stod(Clean_CSV(txt, ";", 1));
    formacaoAcademica = Clean_CSV(txt, ";", 1);
    areaFormacao = txt;
}

Presidente::Presidente(std::string formacaoAcademica, std::string areaFormacao){

    setDesignacao(3);
    setFormacaoacademica(formacaoAcademica);
    setAreaformacao(areaFormacao);
}

Presidente::~Presidente(){}

std::string Presidente::getFormacaoacademica(){
    return formacaoAcademica;
}

std::string Presidente::getAreaformacao(){
    return areaFormacao;
}

void Presidente::setFormacaoacademica(std::string formacaoAcademica){
   this->formacaoAcademica = formacaoAcademica;
}

void Presidente::setAreaformacao(std::string areaFormacao){
   this->areaFormacao = areaFormacao;
}

/*M�todo que funciona a partir do polimorfismo do m�todo encontrado na classe funcionario,
  da qual a classe presidente herda*/
void Presidente::aumentaSalario(){
    double salarioAtualizado;

    salarioAtualizado = salario + (salario * (AUMENTO_BASE / 100.0));

    salario = salarioAtualizado;
}

std::string Presidente:: to_txt(){
    return getDesignacao() + ";" + getCodigo() + ";" + getNome() + ";" + getEndereco().to_txt() + ";" + getTelefone() + ";" + getDataAdmissao().to_txt() + ";" + to_string(getSalario()) + ";" + getFormacaoacademica() + ";" + getAreaformacao() + "\n";
}
