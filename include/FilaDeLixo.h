#ifndef FILADELIXO_H
#define FILADELIXO_H

#include "Fila.h"

class FilaDeLixo : public Fila<Lixo>
{
public:
    FilaDeLixo(int tamanho);

    bool pegaOPrimeiro(Lixo& x); // pega o primeiro elemento da fila
    bool pegaOUltimo(Lixo& x); // pega o ultimo elemento da fila
    void move(float y); // move todos os elementos da fila y unidades para a esquerda
    void destroi(); // destroi a fila
};

#endif // FILADELIXO_H
