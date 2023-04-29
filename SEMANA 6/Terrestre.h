#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class CTerrestre{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;

public:
	CTerrestre(){//POS RANDOM DE TRANSPORTES
		x = rand() % 50 + 15;
		y = rand() % 30 + 5;
	}

	CTerrestre(int x, int y) {//POS PERSONA
		this->x = x;
		this->y = y;
	}
	~CTerrestre(){}

	//ESTOS GETs NOS SERVIRAN PARA VALIDAR COLISIONES
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }

	//ESTOS SETs NOS SERVIRAN PARA REGRESAR A LA PERSONA EN SU POS INICIAL
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	void moverTransporte() {
		if (x + dx <= 3 || x + ancho + dx >= 100)dx *= -1;
		x += dx;
	}
};