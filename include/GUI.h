#ifndef GUI_H
#define GUI_H

/*____Biblioteca para a função de conversão para Strings_____*/
#include <sstream>

/*_____________Biblioteca Gráfica______________*/
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

/*________________Defines______________________*/
#include "constantes.h"

/*________________Classes Utilizadas______________________*/
#include "Objeto.h"
#include "Lixeira.h"
#include "FilaDeLixo.h"

using namespace std;

class GUI
{
public:
    GUI(int width = 1280, int height = 720);
    ~GUI();

    void renderiza();
    void limpaTela();

    void desenhaFundo(int level);
    void desenhaLixeiras(Lixeira* lixeiras);
    void desenhaEsteira(int speed);
    void desenhaLixo(FilaDeLixo& filaLixo, int speed);
    void desenhaTexto(string txt, int csize, sf::Color color, float x, float y, bool origin);
    void desenhaPause();

    int getWidth()const;
    int getHeigth()const;

    sf::RenderWindow tela;

    /*Texturas*/
    sf::Texture logo_tex;
    sf::Texture tut_tex;
    sf::Texture pause_tex;
    sf::Texture cenario_tex[5];
    sf::Texture background_tex[2];
    sf::Texture esteira_tex[2];

    sf::Texture lixeiraVidro_tex[2];
    sf::Texture lixeiraPapel_tex[2];
    sf::Texture lixeiraPlastico_tex[2];
    sf::Texture lixeiraMetal_tex[2];
    sf::Texture lixeiraOrganico_tex[2];
    sf::Texture indicadorLixeira_tex;

    sf::Texture rectBlue_tex;
    sf::Texture rectGreen_tex;
    sf::Texture rectRed_tex;
    sf::Texture rectYellow_tex;
    sf::Texture rectBrown_tex;

    sf::Texture lixoVidro_tex;
    sf::Texture lixoPapel_tex;
    sf::Texture lixoPlastico_tex;
    sf::Texture lixoMetal_tex;
    sf::Texture lixoOrganico_tex;

    sf::Texture cap_tex[6];

    /*Fontes*/
    sf::Font font;

    /*Sounds*/
    sf::Music musicaFundo;

    sf::SoundBuffer clickBuffer;
    sf::Sound click;

    sf::SoundBuffer inicioBuffer;
    sf::Sound inicio;

    sf::SoundBuffer lixeiraCheiaBuffer;
    sf::Sound lixeiraCheia;

    /*Controles de Estado*/
    bool controlEsteira;
    int controlCaptura;

    /*Objetos permanentes*/
    Objeto background;
    Objeto fundo;
    Objeto cap;

    sf::Clock clk_esteira;

private:

    /*Dimensões da tela*/
    int width, height;

};

string to_string(int x);

#endif // GUI_H
