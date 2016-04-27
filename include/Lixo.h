#ifndef LIXO_H
#define LIXO_H

#include <time.h>
#include "Objeto.h"
#include "constantes.h"

class Lixo : public Objeto
{
public:
    Lixo();
    ~Lixo();
    int getTipo()const;
    void setTipo(int tipo);
private:
    int tipo;
};
#endif // LIXO_H
