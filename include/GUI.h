#ifndef GUI_H
#define GUI_H
//_____________Biblioteca Gr�fica_____________
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Lixo.h"

class GUI
{
public:
    GUI(int width, int height);

    sf::RenderWindow tela;


    //void render(sf::RenderWindow);

private:

    int width, height;


};

#endif // GUI_H
