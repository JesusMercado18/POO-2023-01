#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class CAvion{
protected:
	int x, y; //POSICIONES
	int dx, dy; //DIRECCIONES
	int ancho, alto; //DIMENSIONES

public:
	CAvion(){//CONSTRUCTOR PARA POSICIONES DE LA LINEA DE NAZCA
		x = 50;
		y = 25;
	}
	CAvion(int x, int y){//CONSTRUCTOR PARA POSICIONES DE LOS AVIONES
		this->x = x;
		this->y = y;
	}
	~CAvion(){}

	void mover() {
		//REBOTE
		if (x + ancho + dx > 100 || x + dx < 4)dx *= -1;//CAMBIO DIRECCION EN EJE X
		if (y + alto + dy > 50 || y + dy < 4)dy *= -1;//CAMBIO DIRECCION EN EJE Y

		//MOVIMIENTO
		x += dx; //x = dx + x;
		y += dy; //y = dy + y;
	}

};