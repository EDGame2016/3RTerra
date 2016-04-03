#include "Jogo.h"

Jogo::Jogo():tela(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Jogo")
{

}

Jogo::~Jogo()
{

}

Jogo::run()
{
    while(tela.isOpen())
    {
        processarEventos();
        atualizar();
        GUI::renderizar();
    }
}

Jogo::processarEventos()
{

}

Jogo::atualizarEstado()
{

}
