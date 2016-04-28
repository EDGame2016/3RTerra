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

    //Métodos
    void processaEventos(); // processa as entradas do usuário
    void atualizaEstado(); // atualiza o estado do jogo, ou seja,
    void desenha(); // desenha todos os elementos da tela que já foram previamente atualizados
    void geraFila(); // produz uma fila com elementos Lixo randomicamente
    void completaFila(); //
    void playerInput(sf::Keyboard::Key key, bool isPressed);
    bool pegaLixo(int tipo);
    bool verificaLixo();
    void decrementaLevel();
    void incrementaLevel();
    void incrementaScore();

    void intro();
    void tutorial();
    void encerramento();

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
