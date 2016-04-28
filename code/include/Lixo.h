#ifndef LIXO_H
#define LIXO_H

#include <time.h>
#include "Objeto.h"
#include "constantes.h"

class Lixo : public Objeto
{
public:
    Lixo();
    int getTipo()const; // retorna o tipo do lixo conforme definido em constantes.h
    void setTipo(int tipo); // configura o tipo

private:
    int tipo; // armazena o tipo
};
#endif // LIXO_H
