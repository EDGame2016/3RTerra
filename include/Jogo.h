#ifndef JOGO_H
#define JOGO_H
#include "GUI.h"

#define WINDOWWIDTH 1366
#define WINDOWHEIGHT 768

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
    void intro();

    GUI gui;
};

#endif // JOGO_H
