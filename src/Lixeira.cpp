#include "Lixeira.h"

Lixeira::Lixeira()
{
    setTipo(0);
    this->contador = 0;
    this->estado = false;
}

Lixeira::Lixeira(int tipo)
{
    this->setTipo(tipo);
    this->contador = 5;
    this->estado = false;
}

void Lixeira::setTipo(int tipo)
{
    if ((tipo<0)&&(tipo>5))
        this->tipo = 0;
    else
        this->tipo = tipo;
}
bool Lixeira::trocaEstado(bool i)
{
    if(i==true)
    {
        if(this->estado==false)
        {
            this->estado = !this->estado;
            return true;
        }
        else
            return false;
    }
    if(i==false)
    {
        if(this->estado==true)
        {
            this->estado = !this->estado;
            return true;
        }
        else
            return false;

    }
}
void Lixeira::incrementa()
{
    if(this->contador < 10)
        this->contador++;
}
void Lixeira::zera()
{
    this->contador = 0;
}

bool Lixeira::cheia()
{
    if(this->contador==10)
        return true;
    else
        return false;
}

int Lixeira::getContador()const
{
    return this->contador;
}
int Lixeira::getTipo()const
{
    return this->tipo;
}
bool Lixeira::getEstado()const
{
    return this->estado;
}
