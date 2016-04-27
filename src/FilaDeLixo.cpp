#include "FilaDeLixo.h"

FilaDeLixo::FilaDeLixo(int tamanho) : Fila(tamanho)
{

}

FilaDeLixo::~FilaDeLixo()
{

}

bool FilaDeLixo::pegaOPrimeiro(Lixo& x)
{
    if(this->vazia())
        return false;
    else
    {
        x = this->elementos[this->inicio];
        return true;
    }

}

bool FilaDeLixo::pegaOUltimo(Lixo& x)
{
    if(this->vazia())
        return false;
    else
    {
        if(this->ultimo == 0)
            x = this->elementos[this->tamanho-1];
        else
            x = this->elementos[this->ultimo-1];
        return true;
    }

}

void FilaDeLixo::move(float y)
{
    int pos = this->inicio;
    int qtd = 0;

    sf::Vector2f movement(1.f, 0.f);

    while(qtd < this->tamanho)
    {
        this->elementos[pos].move(movement * (-y));

        if (pos == this->tamanho - 1)
            pos = 0;
        else
            pos++;

        qtd++;
    }
}
