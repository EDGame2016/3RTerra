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

    /*Métodos*/
    void processaEventos(); // processa as entradas do usuário
    void atualizaEstado(); // atualiza o estado do jogo, ou seja,
    void desenha(); // desenha todos os elementos da tela que já foram previamente atualizados
    void geraFila(); // produz uma fila com elementos Lixo randomicamente
    void completaFila(); // completa a fila de Lixo para que o fluxo seja contínuo
    void playerInput(sf::Keyboard::Key key, bool isPressed); // executa as devidas funções de acordo com as entradas do usuário
    bool pegaLixo(int tipo); // captura o lixo que está passando no espaço de captura
    bool verificaLixo(); // verifica se o elemento inicial da fila de Lixo ultrapassou a margem da tela e o retira da fila
    void decrementaLevel();
    void incrementaLevel();
    void incrementaScore();

    void intro(); // tela de introdução
    void tutorial(); // tela de tutorial(instruções)
    void encerramento(); // tela de encerramento do jogo (o jogador completou todas as fazes)

    /*Atributos*/
    GUI gui; // Objeto do tipo GUI que possui as operações de interface gráfica
    int level; // armazena a fase atual do jogo
    bool jogo_paused; // controla o estado do jogo (se está em pausa ou não)
    Lixeira lixeiras[5]; // armazena as lixeiras do do tipo Lixeira
    FilaDeLixo filaLixo; // Fila com os elementos "Lixo"
    sf::Time timePerFrame; // configura o FPS

    sf::Clock score; // controlador do Tempo mostrado ao usuário
    sf::Time past_time;

    int antesVirgula; // auxilia no desenho do tempo na tela
    int depoisVirgula; // auxilia no desenho do tempo na tela
};

#endif // JOGO_H
