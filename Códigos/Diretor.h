#include "Funcionario.h"

#ifndef DIRETOR_H
#define DIRETOR_H

class Diretor : public Funcionario{
    private:
        std::string areaSupervisao;/**< �rea de supervis�o do diretor. */
        std::string areaFormacao;/**< �rea de forma��o do diretor. */

    public:
        ///Construtor padr�o.
        Diretor();

        ///Construtor com strings.
        /** \brief Construtor que atribui uma string ao atributo areaSupervisao e outra ao areaFormacao.
         * \param areaSupervisao string que armazena a �rea de supervis�o do funcion�rio.
         * \param areaFormacao string que armazena a �rea de forma��o do funcion�rio.
         */
        Diretor(std::string areaSupervisao, std::string areaFormacao);
        Diretor(std::string txt);

        ///Destrutor
        virtual ~Diretor();

        ///getAreasupervisao.
        /** \brief Retorna o valor armazenado no atributo areaSupervisao.
         * \return Uma string.
         */
        std::string getAreasupervisao();

        ///getAreaformacao.
        /** \brief Retorna o valor armazenado no atributo areaFormacao.
         * \return Uma string.
         */
        std::string getAreaformacao();

        ///setAreasupervisao.
        /** \brief M�todo que atribui uma string ao atributo areaSupervisao.
         * \param areaSupervisao string que armazena a �rea de supervis�o do funcion�rio.
         * \return void.
         */
        void setAreasupervisao(std::string areaSupervisao);

        ///setAreaformacao.
        /** \brief M�todo que atribui uma string ao atributo areaFormacao.
         * \param areaFormacao string que armazena a �rea de forma��o do funcion�rio.
         * \return void.
         */
        void setAreaformacao(std::string areaFormacao);
        std:: string to_txt();

        ///aumentaSalario.
        /** \brief M�todo herdado que aumenta o atributo salario em 20%.
         * \return void.
         */
        void aumentaSalario();
};

#endif
