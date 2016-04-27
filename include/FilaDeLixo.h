#ifndef FILADELIXO_H
#define FILADELIXO_H

#include "Fila.h"

class FilaDeLixo : public Fila<Lixo>
{
public:
    FilaDeLixo(int tamanho);
    ~FilaDeLixo();
    bool pegaOPrimeiro(Lixo& x);
    bool pegaOUltimo(Lixo& x);
    void move(float y);
};

#endif // FILADELIXO_H
