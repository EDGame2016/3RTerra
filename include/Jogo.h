#ifndef JOGO_H
#define JOGO_H
#include "GUI.h"

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

    sf::RenderWindow tela;
};

#endif // JOGO_H
