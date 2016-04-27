#include "Jogo.h"

Jogo::Jogo():gui(), filaLixo(10)
{
    lixeiras[0].setTipo(VERDE);
    lixeiras[1].setTipo(AZUL);
    lixeiras[2].setTipo(VERMELHO);
    lixeiras[3].setTipo(AMARELO);
    lixeiras[4].setTipo(MARROM);

    level = 0;

    jogo_paused = false;

    timePerFrame = sf::seconds(1.f/30.f);

    antesVirgula = 0;
    depoisVirgula = 0;

    srand (time(NULL));
}

void Jogo::run()
{
    intro();

    sf::Clock clock;
    gui.clk_esteira.restart();

    geraFila();

    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    score.restart();

    gui.musicaFundo.play();
    while(gui.tela.isOpen())
    {
        timeSinceLastUpdate += clock.restart();

        if(timeSinceLastUpdate > timePerFrame)
        {
            processaEventos();
            if(!jogo_paused)
            {
                atualizaEstado();
                desenha();
            }

            timeSinceLastUpdate = sf::Time::Zero;
        }

    }
}

void Jogo::processaEventos()
{
    sf::Event evento;

    while (gui.tela.pollEvent(evento))
    {
        switch(evento.type)
        {
        case(sf::Event::Closed):
        {
            gui.tela.close();
            break;
        }
        case(sf::Event::KeyPressed):
        {
            if(evento.key.code == sf::Keyboard::Escape)
            {
                gui.tela.close();
            }
            else
            {
                playerInput(evento.key.code, true);
            }

            break;
        }
        case(sf::Event::KeyReleased):
        {
            if(evento.key.code == sf::Keyboard::Escape)
            {
                gui.tela.close();
            }
            else
            {
                playerInput(evento.key.code, false);
            }

            break;
        }
        default:
            break;
        }
    }

}

void Jogo::playerInput(sf::Keyboard::Key key, bool isPressed)
{
    switch(key)
    {
    case sf::Keyboard::Q:
    {
        if(isPressed && !this->jogo_paused)
        {
            gui.controlCaptura = 1;

            if(this->lixeiras[0].trocaEstado(isPressed))
            {
                pegaLixo(VERDE);
                gui.click.play();
            }

        }
        else
        {
            this->lixeiras[0].trocaEstado(isPressed);
            gui.controlCaptura = 0;
        }

        break;
    }
    case sf::Keyboard::W:
    {
        if(isPressed && !this->jogo_paused)
        {
            gui.controlCaptura = 2;

            if(this->lixeiras[1].trocaEstado(isPressed))
            {
                pegaLixo(AZUL);
                gui.click.play();
            }

        }
        else
        {
            this->lixeiras[1].trocaEstado(isPressed);
            gui.controlCaptura = 0;
        }

        break;
    }
    case sf::Keyboard::E:
    {
        if(isPressed && !this->jogo_paused)
        {
            gui.controlCaptura = 3;

            if(this->lixeiras[2].trocaEstado(isPressed))
            {
                pegaLixo(VERMELHO);
                gui.click.play();
            }

        }
        else
        {
            this->lixeiras[2].trocaEstado(isPressed);
            gui.controlCaptura = 0;
        }

        break;
    }
    case sf::Keyboard::R:
    {
        if(isPressed && !this->jogo_paused)
        {
            gui.controlCaptura = 4;

            if(this->lixeiras[3].trocaEstado(isPressed))
            {
                pegaLixo(AMARELO);
                gui.click.play();
            }

        }
        else
        {
            this->lixeiras[3].trocaEstado(isPressed);
            gui.controlCaptura = 0;
        }

        break;
    }
    case sf::Keyboard::F:
    {
        if(isPressed && !this->jogo_paused)
        {
            gui.controlCaptura = 5;

            if(this->lixeiras[4].trocaEstado(isPressed))
            {
                pegaLixo(MARROM);
                gui.click.play();
            }

        }
        else
        {
            this->lixeiras[4].trocaEstado(isPressed);
            gui.controlCaptura = 0;
        }
        break;
    }
    case sf::Keyboard::P:
    {
        if(isPressed)
        {
            this->jogo_paused = !this->jogo_paused;

            if(this->jogo_paused)
                gui.musicaFundo.setVolume(10);
            else
                gui.musicaFundo.setVolume(100);

            gui.desenhaPause();
        }

    }
    default:
        break;
    }
}

void Jogo::atualizaEstado()
{
    verificaLixo();
    completaFila();
    incrementaScore();
}

void Jogo::desenha()
{
    gui.limpaTela();
    gui.desenhaFundo(this->level);
    gui.desenhaLixeiras(lixeiras);
    gui.desenhaEsteira(this->level);
    gui.desenhaLixo(filaLixo, this->level);
    gui.desenhaTexto("Tempo: "+to_string(antesVirgula) + "." + to_string(depoisVirgula), 30, sf::Color(0,0,0,100), gui.getWidth()/20, gui.getHeigth()/20, false);
    gui.renderiza();
}

void Jogo::geraFila()
{
    int randomTipo;
    int i = 0;
    while(!filaLixo.cheia())
    {
        randomTipo = rand() % 5 + 1;
        Lixo aux;
        aux.setTipo(randomTipo);
        switch(aux.getTipo())
        {
        case VERDE:
        {
            aux.setTexture(gui.lixoVidro_tex);
            break;
        }
        case AZUL:
        {
            aux.setTexture(gui.lixoPapel_tex);
            break;
        }
        case VERMELHO:
        {
            aux.setTexture(gui.lixoPlastico_tex);
            break;
        }
        case AMARELO:
        {
            aux.setTexture(gui.lixoMetal_tex);
            break;
        }
        case MARROM:
        {
            aux.setTexture(gui.lixoOrganico_tex);
            break;
        }
        }
        aux.setOrigin(aux.getGlobalBounds().width/2,aux.getGlobalBounds().height);
        aux.setScale(0.3);
        aux.setPosition(gui.getWidth() + (i*gui.getWidth()/12), 8.5*(gui.getHeigth()/10));
        filaLixo.insere(aux);
        i++;
    }
}

void Jogo::completaFila()
{
    int randomTipo = rand() % 5 + 1;
    Lixo aux;
    Lixo ultimo;
    aux.setTipo(randomTipo);
    switch(aux.getTipo())
    {
    case VERDE:
    {
        aux.setTexture(gui.lixoVidro_tex);
        break;
    }
    case AZUL:
    {
        aux.setTexture(gui.lixoPapel_tex);
        break;
    }
    case VERMELHO:
    {
        aux.setTexture(gui.lixoPlastico_tex);
        break;
    }
    case AMARELO:
    {
        aux.setTexture(gui.lixoMetal_tex);
        break;
    }
    case MARROM:
    {
        aux.setTexture(gui.lixoOrganico_tex);
        break;
    }
    }
    aux.setOrigin(aux.getGlobalBounds().width/2,aux.getGlobalBounds().height);
    aux.setScale(0.3);
    filaLixo.pegaOUltimo(ultimo);
    aux.setPosition(ultimo.getPosition().x + (gui.getWidth()/12), 8.5*(gui.getHeigth()/10));
    filaLixo.insere(aux);


}

bool Jogo::pegaLixo(int tipo)
{
    Lixo aux;
    filaLixo.pegaOPrimeiro(aux);
    if((aux.getPosition().x > 10.5*gui.getWidth()/20)&&(aux.getPosition().x < 100 + (10.5*gui.getWidth()/20)))
    {
        filaLixo.retira(aux);
        if(aux.getTipo()== tipo)
        {
            if(!lixeiras[tipo-1].cheia())
            {
                this->lixeiras[tipo-1].incrementa();
                if(lixeiras[tipo-1].cheia())
                {
                    incrementaLevel();
                    gui.lixeiraCheia.play();
                }
            }
            return true;
        }

        else
        {
            if(lixeiras[tipo-1].cheia())
            {
                decrementaLevel();
            }

            this->lixeiras[tipo-1].zera();
            return false;
        }

    }
    else
    {
        if(lixeiras[tipo-1].cheia())
        {
            decrementaLevel();
        }

        this->lixeiras[tipo-1].zera();
        return false;
    }
}

bool Jogo::verificaLixo()
{
    Lixo aux;
    filaLixo.pegaOPrimeiro(aux);
    if(aux.getPosition().x < 10.5*gui.getWidth()/20)
    {
        filaLixo.retira(aux);

        if(lixeiras[aux.getTipo()-1].cheia())
        {
            decrementaLevel();
        }

        this->lixeiras[aux.getTipo()-1].zera();

        return true;
    }
    else
        return false;
}

void Jogo::decrementaLevel()
{
    if(this->level > 1)
        this->level--;
}
void Jogo::incrementaLevel()
{
    if(this->level < 6)
        this->level++;
}

void Jogo::incrementaScore()
{
    past_time = score.getElapsedTime();

    if(past_time.asSeconds() > 1)
    {
        depoisVirgula++;

        if(depoisVirgula == 10){
            antesVirgula++;
            depoisVirgula = 0;
        }

        score.restart();
    }
}

void Jogo::intro()
{
    Objeto logo(gui.logo_tex);
    logo.setPosition(gui.getWidth()/2, gui.getHeigth()/2.3);

    /*---Texto---*/
    sf::Clock clk_intro;
    int controlAlpha = 2;
    bool sobe = true;

    while(gui.tela.isOpen())
    {
        sf::Event evento;

        gui.limpaTela();

        while (gui.tela.pollEvent(evento))
        {
            switch(evento.type)
            {
            case(sf::Event::Closed):
                gui.tela.close();
                break;
            case(sf::Event::KeyPressed):
            {
                if(evento.key.code == sf::Keyboard::Escape)
                {
                    gui.tela.close();
                }
                else
                {
                    gui.inicio.play();
                    incrementaLevel();
                    sf::Time tempo = sf::milliseconds(500);
                    sf::sleep(tempo);
                    tutorial();

                    return;
                }
                break;
            }
            default:
                break;
            }
        }

        /*---Texto---*/
        sf::Time elapsed = clk_intro.getElapsedTime();

        if(elapsed.asSeconds() > 0.1)
        {
            if(sobe)
                controlAlpha++;
            else
                controlAlpha--;

            if(controlAlpha == 10 || controlAlpha == 2)
                sobe = !sobe;

            clk_intro.restart();
        }

        sf::Color color(100,100,100, 25 * controlAlpha);

        gui.limpaTela();

        gui.desenhaTexto("Pressione qualquer tecla para começar", 30, color, gui.getWidth()/2, gui.getHeigth()/1.2, true);

        gui.tela.draw(logo);
        gui.renderiza();
    }

}

void Jogo::tutorial()
{
    sf::Sprite image(gui.tut_tex);
    image.setPosition(0,0);
    image.setScale(0.48,0.48);

    while(gui.tela.isOpen())
    {
        sf::Event evento;

        gui.limpaTela();

        while (gui.tela.pollEvent(evento))
        {
            switch(evento.type)
            {
            case(sf::Event::Closed):
                gui.tela.close();
                break;
            case(sf::Event::KeyPressed):
            {
                if(evento.key.code == sf::Keyboard::Escape)
                {
                    gui.tela.close();
                }
                else
                {

                    return;
                }
                break;
            }
            default:
                break;
            }
        }

        gui.tela.draw(image);
        gui.renderiza();
    }

}
