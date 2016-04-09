#ifndef ENTIDADE_H
#define ENTIDADE_H
#include "GUI.h"

class Objeto
{
public:

    Objeto();
    Objeto(std::string file);
    virtual ~Objeto();

    void setPosition(sf::Vector2f);
    void setPosition(float x, float y);
    void setScale(float value);
    void setTexture(std::string file);
    void setAlpha(int value);

    sf::Vector2f getPosition() const;
    sf::Sprite getSprite() const;


private:

    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // ENTIDADE_H
