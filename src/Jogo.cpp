#include "Jogo.h"
#include <windows.h>
Jogo::Jogo():gui(WINDOWWIDTH,WINDOWHEIGHT)
{

}

Jogo::~Jogo()
{

}

void Jogo::run()
{
    while(gui.tela.isOpen())
    {
        processarEventos();
        atualizarEstado();
        renderizarTela();
    }
}

void Jogo::processarEventos()
{
    printf("Eventos aqui\n");
    //Sleep(1000);

    sf::Event event;

    while (gui.tela.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
        {
            gui.tela.close();
        }

        // Escape pressed: exit
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            gui.tela.close();
        }
    }

}

void Jogo::atualizarEstado()
{
    printf("Atualizando aqui\n");
    //Sleep(1000);
}

void Jogo::renderizarTela()
{
    printf("Renderizando aqui\n");
    //Sleep(1000);
    //GUI::render(tela);
}
