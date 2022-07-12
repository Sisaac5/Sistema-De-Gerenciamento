#include "Funcionario.h"

//220 horas mensais / 8 horas diarias
//1 hora = 6 reais
#define SALARIO_BASE 1320 //Salario usado como base nesse programa

Funcionario::Funcionario(){

}


Funcionario::Funcionario(string txt){

    codigo = Clean_CSV(txt, ";", 1);
    nome = Clean_CSV(txt, ";", 1);
    endereco = Endereco(Clean_CSV(txt, ";", 4), 1);
    telefone = Clean_CSV(txt, ";", 1);
    dataAdmissao = Data(Clean_CSV(txt, ";", 1));
    salario = stod(txt);
}

void Funcionario::setFuncionario(std::string codigo, std::string nome, std::string cep,
                                 std::string telefone, int designacaoN, int dia, int mes, int ano){
    this->codigo = codigo;
    this->nome = nome;
    setEndereco(cep);
    this->telefone = telefone;
    setDesignacao(designacaoN);
    setDataAdmissao(dia, mes, ano);
}

Funcionario::~Funcionario(){}

std::string Funcionario::getCodigo(){
    return codigo;
}

std::string Funcionario::getNome(){
    return nome;
}

Endereco Funcionario::getEndereco(){
    return endereco;
}

std::string Funcionario::getTelefone(){
    return telefone;
}

Data Funcionario::getDataAdmissao(){
    return dataAdmissao;
}

std::string Funcionario::getDesignacao(){
    return designacao;
}

double Funcionario::getSalario(){
    return salario;
}

void Funcionario::setCodigo(std::string codigo){
   this->codigo = codigo;
}

void Funcionario::setNome(std::string nome){
   this->nome = nome;
}

void Funcionario::setEndereco(std::string cep){
   /*Utiliza m�todo da classe endereco para setar os atributos a partir
     de um arquivo .json baixado da internet*/
   this->endereco = Endereco(cep);
}

void Funcionario::setTelefone(std::string telefone){
   this->telefone = telefone;
}

void Funcionario::setDataAdmissao(int dia, int mes, int ano){

   //Utiliza m�todos da classe data para setar os valores
   this->dataAdmissao.setMes(mes);
   this->dataAdmissao.setDia(dia);
   this->dataAdmissao.setAno(ano);
}

//Atribui a designacao(string) com base no tipo fornecido pelo usu�rio
void Funcionario::setDesignacao(int designacaoN){
   if(designacaoN == 0){
        designacao = "Operador";
        salario = SALARIO_BASE;
    }

    if(designacaoN == 1){
        designacao = "Gerente";
        salario = SALARIO_BASE * 2;
    }

    if(designacaoN == 2){
        designacao = "Diretor";
        salario = SALARIO_BASE * 3;
    }

    if(designacaoN == 3){
        designacao = "Presidente";
        salario = SALARIO_BASE * 4;
    }

    if(designacaoN >= 4 || designacaoN < 0){
        designacao = "INDEFINIDO";
        salario = SALARIO_BASE * 0;
    }
}

void Funcionario::setSalario(double salario){
   this->salario = salario;
}

//M�todo vazio simplesmente para realiza��o posterior de polimorfismo
void Funcionario::aumentaSalario(){

}

string Funcionario:: to_txt(){
    return getDesignacao() + ";" + getCodigo() + ";" + getNome() + ";" + getEndereco().to_txt() + ";" + getTelefone() + ";" + getDataAdmissao().to_txt() + ";" + to_string(getSalario()) + "\n";
}

string Funcionario:: Clean_CSV(string &str, string find, int reads){
    string aux = "";

    for(int i = 0; i < reads; i++){ // reads guarda o número de ocorrências do termo a ser encontrado
        aux += str.substr(0, str.find(find));// adiciona o conteúdo anterior à ocorrência da string find na string txt à string aux.

        if(i != reads - 1)
            aux += ";";

        str.erase(0, str.find(find) + 1);//apaga o conteúdo recem adicionado à string aux
    }

    return aux;// retorna a string com os conteídos desejados separados por ponto e vírgula.
    //Vale lembrar que parte da string str é apagado.
    //Mais precisamente, todo conteúdo presente na string aux foi retirado da string str.
    //Isso faz com que o tratamento das strings retiradas do arquivos CSV seja simplificado 
}
