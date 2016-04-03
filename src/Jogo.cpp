#include "Jogo.h"

#include <windows.h>
Jogo::Jogo():tela(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Jogo")
{

}

Jogo::~Jogo()
{

}

void Jogo::run()
{
    while(tela.isOpen())
    {
        processarEventos();
        atualizarEstado();
        renderizarTela();
    }
}

void Jogo::processarEventos()
{
    printf("Eventos aqui\n");
    Sleep(1000);

    sf::Event event;

    while (tela.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
        {
            tela.close();
        }

        // Escape pressed: exit
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            tela.close();
        }
    }

}

void Jogo::atualizarEstado()
{
    printf("Atualizando aqui\n");
    Sleep(1000);
}

void Jogo::renderizarTela()
{
    printf("Renderizando aqui\n");
    Sleep(1000);
    //GUI::render(tela);
}
