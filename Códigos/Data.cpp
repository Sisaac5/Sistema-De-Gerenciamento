#include "Data.h"

Data::Data(){}

Data::Data(int d, int m, int a)
{
    setMes(m); //Abtribuições iniciais 
    setDia(d);
    setAno(a);
}

Data:: Data(string txt){

    dia = stoi(txt.substr(0, txt.find("/")));// guarda o inteiro anterior à ocorrência de uma barra na string
    txt.erase(0, txt.find("/") + 1);// apaga o conteúdo anterior a primeira ocorrência de uma barra na string

    mes = stoi(txt.substr(0, txt.find("/")));// guarda o inteiro anterior à ocorrência de uma barra na string
    txt.erase(0, txt.find("/") + 1);// apaga o conteúdo anterior a primeira ocorrência de uma barra na string

    ano = stoi(txt);

}

Data::~Data(){

}

int Data::getDia(){
    return dia;
}

int Data::getMes(){
    return mes;
}

int Data::getAano(){
    return ano;
}

int Data::getQuantDiasDoMes(int m){
    return quantDias[m - 1];
}

/*Método que retorna uma determinada data na escala anual, ou seja,
  qual o número do dia dentre os 365 dias dos ano*/
int Data::getDiaDoAno(){
    int auxiliar = 0;

    for (int i = 0; i < getMes(); i++){
        if(i == getMes() - 1)
            auxiliar += getDia();

        else
            auxiliar += quantDias[i];
    }

    return auxiliar;
}

void Data::setDia(int d){

    //Verifica se o dia inserido é válido para o mês que o usuário informou
     try{
        if(d > getQuantDiasDoMes(getMes())){
            dia = 0;
            throw invalid_argument("Dia");
        }else{
            dia = d;
        }
    }

    catch(invalid_argument ex){
        cout << "Invalid Argument: Dia\n";
    }
}

void Data::setMes(int m){

    //Verifica se o mês inserido é válido
    try{
        if (m < 1 || m > 12){
            mes = 0;
            throw invalid_argument("Mes");
        }else{
            mes = m;
        }
    }

    catch(invalid_argument ex){
        cout << "Invalid Argument: Mes\n";
    }
}

void Data::setAno(int a){
    ano = a;
}

string Data:: to_txt(){
    return to_string(getDia()) + "/" + to_string(getMes()) + "/" + to_string(getAano());
}
