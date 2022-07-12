#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>
#include <fstream>

using namespace std;

class Endereco{

public:

    //! Construtor 1.
    /*!
    Construtor vazio
    */
    Endereco();


    //! Construtor 2.
    /*!
    \param string cep
    Utliza o cep entregue como parâmetro para obter informação pela API viacep
    */
    Endereco(string cep);

    //! Construtor 3.
    /*!
    \param string txt uma string com os atributos Rua, Bairro, Cidade e Estado separados por ;
    \param int i diferencia o Construtor 1 e o Construtor 2
    Trata uma string com atributos separados por ;
    */
    Endereco(string txt, int i);


    //! Destrutor
    virtual ~Endereco();


    /*!
    \return string com atributos Rua, Bairro, Cidade e Estado separados por ponto e virgula
    */
    string to_txt();


    /*!
    Apenas exibe os atributos rua, bairro, cidade e estado no console
    */
    void print();

    //gets e sets
    string getRua();
    string getBairro();
    string getCidade();
    string getEstado();

    void setRua(string rua);
    void setBairro(string bairro);
    void setCidade(string cidade);
    void setEstado(string estado);

private:
    string rua;
    string bairro;
    string cidade;
    string estado; //atributos padr�o para o endere�o

    bool valid_cep = true; //verifica se o cep dado como par�metro � v�lido

    void formataRua(); //formata as strings retiradas dos arquivos
    void formataBairro();
    void formataCidade();
    void formataEstado();

    string dowloadComand; //comandos a serem inseridos no cmd do windows ou no terminal do linux
    string deleteComand;

    void SetComandos(string cep); // verifica em qual SO o codigo est� rodando, afim de definir os comandos
};


#endif
