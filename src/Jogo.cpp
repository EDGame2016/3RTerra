#include "Jogo.h"

Jogo::Jogo():gui(WINDOWWIDTH,WINDOWHEIGHT)
{

}

Jogo::~Jogo()
{

}

void Jogo::run()
{
    gui.intro();

    while(gui.tela.isOpen())
    {
        processarEventos();
        atualizarEstado();
        renderizarTela();
    }
}

void Jogo::processarEventos()
{
    sf::Event evento;

    while (gui.tela.pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
        {
            gui.tela.close();
        }

        if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape)
        {
            gui.tela.close();
        }
    }

}

void Jogo::atualizarEstado()
{
    printf("Atualizando aqui\n");
}

void Jogo::renderizarTela()
{
    printf("Renderizando aqui\n");
    gui.render();
}
