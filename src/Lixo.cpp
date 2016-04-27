#include "Lixo.h"

Lixo::Lixo() : Objeto()
{
    this->setTipo(0);
}

Lixo::~Lixo()
{

}

int Lixo::getTipo()const
{
    return this->tipo;
}

void Lixo::setTipo(int tipo)
{
    this->tipo = tipo;
}
