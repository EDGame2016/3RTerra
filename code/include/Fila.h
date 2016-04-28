#ifndef FILA_H
#define FILA_H

#include "Lixo.h"


template <class T>

class Fila
{
public:

	Fila(int tamanho = 10);
	~Fila();
	bool vazia();
	bool cheia();
	bool insere(T x);
	bool retira(T &x);

protected:
	T* elementos;
	int inicio;
	int ultimo;
	int NElementos;
	int tamanho;
};

#endif // FILA_H
