#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class CCaracter{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	bool visibilidad;

public:
	CCaracter(){ //POS PARA ENEMIGOS
		x = rand() % 30 + 20;
		y = rand() % 30 + 6;
	}
	CCaracter(int x, int y){ //POS PARA SOLDADO
		this->x = x;
		this->y = y;
	}
	~CCaracter(){}

	int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	bool getVisibilidad() { return visibilidad; }
	void setVisibilidad(int v) { visibilidad = v; }

	void moverEnemigo() {
		if (x + dx <= 0 || x + dx + ancho >= 70) dx *= -1;
		if (y + dy <= 0 || y + dy + alto >= 40) dy *= -1;
		x += dx;
		y += dy;
	}
};