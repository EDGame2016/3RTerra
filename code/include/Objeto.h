#ifndef OBJETO_H
#define OBJETO_H
#include <SFML/Graphics.hpp>

class Objeto: public sf::Sprite
{
public:

    Objeto();
    Objeto(sf::Texture &texture); // constrói com uma textura

    void setScale(float value); // modifica a escala do objeto
    void setTexture(sf::Texture &texture); // configura a textura
    void setAlpha(int value); // configura a transparência
};

#endif // ENTIDADE_H
