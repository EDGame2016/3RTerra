#include "Objeto.h"

Objeto::Objeto():texture(),sprite()
{

}

Objeto::Objeto(std::string file):texture(),sprite()
{
    setTexture(file);
}


Objeto::~Objeto()
{

}

void Objeto::setPosition(sf::Vector2f pos)
{
    pos.x = pos.x - (this->sprite.getGlobalBounds().width)/2;
    pos.y = pos.y - (this->sprite.getGlobalBounds().height)/2;
    this->sprite.setPosition(pos);
}

void Objeto::setPosition(float x, float y)
{
    setPosition(sf::Vector2f(x,y));
}

void Objeto::setScale(float value)
{
    this->sprite.scale(value, value);
}

void Objeto::setTexture(std::string file)
{
    this->texture.loadFromFile(file);
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(0,0);
}

void Objeto::setAlpha(int value)
{
    if((value<0)&&(value>255))
        value = 255;

    this->sprite.setColor(sf::Color(255,255,255,value));
}

sf::Vector2f Objeto::getPosition() const
{
    return this->sprite.getPosition();
}

sf::Sprite Objeto::getSprite() const
{
    return this->sprite;
}
