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

    /*M�todos*/
    void processaEventos(); // processa as entradas do usu�rio
    void atualizaEstado(); // atualiza o estado do jogo, ou seja,
    void desenha(); // desenha todos os elementos da tela que j� foram previamente atualizados
    void geraFila(); // produz uma fila com elementos Lixo randomicamente
    void completaFila(); // completa a fila de Lixo para que o fluxo seja cont�nuo
    void playerInput(sf::Keyboard::Key key, bool isPressed); // executa as devidas fun��es de acordo com as entradas do usu�rio
    bool pegaLixo(int tipo); // captura o lixo que est� passando no espa�o de captura
    bool verificaLixo(); // verifica se o elemento inicial da fila de Lixo ultrapassou a margem da tela e o retira da fila
    void decrementaLevel();
    void incrementaLevel();
    void incrementaScore();

    void intro(); // tela de introdu��o
    void tutorial(); // tela de tutorial(instru��es)
    void encerramento(); // tela de encerramento do jogo (o jogador completou todas as fazes)

    /*Atributos*/
    GUI gui; // Objeto do tipo GUI que possui as opera��es de interface gr�fica
    int level; // armazena a fase atual do jogo
    bool jogo_paused; // controla o estado do jogo (se est� em pausa ou n�o)
    Lixeira lixeiras[5]; // armazena as lixeiras do do tipo Lixeira
    FilaDeLixo filaLixo; // Fila com os elementos "Lixo"
    sf::Time timePerFrame; // configura o FPS

    sf::Clock score; // controlador do Tempo mostrado ao usu�rio
    sf::Time past_time;

    int antesVirgula; // auxilia no desenho do tempo na tela
    int depoisVirgula; // auxilia no desenho do tempo na tela
};

#endif // JOGO_H
