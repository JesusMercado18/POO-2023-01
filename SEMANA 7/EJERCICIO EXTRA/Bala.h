#pragma once
#include "Caracter.h"

class CBala : public CCaracter{
private:
	char direccionB;

public:
	CBala(int x, int y, char direccionP) : CCaracter(x, y){
		dx = 2;
		dy = 2;
		ancho = 2;
		alto = 1;
		direccionB = direccionP;
		visibilidad = true;
	}
	~CBala(){}

	void moverBala() {
		if (direccionB == 'A' && x + dx >= 0) {
			x -= dx;
		}
		if (direccionB == 'D' && x + dx + ancho <= 70) {
			x += dx;
		}
		if (direccionB == 'W' && y + dy >= 0) {
			y -= dy;
		}
		if (direccionB == 'S' && y + dy + alto <= 40) {
			y += dy;
		}
	}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void dibujar() {
	    Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x, y); cout << "*";
	}

};