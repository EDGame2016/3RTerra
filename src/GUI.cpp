#include "GUI.h"

GUI::GUI(int width, int height):tela(sf::VideoMode(width, height), "Jogo")
{
    this->width = width;
    this->height = height;

}
/*GUI::render(sf::RenderWindow tela)
{
    tela.clear();

    tela.display();
}*/
