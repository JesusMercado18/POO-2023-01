#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class COvni{
protected:
	int x, y;
	int dy;
	int ancho, alto;

public:
	//CONSTRUCTOR
	COvni(int x ,int y){ //RECIBE PARAMETROS PORQUE CADA NAVE TIENE POSICIONES DIFERENTES
		this->x = x;
		this->y = y;
	}
	~COvni(){}

	//FUNCIONES GET
	int getY() { return y; }
	int getAlto() { return alto; }
	int getDy() { return dy; }

	//OTRA FORMA RAPIDA DE UN GET DE LOS 3 ANTERIORES
	int getYmasAltomasDy() { return y + alto + dy; }

	//MOVIMIENTO DE REBOTE
	void moverRebote() {
		if (y + dy <= 0 || y + dy + alto >= 50) dy *= -1; // dy = dy * -1;
		y += dy;
	}

	//MOVIMIENTO DE CAIDA
	void moverCaida() {
		if (y + dy + alto <= 50) y += dy;
	}
};