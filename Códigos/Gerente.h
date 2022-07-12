#include "Funcionario.h"

#ifndef GERENTE_H
#define GERENTE_H

class Gerente : public Funcionario{
    private:
        std::string areaSupervisao;/**< �rea de supervis�o do gerente. */

    public:
        ///Construtor padr�o.
        Gerente();

        ///Construtor com string.
        /** \brief Construtor que atribui uma string ao atributo areaSupervisao.
         * \param areaSupervisao string que armazena a �rea de supervis�o do funcion�rio.
         */
        Gerente(std::string areaSupervisao);

        Gerente(std::string txt, int i);

        ///Destrutor.
        virtual ~Gerente();

        ///getAreasupervisao.
        /** \brief Retorna o valor armazenado no atributo areaSupervisao.
         * \return Uma string.
         */
        std::string getAreasupervisao();

        ///setAreasupervisao.
        /** \brief M�todo que atribui uma string ao atributo areaSupervisao.
         * \param areaSupervisao string que armazena a �rea de supervis�o do funcion�rio.
         * \return void.
         */
        void setAreasupervisao(std::string areaSupervisao);

        ///aumentaSalario.
        /** \brief M�todo herdado que aumenta o atributo salario em 10%.
         * \return void.
         */
        void aumentaSalario();

        std::string to_txt();
};

#endif
