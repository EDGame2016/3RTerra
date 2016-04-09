#include "GUI.h"

GUI::GUI(int width, int height):tela(sf::VideoMode(width, height), "Jogo", sf::Style::Fullscreen)
{
    this->width = width;
    this->height = height;
}

GUI::~GUI()
{

}

void GUI::intro()
{
    Objeto logo("src/images/recycle.png");
    logo.setScale(0.75);
    logo.setPosition(width/2, height/2);
    while(tela.isOpen())
    {
        sf::Event evento;
        tela.clear(sf::Color(255, 255, 255, 255));

        while (tela.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
            {
                tela.close();
            }

            if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape)
            {
                tela.close();
            }
            else if (evento.type == sf::Event::KeyPressed)
            {
                return;
            }
        }
        tela.draw(logo.getSprite());
        tela.display();
    }

}

void GUI::render()
{
    tela.clear(sf::Color(255, 255, 255, 0));
    //tela.draw(sprite);
    tela.display();
}
