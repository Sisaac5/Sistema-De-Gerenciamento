/*!
* \file Data.h
* \author Isaac
* \version 0.1
* \date 13/06/2022
* \brief 
* \remarks None
* 
* 
* 
*/


#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

class Data
{
    public:
        
        //! Construtor 1.
        /*!
        Construtor vazio.
        */
        Data();


        //! Construtor 2.
        /*!
        Recebe os atributos dia, mes e ano.
        \param d dia
        \param m mes
        \param a ano
        */
        Data(int d, int m, int a);


        //! Construtor 3.
        /*!
        Recebe uma string com dia, mes e ano separados por barras
        */
        Data(string txt);


        //! Destrutor
        virtual ~Data();


        //gets e sets
        int getDia();
        int getMes();
        int getAano();
        void setDia(int d);
        void setMes(int m);
        void setAno(int a);


        /*!
        \param m mes 
        \return a quantidade de dias do mes m (int).
        */
        int getQuantDiasDoMes(int m);


        /*!
        \return a posição da data em relação aos 365 dias do ano (int).
        */
        int getDiaDoAno();


        //! Preapara a classe para ser escrita em aquivos.
        /*!
        \return string com atribitos dia, mês e ano separados por barras
        */
        string to_txt();


    protected:

    private:

        int dia;
        int mes;
        int ano;
        int quantDias[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

#endif // DATA_H
