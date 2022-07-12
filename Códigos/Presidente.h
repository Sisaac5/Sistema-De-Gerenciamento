#include "Funcionario.h"

#ifndef PRESIDENTE_H
#define PRESIDENTE_H

class Presidente : public Funcionario{
    private:
        std::string formacaoAcademica;/**< N�vel de forma��o acad�mica do presidente. */
        std::string areaFormacao;/**< �rea de forma��o do presidente. */

    public:
        ///Construtor padr�o
        Presidente();

        ///Construtor com strings.
        /** \brief Construtor que atribui uma string ao atributo areaFormacao e outra ao formacaoAcademica.
         * \param areaFormacao string que armazena a �rea de forma��o do funcion�rio.
         * \param formacaoAcademica string que armazena o n�vel de forma��o acad�mica do funcion�rio.
         */
        Presidente(std::string formacaoAcademica, std::string areaFormacao);
        Presidente(string txt);

        ///Destrutor
        virtual ~Presidente();

        ///getFormacaoacademica.
        /** \brief Retorna o valor armazenado no atributo formacaoAcademica.
         * \return Uma string.
         */
        std::string getFormacaoacademica();

        ///getAreaformacao.
        /** \brief Retorna o valor armazenado no atributo areaFormacao.
         * \return Uma string.
         */
        std::string getAreaformacao();

        ///setFormacaoacademica.
        /** \brief M�todo que atribui uma string ao atributo formacaoAcademica.
         * \param formacaoAcademica string que armazena o n�vel de forma��o acad�mica do funcion�rio.
         * \return void.
         */
        void setFormacaoacademica(std::string formacaoAcademica);

        ///setAreaformacao.
        /** \brief M�todo que atribui uma string ao atributo areaFormacao.
         * \param areaFormacao string que armazena a �rea de forma��o do funcion�rio.
         * \return void.
         */
        void setAreaformacao(std::string areaFormacao);

        std::string to_txt();

        ///aumentaSalario.
        /** \brief M�todo herdado que aumenta o atributo salario em 30%.
         * \return void.
         */
        void aumentaSalario();
};

#endif
