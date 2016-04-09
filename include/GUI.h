#ifndef GUI_H
#define GUI_H
//_____________Biblioteca Gr�fica______________
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Objeto.h"
#include "Lixo.h"

class GUI
{
public:
    GUI(int width, int height);
    ~GUI();

    //M�todos
    void intro();
    void render();


    //Atributos
    sf::RenderWindow tela;

private:

    int width, height;

};

#endif // GUI_H
