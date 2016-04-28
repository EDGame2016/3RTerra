#include "Lixo.h"

Lixo::Lixo() : Objeto()
{
    this->setTipo(0);
}

int Lixo::getTipo()const
{
    return this->tipo;
}

void Lixo::setTipo(int tipo)
{
    this->tipo = tipo;
}
