#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>
#include "Data.h"
#include "Endereco.h"

class Funcionario{
    protected:
        std::string codigo;/**< Código do funcionário. */
        std::string nome;/**< Nome completo do funcionário. */
        Endereco endereco;/**< Composição da classe Endereco, armazenando informações extraidas do CEP. */
        std::string telefone;/**< Telefone do funcionário. */
        Data dataAdmissao;/**< Composição da classe Data, armazenando a data de admissão do funcionário. */
        std::string designacao;/**< Indica se o funcionário é um operador, gerente, diretor ou presidente. */
        double salario;/**< Armazena o salário do funcionário. */

        string Clean_CSV(string &str, string find, int reads);

    public:
        ///Construtor padrão.
        Funcionario();
        Funcionario(string txt);

        ///Destrutor.
        virtual ~Funcionario();

        ///setFuncionario.
        /** \brief Atribui as informações do funcionário aos atributos da classe.
         *
         * \param codigo uma string que armazena o código de identificação do funcionário.
         * \param nome uma string que armazena o nome completo do funcionário.
         * \param cep uma string que armazena o cep do funcionário.
         * \param telefone uma string que armazena o telefone para contato do funcionário.
         * \param designacaoN inteiro usado para indicar a ocupação do funcionário na empresa.
         * \param dia inteiro que armazena o dia de admissão.
         * \param mes inteiro que armazena o mês de admissão.
         * \param ano inteiro que armazena o ano de admissão.
         * \return void
         * \sa setEndereco(), setDataadmissao() e setDesignacao()
         */
        void setFuncionario(std::string codigo, std::string nome, std::string cep,
                            std::string telefone, int designacaoN, int dia, int mes, int ano);

        ///getCodigo
        /** \brief Retorna o valor armazenado no atributo codigo.
         * \return Uma string.
         */
        std::string getCodigo();

        ///getNome
        /** \brief Retorna o valor armazenado no atributo nome.
         * \return Uma string.
         */
        std::string getNome();

        ///getEndereco
        /** \brief Retorna o objeto criado a partir da classe Endereco.
         * \return Uma tipo Endereco.
         */
        Endereco getEndereco();

        ///getTelefone
        /** \brief Retorna o valor armazenado no atributo telefone.
         * \return Uma string.
         */
        std::string getTelefone();

        ///getDataAdmissao
        /** \brief Retorna o objeto criado a partir da classe Data.
         * \return Uma tipo Data.
         */
        Data getDataAdmissao();

        ///getDesignacao
        /** \brief Retorna o valor armazenado no atributo designacao.
         * \return Uma string.
         */
        std::string getDesignacao();

        ///getTelefone
        /** \brief Retorna o valor armazenado no atributo salario.
         * \return Um double.
         */
        double getSalario();

        ///setCodigo
        /** \brief Atribui um valor ao atributo codigo.
         * \return void.
         */
        void setCodigo(std::string codigo);

        ///setNome
        /** \brief Atribui um valor ao atributo nome.
         * \param nome string que armazena o nome completo do funcionário.
         * \return void.
         */
        void setNome(std::string nome);

        ///setEndereco
        /** \brief Atribui um valor ao objeto endereco.
         * \param cep string que armazena o CEP do funcionário e será usado para adquirir as informações do endereço.
         * \return void.
         */
        void setEndereco(std::string cep);

        ///setTelefone
        /** \brief Atribui um valor ao atributo telefone.
         * \param telefone string que armazena o telefone de contato do funcionário.
         * \return void.
         */
        void setTelefone(std::string telefone);

        ///setDataAdmissao
        /** \brief Atribui um valor ao objeto dataAdmissao.
         * \param dia inteiro que armazena o dia de admissão.
         * \param mes inteiro que armazena o mês de admissão.
         * \param ano inteiro que armazena o ano de admissão.
         * \return void.
         */
        void setDataAdmissao(int dia, int mes, int ano);

        ///setDesignacao
        /** \brief Atribui um valor ao atributo designacao a partir do numero da ocupacao.
         * \param designacaoN inteiro que armazena o número da ocupação do funcionário.
         * \return void.
         */
        void setDesignacao(int designacaoN);

        ///setSalario
        /** \brief Atribui um valor ao atributo salario.
         * \param salario double que armazena o valor do salário do funcionário.
         * \return void.
         */
        void setSalario(double salario);

        virtual string to_txt();

        ///aumentaSalario
        /** \brief Método herdado pelas classes filhas, aumentando o atributo salario em diferentes porcentagens.
         * \return void.
         */
        virtual void aumentaSalario();
};

#endif
