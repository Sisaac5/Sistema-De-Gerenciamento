#ifndef OPERADOR_H
#define OPERADOR_H

#include "Funcionario.h"

class Operador : public Funcionario{
    public:
        ///Construtor padr�o.
        Operador();
        Operador(string txt);

        ///Destrutor.
        ~Operador();

        ///aumentaSalario.
        /** \brief M�todo herdado que aumenta o atributo salario em 5%.
         * \return void.
         */
        void aumentaSalario();
};

#endif // OPERADOR_H
