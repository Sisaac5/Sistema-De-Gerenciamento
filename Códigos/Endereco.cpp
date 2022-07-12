#include "Endereco.h"

Endereco::Endereco(string cep){
    
    SetComandos(cep);
    string aux;
    ifstream arqI;

    system(dowloadComand.c_str());

    arqI.open("index.html");

    try{

        if(!arqI.is_open()){
            throw domain_error("CEP INVÁLIDO");
        }

        for(int i = 0; i < 7; i++){
            getline(arqI, aux);

            switch (i){

            case 1:
                if(aux == "  \"erro\": \"true\""){
                    arqI.close();
                    system(deleteComand.c_str());
                    throw domain_error("CEP INVÁLIDO");
                }

            case 2:
                setRua(aux);
                formataRua();
                break;

            case 4:
                setBairro(aux);
                formataBairro();
                break;

            case 5:
                setCidade(aux);
                formataCidade();
                break;

            case 6:
                setEstado(aux);
                formataEstado();
                break;
            }
        }

        arqI.close();
        system(deleteComand.c_str());
    }

    catch(domain_error a){
        this->valid_cep = false;
        cout << "CEP INVÁLIDO" << endl;
    }

}

Endereco::~Endereco(){}

Endereco::Endereco(){}

Endereco::Endereco(string txt, int i){

    setRua(txt.substr(0, txt.find(";")));
    txt.erase(0, txt.find(";") + 1);

    setBairro(txt.substr(0, txt.find(";")));
    txt.erase(0, txt.find(";") + 1);

    setCidade(txt.substr(0, txt.find(";")));
    txt.erase(0, txt.find(";") + 1);

    setEstado(txt.substr(0, txt.find(";")));
    txt.erase(0, txt.find(";") + 1);

}

void Endereco:: SetComandos(string cep){

    dowloadComand = "wget -q https://viacep.com.br/ws/"+ cep +"/json/";

    #ifdef __linux__
        deleteComand = "unlink index.html";
    #endif

    #ifdef _WIN32
        deleteComand = "del index.html";
    #endif
}

string Endereco:: to_txt(){
    return getRua() + ";" + getBairro() + ";" + getCidade() + ";" + getEstado();
}

void Endereco::formataRua(){
    rua.erase(0,17);
    rua.erase(rua.end() - 2, rua.end());
}

void Endereco::formataBairro(){
    bairro.erase(0,13);
    bairro.erase(bairro.end() - 2, bairro.end());
}

void Endereco::formataCidade(){
    cidade.erase(0,17);
    cidade.erase(cidade.end() - 2, cidade.end());
}

void Endereco::formataEstado(){
    estado.erase(0,9);
    estado.erase(estado.end() - 2, estado.end());
}

void Endereco::print(){
    if(valid_cep){
        cout << "Estado: " << getEstado() << endl;
        cout << "Cidade: " << getCidade() << endl;
        cout << "Bairro: " << getBairro() << endl;
        cout << "Rua: " << getRua() << endl;
    }
}

string Endereco::getRua(){
    return rua;
}

string Endereco::getBairro(){
    return bairro;
}

string Endereco::getCidade(){
    return cidade;
}

string Endereco::getEstado(){
    return estado;
}

void Endereco::setRua(string rua){
   this->rua = rua;
}

void Endereco::setBairro(string bairro){
   this->bairro = bairro;
}

void Endereco::setCidade(string cidade){
   this->cidade = cidade;
}

void Endereco::setEstado(string estado){
   this->estado = estado;
}
