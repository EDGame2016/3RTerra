#include "GUI.h"

GUI::GUI(int width, int height):tela(sf::VideoMode(width, height), "Jogo", sf::Style::Fullscreen), clk_esteira()
{
    tela.setMouseCursorVisible(false);

    /*Configura as dimensões da tela*/
    this->width = width;
    this->height = height;

    string aux;

    /*Carrega as texturas (imagens)*/
    logo_tex.loadFromFile("src/images/logoTerra.png");
    logo_tex.setSmooth(true);

    tut_tex.loadFromFile("src/images/tut.jpg");
    tut_tex.setSmooth(true);

    pause_tex.loadFromFile("src/images/pause.png");
    pause_tex.setSmooth(true);

    int i;

    for(i = 0; i<5; i++)
    {
        aux = to_string(i+1);
        cenario_tex[i].loadFromFile("src/images/cenarios/level"+aux+".png");
        cenario_tex[i].setSmooth(true);
    }

    for(i = 0; i<2; i++)
    {
        aux = to_string(i+1);

        background_tex[i].loadFromFile("src/images/cenarios/background"+aux+".jpg");
        background_tex[i].setSmooth(true);

        esteira_tex[i].loadFromFile("src/images/elementos/esteira"+aux+".png");
        esteira_tex[i].setSmooth(true);

        lixeiraVidro_tex[i].loadFromFile("src/images/lixeiras/vidro"+aux+".png");
        lixeiraVidro_tex[i].setSmooth(true);

        lixeiraPapel_tex[i].loadFromFile("src/images/lixeiras/papel"+aux+".png");
        lixeiraPapel_tex[i].setSmooth(true);

        lixeiraPlastico_tex[i].loadFromFile("src/images/lixeiras/plastico"+aux+".png");
        lixeiraPlastico_tex[i].setSmooth(true);

        lixeiraMetal_tex[i].loadFromFile("src/images/lixeiras/metal"+aux+".png");
        lixeiraMetal_tex[i].setSmooth(true);

        lixeiraOrganico_tex[i].loadFromFile("src/images/lixeiras/organico"+aux+".png");
        lixeiraOrganico_tex[i].setSmooth(true);
    }

    indicadorLixeira_tex.loadFromFile("src/images/lixeiras/indicador.png");
    indicadorLixeira_tex.setSmooth(true);

    rectGreen_tex.loadFromFile("src/images/lixeiras/rectGreen.png");
    rectBlue_tex.loadFromFile("src/images/lixeiras/rectBlue.png");
    rectRed_tex.loadFromFile("src/images/lixeiras/rectRed.png");
    rectYellow_tex.loadFromFile("src/images/lixeiras/rectYellow.png");
    rectBrown_tex.loadFromFile("src/images/lixeiras/rectBrown.png");

    lixoVidro_tex.loadFromFile("src/images/lixo/vidro1.png");
    lixoVidro_tex.setSmooth(true);
    lixoPapel_tex.loadFromFile("src/images/lixo/papel1.png");
    lixoPapel_tex.setSmooth(true);
    lixoPlastico_tex.loadFromFile("src/images/lixo/plastico1.png");
    lixoPlastico_tex.setSmooth(true);
    lixoMetal_tex.loadFromFile("src/images/lixo/metal1.png");
    lixoMetal_tex.setSmooth(true);
    lixoOrganico_tex.loadFromFile("src/images/lixo/org1.png");
    lixoOrganico_tex.setSmooth(true);

    for(i=0; i < 6; i++)
    {
        aux = to_string(i);
        cap_tex[i].loadFromFile("src/images/caps/cap"+aux+".png");
    }

    /*Carrega as fontes de texto*/
    font.loadFromFile("src/fonts/HelveticaNeue.otf");

    /*Carrega o áudios*/
    musicaFundo.openFromFile("src/sounds/Carefree.ogg");
    musicaFundo.setLoop(true);

    clickBuffer.loadFromFile("src/sounds/click.ogg");
    click.setBuffer(clickBuffer);

    inicioBuffer.loadFromFile("src/sounds/inicio.ogg");
    inicio.setBuffer(inicioBuffer);

    lixeiraCheiaBuffer.loadFromFile("src/sounds/lixeiraCheia.ogg");
    lixeiraCheia.setBuffer(lixeiraCheiaBuffer);

    successBuffer.loadFromFile("src/sounds/success.ogg");
    success.setBuffer(successBuffer);

    /*Inicializa os controladores*/
    controlEsteira = true;
    controlCaptura = 0;

    /*Inicialização dos Objetos permanentes*/
    background.setTexture(background_tex[0]);
    background.setPosition(width/2, height/2);

    fundo.setTexture(cenario_tex[0]);
    fundo.setPosition(width/2, 7.2*height/20);
    fundo.setScale(0.4);

    cap.setTexture(cap_tex[0]);
    cap.setOrigin(0,cap.getGlobalBounds().height);
    cap.setScale(0.5);
    cap.setAlpha(70);
    cap.setPosition(10.5*width/20, 17.1*(height/20));

    /*Inicializa o contador de tempo para a função desenha esteira*/
    clk_esteira.restart();

}

GUI::~GUI()
{

}

void GUI::renderiza()
{
    tela.display();
}

void GUI::limpaTela()
{
    tela.clear(sf::Color(255, 255, 255, 0));
}

void GUI::desenhaFundo(int level)
{
    this->fundo.setTexture(cenario_tex[4]);
    if(level < 6)
    {
        this->background.setTexture(background_tex[0]);
        this->fundo.setTexture(cenario_tex[level-1]);
        this->cap.setTexture(cap_tex[controlCaptura]);
    }

    if(level == 6)
        this->background.setTexture(background_tex[1]);

    this->tela.draw(background);

    if(level < 6)
        this->tela.draw(cap);

    this->tela.draw(fundo);
}

void GUI::desenhaLixeiras(Lixeira* lixeiras)
{
    Objeto indicadorLixeira(indicadorLixeira_tex);
    indicadorLixeira.setScale(0.4);
    Objeto rect(rectGreen_tex);
    rect.setScale(0.4);
    sf::Texture aux(lixeiraVidro_tex[0]);
    Objeto icone(aux);
    icone.setScale(0.4);

    for(int i=0; i<5; i++)
    {
        indicadorLixeira.setPosition((width/20)*(i+1), height-(height/3.43));
        this->tela.draw(indicadorLixeira);

        switch(lixeiras[i].getTipo())
        {
        case VERDE:
        {
            if(lixeiras[i].getEstado())
                aux = lixeiraVidro_tex[1];
            icone.setTexture(aux);
            rect.setTexture(rectGreen_tex);
            break;
        }
        case AZUL:
        {
            if(!lixeiras[i].getEstado())
                aux = lixeiraPapel_tex[0];
            else
                aux = lixeiraPapel_tex[1];
            icone.setTexture(aux);
            rect.setTexture(rectBlue_tex);
            break;
        }
        case VERMELHO:
        {
            if(!lixeiras[i].getEstado())
                aux = lixeiraPlastico_tex[0];
            else
                aux = lixeiraPlastico_tex[1];
            icone.setTexture(aux);
            rect.setTexture(rectRed_tex);
            break;
        }
        case AMARELO:
        {
            if(!lixeiras[i].getEstado())
                aux = lixeiraMetal_tex[0];
            else
                aux = lixeiraMetal_tex[1];
            icone.setTexture(aux);
            rect.setTexture(rectYellow_tex);
            break;
        }
        case MARROM:
        {
            if(!lixeiras[i].getEstado())
                aux = lixeiraOrganico_tex[0];
            else
                aux = lixeiraOrganico_tex[1];
            icone.setTexture(aux);
            rect.setTexture(rectBrown_tex);
            break;
        }
        default:
            break;
        }

        for(int j=0; j <lixeiras[i].getContador(); j++)
        {
            rect.setPosition((width/20)*(i+1), height-(height/5.4)-(17*j));
            this->tela.draw(rect);
        }

        icone.setPosition((width/20)*(i+1), height-(height/10));
        this->tela.draw(icone);
    }
}

void GUI::desenhaEsteira(int speed)
{
    sf::Time deltaTime = clk_esteira.getElapsedTime();
    sf::Texture aux(esteira_tex[0]);

    if(!this->controlEsteira)
        aux = this->esteira_tex[1];

    Objeto esteira(aux);
    esteira.setScale(0.4);
    esteira.setPosition(15*(width/20), 9*(height/10));
    tela.draw(esteira);
    if(deltaTime.asSeconds()>= 0.1/(speed/2.f))
    {
        this->controlEsteira = !this->controlEsteira;
        clk_esteira.restart();
    }
}

void GUI::desenhaLixo(FilaDeLixo& filaLixo, int speed)
{
    Lixo aux;
    FilaDeLixo a(10);
    filaLixo.move(speed);
    sf::Vector2f movement(1.f, 0.f);

    while(filaLixo.retira(aux))
    {
        tela.draw(aux);
        a.insere(aux);
    }
    while(a.retira(aux))
    {
        filaLixo.insere(aux);
    }
}

void GUI::desenhaTexto(string txt, int csize, sf::Color color, float x, float y, bool origin)
{
    sf::Text text;
    text.setFont(font);

    text.setCharacterSize(csize);
    text.setColor(color);
    text.setString(txt);

    if(origin)
        text.setOrigin((text.getGlobalBounds().width/2),(text.getGlobalBounds().height/2));
    else
        text.setOrigin(0,0);

    text.setPosition (x, y);

    tela.draw(text);
}

void GUI::desenhaPause()
{
    Objeto aux(pause_tex);
    aux.setAlpha(200);
    aux.setScale(0.5);
    aux.setPosition(width/2, height/2);
    tela.draw(aux);
    tela.display();
}

int GUI::getWidth()const
{
    return this->width;
}
int GUI::getHeigth()const
{
    return this->height;
}

string to_string(int x)
{
    std::stringstream result;
    result << x;
    return result.str();
}
