#ifndef JOGO_H
#define JOGO_H

#include "Lixo.h"
#include "GUI.h"
#include "constantes.h"

class Jogo
{
public:

    Jogo();
    void run();

private:

    //M�todos
    void processaEventos();
    void atualizaEstado();
    void desenha();
    void geraFila();
    void completaFila();
    void playerInput(sf::Keyboard::Key key, bool isPressed);
    bool pegaLixo(int tipo);
    bool verificaLixo();
    void decrementaLevel();
    void incrementaLevel();
    void incrementaScore();

    void intro();
    void tutorial();

    //Atributos
    GUI gui;
    int level;
    bool jogo_paused;
    Lixeira lixeiras[5];
    FilaDeLixo filaLixo;
    sf::Time timePerFrame;

    sf::Clock score;
    sf::Time past_time;
    int antesVirgula;
    int depoisVirgula;
};

#endif // JOGO_H
