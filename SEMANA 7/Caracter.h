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

public:
	CCaracter(){//POS RANDOM PARA VIRUS Y VACUNAS
		this->x = rand() % 30 + 20;
		this->y = rand() % 30 + 6; 
	}

	CCaracter(int x, int y) {//POS ESPECIFICAS PARA PERSONA Y CASA
		this->x = x;
		this->y = y;
	}

	~CCaracter(){}

	//GETs PARA VALIDAR COLISION
	int getX() { return x; }
	int getY() { return y; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }

	//SETs PARA REGRESAR A LA PERSONA EN SU POS INICIAL
	void setX(int x) { this->x=x; }
	void setY(int y) { this->y=y; }

	virtual void mover(){}
};