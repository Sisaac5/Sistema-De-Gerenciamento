#include <stdlib.h>
#include <locale>
#include "SistemaGerenciaFuncionario.h"

#ifdef __linux__ 
    #include <unistd.h>
    #define CLEAN "clear"

#elif _WIN32 || _WIN64
    #include <windows.h>
    #define CLEAN "cls"
#else
    #error "OS not supported!"
#endif

void mySleep(int sleepMs){ //Função responsável por fazer a transformação de acordo com o sistema operacional, para parar o programa por alguns instantes.
    #ifdef __linux__
        usleep(sleepMs * 1000);   
    #endif
    #ifdef _WIN32 
        Sleep(sleepMs);
    #endif
}
void caracteres(){
    #ifdef _WIN32 
    SetConsoleOutputCP(CP_UTF8); 
    #endif
}

using namespace std;

int main(){
    caracteres(); //Função para imprimir os couts com caracteres especiais
    SistemaGerenciaFuncionario empresa = SistemaGerenciaFuncionario();/*empresa é a váriavel responsável por controlar o programa, tendo
                                                                        dentro de si um vector do tipo funcionario, o qual armazena os
                                                                        diversos dados dos funcionários cadastrados.*/
                            
    string codigo, nome, endereco, telefone;/*Variáveis responsáveis por armazenarem temporariamente os dados dos funcionários.
                                               Isso aplica-se a todas as seguintes, com exceção de n, menu e totalFuncionarios*/
    int designacao;
    string areaSupervisao, areaFormacao, formacaoAcademica;
    int dia, mes, ano;
    int n, menu;//n armazena um número fornecido pelo usuário que será usado no laço de repetição do for
                 //menu recebe comandos entre 1 e 10 para executar funções de acordo com a vontade do usuário
    double salario;
    int totalFuncionarios = empresa.getSize();//Variável usada para manter o controle do total de funcionários cadastrados
    string cod;

    //Laço usado para manter o programa em funcionamento até que o usuário selecione encerrá-lo
    while(true){

        cout << "-----------------------------------------------" << endl;
        cout << "           SISTEMA DE GERENCIAMENTO            " << endl;
        cout << "-----------------------------------------------" << endl << endl;
        cout << "   Insira o número referente ao que deseja:" << endl;
        cout << " 1-Adicionar um novo funcionário;" << endl;
        cout << " 2-Modificar ou editar um registro de funcionário;" << endl;
        cout << " 3-Excluir um registro de funcionário;" << endl;
        cout << " 4-Exibir lista de funcionários;" << endl;
        cout << " 5-Conceder aumento para os funcionários;" << endl;
        cout << " 6-Calcular folha salarial;" << endl;
        cout << " 7-Imprimir folha salarial de um funcionário;" << endl;
        cout << " 8-Imprimir folha salarial da empresa;" << endl;
        cout << " 9-Buscar;" << endl;
        cout << " 10-Sair." << endl << endl;

        cout << "Opção: ";
        cin >> menu;
        system(CLEAN);

        if(menu < 1 || menu > 10){
            break;
        }

        switch(menu){
            //Adicionar Funcionário
            case 1:{
                cout << "Quantos funcionários deseja cadastrar?" << endl;
                cin >> n;
                system(CLEAN);
                /*totalFuncionarios usado nesse laço for para manter o controle da quantidade de funcionários
                cadastrados na empresa e evitar que dados sejam sobrescritos acidentalmente*/
                for(int i = totalFuncionarios; i < (n + totalFuncionarios); i++){
                    int indexCod;

                    cout << "---------------------------------" << endl;
                    cout << "           CADASTRO "<< i+1 << "           " << endl;
                    cout << "---------------------------------" << endl << endl;

                    cout << " 0-Operador;" << endl;
                    cout << " 1-Gerente;" << endl;
                    cout << " 2-Diretor;" << endl;
                    cout << " 3-Presidente." << endl;
                    cout << "Qual a designação desse funcionário? ";
                    cin >> designacao;

                    if(designacao < 0 || designacao > 3){
                        system(CLEAN);
                        cout << "Opção inválida!" << endl;
                        mySleep(1000);
                        system(CLEAN);
                        break;
                    }

                    cout << "Data de Admicao:\n\tDia: ";
                    cin >> dia;
                    cout << "\tMês: ";
                    cin >> mes;
                    cout << "\tAno: ";
                    cin >> ano;
                    cin.ignore();

                    cout << "Código: ";
                    getline(cin, cod);
                    indexCod = empresa.buscaCodFuncionario(cod);

                    //Verifica se o funcionário já existe
                    if(indexCod >= 0){
                        cout << "Código já existente para outro funcionário" << endl;
                        cout << "Insira outro código: ";
                        getline(cin, cod);
                        indexCod = empresa.buscaCodFuncionario(cod);
                        if(indexCod >= 0){
                            cout << "Código já existente para outro funcionário, reinicie o cadastro!" << endl;
                            break;
                        }else{
                            cout << "Nome: ";
                            getline(cin, nome);
                            cout << endl;
                            cout << "CEP:";
                            getline(cin, endereco);
                            cout << endl;
                            cout << "Telefone: ";
                            getline(cin, telefone);
                            cout << endl;
                        }
                    }else{
                        cout << "Nome: ";
                        getline(cin, nome);
                        cout << "CEP:";
                        getline(cin, endereco);
                        cout << "Telefone: ";
                        getline(cin, telefone);
                    }

                    /*Os seguintes Ifs verificam qual a designação do funcionário e, caso necessário,
                    requisitam a insercação dos dados pendentes*/
                    if(designacao == 0){
                        empresa.pushOperador();
                    }

                    if(designacao == 1){
                        empresa.pushGerente();
                        cout << "Área de supervisão: ";
                        getline(cin, areaSupervisao);
                        empresa.setAreasupervisao(areaSupervisao, i);
                    }

                    if(designacao == 2){
                        empresa.pushDiretor();
                        cout << "Área de supervisão: ";
                        getline(cin, areaSupervisao);
                        cout << "Área de formação: ";
                        getline(cin, areaFormacao);

                        empresa.setAreasupervisao(areaSupervisao, i);
                        empresa.setAreaformacao(areaFormacao, i);
                    }

                    if(designacao == 3){
                        empresa.pushPresidente();
                        cout << "Área de supervisão: ";
                        getline(cin, areaSupervisao);
                        cout << "Área de formação: ";
                        getline(cin, areaFormacao);

                        empresa.setAreaformacao(areaFormacao, i);
                        empresa.setFormacaoacademica(formacaoAcademica, i);
                    }

                    /*Seta os dados dos funcionários no vector do tipo funcionario dentro da variável empresa,
                    que é do tipo SistemaGerenciaFuncionario*/
                    empresa.setFuncionario(cod, nome, endereco, telefone, designacao, dia, mes, ano, i);
                }

                totalFuncionarios += n; //Atualiza o total de funcionários cadastrados

                mySleep(1000);
                system(CLEAN);
                break;
            }
            //Atualizar funcionário 
            case 2:{
                int indexCod;
                int atualizar;
                string auxDesig;

                cin.ignore();
                cout << "Insira o código do funcionário que deseja atualizar o registro: " << endl;
                getline(cin, cod);
                indexCod = empresa.buscaCodFuncionario(cod); //Verifica a existência do funcionário

                if(indexCod >= 0){
                    /*Verifica a designação do funcionário para pemritir a atualização de dados exclusivos
                    a certos cargos*/
                    auxDesig = empresa.getDesigFuncionario(indexCod);

                    cout << "Digite o número do que deseja atualizar: " << endl;
                    cout << " 1-Código;" << endl;
                    cout << " 2-Nome;" << endl;
                    cout << " 3-Endereço;" << endl;
                    cout << " 4-Telefone;" << endl;
                    cout << " 5-Designação;" << endl;
                    cout << " 6-Sálario;" << endl;
                    cout << " 7-Área de supervisão;" << endl;
                    cout << " 8-Área de formação;" << endl;
                    cout << " 9-Formação acadêmica;" << endl;
                    cout << " 10-Data de ingresso;" << endl;

                    cin >> atualizar;// Recebe o comando do dado que o usuário deseja atualizar
                    cin.ignore();

                    if(atualizar < 1 || atualizar > 11){
                        system(CLEAN);
                        cout << "Opção inválida!" << endl;
                        mySleep(1000);
                        system(CLEAN);
                        break;
                    }

                    if(atualizar == 1){
                        cout << "Insira o novo código: ";
                        getline(cin, codigo);
                        empresa.setCodigo(codigo, indexCod);
                    }

                    if(atualizar == 2){
                        cout << "Insira o novo nome: ";
                        getline(cin, nome);
                        empresa.setNome(nome, indexCod);
                    }

                    if(atualizar == 3){
                        cout << "Digite o novo CEP: ";
                        getline(cin, endereco);
                        empresa.setEndereco(endereco, indexCod);
                    }

                    if(atualizar == 4){
                        cout << "Insira o novo telefone: ";
                        getline(cin, telefone);
                        empresa.setTelefone(telefone, indexCod);
                    }

                    if(atualizar == 5){
                        cout << "Insira a nova designação: ";
                        cin >> designacao;
                        empresa.setDesignacao(designacao, indexCod);
                    }

                    if(atualizar == 6){
                        cout << "Insira o novo salário: ";
                        cin >> salario;
                        empresa.setSalario(salario, indexCod);
                    }

                    if(atualizar == 7){
                        if(auxDesig == "Gerente" || auxDesig == "Diretor"){
                            cout << "Insira a nova área de supervisão: ";
                            getline(cin, areaSupervisao);
                            empresa.setAreasupervisao(areaSupervisao, indexCod);
                        }else{
                            cout << "Opção inválida!" << endl;
                        }
                    }

                    if(atualizar == 8){
                        if(auxDesig == "Diretor" || auxDesig == "Presidente"){
                            cout << "Insira a nova área de formação: ";
                            getline(cin, areaFormacao);
                            empresa.setAreaformacao(areaFormacao, indexCod);
                        }else{
                            cout << "Opção inválida!" << endl;
                        }
                    }

                    if(atualizar == 9){
                        if(auxDesig == "Presidente"){
                            cout << "Insira a nova formação acadêmica: ";
                            getline(cin, formacaoAcademica);
                            empresa.setFormacaoacademica(formacaoAcademica, indexCod);
                        }
                    }

                    if(atualizar == 10){
                        cout << "Insira a nova data de ingresso: ";
                        cout << "\tDia: ";
                        cin >> dia;
                        cout << "\tMês: ";
                        cin >> mes;
                        cout << "\tAno: ";
                        cin >> ano;
                        empresa.setDataAdmissao(dia, mes, ano, indexCod);
                    }
                }else{
                    cout << "Funcionário não encontrado" << endl;
                }
                cout << "Atualização realizada." << endl;
                mySleep(2000);
                system(CLEAN);
                break;
            }
            //Excluir funcionarios 
            case 3:{
                int indexCod;
                int flag = 0;//flag responsável por impedir que um Diretor ou Presidente seja deletado
                string auxDesig;
                string confirma;
                string codBusca;

                cin.ignore();
                cout << "Insira o código do funcionário que deseja excluir: " << endl;
                getline(cin, codBusca);
                indexCod = empresa.buscaCodFuncionario(codBusca);//Verifica a existência do funcionário

                if(indexCod >= 0){
                    auxDesig = empresa.getDesigFuncionario(indexCod);//Verifica a função do funcionário na empresa
                    if(auxDesig == "Diretor" || auxDesig == "Presidente"){
                        flag = 1;//Atribui 1 a set, impedindo que o funcionário seja deletado
                        cout << "Funcionario não pode ser deletado" << endl;
                    }
                }

                if(indexCod >= 0 && flag == 0){
                    cout << "Deseja realmente excluir esse registro?" << endl;
                    getline(cin,confirma);

                    if(confirma == "Sim" || confirma == "sim"){
                        //Caso o funcionário seja um operador ou gerente, será deletado
                        empresa.deletaFuncionario(indexCod);
                        
                        cout << "Funcionário deletado." << endl;
                        totalFuncionarios--; //Atualiza o total de funcionários cadastrados
                    }else{
                        cout << "Operação cancelada" << endl;
                    }
                }

                mySleep(2000);
                system(CLEAN);
                break;
            }
            //Imprimir dados
            case 4:{
                int imprimir;

                cout << "Escolha a opção que deseja:" << endl;
                cout << " 1-Imprimir dados de todos os funcionários." << endl;
                cout << " 2-Imprimir os dados de apenas um designação." << endl;
                cin >> imprimir;

                if(imprimir < 1 || imprimir > 2){
                    system(CLEAN);
                    cout << "Opção inválida!" << endl;
                    mySleep(1000);
                    system(CLEAN);
                    break;
                }

                //Função voltada a simplesmente imprimir todos os funcionários cadastrados
                if(imprimir == 1){
                    for(int i = 0; i < totalFuncionarios; i++){
                        cout << endl;
                        empresa.imprimeFuncionario(i);
                        cout << endl;
                    };
                }

                //Imprime designacao
                if(imprimir == 2){
                    string auxDesig;
                    int flag;

                    cin.ignore();
                    cout << "Insira a designação desejada (primeira letra maiúscula): "; 
                    getline(cin, auxDesig);
                    cout << endl;

                    //Verifica se funcionários com o cargo buscado existem na empresa
                    flag = empresa.existeDesigFuncionario(auxDesig);

                    if(flag >= 1){
                        for(int i = 0; i < totalFuncionarios; i++){
                            empresa.imprimeFuncionarioDesig(auxDesig, i);
                        }
                    }else{
                        cout << "Designacao Inexistente na Lista" << endl;
                    }
                }

                break;
            }
            //Aumentar salário
            case 5:{
                empresa.aumentoDeSalarios();
                cout << "Aumento Realizado" << endl << endl;

                mySleep(2000);
                system(CLEAN);
                break;
            }
            //Cálculo da Folha Salarial
            case 6:{
                int mes, ano;
                cout << "Para ser realizado o cálculo da folha salarial, insira:" << endl;
                cout << "Mês: ";
                cin >> mes;
                cout << "Ano: ";
                cin >> ano;

                empresa.geraFolhaMensal(mes, ano);

                mySleep(2000);
                system(CLEAN);
                break;
            }
            //Imprime Folha Salarial de um funcionário
            case 7:{
                int indexBusca;
                int metodoPesquisa;//Recebe o método de pesquisa desejado pelo usuário
                string codBusca, nomeBusca;

                cout << "Insira o método de pesquisa desejado para o cálculo da folha salarial: " << endl;
                cout << " 1-Código;" << endl;
                cout << " 2-Nome." << endl;
                cin >> metodoPesquisa;
                cin.ignore();

                if(metodoPesquisa < 1 || metodoPesquisa > 2){
                    system(CLEAN);
                    cout << "Opção inválida!" << endl;
                    mySleep(1000);
                    system(CLEAN);
                    break;
                }

                if(metodoPesquisa == 1){
                    cout << "Código do funcionário: "; 
                    getline(cin, codBusca);
                    indexBusca = empresa.buscaCodFuncionario(codBusca);
                }

                if(metodoPesquisa == 2){
                    cout << "Nome do funcionário: ";
                    getline(cin, nomeBusca);
                    indexBusca = empresa.buscaNomeFuncionarioIndex(nomeBusca);
                }

                 //Imprime, caso o funcionário exista, a sua folha salarial
                if(indexBusca >= 0){
                    empresa.folhaSalarialFuncionario(indexBusca);
                }
                mySleep(10000);
                system(CLEAN);
                break;
            }
            //Imprime Folha Salarial da empresa
            case 8:{
                int escolha;
                cout << "Insira qual folha salarial deseja:" << endl;
                cout << " 1-Mensal;" << endl;
                cout << " 2-Anual." << endl;

                cin >> escolha;

                if(escolha < 1 || escolha > 2){
                    system(CLEAN);
                    cout << "Opção inválida!" << endl;
                    mySleep(1000);
                    system(CLEAN);
                    break;
                }

                if(escolha == 1){
                    int mes, ano;

                    cout << "Insira o mês e o ano desejado." << endl;
                    cout << "Mês: ";
                    cin >> mes;
                    cout << "Ano: ";
                    cin >> ano;

                    empresa.imprimeFolha(mes, ano);
                }
                if(escolha == 2){
                    int ano;
                    cout << "Digite o ano de referência: ";
                    cin >> ano;
                    empresa.folhaSalarialAnual(ano);
                }
                break;
            }
             //Buscas
            case 9:{
                int buscar;
                
                cout << " 1-Código;" << endl;
                cout << " 2-Nome;" << endl;
                cout << " 3-Data de Admissão;" << endl;
                cout << " 4-Endereço." << endl;
                cout << "Insira um método de busca: ";

                cin >> buscar;
                if(buscar < 1 || buscar > 4){
                    system(CLEAN);
                    cout << "Opção inválida!" << endl;
                    mySleep(1000);
                    system(CLEAN);
                    break;
                }

                cin.ignore();
                system(CLEAN);

                //Busca codigo funcionario
                if(buscar == 1){
                    int indexCod;//Armazena o índice do funcionário buscado caso ele seja encontrado no vector
                    cout << "Código: ";
                    getline(cin, cod);
                    indexCod = empresa.buscaCodFuncionario(cod);

                    //Verifica se o funcionário foi encontrado no vector
                    if(indexCod >= 0){
                        empresa.imprimeFuncionario(indexCod);
                    }else{
                        cout << "Não encontrado" << endl;
                    }
                }

                //Busca por nome
                if(buscar == 2){ 
                    string nomeBusca;
                    cout << "Nome: ";
                    getline(cin, nomeBusca);

                    empresa.buscaNomeFuncionario(nomeBusca);
                }

                //Busca por intervalo de tempo
                if(buscar == 3){
                    int buscaData; //Recebe o tipo de busca que o usuário deseja fazer entre os intervalos de tempo
                    int diaBusca, mesBusca, anoBusca;
                    int diaBusca2, mesBusca2, anoBusca2;

                    cout << " 1-Dias;" << endl;
                    cout << " 2-Meses;" << endl;
                    cout << " 3-Anos." << endl;
                    cout << "Insira o tipo do intervalo que deseja: ";
                    cin >> buscaData;

                    if(buscaData < 1 || buscaData > 3){
                        system(CLEAN);
                        cout << "Opção inválida!" << endl;
                        mySleep(1000);
                        system(CLEAN);
                        break;
                    }

                    if(buscaData == 1){
                        cout << "Menor dia do intervalo: ";
                        cin >> diaBusca;
                        cout << "Maior dia do intervalo: ";
                        cin >> diaBusca2;
                        cout << "Mês de referência: ";
                        cin >> mesBusca;
                        cout << "Ano de referência: ";
                        cin >> anoBusca;

                        empresa.buscaDataDia(diaBusca, diaBusca2, mesBusca, anoBusca);
                    }

                    if(buscaData == 2){
                        cout << "Menor mes do intervalo: ";
                        cin >> mesBusca;
                        cout << "Maior mes do intervalo: ";
                        cin >> mesBusca2;
                        cout << "Ano de referência: ";
                        cin >> anoBusca;

                        empresa.buscaDataMes(mesBusca, mesBusca2, anoBusca);
                    }

                    if(buscaData == 3){
                        cout << "Menor ano do intervalo: ";
                        cin >> anoBusca;
                        cout << "Maior ano do intervalo: ";
                        cin >> anoBusca2;

                        empresa.buscaDataAno(anoBusca, anoBusca2);
                    }
                }
                if(buscar == 4){
                    int buscaEndereco;
                    string rua, bairro, cidade, estado;

                    cout << " 1-Rua;" << endl;
                    cout << " 2-Bairro;" << endl;
                    cout << " 3-Cidade;" << endl;
                    cout << " 4-Estado.;" << endl;
                    cout << "Insira o tipo da busca que deseja: ";
                    cin >> buscaEndereco;

                    if(buscaEndereco < 1 || buscaEndereco > 4){
                        system(CLEAN);
                        cout << "Opção inválida!" << endl;
                        mySleep(1000);
                        system(CLEAN);
                        break;
                    }

                    if(buscaEndereco == 1){
                        cin.ignore();
                        cout << "Insira a rua: ";
                        getline(cin, rua);
                        empresa.buscaEnderecoRua(rua);
                    }
                    if(buscaEndereco == 2){
                        cin.ignore();
                        cout << "Insira o bairro: ";
                        getline(cin, bairro);
                        empresa.buscaEnderecoBairro(bairro);
                    }
                    if(buscaEndereco == 3){
                        cin.ignore();
                        cout << "Insira a cidade: ";
                        getline(cin, cidade);
                        empresa.buscaEnderecoCidade(cidade);
                    }
                    if(buscaEndereco == 4){
                        cin.ignore();
                        cout << "Insira o estado: ";
                        getline(cin, estado);
                        empresa.buscaEnderecoEstado(estado);
                    }
                }
                mySleep(5000);
                system(CLEAN);
                break;
            }
             case 10:{
                cout << "Saindo do sistema." << endl;
                mySleep(1000);
                system(CLEAN);
                return 0;
            }
        }
    }
}
