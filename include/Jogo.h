#ifndef JOGO_H
#define JOGO_H
#include "GUI.h"

#define WINDOWWIDTH 800
#define WINDOWHEIGHT 600

class Jogo
{
public:

    Jogo();
    ~Jogo();
    void run();

private:

    void processarEventos();
    void atualizarEstado();
    void renderizarTela();

    GUI gui;
};

#endif // JOGO_H
