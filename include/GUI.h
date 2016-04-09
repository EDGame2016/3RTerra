#ifndef GUI_H
#define GUI_H
//_____________Biblioteca Gráfica______________
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

    //Métodos
    void intro();
    void render();


    //Atributos
    sf::RenderWindow tela;

private:

    int width, height;

};

#endif // GUI_H
