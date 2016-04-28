#include "Objeto.h"

Objeto::Objeto():Sprite()
{
    Sprite::setPosition(0,0);
}

Objeto::Objeto(sf::Texture &texture):Sprite()
{
    setTexture(texture);
}

void Objeto::setScale(float value)
{
    Sprite::scale(value, value);
}

void Objeto::setTexture(sf::Texture &texture)
{
    bool aux = true;
    if(!Sprite::getTexture())
        aux = false;
    Sprite::setTexture(texture);

    if(!aux)
        Sprite::setOrigin((Sprite::getGlobalBounds().width/2),(Sprite::getGlobalBounds().height/2));
}

void Objeto::setAlpha(int value)
{
    if((value<0)&&(value>255))
        value = 255;

    Sprite::setColor(sf::Color(255,255,255,value));
}
