#pragma once
#include "Terrestre.h"

class CPersona : public CTerrestre{
private:
public:
	CPersona(int x, int y) : CTerrestre(x, y){
		dx = 2;
		dy = 2;
		ancho = 2;
		alto = 2;
	}
	~CPersona(){}

	void dibujar() {
		//PERSONA DE COLOR VERDE
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y);     cout << "@";
		Console::SetCursorPosition(x, y + 1); cout << char(197);
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << " ";
		Console::SetCursorPosition(x, y + 1); cout << " ";
	}

	void moverPersona(char key){
		switch (key){
		case 'A':
			if (x >= 3)x -= dx;
			break;
		case 'D':
			if (x + dx + ancho <= 100) x += dx;
			break;
		case 'W':
			if (y >= 3) y -= dy;
			break;
		case 'S':
			if (y + dy + alto <= 50) y += dy;
			break;
		}
	}
};