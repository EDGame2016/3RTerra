#include "Fila.h"

#define TAMDEF 10

template <typename T>
Fila<T>::Fila(int tamanho)
{
    this->inicio = 0;
    this->ultimo = 0;
    this->NElementos = 0;

    if (tamanho < 1)
    {
        this->tamanho = TAMDEF;
    }
    else
    {
        this->tamanho = tamanho;
    }

    this->elementos = new T[this->tamanho];
}

template <typename T>
Fila<T>::~Fila()
{
    delete []elementos;
}

template <typename T>
bool Fila<T>::vazia()
{
    if (this->NElementos == 0)
        return true;
    else
        return false;
}

template <typename T>
bool Fila<T>::cheia()
{
    if (this->NElementos == this->tamanho)
        return true;
    else
        return false;
}

template <typename T>
bool Fila<T>::insere(T x)
{
    if (!this->cheia())
    {
        this->elementos[this->ultimo] = x;
        if (this->ultimo == this->tamanho - 1)
            this->ultimo = 0;
        else
            this->ultimo++;

        this->NElementos++;

        return true;
    }
    else
        return false;

}

template <typename T>
bool Fila<T>::retira(T &x)
{
    if (!this->vazia())
    {
        x = this->elementos[this->inicio];

        if(this->inicio == this->tamanho - 1)
            this->inicio = 0;
        else
            this->inicio++;

        this->NElementos--;

        return true;
    }
    else
        return false;
}

template class Fila<Lixo>;
