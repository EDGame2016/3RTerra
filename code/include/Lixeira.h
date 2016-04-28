#ifndef LIXEIRA_H
#define LIXEIRA_H


class Lixeira
{
public:
    Lixeira();
    Lixeira(int tipo); // constroi com o tipo da lixeira

    void setTipo(int tipo);
    bool trocaEstado(bool i); // troca o estado de estar pressionada ou não

    void incrementa(); // incrementa o contador de lixo
    void zera(); // zera o contador de lixo
    bool cheia(); // retorna true se a lixeira estiver cheia

    int getContador()const; // retorna a quantidade de lixo
    int getTipo()const;
    bool getEstado()const;

private:
    int tipo;
    int contador;
    bool estado;
};

#endif // LIXEIRA_H
