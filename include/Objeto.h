#ifndef OBJETO_H
#define OBJETO_H
#include <SFML/Graphics.hpp>

class Objeto: public sf::Sprite
{
public:

    Objeto();
    Objeto(sf::Texture &texture);
    virtual ~Objeto();

    void setScale(float value);
    void setTexture(sf::Texture &texture);
    void setAlpha(int value);
};

#endif // ENTIDADE_H
