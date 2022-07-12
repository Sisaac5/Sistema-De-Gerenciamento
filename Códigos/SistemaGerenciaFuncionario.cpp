#include "SistemaGerenciaFuncionario.h"

using namespace std;

SistemaGerenciaFuncionario::SistemaGerenciaFuncionario(){
    startSystem();
}

SistemaGerenciaFuncionario::~SistemaGerenciaFuncionario(){
    endSystem();
    liberaMemoria();
}

void SistemaGerenciaFuncionario::pushOperador(){
    funcionarios.push_back(new Operador());
}

void SistemaGerenciaFuncionario::pushGerente(){
    funcionarios.push_back(new Gerente());
}

void SistemaGerenciaFuncionario::pushDiretor(){
    funcionarios.push_back(new Diretor());
}

void SistemaGerenciaFuncionario::pushPresidente(){
    funcionarios.push_back(new Presidente());
}

void SistemaGerenciaFuncionario::setFuncionario(std::string cod, std::string nom, std::string ende,
                                                std::string tel, int desig, int d, int m, int a, int pos){
    funcionarios[pos]->setCodigo(cod);
    funcionarios[pos]->setNome(nom);
    funcionarios[pos]->setEndereco(ende);
    funcionarios[pos]->setTelefone(tel);
    funcionarios[pos]->setDataAdmissao(d, m, a);
    funcionarios[pos]->setDesignacao(desig);
}

void SistemaGerenciaFuncionario::setAreasupervisao(std::string areaS, int pos){
    /*Verifica se o funcionário é um gerente ou diretor antes de executar, visando
      evitar a alocação indevida dos valores no vector*/
    if(funcionarios[pos]->getDesignacao() == "Gerente"){
        ((Gerente *)funcionarios[pos])->setAreasupervisao(areaS);
    }

    if(funcionarios[pos]->getDesignacao() == "Diretor"){
        ((Diretor *)funcionarios[pos])->setAreasupervisao(areaS);
    }
}

void SistemaGerenciaFuncionario::setAreaformacao(std::string areaF, int pos){
    /*Verifica se o funcionário é um diretor ou presidente antes de executar, visando
      evitar a alocação indevida dos valores no vector*/
    if(funcionarios[pos]->getDesignacao() == "Diretor"){
        ((Diretor *)funcionarios[pos])->setAreaformacao(areaF);
    }

    if(funcionarios[pos]->getDesignacao() == "Presidente"){
        ((Presidente *)funcionarios[pos])->setAreaformacao(areaF);
    }
}

void SistemaGerenciaFuncionario::setFormacaoacademica(std::string formacaoA, int pos){
    /*Verifica se o funcionário é um presidente antes de executar, visando
      evitar a alocação indevida dos valores no vector*/
    if(funcionarios[pos]->getDesignacao() == "Presidente"){
        ((Presidente *)funcionarios[pos])->setFormacaoacademica(formacaoA);
    }
}

void SistemaGerenciaFuncionario::imprimeFuncionario(int pos){
    Data dataDeIngresso;

    cout << "Código: "<< funcionarios[pos]->getCodigo() << endl;
    funcionarios[pos]->getEndereco().print();
    cout << "Nome: " << funcionarios[pos]->getNome() << endl;
    cout << "Telefone: " << funcionarios[pos]->getTelefone() << endl;
    cout << "Designação: " << funcionarios[pos]->getDesignacao() << endl;
    cout << "Sálario: " << funcionarios[pos]->getSalario() << endl;
    cout << "Data de admissão: " << funcionarios[pos]->getDataAdmissao().to_txt() << endl;

    /*As seguintes informações só serão impressas caso o funcionário informado
      possua, de fato, esses atributos*/
    if(funcionarios[pos]->getDesignacao()== "Gerente"){
        cout << "Área de supervisão: " << ((Gerente *)funcionarios[pos])->getAreasupervisao() << endl;
    }

    if(funcionarios[pos]->getDesignacao() == "Diretor"){
        cout << "Área de supervisão: " << ((Diretor *)funcionarios[pos])->getAreasupervisao() << endl;
        cout << "Área de formação: " << ((Diretor *)funcionarios[pos])->getAreaformacao() << endl;
    }

    if(funcionarios[pos]->getDesignacao() == "Presidente"){
        cout << "Área de formação: " << ((Presidente *)funcionarios[pos])->getAreaformacao() << endl;
        cout << "Formação acadêmica: " << ((Presidente *)funcionarios[pos])->getFormacaoacademica() << endl;
    }
}

void SistemaGerenciaFuncionario::addFuncionario(Funcionario *func){
    funcionarios.push_back(func);
}

void SistemaGerenciaFuncionario::imprimeFuncionarioDesig(std::string desig, int pos){
    if(funcionarios[pos]->getDesignacao() == desig){
        imprimeFuncionario(pos);
        cout << endl;
    }
}

int SistemaGerenciaFuncionario::buscaCodFuncionario(std::string cod){
    int index = -1;

    /*Busca pelo código informado e para ao encontrar o primeiro caso condizente,
      o index fica responsável por indicar se o método encontrou ou não o código*/
    for(int i = 0; i < ((int) funcionarios.size()); i++){
        if(funcionarios[i]->getCodigo() == cod){
            index = i;
            break;
        }
    }

    return index;
}

int SistemaGerenciaFuncionario::existeDesigFuncionario(std::string desig){
    int flag = -1;

    /*Busca pela designação informada e para ao encontrar o primeiro caso condizente,
      a flag fica responsável por indicar se o método encontrou ou não a designação*/
    for(int i = 0; i < ((int) funcionarios.size()); i++){
        if(funcionarios[i]->getDesignacao() == desig){
            flag = 1;
            break;
        }
    }

    return flag;
}

void SistemaGerenciaFuncionario::deletaFuncionario(int pos){
    funcionarios.erase(funcionarios.begin() + pos);
}

void SistemaGerenciaFuncionario::liberaMemoria(){

    for(int i = 0; i < (int) funcionarios.size(); i++){
        delete funcionarios[i];
    }
}

std::string SistemaGerenciaFuncionario::getDesigFuncionario(int pos){
    return funcionarios[pos]->getDesignacao();
}


void SistemaGerenciaFuncionario::setCodigo(std::string codigo, int pos){
    funcionarios[pos]->setCodigo(codigo);
}

void SistemaGerenciaFuncionario::setNome(std::string nome, int pos){
    funcionarios[pos]->setNome(nome);
}

void SistemaGerenciaFuncionario::setEndereco(std::string endereco, int pos){
   funcionarios[pos]->setEndereco(endereco);
}

void SistemaGerenciaFuncionario::setTelefone(std::string telefone, int pos){
   funcionarios[pos]->setTelefone(telefone);
}

void SistemaGerenciaFuncionario::setDataAdmissao(int dia, int mes, int ano, int pos){
   funcionarios[pos]->setDataAdmissao(dia, mes, ano);
}

void SistemaGerenciaFuncionario::setDesignacao(int designacaoN, int pos){
   if(designacaoN == 0){
        funcionarios[pos]->setDesignacao(0);
    }

    if(designacaoN == 1){
        funcionarios[pos]->setDesignacao(1);
    }

    if(designacaoN == 2){
        funcionarios[pos]->setDesignacao(2);
    }

    if(designacaoN == 3){
        funcionarios[pos]->setDesignacao(3);
    }

    if(designacaoN >= 4 || designacaoN < 0){
        funcionarios[pos]->setDesignacao(4);
    }
}

void SistemaGerenciaFuncionario::setSalario(double salario, int pos){
    funcionarios[pos]->setSalario(salario);
}

/*Verifica a designacao do funcionario e, através de polimorfismo,
  executa o seu respectivo métdodo aumentaSalario
  OBS.: procedimento de casting foi necessário para o polimorfismo*/
void SistemaGerenciaFuncionario::aumentoDeSalarios(){
    for(int i = 0; i < (int) funcionarios.size(); i++){
        if(funcionarios[i]->getDesignacao()== "Operador"){
            ((Operador *)funcionarios[i])->aumentaSalario();
        }

        if(funcionarios[i]->getDesignacao()== "Gerente"){
            ((Gerente *)funcionarios[i])->aumentaSalario();
        }

        if(funcionarios[i]->getDesignacao() == "Diretor"){
            ((Diretor *)funcionarios[i])->aumentaSalario();
        }

        if(funcionarios[i]->getDesignacao() == "Presidente"){
            ((Presidente *)funcionarios[i])->aumentaSalario();
        }
    }
}

/*Busca pelo nome informado e imprime as informações do funcionário nos casos condizentes,
  o index fica responsável por indicar se o método encontrou ou não o código*/
void SistemaGerenciaFuncionario::buscaNomeFuncionario(std::string nome){
    int index = -1;
    std::string nomeTemp;

    for(int i = 0; i < ((int) funcionarios.size()); i++){
        nomeTemp = funcionarios[i]->getNome();
        if(nomeTemp.find(nome) != std::string::npos){
            index = i;

            cout << "Nome : " << funcionarios[i]->getNome()
            << " | Código: " << funcionarios[i]->getCodigo()
            << " | Designação: " << funcionarios[i]->getDesignacao() << endl;
            
        }
    }

    if(index == -1){
        cout << "Nome nao encontrado entre os funcionarios." << endl;
    }
}

/*Busca pelo nome informado e para ao encontrar o primeiro caso condizente,
  o index fica responsável por indicar se o método encontrou ou não o código,
  além de ser retornado como a posição do funcionário encontrado para uso posterior*/
int SistemaGerenciaFuncionario::buscaNomeFuncionarioIndex(std::string nome){
    int index = -1;
    std::string nomeTemp;

    for(int i = 0; i < ((int) funcionarios.size()); i++){
        nomeTemp = funcionarios[i]->getNome();
        if(nomeTemp.find(nome) != std::string::npos){
            index = i;

            break;
        }
    }

    if(index == -1){
        cout << "Nome nao encontrado entre os funcionarios." << endl;
    }

    return index;
}

/*Busca os funcionário cadastrados em uma determinada faixa de dias dentro de um
  mesmo mês e ano*/
void SistemaGerenciaFuncionario::buscaDataDia(int d1, int d2, int m, int a){
    Data dataTemp;
    int flag = -1; //Indica se foram encontrados funcionários ou não

    for(int i = 0; i < (int)funcionarios.size(); i++){
        dataTemp = funcionarios[i]->getDataAdmissao(); //Recebe o objeto do tipo data declarado dentro de funcionario

        //Verifica se o mês e ano de admição são condizentes com os que foram recebidos como parâmetros
        if(dataTemp.getMes() == m && dataTemp.getAano() == a){
            //Verifica se o dia de admição está entre os dias passados pelo usuário
            if(dataTemp.getDia() >= d1 && dataTemp.getDia() <= d2){
                flag = 1;

                cout << "Nome : " << funcionarios[i]->getNome()
                << " | Código: " << funcionarios[i]->getCodigo()
                << " | Designação: " << funcionarios[i]->getDesignacao() 
                << " | Data de admissão: " << dataTemp.to_txt() << endl;
            }
        }
    }

    if(flag == -1){
        cout << "Nao foram encontrados resultados para esse intervalo de tempo" << endl;
    }
}

/*Busca os funcionário cadastrados em uma determinada faixa de meses dentro de um
  mesmo ano*/
void SistemaGerenciaFuncionario::buscaDataMes(int m1, int m2, int a){
    Data dataTemp;
    int flag = -1; //Indica se foram encontrados funcionários ou não

    for(int i = 0; i < (int)funcionarios.size(); i++){
        dataTemp = funcionarios[i]->getDataAdmissao();

        //Verifica se o ano de admição é condizente com o que foi recebido como parâmetro
        if(dataTemp.getAano() == a){
            //Verifica se o mês de admição está entre os meses passados pelo usuário
            if(dataTemp.getMes() >= m1 && dataTemp.getMes() <= m2){
                flag = 1;

                cout << "Nome : " << funcionarios[i]->getNome()
                << " | Código: " << funcionarios[i]->getCodigo()
                << " | Designação: " << funcionarios[i]->getDesignacao() 
                << " | Data de admissão: "<< dataTemp.getDia() << "/" <<
                dataTemp.getMes() << "/" << dataTemp.getAano() << endl;
            }
        }
    }

    if(flag == -1){
        cout << "Nao foram encontrados resultados para esse intervalo de tempo" << endl;
    }
}

//Busca os funcionário cadastrados em uma determinada faixa de anos
void SistemaGerenciaFuncionario::buscaDataAno(int a1, int a2){
    Data dataTemp;
    int flag = -1; //Indica se foram encontrados funcionários ou não

    for(int i = 0; i < (int)funcionarios.size(); i++){
        dataTemp = funcionarios[i]->getDataAdmissao();

        //Verifica se o ano de admição está entre os anos passados pelo usuário
        if(dataTemp.getAano() >= a1 && dataTemp.getAano() <= a2){
            flag = 1;
            cout << "Nome : " << funcionarios[i]->getNome()
            << " | Código: " << funcionarios[i]->getCodigo()
            << " | Designação: " << funcionarios[i]->getDesignacao() 
            << " | Data de admissão: " << dataTemp.getDia() << "/" <<
            dataTemp.getMes() << "/" << dataTemp.getAano() << endl;
        }
    }

    if(flag == -1){
        cout << "Nao foram encontrados resultados para esse intervalo de tempo" << endl;
    }
}

//As porcentagens do INSS foram baseados na tabela de 2022
double SistemaGerenciaFuncionario::calculaINSS(double salario){

    //Calculo do INSS
    if(salario <= 1212)
        return (salario * 7.5) / 100;
    

    else if(salario > 1212 && salario <= 2427.35)
        return (salario * 9) / 100;
    

    else if(salario > 2427.35 && salario <= 3641.03)
        return (salario * 12) / 100;
    

    else if(salario > 3641.03)
       return (salario * 14) / 100;
    

    return 0;
    
}

//As porcentagens do Imposto de Renda foram baseados na tabela de 2022
double SistemaGerenciaFuncionario::calculaImpostoRenda(double salario){

    //Calculo imposto de renda
    if(salario <= 1903.98)
        return  0;
    

    else if(salario > 1903.98 && salario <= 2826.65)
        return  (salario * 7.5) / 100;
    

    else if(salario > 2826.65 && salario <= 3751.05)
        return  (salario * 15) / 100;
    

    else if(salario > 3751.05 && salario <= 4664.68)
        return (salario * 22.5) / 100;
    

    else if(salario > 4664.68)
        return (salario * 27.5) / 100;

    return 0;

}

//Calcula e imprime a folha salarial (simplificada) de um funcionário
double SistemaGerenciaFuncionario::folhaSalarialFuncionario(int pos){
    double salarioTemp, salarioLiquido;
    double inss, impostoRenda;

    salarioTemp = funcionarios[pos]->getSalario();

    inss = calculaINSS(salarioTemp);
    impostoRenda = calculaImpostoRenda(salarioTemp);

    salarioLiquido = salarioTemp - inss - impostoRenda;

    cout << "Salario Bruto: " << salarioTemp << endl;
    cout << "INSS: " << inss << endl;
    cout << "Imposto de Renda: " << impostoRenda << endl;
    cout << "Salario Liquido: " << salarioLiquido << endl;

    return salarioLiquido;
}


//Calcula e imprime a folha salarial mensal da empresa, percorrendo o salário de todos os funcionários
void SistemaGerenciaFuncionario::folhaSalarialAnual(int ano){

    string linha;
    ifstream file;
    ofstream fileO;
    double soma = 0;

    string nomeFolha = "FolhasDePagamento/Anuais/folha" + to_string(ano) + ".txt";
    
    //abre a folha de gastos anual
    file.open(nomeFolha.c_str());

    //se o arquivo não existir, será criado
    if (!file.is_open()){

        fileO.open(nomeFolha.c_str());

        srand((unsigned)time(0));

        for(int i = 1; i <=12 ; i++){
            string mesRef = "FolhasDePagamento/Mensais/" + to_string(i) + to_string(ano) + ".txt";
            // para gerar a folha anual, é preciso verificar se as folhas mensais desse ano já foram geradas
            file.open(mesRef.c_str());

            // se a folha de um determinado mês não estava gerada, será gerada
            if(!file.is_open()){
                geraFolhaMensal(i, ano, true);
                file.open(mesRef.c_str());
            }
            // a folha de do mês é aberta, para que seu total de gastos seja usado na composição da olha anual
            file.seekg(-60,ios::end);

            getline(file, linha);

            linha.erase(0,30);
            soma += stod(linha);
            file.close();

            //formatação da folha de gastos anual
            switch (i){

            case 1:
                fileO << escreveFormato("JANEIRO");
                break;
            
            case 2:
                fileO << escreveFormato("FEVEREIRO");
                break;

            case 3:
                fileO << escreveFormato("MARCO");
                break;

            case 4:
                fileO << escreveFormato("ABRIL");
                break;

            case 5:
                fileO << escreveFormato("MAIO");
                break;
            
            case 6:
                fileO << escreveFormato("JUNHO");
                break;
                
            case 7:
                fileO << escreveFormato("JULHO");
                break;

            case 8:
                fileO << escreveFormato("AGOSTO");
                break; 

            case 9:
                fileO << escreveFormato("SETEMBRO");
                break;
            
            case 10:
                fileO << escreveFormato("OUTUBRO");
                break;
                
            case 11:
                fileO << escreveFormato("NOVEMBRO");
                break;

            case 12:
                fileO << escreveFormato("DEZEMBRO");
                break;        
            }

            fileO << "R$ " << linha << endl; 
        }
        
        for(int i = 0; i < 60; i++){
            fileO << "-";
        }
        fileO << endl;

        fileO << escreveFormato("Total de " + to_string(ano) + ":") << "R$ " << to_string(soma);
        fileO.close();
    }

    // exibe a folha no console
    imprimeFolha(0,ano);
}

void SistemaGerenciaFuncionario::startSystem(){
        string linha;
        ifstream arquivoE;
        Funcionario *func;
        int i = 1;

        arquivoE.open("backup.csv");

        if(!arquivoE.is_open())
            cout << "Error\n";

        getline(arquivoE, linha);

        // verifica a designação do funcionário para adicioná-lo à memoria do programa da melhor forma possível
        do{

            if(linha.substr(0, linha.find(";")) == "Operador"){
                linha.erase(0, linha.find(";") + 1);
                func = new Operador(linha);
            }

            else if(linha.substr(0, linha.find(";")) == "Gerente"){
                linha.erase(0, linha.find(";") + 1);
                func = new Gerente(linha, 1);
            }

            else if(linha.substr(0, linha.find(";")) == "Diretor"){
                linha.erase(0, linha.find(";") + 1);
                func = new Diretor(linha);
            }

            else if(linha.substr(0, linha.find(";")) == "Presidente"){
                linha.erase(0, linha.find(";") + 1);
                func = new Presidente(linha);
            }

            addFuncionario(func);            
            getline(arquivoE, linha);

        }while(!arquivoE.eof());

        arquivoE.close();
}

void SistemaGerenciaFuncionario::buscaEnderecoRua(string _rua){
    bool flag = true;

    for(int i = 0; i < funcionarios.size(); i++){

        if(funcionarios[i]->getEndereco().getRua().find(_rua) != string::npos){

            flag = false;
            cout << "Nome : " << funcionarios[i]->getNome()
            << " | Código: " << funcionarios[i]->getCodigo()
            << " | Designação: " << funcionarios[i]->getDesignacao() << endl;
        }
    }

    if(flag)
        cout << "Nenhum Funcionário Encontrado" << endl;
}

void SistemaGerenciaFuncionario::buscaEnderecoBairro(string _bairro){
    bool flag = true;

    for(int i = 0; i < funcionarios.size(); i++){

        if(funcionarios[i]->getEndereco().getBairro().find(_bairro) != string::npos){
            flag = false;
            cout << "Nome : " << funcionarios[i]->getNome()
            << " | Código: " << funcionarios[i]->getCodigo()
            << " | Designação: " << funcionarios[i]->getDesignacao() << endl;
        }
    }

    if(flag)
        cout << "Nenhum Funcionário Encontrado" << endl;
}

void SistemaGerenciaFuncionario::buscaEnderecoCidade(string _cidade){
    bool flag = true;

    for(int i = 0; i < funcionarios.size(); i++){

        if(funcionarios[i]->getEndereco().getCidade().find(_cidade) != string::npos){
            flag = false;
            cout << "Nome : " << funcionarios[i]->getNome()
            << " | Código: " << funcionarios[i]->getCodigo()
            << " | Designação: " << funcionarios[i]->getDesignacao() << endl;
        }
    }

    if(flag)
        cout << "Nenhum Funcionário Encontrado" << endl;
}

void SistemaGerenciaFuncionario::buscaEnderecoEstado(string _estado){
    bool flag = true;

    for(int i = 0; i < funcionarios.size(); i++){

        if(funcionarios[i]->getEndereco().getEstado().find(_estado) != string::npos){
            flag = false;
            cout << "Nome : " << funcionarios[i]->getNome()
            << " | Código: " << funcionarios[i]->getCodigo()
            << " | Designação: " << funcionarios[i]->getDesignacao() << endl;
        }
    }

    if(flag)
        cout << "Nenhum Funcionário Encontrado" << endl;
}

int SistemaGerenciaFuncionario::getSize(){

    return funcionarios.size();
}

void SistemaGerenciaFuncionario::endSystem(){
    ofstream arquivoS;
    arquivoS.open("backup.csv");

    if(!arquivoS.is_open()){
        cout << "Error" << endl;
    }

    for(int i = 0; i < funcionarios.size(); i++){
        arquivoS << funcionarios[i]->to_txt();
    }

    arquivoS.close();
}

string SistemaGerenciaFuncionario::toUpper(string teste){
    int t = teste.length();
    teste.c_str();

    for (int i = 0; i < t; i++){
        teste[i] = toupper(teste[i]);
    }

    return teste;
}

string SistemaGerenciaFuncionario::escreveFormato(string teste){
    string aux = "";

    for(int i = 0 ; i < 30 - teste.length(); i++){
        aux = aux + " ";
    }

    return teste + aux;
}


int SistemaGerenciaFuncionario::numeroAleatorio(int menor, int maior) {
       return rand()%(maior-menor+1) + menor;
}

void SistemaGerenciaFuncionario::geraFolhaMensal(int mes, int ano, bool anual){

    string nomeFolha = "FolhasDePagamento/Mensais/" + to_string(mes) + to_string(ano) + ".txt";
    ifstream folhaDePagamento;

    //se a folha de gastos do mês já existir, imprime uma mensagem
    folhaDePagamento.open(nomeFolha.c_str());
    if(folhaDePagamento.is_open()){
        folhaDePagamento.close();
        cout << "A folha de pagamento já foi gerada" << endl;
    }

    // caso não, a folha é gerada
    else{

        if(!anual){
            srand((unsigned)time(0));
        }

        double soma = 0, inss, iprf, salario, valorDaHora;
        int horas_trabalhadas, horas_extras;
        bool flag = false;

        ofstream folhaDePagamento;

        folhaDePagamento.open(nomeFolha.c_str());

        if(!folhaDePagamento.is_open()){
            cout << "Erro" << endl;
        }

        // Dados iniciais da folha de pagamento são impressos no arquivo
        folhaDePagamento << escreveFormato("NOME");
        folhaDePagamento << escreveFormato("DESIGNACAO");
        folhaDePagamento << escreveFormato("SALARIO BRUTO (R$)");
        folhaDePagamento << escreveFormato("H.E pagas");
        folhaDePagamento << escreveFormato("DEDUCAO INSS (R$)");
        folhaDePagamento << escreveFormato("DEDUCAO IRPF (R$)");
        folhaDePagamento << "SALARIO LIQUIDO (R$)" << endl;

        for(int i = 0; i < funcionarios.size(); i++){
            
            // verifica se um determinado funcionário estava trabalhando na empresa no mês ao qual a folha se refere
            if((funcionarios[i]->getDataAdmissao().getAano() < ano)||
            (funcionarios[i]->getDataAdmissao().getAano() == ano && funcionarios[i]->getDataAdmissao().getMes() < mes)){
                
                horas_trabalhadas = 220;// se sim, é suposta que trabalhou todas as horas do mês
                flag = true;
            }

            // uma clausula especial para o caso em que o funcionário foi contratado no mês de referência da folha
            else if(funcionarios[i]->getDataAdmissao().getAano() == ano && funcionarios[i]->getDataAdmissao().getMes() == mes){
                
                //as horas tabalhadas são definidas com base na quantidade de dias trabalhados
                horas_trabalhadas = 8 * (funcionarios[i]->getDataAdmissao().getQuantDiasDoMes(funcionarios[i]->getDataAdmissao().getMes()) - funcionarios[i]->getDataAdmissao().getDia());
                flag = true;

            }

            // formata as informações no arquivo da folha de pagamento
            if(flag){
                
                valorDaHora = funcionarios[i]->getSalario()/220;
                horas_extras = numeroAleatorio(0,30);
                salario = (valorDaHora * horas_trabalhadas) + (valorDaHora * 2 * horas_extras);
                inss = calculaINSS(salario);
                iprf = calculaImpostoRenda(salario);
                soma += salario;

                folhaDePagamento << escreveFormato(toUpper(funcionarios[i]->getNome()));
                folhaDePagamento << escreveFormato(toUpper(funcionarios[i]->getDesignacao()));
                folhaDePagamento << escreveFormato(to_string(salario));
                folhaDePagamento << escreveFormato(to_string(horas_extras));
                folhaDePagamento << escreveFormato(to_string(inss));
                folhaDePagamento << escreveFormato(to_string(iprf));
                folhaDePagamento << to_string(salario - inss - iprf) << endl;

                flag = false;
            }
        }

        for(int i = 0; i < 210; i++){
            folhaDePagamento << "-";
        }

        folhaDePagamento << endl;

        folhaDePagamento << escreveFormato("Total de Gastos: R$");
        folhaDePagamento << escreveFormato(to_string(soma));

        folhaDePagamento.close();
    }
}

void SistemaGerenciaFuncionario::imprimeFolha(int mes, int ano){

    string nomeFolha;
    
    if (mes == 0)
        nomeFolha = "FolhasDePagamento/Anuais/folha" + to_string(ano) + ".txt";
    
    else
        nomeFolha = "FolhasDePagamento/Mensais/" + to_string(mes) + to_string(ano) + ".txt";
    
    ifstream folhaDePagamento;

    folhaDePagamento.open(nomeFolha.c_str());

    if(!folhaDePagamento.is_open()){
        cout << "Folha não gerada" << endl;
    }

    else{
        string linha;
        while (!folhaDePagamento.eof()){

            getline(folhaDePagamento, linha);
            cout << linha << endl;
        }

        folhaDePagamento.close();
        
    }

}


