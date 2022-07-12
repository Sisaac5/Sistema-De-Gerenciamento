#include <ctime>
#include <vector>
#include <fstream>
#include <string>
#include "Data.h"
#include "Funcionario.h"
#include "Diretor.h"
#include "Gerente.h"
#include "Operador.h"
#include "Presidente.h"


#ifndef SISTEMAGERENCIAFUNCIONARIO_H
#define SISTEMAGERENCIAFUNCIONARIO_H


class SistemaGerenciaFuncionario{
    private:
        std::vector<Funcionario *> funcionarios;/**< Vector que armazena objetos do tipo Funcionario. */

        //trasforma os caracteres alfabéticos em maiúsculos
        string toUpper(string texto);

        //auxilia na formatação das folhas de pagamento
        string escreveFormato(string texto);

        //retorna um número aleatório dentro de um intervalo definido
        int numeroAleatorio(int maior, int menor);

        //atualiza o aquivo backup ao encerrar o sistema
        void endSystem();

        //faz leitura do arquivo backup para iniciar o sistema
        void startSystem();

        // adiciona um funcionario
        void addFuncionario(Funcionario *func);

        //Libera da memória os espaços alocados dinamicamente do vector funcionários.
        void liberaMemoria();

        // Método que retorna o desconto do INSS de acordo com o salário passado.
        double calculaINSS(double salario);

        // Método que retorna o desconto do imposto de renda de acordo com o salário passado.
        double calculaImpostoRenda(double salario);

    public:
        ///Construtor padrão.
        SistemaGerenciaFuncionario();

        ///Destrutor.
        virtual ~SistemaGerenciaFuncionario();

        ///pushOperador.
        /** \brief Aloca no vector espaco na memória para um objeto do tipo Operador.
         * \return void.
         */
        void pushOperador();

        ///pushGerente.
        /** \brief Aloca no vector espaco na memória para um objeto do tipo Gerente.
         * \return void.
         */
        void pushGerente();

        ///pushDiretor.
        /** \brief Aloca no vector espaco na memória para um objeto do tipo Diretor.
         * \return void.
         */
        void pushDiretor();

        ///pushPresidente.
        /** \brief Aloca no vector espaco na memória para um objeto do tipo Presidente.
         * \return void.
         */
        void pushPresidente();

        /*Todos os m�todos set possuem o par�metro pos, o qual � respons�vel por indicar o �ndice do
          vector no qual os valores devem ser setados
          OBS.: Os m�todos set da SistemaGerenciaFuncionario chamam sets da classe funcionario.
                Esse procedimento foi necess�rio pelo fato de que o vector funcion�rios deve ser
                encapsulado (private)*/

        ///setFuncionario.
        /** \brief Chama os métodos set da classe Funcionario e atribui as informações do funcionário no índice do vector.
         *
         * \param cod uma string que armazena o código de identificação do funcionário.
         * \param nom uma string que armazena o nome completo do funcionário.
         * \param ende uma string que armazena o cep do funcionário.
         * \param tel uma string que armazena o telefone para contato do funcionário.
         * \param desig inteiro usado para indicar a ocupação do funcionário na empresa.
         * \param d inteiro que armazena o dia de admissão.
         * \param m inteiro que armazena o mês de admissão.
         * \param a inteiro que armazena o ano de admissão.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void
         */
        void setFuncionario(std::string cod, std::string nom, std::string ende,
                            std::string tel, int desig, int d, int m, int a, int pos);

        ///setAreasupervisao.
        /** \brief Método que chama o setAreasupervisao() do objeto de tipo Gerente ou Diretor.
         * \param areaS string que armazena a área de supervisão do funcionário.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void setAreasupervisao(std::string  areaS, int pos);

        ///setAreaformacao.
        /** \brief Método que chama o setAreasupervisao() do objeto de tipo Diretor ou Presidente.
         * \param areaF string que armazena a área de formação do funcionário.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void setAreaformacao(std::string areaF, int pos);

        ///setFormacaoacademica.
        /** \brief Método que chama o setFormacaoacademica() do objeto de tipo Presidente.
         * \param formacaoA string que armazena o nível de formação acadêmica do funcionário.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void setFormacaoacademica(std::string formacaoA, int pos);

        ///setCodigo.
        /** \brief Método que chama o setCodigo() do objeto de tipo Funcionario.
         * \param codigo string que armazena o código de indentificação do funcionário.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void setCodigo(std::string codigo, int pos);

        ///setNome.
        /** \brief Método que chama o setNome() do objeto de tipo Funcionario.
         * \param nome string que armazena o nome completo do funcionário.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void setNome(std::string nome, int pos);

        ///setEndereco.
        /** \brief Método que chama o setEndereco() do objeto de tipo Funcionario.
         * \param endereco string que armazena o CEP do funcionário que será usado para adquirir as demais informações de seu endereço.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void setEndereco(std::string endereco, int pos);

        ///setTelefone.
        /** \brief Método que chama o setTelefone() do objeto de tipo Funcionario.
         * \param telefone string que armazena o telefone de contato do funcionário.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void setTelefone(std::string telefone, int pos);

        ///setDesignacao.
        /** \brief Método que chama o setDesignacao do objeto de tipo Funcionario.
         * \param designacaoN inteiro que armazena o número referente ao cargo do funcionário.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void setDesignacao(int designacaoN, int pos);

        ///setSalario.
        /** \brief Método que chama o setSalario() do objeto de tipo Funcionario.
         * \param Salario double que armazena o salario do funcionário.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void setSalario(double salario, int pos);

        ///setDataAdmissao.
        /** \brief Método que chama o setDataAdmissao() do objeto de tipo Funcionario.
         * \param dia inteiro que armazena o dia de admissão.
         * \param mes inteiro que armazena o mês de admissão.
         * \param ano inteiro que armazena o ano de admissão.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void setDataAdmissao(int dia, int mes, int ano, int pos);

        ///getSize.
        /** \brief Método que retorna a quantidade de objetos armazenados no vector funcionarios (o seu tamanho).
         * \return Um inteiro.
         */
        int getSize();

        ///imprimeFuncionario.
        /** \brief Método que imprime os dados do objeto Funcionario encontrado no índice passado.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void imprimeFuncionario(int pos);

        ///imprimeFuncionarioDesig.
        /** \brief Método que imprime os dados do objeto Funcionario encontrado no índice passado caso coincida com a designação passada.
         * \param desig string que indica quais funcionários devem ser impressos de acordo com sua ocupação.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void imprimeFuncionarioDesig(std::string desig, int pos);

        ///deletaFuncionario.
        /** \brief Método que remove do vector funcionarios o objeto armazenado no índice passado.
         * \param pos inteiro que indica o índice do vector ao qual as informações serão atribuídas.
         * \return void.
         */
        void deletaFuncionario(int pos);

        ///buscaCodFuncionario.
        /** \brief Faz uma busca do código passado dentre os já cadastrados e retorna, caso encontrado, seu índice no vector.
         * \param cod string que armazena o código a ser buscado.
         * \return Um inteiro.
         */
        int buscaCodFuncionario(std::string cod);

        ///buscaNomeFuncionario.
        /** \brief Faz uma busca do nome passado dentre os já cadastrados e imprime, caso encontrado, seus dados.
         * \param nome string que armazena o nome a ser buscado.
         * \return void.
         */
        void buscaNomeFuncionario(std::string nome);

        ///buscaDataDia.
        /** \brief Faz uma busca dos funcionários admtidos entre dois dias dentro de um mesmo mês e ano, imprimindo, caso encontrado, os seus dados.
         * \param d1 inteiro que armazena o dia no qual a busca se iniciará.
         * \param d2 inteiro que armazena o dia no qual a busca se encerrará.
         * \param m inteiro que indica o mês no qual será realizada a busca.
         * \param a inteiro que indica o ano no qual será realizada a busca.
         * \return void.
         */
        void buscaDataDia(int d1, int d2, int m, int a);

        ///buscaDataMes.
        /** \brief Faz uma busca dos funcionários admtidos entre dois meses dentro de um mesmo ano, imprimindo, caso encontrado, os seus dados.
         * \param m1 inteiro que armazena o mês no qual a busca se iniciará.
         * \param m2 inteiro que armazena o mês no qual a busca se encerrará.
         * \param a inteiro que indica o ano no qual será realizada a busca.
         * \return void.
         */
        void buscaDataMes(int m1, int m2, int a);

        ///buscaDataMes.
        /** \brief Faz uma busca dos funcionários admtidos entre dois anos, imprimindo, caso encontrado, os seus dados.
         * \param a1 inteiro que armazena o ano no qual a busca se iniciará.
         * \param a2 inteiro que armazena o ano no qual a busca se encerrará.
         * \return void.
         */
        void buscaDataAno(int a1, int a2);

        ///buscaNomeFuncionarioIndex.
        /** \brief Faz uma busca do nome passado dentre os já cadastrados e retorna, caso encontrado, seu índice no vector.
         * \param nome string que armazena o nome a ser buscado.
         * \return Um inteiro.
         */
        int buscaNomeFuncionarioIndex(std::string nome);

        ///setSalario.
        /** \brief Método que chama o getDesignacao() do objeto de tipo Funcionario.
         * \param pos inteiro que indica o índice do vector do qual as informações serão extraídas.
         * \return Uma string.
         */
        std::string getDesigFuncionario(int pos);

        ///existeDesigFuncionario.
        /** \brief Faz uma busca da designação passada dentre os já cadastrados e retorna, caso encontrado, um valor positivo.
         * \param desig string que armazena a designação a ser buscada.
         * \return Um inteiro.
         */
        int existeDesigFuncionario(std::string desig);

        ///aumentoDeSalario.
        /** \brief Método que chama o respectivo aumentaSalario() de cada objeto do vector.
         * \return void.
         */
        void aumentoDeSalarios();

        ///folhaSalarialFuncionario.
        /** \brief Método que calcula, imprime e retorna o salário líquido do funcionário.
         * \param pos inteiro que indica o índice do funcionário que terá seu salário líquido calculado.
         * \return Um double.
         * \sa
         */
        double folhaSalarialFuncionario(int pos);

        ///folhaSalarialAnual.
        /** \brief Exibe os gastos mensais da empresa e o total anual.
         * \param ano ano de referência.
         * \return void.
         */
        void folhaSalarialAnual(int ano);

        ///buscaEnderecoRua.
        /** \brief Busca por funcionarios que residem em uma determinada rua.
         * \param _rua string que guarda a rua usada na busca.
         * \return void.
         */
        void buscaEnderecoRua(string _rua);

        ///buscaEnderecoBairro.
        /** \brief Busca por funcionarios que residem em um determinado bairro.
         * \param _bairro string que guarda o bairro usado na busca.
         * \return void.
         */
        void buscaEnderecoBairro(string _bairro);

        ///buscaEnderecoCidade.
        /** \brief Busca por funcionarios que residem em uma determinada cidade.
         * \param _cidade string que guarda a cidade usada na busca.
         * \return void.
         */
        void buscaEnderecoCidade(string _cidade);

        ///buscaEnderecoEstado.
        /** \brief Busca por funcionarios que residem em um determinado estado.
         * \param _estado string que guarda a sigla do estado usado na busca.
         * \return void.
         */
        void buscaEnderecoEstado(string _estado);

        ///geraFolhaMensal.
        /** \brief Método que calcula e imprime o salário líquido dos funcionários e total pago pela empresa dentro de um mês.
         * \param mes mes de referência.
         * \param ano ano de referência.
         * \param bool-anual indica que mais de uma folha do mesmo ano estão sendo geradas ao mesmo tempo.
         * \return void.
         */
        void geraFolhaMensal(int mes, int ano,bool anual=false);

        ///imprimeFolha.
        /** \brief Abre arquivo e exibe suas informações.
         * \param mes mes de referência.
         * \param ano ano de referência.
         * \return void.
         */
        void imprimeFolha(int mes, int ano);
};

#endif
