#ifndef LIXO_H
#define LIXO_H

#include "Objeto.h"

enum Objet{PAPEL, PLASTICO, VIDRO, METAL, ORGANICO};

enum Cor{AZUL, VERMELHO, VERDE, AMARELO, MARROM};

class Lixo//:public Objeto
{
public:
    Lixo();
    ~Lixo();

private:

};

#endif // LIXO_H
