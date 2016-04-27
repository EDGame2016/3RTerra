#ifndef LIXEIRA_H
#define LIXEIRA_H


class Lixeira
{
public:
    Lixeira();
    Lixeira(int tipo);
    ~Lixeira();

    void setTipo(int tipo);
    bool trocaEstado(bool i);

    void incrementa();
    void zera();
    bool cheia();

    int getContador()const;
    int getTipo()const;
    bool getEstado()const;

private:
    int tipo;
    int contador;
    bool estado;
};

#endif // LIXEIRA_H
